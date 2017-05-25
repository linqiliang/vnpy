//˵������

//ϵͳ
#include "stdafx.h"
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
#include "KSOTPTraderApi.h"

//�����ռ�
using namespace std;
using namespace boost::python;
using namespace boost;
using namespace KingstarAPI;

//����
#define ONFRONTCONNECTED 1
#define ONFRONTDISCONNECTED 2
#define ONRSPUSERLOGIN 3
#define ONRSPUSERLOGOUT 4
#define ONRSPUSERPASSWORDUPDATE 5
#define ONRSPTRADINGACCOUNTPASSWORDUPDATE 6
#define ONRSPORDERINSERT 7
#define ONRSPORDERACTION 8
#define ONRSPQRYORDER 9
#define ONRSPQRYTRADE 10
#define ONRSPQRYINVESTORPOSITION 11
#define ONRSPQRYTRADINGACCOUNT 12
#define ONRSPQRYINVESTOR 13
#define ONRSPQRYTRADINGCODE 14
#define ONRSPQRYEXCHANGE 15
#define ONRSPQRYINSTRUMENT 16
#define ONRSPQRYINVESTORPOSITIONDETAIL 17
#define ONRSPQRYTRADINGNOTICE 18
#define ONRSPEXECORDERINSERT 19
#define ONRSPLOCKINSERT 20
#define ONRSPEXECORDERACTION 21
#define ONRSPQRYEXECORDER 22
#define ONRSPQRYEXECORDERVOLUME 23
#define ONRSPQRYLOCK 24
#define ONRSPQRYLOCKPOSITION 25
#define ONRSPQRYUNDERLYINGSTOCKINFO 26
#define ONRSPQRYOTPINSCOMMRATE 27
#define ONRSPQRYINSTRUMENTMARGINRATE 28
#define ONRSPQRYOTPASSIGNMENT 29
#define ONRSPQRYDEPTHMARKETDATA 30
#define ONRSPFROMBANKTOSTOCKBYSTOCK 31
#define ONRTNFROMBANKTOSTOCKBYSTOCK 32
#define ONRSPFROMSTOCKTOBANKBYSTOCK 33
#define ONRTNFROMSTOCKTOBANKBYSTOCK 34
#define ONRTNQUERYBANKBALANCEBYSTOCK 35
#define ONRSPQRYCONTRACTBANK 36
#define ONRSPQUERYBANKACCOUNTMONEYBYSTOCK 37
#define ONRSPQRYTRANSFERSERIAL 38
#define ONRSPQRYSETTLEMENTINFOCONFIRM 39
#define ONRSPSETTLEMENTINFOCONFIRM 40
#define ONRSPQRYSETTLEMENTINFO 41
#define ONRSPQRYINVESTORTRADELEVEL 42
#define ONRSPQRYPURCHASELIMITAMT 43
#define ONRSPQRYPOSITIONLIMITVOL 44
#define ONRSPQRYHISTORYORDER 45
#define ONRSPQRYHISTORYTRADE 46
#define ONRSPQRYHISTORYASSIGNMENT 47
#define ONRSPQRYDELIVDETAIL 48
#define ONRSPAUTOEXECORDERACTION 49
#define ONRSPCOMBACTIONINSERT 50
#define ONRSPQRYINVESTORCOMBINEPOSITION 51
#define ONRSPQRYCOMBACTIONVOLUME 52
#define ONRSPFUNDOUTCREDITAPPLY 53
#define ONRSPQRYFUNDOUTCREDIT 54
#define ONRSPQRYFUNDOUTCREDITAPPLY 55
#define ONRSPERROR 56
#define ONRTNORDER 57
#define ONRTNTRADE 58
#define ONRTNEXECORDER 59
#define ONRTNLOCK 60
#define ONRTNINSTRUMENTSTATUS 61
#define ONRTNTRADINGNOTICE 62
#define ONRTNCOMBACTION 63


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
class TdApi : public CKSOTPTraderSpi
{
private:
	CKSOTPTraderApi* api;			//API����
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

	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷���������.
	virtual void OnFrontConnected();

	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷���������.
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	///        0x2004 �����������Ͽ�
	virtual void OnFrontDisconnected(int nReason);

	///��¼������Ӧ
	virtual void OnRspUserLogin(CKSOTPRspUserLoginField *pRspUserLogin, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CKSOTPUserLogoutField *pUserLogout, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�û��������������Ӧ
	virtual void OnRspUserPasswordUpdate(CKSOTPUserPasswordUpdateField *pUserPasswordUpdate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ʽ��˻��������������Ӧ
	virtual void OnRspTradingAccountPasswordUpdate(CKSOTPTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����¼��������Ӧ
	virtual void OnRspOrderInsert(CKSOTPInputOrderField *pInputOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��������������Ӧ
	virtual void OnRspOrderAction(CKSOTPInputOrderActionField *pInputOrderAction, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ������Ӧ
	virtual void OnRspQryOrder(CKSOTPOrderField *pOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�ɽ���Ӧ
	virtual void OnRspQryTrade(CKSOTPTradeField *pTrade, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ���ֲ߳���Ӧ
	virtual void OnRspQryInvestorPosition(CKSOTPInvestorPositionField *pInvestorPosition, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�ʽ��˻���Ӧ
	virtual void OnRspQryTradingAccount(CKSOTPTradingAccountField *pTradingAccount, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ������Ӧ
	virtual void OnRspQryInvestor(CKSOTPInvestorField *pInvestor, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Լ�˺���Ӧ
	virtual void OnRspQryTradingCode(CKSOTPTradingCodeField *pTradingCode, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��������Ӧ
	virtual void OnRspQryExchange(CKSOTPExchangeField *pExchange, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Լ��Ӧ
	virtual void OnRspQryInstrument(CKSOTPInstrumentField *pInstrument, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ���ֲ߳���ϸ��Ӧ
	virtual void OnRspQryInvestorPositionDetail(CKSOTPInvestorPositionDetailField *pInvestorPositionDetail, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ����֪ͨ��Ӧ
	virtual void OnRspQryTradingNotice(CKSOTPTradingNoticeField *pTradingNotice, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///ִ������¼��������Ӧ
	virtual void OnRspExecOrderInsert(CKSOTPInputExecOrderField *pInputExecOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����Ӧ��
	virtual void OnRspLockInsert(CKSOTPInputLockField *pInputLock, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///ִ���������������Ӧ
	virtual void OnRspExecOrderAction(CKSOTPInputExecOrderActionField *pInputExecOrderAction, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯִ��������Ӧ
	virtual void OnRspQryExecOrder(CKSOTPExecOrderField *pExecOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ѯ��������������Ӧ
	virtual void OnRspQryExecOrderVolume(CKSOTPExecOrderVolumeField *pExecOrderVolume, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ����Ӧ��
	virtual void OnRspQryLock(CKSOTPLockField *pLock, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ����֤ȯ��λӦ��
	virtual void OnRspQryLockPosition(CKSOTPLockPositionField *pLockPosition, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ���ȯ��Ϣ��Ӧ
	virtual void OnRspQryUnderlyingStockInfo(CKSOTPUnderlyingStockInfoField *pUnderlyingStockInfo, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ѯ������Ȩ��������������Ӧ
	virtual void OnRspQryOTPInsCommRate(CKSOTPOTPInsCommRateField *pOTPInsCommRate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ѯ������Ȩ��Լ��֤����������Ӧ
	virtual void OnRspQryInstrumentMarginRate(CKSOTPInstrumentMarginRateField *pInstrumentMarginRate, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ѯ������Ȩָ����Ϣ������Ӧ
	virtual void OnRspQryOTPAssignment(CKSOTPOTPAssignmentField *pOTPAssignment, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ������Ӧ
	virtual void OnRspQryDepthMarketData(CKSOTPDepthMarketDataField *pDepthMarketData, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///���������ʽ�ת֤ȯӦ��
	virtual void OnRspFromBankToStockByStock(CKSOTPReqTransferField *pReqTransfer, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///֤ȯ���������ʽ�ת֤ȯ֪ͨ
	virtual void OnRtnFromBankToStockByStock(CKSOTPRspTransferField *pRspTransfer);

	///֤ȯ����֤ȯ�ʽ�ת����Ӧ��
	virtual void OnRspFromStockToBankByStock(CKSOTPReqTransferField *pReqTransfer, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///֤ȯ����֤ȯ�ʽ�ת����֪ͨ
	virtual void OnRtnFromStockToBankByStock(CKSOTPRspTransferField *pRspTransfer);

	///֤ȯ�����ѯ�������֪ͨ
	virtual void OnRtnQueryBankBalanceByStock(CKSOTPNotifyQueryAccountField *pNotifyQueryAccount);

	///�����ѯǩԼ������Ӧ
	virtual void OnRspQryContractBank(CKSOTPContractBankField *pContractBank, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///֤ȯ�����ѯ�������Ӧ��
	virtual void OnRspQueryBankAccountMoneyByStock(CKSOTPReqQueryAccountField *pReqQueryAccount, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯת����ˮ��Ӧ
	virtual void OnRspQryTransferSerial(CKSOTPTransferSerialField *pTransferSerial, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ������Ϣȷ����Ӧ
	virtual void OnRspQrySettlementInfoConfirm(CKSOTPSettlementInfoConfirmField *pSettlementInfoConfirm, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///Ͷ���߽�����ȷ����Ӧ
	virtual void OnRspSettlementInfoConfirm(CKSOTPSettlementInfoConfirmField *pSettlementInfoConfirm, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ���߽�������Ӧ
	virtual void OnRspQrySettlementInfo(CKSOTPSettlementInfoField *pSettlementInfo, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ѯ�ͻ����׼�����Ӧ
	virtual void OnRspQryInvestorTradeLevel(CKSOTPInvestorTradeLevelField *pInvestorTradeLevel, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ѯ�����޹������Ӧ
	virtual void OnRspQryPurchaseLimitAmt(CKSOTPPurchaseLimitAmtField *pPurchaseLimitAmt, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ѯ�����޲ֶ����Ӧ
	virtual void OnRspQryPositionLimitVol(CKSOTPPositionLimitVolField *pPositionLimitVol, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��ʷ������Ӧ
	virtual void OnRspQryHistoryOrder(CKSOTPHistoryOrderField *pHistoryOrder, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��ʷ�ɽ���Ӧ
	virtual void OnRspQryHistoryTrade(CKSOTPHistoryTradeField *pHistoryTrade, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��ʷ��Ȩָ����ϸ��Ӧ
	virtual void OnRspQryHistoryAssignment(CKSOTPHistoryAssignmentField *pHistoryAssignment, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ��Ȩ������ϸ��Ӧ
	virtual void OnRspQryDelivDetail(CKSOTPDelivDetailField *pDelivDetail, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�Զ���Ȩִ�в�����Ӧ
	virtual void OnRspAutoExecOrderAction(CKSOTPAutoExecOrderActionField *pAutoExecOrderAction, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�������¼��������Ӧ
	virtual void OnRspCombActionInsert(CKSOTPInputCombActionField *pInputCombAction, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��ѯ������ϳֲ���ϸӦ��
	virtual void OnRspQryInvestorCombinePosition(CKSOTPInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///���ɿ���Ͽɲ������������Ӧ
	virtual void OnRspQryCombActionVolume(CKSOTPCombActionVolumeField *pCombActionVolume, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ͻ�ÿ�ճ�����������Ӧ
	virtual void OnRspFundOutCreditApply(CKSOTPInputFundOutCreditApplyField *pFundOutCreditApply, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ͻ�ÿ�ճ����Ȳ�ѯ��Ӧ
	virtual void OnRspQryFundOutCredit(CKSOTPRspQryFundOutCreditField *pRspQryFundOutCredit, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ͻ�ÿ�ճ����������ѯ��Ӧ
	virtual void OnRspQryFundOutCreditApply(CKSOTPRspQryFundOutCreditApplyField *pRspQryFundOutCreditApply, CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����Ӧ��
	virtual void OnRspError(CKSOTPRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����֪ͨ
	virtual void OnRtnOrder(CKSOTPOrderField *pOrder);

	///�ɽ�֪ͨ
	virtual void OnRtnTrade(CKSOTPTradeField *pTrade);

	///ִ������֪ͨ
	virtual void OnRtnExecOrder(CKSOTPExecOrderField *pExecOrder);

	///����֪ͨ
	virtual void OnRtnLock(CKSOTPLockField *pLock);

	///��Լ����״̬֪ͨ
	virtual void OnRtnInstrumentStatus(CKSOTPInstrumentStatusField *pInstrumentStatus);

	///����֪ͨ
	virtual void OnRtnTradingNotice(CKSOTPTradingNoticeInfoField *pTradingNoticeInfo);

	///������ϲ��ί��֪ͨ
	virtual void OnRtnCombAction(CKSOTPCombActionField *pCombAction);

	//-------------------------------------------------------------------------------------
	//task������
	//-------------------------------------------------------------------------------------

	void processTask();

	void processFrontConnected(Task task);

	void processFrontDisconnected(Task task);

	void processRspUserLogin(Task task);

	void processRspUserLogout(Task task);

	void processRspUserPasswordUpdate(Task task);

	void processRspTradingAccountPasswordUpdate(Task task);

	void processRspOrderInsert(Task task);

	void processRspOrderAction(Task task);

	void processRspQryOrder(Task task);

	void processRspQryTrade(Task task);

	void processRspQryInvestorPosition(Task task);

	void processRspQryTradingAccount(Task task);

	void processRspQryInvestor(Task task);

	void processRspQryTradingCode(Task task);

	void processRspQryExchange(Task task);

	void processRspQryInstrument(Task task);

	void processRspQryInvestorPositionDetail(Task task);

	void processRspQryTradingNotice(Task task);

	void processRspExecOrderInsert(Task task);

	void processRspLockInsert(Task task);

	void processRspExecOrderAction(Task task);

	void processRspQryExecOrder(Task task);

	void processRspQryExecOrderVolume(Task task);

	void processRspQryLock(Task task);

	void processRspQryLockPosition(Task task);

	void processRspQryUnderlyingStockInfo(Task task);

	void processRspQryOTPInsCommRate(Task task);

	void processRspQryInstrumentMarginRate(Task task);

	void processRspQryOTPAssignment(Task task);

	void processRspQryDepthMarketData(Task task);

	void processRspFromBankToStockByStock(Task task);

	void processRtnFromBankToStockByStock(Task task);

	void processRspFromStockToBankByStock(Task task);

	void processRtnFromStockToBankByStock(Task task);

	void processRtnQueryBankBalanceByStock(Task task);

	void processRspQryContractBank(Task task);

	void processRspQueryBankAccountMoneyByStock(Task task);

	void processRspQryTransferSerial(Task task);

	void processRspQrySettlementInfoConfirm(Task task);

	void processRspSettlementInfoConfirm(Task task);

	void processRspQrySettlementInfo(Task task);

	void processRspQryInvestorTradeLevel(Task task);

	void processRspQryPurchaseLimitAmt(Task task);

	void processRspQryPositionLimitVol(Task task);

	void processRspQryHistoryOrder(Task task);

	void processRspQryHistoryTrade(Task task);

	void processRspQryHistoryAssignment(Task task);

	void processRspQryDelivDetail(Task task);

	void processRspAutoExecOrderAction(Task task);

	void processRspCombActionInsert(Task task);

	void processRspQryInvestorCombinePosition(Task task);

	void processRspQryCombActionVolume(Task task);

	void processRspFundOutCreditApply(Task task);

	void processRspQryFundOutCredit(Task task);

	void processRspQryFundOutCreditApply(Task task);

	void processRspError(Task task);

	void processRtnOrder(Task task);

	void processRtnTrade(Task task);

	void processRtnExecOrder(Task task);

	void processRtnLock(Task task);

	void processRtnInstrumentStatus(Task task);

	void processRtnTradingNotice(Task task);

	void processRtnCombAction(Task task);

	//-------------------------------------------------------------------------------------
	//data���ص������������ֵ�
	//error���ص������Ĵ����ֵ�
	//id������id
	//last���Ƿ�Ϊ��󷵻�
	//i������
	//-------------------------------------------------------------------------------------

	virtual void onFrontConnected(){};

	virtual void onFrontDisconnected(int i){};

	virtual void onRspError(dict error, int id, bool last) {};

	virtual void onRspUserLogin(dict data, dict error, int id, bool last) {};

	virtual void onRspUserLogout(dict data, dict error, int id, bool last) {};

	virtual void onRspUserPasswordUpdate(dict data, dict error, int id, bool last) {};

	virtual void onRspTradingAccountPasswordUpdate(dict data, dict error, int id, bool last) {};

	virtual void onRspOrderInsert(dict data, dict error, int id, bool last) {};

	virtual void onRspOrderAction(dict data, dict error, int id, bool last) {};

	virtual void onRspQryOrder(dict data, dict error, int id, bool last) {};

	virtual void onRspQryTrade(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInvestorPosition(dict data, dict error, int id, bool last) {};

	virtual void onRspQryTradingAccount(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInvestor(dict data, dict error, int id, bool last) {};

	virtual void onRspQryTradingCode(dict data, dict error, int id, bool last) {};

	virtual void onRspQryExchange(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInstrument(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInvestorPositionDetail(dict data, dict error, int id, bool last) {};

	virtual void onRspQryTradingNotice(dict data, dict error, int id, bool last) {};

	virtual void onRspExecOrderInsert(dict data, dict error, int id, bool last) {};

	virtual void onRspLockInsert(dict data, dict error, int id, bool last) {};

	virtual void onRspExecOrderAction(dict data, dict error, int id, bool last) {};

	virtual void onRspQryExecOrder(dict data, dict error, int id, bool last) {};

	virtual void onRspQryExecOrderVolume(dict data, dict error, int id, bool last) {};

	virtual void onRspQryLock(dict data, dict error, int id, bool last) {};

	virtual void onRspQryLockPosition(dict data, dict error, int id, bool last) {};

	virtual void onRspQryUnderlyingStockInfo(dict data, dict error, int id, bool last) {};

	virtual void onRspQryOTPInsCommRate(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInstrumentMarginRate(dict data, dict error, int id, bool last) {};

	virtual void onRspQryOTPAssignment(dict data, dict error, int id, bool last) {};

	virtual void onRspQryDepthMarketData(dict data, dict error, int id, bool last) {};

	virtual void onRspFromBankToStockByStock(dict data, dict error, int id, bool last) {};

	virtual void onRtnFromBankToStockByStock(dict data) {};

	virtual void onRspFromStockToBankByStock(dict data, dict error, int id, bool last) {};

	virtual void onRtnFromStockToBankByStock(dict data) {};

	virtual void onRtnQueryBankBalanceByStock(dict data) {};

	virtual void onRspQryContractBank(dict data, dict error, int id, bool last) {};

	virtual void onRspQueryBankAccountMoneyByStock(dict data, dict error, int id, bool last) {};

	virtual void onRspQryTransferSerial(dict data, dict error, int id, bool last) {};

	virtual void onRspQrySettlementInfoConfirm(dict data, dict error, int id, bool last) {};

	virtual void onRspSettlementInfoConfirm(dict data, dict error, int id, bool last) {};

	virtual void onRspQrySettlementInfo(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInvestorTradeLevel(dict data, dict error, int id, bool last) {};

	virtual void onRspQryPurchaseLimitAmt(dict data, dict error, int id, bool last) {};

	virtual void onRspQryPositionLimitVol(dict data, dict error, int id, bool last) {};

	virtual void onRspQryHistoryOrder(dict data, dict error, int id, bool last) {};

	virtual void onRspQryHistoryTrade(dict data, dict error, int id, bool last) {};

	virtual void onRspQryHistoryAssignment(dict data, dict error, int id, bool last) {};

	virtual void onRspQryDelivDetail(dict data, dict error, int id, bool last) {};

	virtual void onRspAutoExecOrderAction(dict data, dict error, int id, bool last) {};

	virtual void onRspCombActionInsert(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInvestorCombinePosition(dict data, dict error, int id, bool last) {};

	virtual void onRspQryCombActionVolume(dict data, dict error, int id, bool last) {};

	virtual void onRspFundOutCreditApply(dict data, dict error, int id, bool last) {};

	virtual void onRspQryFundOutCredit(dict data, dict error, int id, bool last) {};

	virtual void onRspQryFundOutCreditApply(dict data, dict error, int id, bool last) {};

	virtual void onRtnOrder(dict data) {};

	virtual void onRtnTrade(dict data) {};

	virtual void onRtnExecOrder(dict data) {};

	virtual void onRtnLock(dict data) {};

	virtual void onRtnInstrumentStatus(dict data) {};

	virtual void onRtnTradingNotice(dict data) {};

	virtual void onRtnCombAction(dict data) {};

	//-------------------------------------------------------------------------------------
	//req:���������������ֵ�
	//-------------------------------------------------------------------------------------

	void createOTPTraderApi(string pszFlowPath = "");

	void release();

	void init();

	int exit();

	string getTradingDay();

	void registerFront(string pszFrontAddress);

	void subscribePrivateTopic(int nType);

	void subscribePublicTopic(int nType);

	int reqUserLogin(dict req, int nRequestID);

	int reqUserLogout(dict req, int nRequestID);

	int reqUserPasswordUpdate(dict req, int nRequestID);

	int reqTradingAccountPasswordUpdate(dict req, int nRequestID);

	int reqOrderInsert(dict req, int nRequestID);

	int reqOrderAction(dict req, int nRequestID);

	int reqQryOrder(dict req, int nRequestID);

	int reqQryTrade(dict req, int nRequestID);

	int reqQryInvestorPosition(dict req, int nRequestID);

	int reqQryTradingAccount(dict req, int nRequestID);

	int reqQryInvestor(dict req, int nRequestID);

	int reqQryTradingCode(dict req, int nRequestID);

	int reqQryExchange(dict req, int nRequestID);

	int reqQryInstrument(dict req, int nRequestID);

	int reqQryInvestorPositionDetail(dict req, int nRequestID);

	int reqQryTradingNotice(dict req, int nRequestID);

	int reqExecOrderInsert(dict req, int nRequestID);

	int reqExecOrderAction(dict req, int nRequestID);

	int reqLockInsert(dict req, int nRequestID);

	int reqQryExecOrder(dict req, int nRequestID);

	int reqQryExecOrderVolume(dict req, int nRequestID);

	int reqQryLock(dict req, int nRequestID);

	int reqQryLockPosition(dict req, int nRequestID);

	int reqQryUnderlyingStockInfo(dict req, int nRequestID);

	int reqQryOTPInsCommRate(dict req, int nRequestID);

	int reqQryInstrumentMarginRate(dict req, int nRequestID);

	int reqQryOTPAssignment(dict req, int nRequestID);

	int reqQryDepthMarketData(dict req, int nRequestID);

	int reqFromBankToStockByStock(dict req, int nRequestID);

	int reqFromStockToBankByStock(dict req, int nRequestID);

	int reqQryContractBank(dict req, int nRequestID);

	int reqQueryBankAccountMoneyByStock(dict req, int nRequestID);

	int reqQryTransferSerial(dict req, int nRequestID);

	int reqQrySettlementInfoConfirm(dict req, int nRequestID);

	int reqSettlementInfoConfirm(dict req, int nRequestID);

	int reqQrySettlementInfo(dict req, int nRequestID);

	int reqQryInvestorTradeLevel(dict req, int nRequestID);

	int reqQryPurchaseLimitAmt(dict req, int nRequestID);

	int reqQryPositionLimitVol(dict req, int nRequestID);

	int reqQryHistoryOrder(dict req, int nRequestID);

	int reqQryHistoryTrade(dict req, int nRequestID);

	int reqQryHistoryAssignment(dict req, int nRequestID);

	int reqQryDelivDetail(dict req, int nRequestID);

	int reqAutoExecOrderAction(dict req, int nRequestID);

	int reqCombActionInsert(dict req, int nRequestID);

	int reqQryInvestorCombinePosition(dict req, int nRequestID);

	int reqQryCombActionVolume(dict req, int nRequestID);

	int reqFundOutCreditApply(dict req, int nRequestID);

	int reqQryFundOutCredit(dict req, int nRequestID);

	int reqQryFundOutCreditApply(dict req, int nRequestID);
};
