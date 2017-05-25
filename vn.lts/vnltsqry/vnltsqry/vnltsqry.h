//˵������

//ϵͳ
#ifdef WIN32
#include "stdafx.h"
#endif
#include <string>
#include <queue>

//Boost
#define BOOST_PYTHON_STATIC_LIB
#include <boost/python/module.hpp>	//python��װ
#include <boost/python/def.hpp>		//python��װ
#include <boost/python/dict.hpp>	//python��װ
#include <boost/python/object.hpp>	//python��װ
#include <boost/python.hpp>			//python��װ
#include <boost/thread.hpp>			//������е��̹߳���
#include <boost/bind.hpp>			//������е��̹߳���
#include <boost/any.hpp>			//������е�����ʵ��

//API
#include "SecurityFtdcQueryApi.h"

//�����ռ�
using namespace std;
using namespace boost::python;
using namespace boost;

//����
#define ONFRONTCONNECTED 1
#define ONFRONTDISCONNECTED 2
#define ONHEARTBEATWARNING 3
#define ONRSPERROR 4
#define ONRSPUSERLOGIN 5
#define ONRSPUSERLOGOUT 6
#define ONRSPFETCHAUTHRANDCODE 7
#define ONRSPQRYEXCHANGE 8
#define ONRSPQRYINSTRUMENT 9
#define ONRSPQRYINVESTOR 10
#define ONRSPQRYTRADINGCODE 11
#define ONRSPQRYTRADINGACCOUNT 12
#define ONRSPQRYBONDINTEREST 13
#define ONRSPQRYMARKETRATIONINFO 14
#define ONRSPQRYINSTRUMENTCOMMISSIONRATE 15
#define ONRSPQRYETFINSTRUMENT 16
#define ONRSPQRYETFBASKET 17
#define ONRSPQRYOFINSTRUMENT 18
#define ONRSPQRYSFINSTRUMENT 19
#define ONRSPQRYINSTRUMENTUNITMARGIN 20
#define ONRSPQRYPREDELIVINFO 21
#define ONRSPQRYCREDITSTOCKASSIGNINFO 22
#define ONRSPQRYCREDITCASHASSIGNINFO 23
#define ONRSPQRYCONVERSIONRATE 24
#define ONRSPQRYHISCREDITDEBTINFO 25
#define ONRSPQRYMARKETDATASTATICINFO 26
#define ONRSPQRYEXPIREREPURCHINFO 27
#define ONRSPQRYBONDPLEDGERATE 28
#define ONRSPQRYPLEDGEBOND 29
#define ONRSPQRYORDER 30
#define ONRSPQRYTRADE 31
#define ONRSPQRYINVESTORPOSITION 32
#define ONRSPQRYFUNDTRANSFERSERIAL 33
#define ONRSPQRYFUNDINTERTRANSFERSERIAL 34


///-------------------------------------------------------------------------------------
///API�еĲ������
///-------------------------------------------------------------------------------------

//GILȫ�����򻯻�ȡ�ã�
//���ڰ���C++�̻߳��GIL�����Ӷ���ֹpython����
class PyLock
{
private:
	PyGILState_STATE gil_state;

public:
	//��ĳ�����������д����ö���ʱ�����GIL��
	PyLock()
	{
		gil_state = PyGILState_Ensure();
	}

	//��ĳ��������ɺ����ٸö���ʱ�����GIL��
	~PyLock()
	{
		PyGILState_Release(gil_state);
	}
};


//����ṹ��
struct Task
{
	int task_name;		//�ص��������ƶ�Ӧ�ĳ���
	any task_data;		//���ݽṹ��
	any task_error;		//����ṹ��
	int task_id;		//����id
	bool task_last;		//�Ƿ�Ϊ��󷵻�
};


///�̰߳�ȫ�Ķ���
template<typename Data>

class ConcurrentQueue
{
private:
	queue<Data> the_queue;								//��׼�����
	mutable mutex the_mutex;							//boost������
	condition_variable the_condition_variable;			//boost��������

public:

	//�����µ�����
	void push(Data const& data)
	{
		mutex::scoped_lock lock(the_mutex);				//��ȡ������
		the_queue.push(data);							//������д�������
		lock.unlock();									//�ͷ���
		the_condition_variable.notify_one();			//֪ͨ���������ȴ����߳�
	}

	//�������Ƿ�Ϊ��
	bool empty() const
	{
		mutex::scoped_lock lock(the_mutex);
		return the_queue.empty();
	}

	//ȡ��
	Data wait_and_pop()
	{
		mutex::scoped_lock lock(the_mutex);

		while (the_queue.empty())						//������Ϊ��ʱ
		{
			the_condition_variable.wait(lock);			//�ȴ���������֪ͨ
		}

		Data popped_value = the_queue.front();			//��ȡ�����е����һ������
		the_queue.pop();								//ɾ��������
		return popped_value;							//���ظ�����
	}

};


//���ֵ��л�ȡĳ����ֵ��Ӧ������������ֵ������ṹ������ֵ��
void getInt(dict d, string key, int* value);


//���ֵ��л�ȡĳ����ֵ��Ӧ�ĸ�����������ֵ������ṹ������ֵ��
void getDouble(dict d, string key, double* value);


//���ֵ��л�ȡĳ����ֵ��Ӧ���ַ���������ֵ������ṹ������ֵ��
void getChar(dict d, string key, char* value);


///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class QryApi : public CSecurityFtdcQuerySpi
{
private:
	CSecurityFtdcQueryApi* api;			//API����
	thread *task_thread;				//�����߳�ָ�루��python���������ݣ�
	ConcurrentQueue<Task> task_queue;	//�������

public:
	QryApi()
	{
		function0<void> f = boost::bind(&QryApi::processTask, this);
		thread t(f);
		this->task_thread = &t;
	};

	~QryApi()
	{
	};

	//-------------------------------------------------------------------------------------
	//API�ص�����
	//-------------------------------------------------------------------------------------

	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected();

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason);

	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse);

	///����Ӧ��
	virtual void OnRspError(CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��¼������Ӧ
	virtual void OnRspUserLogin(CSecurityFtdcRspUserLoginField *pRspUserLogin, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CSecurityFtdcUserLogoutField *pUserLogout, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ȡ��֤�����������Ӧ
	virtual void OnRspFetchAuthRandCode(CSecurityFtdcAuthRandCodeField *pAuthRandCode, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��������Ӧ
	virtual void OnRspQryExchange(CSecurityFtdcExchangeField *pExchange, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Լ��Ӧ
	virtual void OnRspQryInstrument(CSecurityFtdcInstrumentField *pInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ������Ӧ
	virtual void OnRspQryInvestor(CSecurityFtdcInvestorField *pInvestor, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ���ױ�����Ӧ
	virtual void OnRspQryTradingCode(CSecurityFtdcTradingCodeField *pTradingCode, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�ʽ��˻���Ӧ
	virtual void OnRspQryTradingAccount(CSecurityFtdcTradingAccountField *pTradingAccount, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯծȯ��Ϣ��Ӧ
	virtual void OnRspQryBondInterest(CSecurityFtdcBondInterestField *pBondInterest, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��ֵ������Ϣ��Ӧ
	virtual void OnRspQryMarketRationInfo(CSecurityFtdcMarketRationInfoField *pMarketRationInfo, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Լ����������Ӧ
	virtual void OnRspQryInstrumentCommissionRate(CSecurityFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯETF��Լ��Ӧ
	virtual void OnRspQryETFInstrument(CSecurityFtdcETFInstrumentField *pETFInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯETF��Ʊ����Ӧ
	virtual void OnRspQryETFBasket(CSecurityFtdcETFBasketField *pETFBasket, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯOF��Լ��Ӧ
	virtual void OnRspQryOFInstrument(CSecurityFtdcOFInstrumentField *pOFInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯSF��Լ��Ӧ
	virtual void OnRspQrySFInstrument(CSecurityFtdcSFInstrumentField *pSFInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Լ���ֱ�֤����Ӧ
	virtual void OnRspQryInstrumentUnitMargin(CSecurityFtdcInstrumentUnitMarginField *pInstrumentUnitMargin, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯԤ������Ϣ��Ӧ
	virtual void OnRspQryPreDelivInfo(CSecurityFtdcPreDelivInfoField *pPreDelivInfo, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ����ȯ������Ϣ��Ӧ
	virtual void OnRspQryCreditStockAssignInfo(CSecurityFtdcCreditStockAssignInfoField *pCreditStockAssignInfo, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�����ʷ�����Ϣ��Ӧ
	virtual void OnRspQryCreditCashAssignInfo(CSecurityFtdcCreditCashAssignInfoField *pCreditCashAssignInfo, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ֤ȯ��������Ӧ
	virtual void OnRspQryConversionRate(CSecurityFtdcConversionRateField *pConversionRate, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��ʷ���ø�ծ��Ϣ��Ӧ
	virtual void OnRspQryHisCreditDebtInfo(CSecurityFtdcHisCreditDebtInfoField *pHisCreditDebtInfo, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ���龲̬��Ϣ��Ӧ
	virtual void OnRspQryMarketDataStaticInfo(CSecurityFtdcMarketDataStaticInfoField *pMarketDataStaticInfo, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ���ڻع���Ϣ��Ӧ
	virtual void OnRspQryExpireRepurchInfo(CSecurityFtdcExpireRepurchInfoField *pExpireRepurchInfo, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯծȯ��ѺΪ��׼ȯ������Ӧ
	virtual void OnRspQryBondPledgeRate(CSecurityFtdcBondPledgeRateField *pBondPledgeRate, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯծȯ��Ѻ������չ�ϵ��Ӧ
	virtual void OnRspQryPledgeBond(CSecurityFtdcPledgeBondField *pPledgeBond, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ������Ӧ
	virtual void OnRspQryOrder(CSecurityFtdcOrderField *pOrder, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�ɽ���Ӧ
	virtual void OnRspQryTrade(CSecurityFtdcTradeField *pTrade, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ���ֲ߳���Ӧ
	virtual void OnRspQryInvestorPosition(CSecurityFtdcInvestorPositionField *pInvestorPosition, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ʽ�ת�˲�ѯӦ��
	virtual void OnRspQryFundTransferSerial(CSecurityFtdcFundTransferField *pFundTransfer, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ʽ���ת��ˮ��ѯӦ��
	virtual void OnRspQryFundInterTransferSerial(CSecurityFtdcFundInterTransferSerialField *pFundInterTransferSerial, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	//-------------------------------------------------------------------------------------
	//task������
	//-------------------------------------------------------------------------------------

	void processTask();

	void processFrontConnected(Task task);

	void processFrontDisconnected(Task task);

	void processHeartBeatWarning(Task task);

	void processRspError(Task task);

	void processRspUserLogin(Task task);

	void processRspUserLogout(Task task);

	void processRspFetchAuthRandCode(Task task);

	void processRspQryExchange(Task task);

	void processRspQryInstrument(Task task);

	void processRspQryInvestor(Task task);

	void processRspQryTradingCode(Task task);

	void processRspQryTradingAccount(Task task);

	void processRspQryBondInterest(Task task);

	void processRspQryMarketRationInfo(Task task);

	void processRspQryInstrumentCommissionRate(Task task);

	void processRspQryETFInstrument(Task task);

	void processRspQryETFBasket(Task task);

	void processRspQryOFInstrument(Task task);

	void processRspQrySFInstrument(Task task);

	void processRspQryInstrumentUnitMargin(Task task);

	void processRspQryPreDelivInfo(Task task);

	void processRspQryCreditStockAssignInfo(Task task);

	void processRspQryCreditCashAssignInfo(Task task);

	void processRspQryConversionRate(Task task);

	void processRspQryHisCreditDebtInfo(Task task);

	void processRspQryMarketDataStaticInfo(Task task);

	void processRspQryExpireRepurchInfo(Task task);

	void processRspQryBondPledgeRate(Task task);

	void processRspQryPledgeBond(Task task);

	void processRspQryOrder(Task task);

	void processRspQryTrade(Task task);

	void processRspQryInvestorPosition(Task task);

	void processRspQryFundTransferSerial(Task task);

	void processRspQryFundInterTransferSerial(Task task);

	//-------------------------------------------------------------------------------------
	//data���ص������������ֵ�
	//error���ص������Ĵ����ֵ�
	//id������id
	//last���Ƿ�Ϊ��󷵻�
	//i������
	//-------------------------------------------------------------------------------------

	virtual void onFrontConnected(){};

	virtual void onFrontDisconnected(int i){};

	virtual void onHeartBeatWarning(int i){};

	virtual void onRspError(dict error, int id, bool last) {};

	virtual void onRspUserLogin(dict data, dict error, int id, bool last) {};

	virtual void onRspUserLogout(dict data, dict error, int id, bool last) {};

	virtual void onRspFetchAuthRandCode(dict data, dict error, int id, bool last) {};

	virtual void onRspQryExchange(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInstrument(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInvestor(dict data, dict error, int id, bool last) {};

	virtual void onRspQryTradingCode(dict data, dict error, int id, bool last) {};

	virtual void onRspQryTradingAccount(dict data, dict error, int id, bool last) {};

	virtual void onRspQryBondInterest(dict data, dict error, int id, bool last) {};

	virtual void onRspQryMarketRationInfo(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInstrumentCommissionRate(dict data, dict error, int id, bool last) {};

	virtual void onRspQryETFInstrument(dict data, dict error, int id, bool last) {};

	virtual void onRspQryETFBasket(dict data, dict error, int id, bool last) {};

	virtual void onRspQryOFInstrument(dict data, dict error, int id, bool last) {};

	virtual void onRspQrySFInstrument(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInstrumentUnitMargin(dict data, dict error, int id, bool last) {};

	virtual void onRspQryPreDelivInfo(dict data, dict error, int id, bool last) {};

	virtual void onRspQryCreditStockAssignInfo(dict data, dict error, int id, bool last) {};

	virtual void onRspQryCreditCashAssignInfo(dict data, dict error, int id, bool last) {};

	virtual void onRspQryConversionRate(dict data, dict error, int id, bool last) {};

	virtual void onRspQryHisCreditDebtInfo(dict data, dict error, int id, bool last) {};

	virtual void onRspQryMarketDataStaticInfo(dict data, dict error, int id, bool last) {};

	virtual void onRspQryExpireRepurchInfo(dict data, dict error, int id, bool last) {};

	virtual void onRspQryBondPledgeRate(dict data, dict error, int id, bool last) {};

	virtual void onRspQryPledgeBond(dict data, dict error, int id, bool last) {};

	virtual void onRspQryOrder(dict data, dict error, int id, bool last) {};

	virtual void onRspQryTrade(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInvestorPosition(dict data, dict error, int id, bool last) {};

	virtual void onRspQryFundTransferSerial(dict data, dict error, int id, bool last) {};

	virtual void onRspQryFundInterTransferSerial(dict data, dict error, int id, bool last) {};

	//-------------------------------------------------------------------------------------
	//req:���������������ֵ�
	//-------------------------------------------------------------------------------------

	void createFtdcQueryApi(string pszFlowPath = "");

	void release();

	void init();

	int join();

	int exit();

	string getTradingDay();

	void registerFront(string pszFrontAddress);

	int reqUserLogin(dict req, int nRequestID);

	int reqUserLogout(dict req, int nRequestID);

	int reqFetchAuthRandCode(dict req, int nRequestID);

	int reqQryExchange(dict req, int nRequestID);

	int reqQryInstrument(dict req, int nRequestID);

	int reqQryInvestor(dict req, int nRequestID);

	int reqQryTradingCode(dict req, int nRequestID);

	int reqQryTradingAccount(dict req, int nRequestID);

	int reqQryBondInterest(dict req, int nRequestID);

	int reqQryMarketRationInfo(dict req, int nRequestID);

	int reqQryInstrumentCommissionRate(dict req, int nRequestID);

	int reqQryETFInstrument(dict req, int nRequestID);

	int reqQryETFBasket(dict req, int nRequestID);

	int reqQryOFInstrument(dict req, int nRequestID);

	int reqQrySFInstrument(dict req, int nRequestID);

	int reqQryInstrumentUnitMargin(dict req, int nRequestID);

	int reqQryPreDelivInfo(dict req, int nRequestID);

	int reqQryCreditStockAssignInfo(dict req, int nRequestID);

	int reqQryCreditCashAssignInfo(dict req, int nRequestID);

	int reqQryConversionRate(dict req, int nRequestID);

	int reqQryHisCreditDebtInfo(dict req, int nRequestID);

	int reqQryMarketDataStaticInfo(dict req, int nRequestID);

	int reqQryExpireRepurchInfo(dict req, int nRequestID);

	int reqQryBondPledgeRate(dict req, int nRequestID);

	int reqQryPledgeBond(dict req, int nRequestID);

	int reqQryOrder(dict req, int nRequestID);

	int reqQryTrade(dict req, int nRequestID);

	int reqQryInvestorPosition(dict req, int nRequestID);

	int reqQryFundTransferSerial(dict req, int nRequestID);

	int reqQryFundInterTransferSerial(dict req, int nRequestID);
};
