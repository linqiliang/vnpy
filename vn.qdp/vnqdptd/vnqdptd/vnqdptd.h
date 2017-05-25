//˵������
/*
����CTP API�к��ʽ�ת����صĺ���̫�࣬
ͬʱҲ�Ѿ��д����Ŀͻ���֧����Щ���ܣ�
��������Python��װ����ʱѡ��ֻ֧�ֽ��׹���
*/


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
#include "QdpFtdcTraderApi.h"

//�����ռ�
using namespace std;
using namespace boost::python;
using namespace boost;

//����
#define ONFRONTCONNECTED 1
#define ONFRONTDISCONNECTED 2
#define ONHEARTBEATWARNING 3
#define ONPACKAGESTART 4
#define ONPACKAGEEND 5
#define ONRSPERROR 6
#define ONRSPUSERLOGIN 7
#define ONRSPUSERLOGOUT 8
#define ONRSPUSERPASSWORDUPDATE 9
#define ONRSPORDERINSERT 10
#define ONRSPORDERACTION 11
#define ONRSPFROMBANKTOFUTUREBYFUTURE 12
#define ONRSPFROMFUTURETOBANKBYFUTURE 13
#define ONRTNFLOWMESSAGECANCEL 14
#define ONRTNTRADE 15
#define ONRTNORDER 16
#define ONERRRTNORDERINSERT 17
#define ONERRRTNORDERACTION 18
#define ONRTNINSTRUMENTSTATUS 19
#define ONRTNINVESTORACCOUNTDEPOSIT 20
#define ONRTNMESSAGENOTIFY 21
#define ONERRRTNQUERYBANKBALANCEBYFUTURE 22
#define ONERRRTNBANKTOFUTUREBYFUTURE 23
#define ONERRRTNFUTURETOBANKBYFUTURE 24
#define ONRTNQUERYBANKBALANCEBYFUTURE 25
#define ONRTNFROMBANKTOFUTUREBYFUTURE 26
#define ONRTNFROMFUTURETOBANKBYFUTURE 27
#define ONRTNSGEDEFERRATE 28
#define ONRSPQRYORDER 29
#define ONRSPQRYTRADE 30
#define ONRSPQRYUSERINVESTOR 31
#define ONRSPQRYINVESTORACCOUNT 32
#define ONRSPQRYINSTRUMENT 33
#define ONRSPQRYEXCHANGE 34
#define ONRSPQRYINVESTORPOSITION 35
#define ONRSPSUBSCRIBETOPIC 36
#define ONRSPQRYTOPIC 37
#define ONRSPQRYINVESTORFEE 38
#define ONRSPQRYINVESTORMARGIN 39
#define ONRSPQRYEXCHANGEDIFFTIME 40
#define ONRSPQRYCONTRACTBANK 41
#define ONRSPQUERYBANKACCOUNTMONEYBYFUTURE 42
#define ONRSPQRYTRANSFERSERIAL 43
#define ONRSPQRYSGEDEFERRATE 44
#define ONRSPQRYMARKETDATA 45


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

	int additional_int;	//�����Ͳ����ֶ�
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


//���ֵ��л�ȡĳ����ֵ��Ӧ���ַ�������ֵ������ṹ������ֵ��
void getChar(dict d, string key, char* value);


//���ֵ��л�ȡĳ����ֵ��Ӧ���ַ���������ֵ������ṹ������ֵ��
void getStr(dict d, string key, char* value);


///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class TdApi : public CQdpFtdcTraderSpi
{
private:
	CQdpFtdcTraderApi* api;			//API����
	thread *task_thread;				//�����߳�ָ�루��python���������ݣ�
	ConcurrentQueue<Task> task_queue;	//�������

public:
	TdApi()
	{
		function0<void> f = boost::bind(&TdApi::processTask, this);
		thread t(f);
		this->task_thread = &t;
	};

	~TdApi()
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

	///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
	///@param nTopicID ������루��˽���������������������ȣ�
	///@param nSequenceNo �������
	virtual void OnPackageStart(int nTopicID, int nSequenceNo);

	///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
	///@param nTopicID ������루��˽���������������������ȣ�
	///@param nSequenceNo �������
	virtual void OnPackageEnd(int nTopicID, int nSequenceNo);


	///����Ӧ��
	virtual void OnRspError(CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�û���¼Ӧ��
	virtual void OnRspUserLogin(CQdpFtdcRspUserLoginField *pRspUserLogin, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�û��˳�Ӧ��
	virtual void OnRspUserLogout(CQdpFtdcRspUserLogoutField *pRspUserLogout, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�û������޸�Ӧ��
	virtual void OnRspUserPasswordUpdate(CQdpFtdcUserPasswordUpdateField *pUserPasswordUpdate, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///����¼��Ӧ��
	virtual void OnRspOrderInsert(CQdpFtdcInputOrderField *pInputOrder, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��������Ӧ��
	virtual void OnRspOrderAction(CQdpFtdcOrderActionField *pOrderAction, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�ڻ����������ʽ�ת�ڻ�Ӧ��
	virtual void OnRspFromBankToFutureByFuture(CQdpFtdcReqTransferField *pReqTransfer, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�ڻ������ڻ��ʽ�ת����Ӧ��
	virtual void OnRspFromFutureToBankByFuture(CQdpFtdcReqTransferField *pReqTransfer, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///����������֪ͨ
	virtual void OnRtnFlowMessageCancel(CQdpFtdcFlowMessageCancelField *pFlowMessageCancel) ;

	///�ɽ��ر�
	virtual void OnRtnTrade(CQdpFtdcTradeField *pTrade) ;

	///�����ر�
	virtual void OnRtnOrder(CQdpFtdcOrderField *pOrder) ;

	///����¼�����ر�
	virtual void OnErrRtnOrderInsert(CQdpFtdcInputOrderField *pInputOrder, CQdpFtdcRspInfoField *pRspInfo) ;

	///������������ر�
	virtual void OnErrRtnOrderAction(CQdpFtdcOrderActionField *pOrderAction, CQdpFtdcRspInfoField *pRspInfo) ;

	///��Լ����״̬֪ͨ
	virtual void OnRtnInstrumentStatus(CQdpFtdcInstrumentStatusField *pInstrumentStatus) ;

	///�˻������ر�
	virtual void OnRtnInvestorAccountDeposit(CQdpFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes) ;

	///QDP������Ϣ֪ͨ
	virtual void OnRtnMessageNotify(CQdpFtdcMessageNotifyInfoField *pMessageNotifyInfo) ;

	///�ڻ������ѯ����������ر�
	virtual void OnErrRtnQueryBankBalanceByFuture(CQdpFtdcReqQueryAccountField *pReqQueryAccount, CQdpFtdcRspInfoField *pRspInfo) ;

	///�ڻ����������ʽ�ת�ڻ�����ر�
	virtual void OnErrRtnBankToFutureByFuture(CQdpFtdcReqTransferField *pReqTransfer, CQdpFtdcRspInfoField *pRspInfo) ;

	///�ڻ������ڻ��ʽ�ת���д���ر�
	virtual void OnErrRtnFutureToBankByFuture(CQdpFtdcReqTransferField *pReqTransfer, CQdpFtdcRspInfoField *pRspInfo) ;

	///�ڻ������ѯ�������֪ͨ
	virtual void OnRtnQueryBankBalanceByFuture(CQdpFtdcNotifyQueryAccountField *pNotifyQueryAccount) ;

	///�ڻ����������ʽ�ת�ڻ�֪ͨ
	virtual void OnRtnFromBankToFutureByFuture(CQdpFtdcRspTransferField *pRspTransfer) ;

	///�ڻ������ڻ��ʽ�ת����֪ͨ
	virtual void OnRtnFromFutureToBankByFuture(CQdpFtdcRspTransferField *pRspTransfer) ;

	///�������ӷ���֪ͨ
	virtual void OnRtnSGEDeferRate(CQdpFtdcSGEDeferRateField *pSGEDeferRate) ;

	///������ѯӦ��
	virtual void OnRspQryOrder(CQdpFtdcOrderField *pOrder, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�ɽ�����ѯӦ��
	virtual void OnRspQryTrade(CQdpFtdcTradeField *pTrade, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///����Ͷ�����˻���ѯӦ��
	virtual void OnRspQryUserInvestor(CQdpFtdcRspUserInvestorField *pRspUserInvestor, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///Ͷ�����ʽ��˻���ѯӦ��
	virtual void OnRspQryInvestorAccount(CQdpFtdcRspInvestorAccountField *pRspInvestorAccount, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��Լ��ѯӦ��
	virtual void OnRspQryInstrument(CQdpFtdcRspInstrumentField *pRspInstrument, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��������ѯӦ��
	virtual void OnRspQryExchange(CQdpFtdcRspExchangeField *pRspExchange, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///Ͷ���ֲֲ߳�ѯӦ��
	virtual void OnRspQryInvestorPosition(CQdpFtdcRspInvestorPositionField *pRspInvestorPosition, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��������Ӧ��
	virtual void OnRspSubscribeTopic(CQdpFtdcDisseminationField *pDissemination, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�����ѯӦ��
	virtual void OnRspQryTopic(CQdpFtdcDisseminationField *pDissemination, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///Ͷ�����������ʲ�ѯӦ��
	virtual void OnRspQryInvestorFee(CQdpFtdcInvestorFeeField *pInvestorFee, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///Ͷ���߱�֤���ʲ�ѯӦ��
	virtual void OnRspQryInvestorMargin(CQdpFtdcInvestorMarginField *pInvestorMargin, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///������ʱ��ƫ���ѯӦ��
	virtual void OnRspQryExchangeDiffTime(CQdpFtdcRspExchangeDiffTimeField *pRspExchangeDiffTime, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��ѯǩԼ����Ӧ��
	virtual void OnRspQryContractBank(CQdpFtdcContractBankField *pContractBank, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�ڻ������ѯ�������Ӧ��
	virtual void OnRspQueryBankAccountMoneyByFuture(CQdpFtdcReqQueryAccountField *pReqQueryAccount, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��ѯת����ˮӦ��
	virtual void OnRspQryTransferSerial(CQdpFtdcTransferSerialField *pTransferSerial, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�������ӷ��ʲ�ѯӦ��
	virtual void OnRspQrySGEDeferRate(CQdpFtdcSGEDeferRateField *pSGEDeferRate, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///ʵʱ�����ѯӦ��
	virtual void OnRspQryMarketData(CQdpFtdcMarketDataField *pMarketData, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	//-------------------------------------------------------------------------------------
	//task������
	//-------------------------------------------------------------------------------------

	void processTask();

	void processFrontConnected(Task task);

	void processFrontDisconnected(Task task);

	void processHeartBeatWarning(Task task);

	void processPackageStart(Task task);

	void processPackageEnd(Task task);

	void processRspError(Task task);

	void processRspUserLogin(Task task);

	void processRspUserLogout(Task task);

	void processRspUserPasswordUpdate(Task task);

	void processRspOrderInsert(Task task);

	void processRspOrderAction(Task task);

	void processRspFromBankToFutureByFuture(Task task);

	void processRspFromFutureToBankByFuture(Task task);

	void processRtnFlowMessageCancel(Task task);

	void processRtnTrade(Task task);

	void processRtnOrder(Task task);

	void processErrRtnOrderInsert(Task task);

	void processErrRtnOrderAction(Task task);

	void processRtnInstrumentStatus(Task task);

	void processRtnInvestorAccountDeposit(Task task);

	void processRtnMessageNotify(Task task);

	void processErrRtnQueryBankBalanceByFuture(Task task);

	void processErrRtnBankToFutureByFuture(Task task);

	void processErrRtnFutureToBankByFuture(Task task);

	void processRtnQueryBankBalanceByFuture(Task task);

	void processRtnFromBankToFutureByFuture(Task task);

	void processRtnFromFutureToBankByFuture(Task task);

	void processRtnSGEDeferRate(Task task);

	void processRspQryOrder(Task task);

	void processRspQryTrade(Task task);

	void processRspQryUserInvestor(Task task);

	void processRspQryInvestorAccount(Task task);

	void processRspQryInstrument(Task task);

	void processRspQryExchange(Task task);

	void processRspQryInvestorPosition(Task task);

	void processRspSubscribeTopic(Task task);

	void processRspQryTopic(Task task);

	void processRspQryInvestorFee(Task task);

	void processRspQryInvestorMargin(Task task);

	void processRspQryExchangeDiffTime(Task task);

	void processRspQryContractBank(Task task);

	void processRspQueryBankAccountMoneyByFuture(Task task);

	void processRspQryTransferSerial(Task task);

	void processRspQrySGEDeferRate(Task task);

	void processRspQryMarketData(Task task);

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

	virtual void onPackageStart(int topicID, int sequenceNo){};

	virtual void onPackageEnd(int topicID, int sequenceNo){};

	virtual void onRspError(dict error, int id, bool last) {};

	virtual void onRspUserLogin(dict data, dict error, int id, bool last) {};

	virtual void onRspUserLogout(dict data, dict error, int id, bool last) {};

	virtual void onRspUserPasswordUpdate(dict data, dict error, int id, bool last) {};

	virtual void onRspOrderInsert(dict data, dict error, int id, bool last) {};

	virtual void onRspOrderAction(dict data, dict error, int id, bool last) {};

	virtual void onRspFromBankToFutureByFuture(dict data, dict error, int id, bool last) {};

	virtual void onRspFromFutureToBankByFuture(dict data, dict error, int id, bool last) {};

	virtual void onRtnFlowMessageCancel(dict data) {};

	virtual void onRtnTrade(dict data) {};

	virtual void onRtnOrder(dict data) {};

	virtual void onErrRtnOrderInsert(dict data, dict error) {};

	virtual void onErrRtnOrderAction(dict data, dict error) {};

	virtual void onRtnInstrumentStatus(dict data) {};

	virtual void onRtnInvestorAccountDeposit(dict data) {};

	virtual void onRtnMessageNotify(dict data) {};

	virtual void onErrRtnQueryBankBalanceByFuture(dict data, dict error) {};

	virtual void onErrRtnBankToFutureByFuture(dict data, dict error) {};

	virtual void onErrRtnFutureToBankByFuture(dict data, dict error) {};

	virtual void onRtnQueryBankBalanceByFuture(dict data) {};

	virtual void onRtnFromBankToFutureByFuture(dict data) {};

	virtual void onRtnFromFutureToBankByFuture(dict data) {};

	virtual void onRtnSGEDeferRate(dict data) {};

	virtual void onRspQryOrder(dict data, dict error, int id, bool last) {};

	virtual void onRspQryTrade(dict data, dict error, int id, bool last) {};

	virtual void onRspQryUserInvestor(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInvestorAccount(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInstrument(dict data, dict error, int id, bool last) {};

	virtual void onRspQryExchange(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInvestorPosition(dict data, dict error, int id, bool last) {};

	virtual void onRspSubscribeTopic(dict data, dict error, int id, bool last) {};

	virtual void onRspQryTopic(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInvestorFee(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInvestorMargin(dict data, dict error, int id, bool last) {};

	virtual void onRspQryExchangeDiffTime(dict data, dict error, int id, bool last) {};

	virtual void onRspQryContractBank(dict data, dict error, int id, bool last) {};

	virtual void onRspQueryBankAccountMoneyByFuture(dict data, dict error, int id, bool last) {};

	virtual void onRspQryTransferSerial(dict data, dict error, int id, bool last) {};

	virtual void onRspQrySGEDeferRate(dict data, dict error, int id, bool last) {};

	virtual void onRspQryMarketData(dict data, dict error, int id, bool last) {};

	//-------------------------------------------------------------------------------------
	//req:���������������ֵ�
	//-------------------------------------------------------------------------------------

	void createFtdcTraderApi(string pszFlowPath = "");

	string getVersion(int major, int minor);

	void release();

	void init();

	int join();

	int exit();

	string getTradingDay();

	void registerFront(string pszFrontAddress);

	void registerNameServer(string pszNsAddress);

	void subscribePrivateTopic(int nType);

	void subscribePublicTopic(int nType);

	void setHeartbeatTimeout(int timeout);

	int openRequestLog(string fileName);

	int openResponseLog(string fileName);

	int reqUserLogin(dict req, int nRequestID);

	int reqUserLogout(dict req, int nRequestID);

	int reqUserPasswordUpdate(dict req, int nRequestID);

	int reqOrderInsert(dict req, int nRequestID);

	int reqOrderAction(dict req, int nRequestID);

	int reqFromBankToFutureByFuture(dict req, int nRequestID);

	int reqFromFutureToBankByFuture(dict req, int nRequestID);

	int reqQryOrder(dict req, int nRequestID);

	int reqQryTrade(dict req, int nRequestID);

	int reqQryUserInvestor(dict req, int nRequestID);

	int reqQryInvestorAccount(dict req, int nRequestID);

	int reqQryInstrument(dict req, int nRequestID);

	int reqQryExchange(dict req, int nRequestID);

	int reqQryInvestorPosition(dict req, int nRequestID);

	int reqSubscribeTopic(dict req, int nRequestID);

	int reqQryTopic(dict req, int nRequestID);

	int reqQryInvestorFee(dict req, int nRequestID);

	int reqQryInvestorMargin(dict req, int nRequestID);

	int reqQryExchangeDiffTime(dict req, int nRequestID);

	int reqQryContractBank(dict req, int nRequestID);

	int reqQueryBankAccountMoneyByFuture(dict req, int nRequestID);

	int reqQryTransferSerial(dict req, int nRequestID);

	int reqQrySGEDeferRate(dict req, int nRequestID);

	int reqQryMarketData(dict req, int nRequestID);
};

