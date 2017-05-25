//˵������
/*
����CTP API�к��ʽ�ת����صĺ���̫�࣬
ͬʱҲ�Ѿ��д����Ŀͻ���֧����Щ���ܣ�
��������Python��װ����ʱѡ��ֻ֧�ֽ��׹���
*/


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
#include "GoldTradeApi.h"
#include "Constant.h"

//�����ռ�
using namespace std;
using namespace boost::python;
using namespace boost;

//����
#define ONFRONTCONNECTED 1
#define ONFRONTDISCONNECTED 2
#define ONRSPUSERLOGIN 3
#define ONRSPUSERLOGOUT 4
#define ONNTYMKTSTATUS 5
#define ONRSPQRYINSTRUMENT 6
#define ONRTNDEPTHMARKETDATA 7
#define ONRSPORDERINSERT 8
#define ONERRRTNORDERINSERT 9
#define ONRTNORDER 10
#define ONFORCELOGOUT 11
#define ONRSPORDERACTION 12
#define ONERRRTNORDERACTION 13
#define ONRTNTRADE 14
#define ONRSPQRYTRADINGACCOUNT 15
#define ONRSPQRYORDER 16
#define ONRSPQRYTRADE 17
#define ONRSPQRYINVESTORPOSITION 18
#define ONRSPQRYCLIENTSTORAGE 19
#define ONRSPSUBMARKETDATA 20


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
class TdApi : public CGoldTradeSpi
{
private:
	CGoldTradeApi* api;			//API����
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

	//���ӽ���֪ͨ
	virtual void OnFrontConnected();

	//���ӶϿ�
	virtual void OnFrontDisconnected(int nReason);

	///��¼������Ӧ
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	//�г�״̬֪ͨ
	virtual void OnNtyMktStatus(const CThostFtdcMarketStatusField *pfldMktStatus);

	///�����ѯ��Լ��Ӧ
	virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);

	///����¼��������Ӧ(����ϵͳ������
	virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///����¼�����ر�(��������
	virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);

	///����֪ͨ
	//virtual void OnRtnOrder(CThostFtdcOrderField *pOrder); //����
	virtual void OnRtnOrder(CThostFtdcOrderRtnField *pOrder);

	//ǿ��֪ͨ
	virtual void OnForceLogout(CThostFtdcUserLogoutField *pLogout);

	//����Ӧ��
	///��������������Ӧ(����ϵͳ���ذ����˴������ʹ�����Ϣ)
	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///������������ر�(����������)
	virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);

	///�ɽ�֪ͨ
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);

	///�����ѯ�ʽ��˻���Ӧ
	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ������Ӧ
	virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯ�ɽ���Ӧ
	virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///�����ѯͶ���ֲ߳���Ӧ
	virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	//��ѯ�ͻ����Ӧ��
	virtual void OnRspQryClientStorage(CThostFtdcStorageField *pStorage, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	///��������Ӧ��
	virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	//-------------------------------------------------------------------------------------
	//task������
	//-------------------------------------------------------------------------------------

	void processTask();

	void processFrontConnected(Task task);

	void processFrontDisconnected(Task task);

	void processRspUserLogin(Task task);

	void processRspUserLogout(Task task);

	void processNtyMktStatus(Task task);

	void processRspQryInstrument(Task task);

	void processRtnDepthMarketData(Task task);

	void processRspOrderInsert(Task task);

	void processErrRtnOrderInsert(Task task);

	void processRtnOrder(Task task);

	void processForceLogout(Task task);

	void processRspOrderAction(Task task);

	void processErrRtnOrderAction(Task task);

	void processRtnTrade(Task task);

	void processRspQryTradingAccount(Task task);

	void processRspQryOrder(Task task);

	void processRspQryTrade(Task task);

	void processRspQryInvestorPosition(Task task);

	void processRspQryClientStorage(Task task);

	void processRspSubMarketData(Task task);

	//-------------------------------------------------------------------------------------
	//data���ص������������ֵ�
	//error���ص������Ĵ����ֵ�
	//id������id
	//last���Ƿ�Ϊ��󷵻�
	//i������
	//-------------------------------------------------------------------------------------

	virtual void onFrontConnected(){};

	virtual void onFrontDisconnected(int i){};

	virtual void onRspUserLogin(dict data, dict error, int id, bool last) {};

	virtual void onRspUserLogout(dict data, dict error, int id, bool last) {};

	virtual void onNtyMktStatus(dict data) {};

	virtual void onRspQryInstrument(dict data, dict error, int id, bool last) {};

	virtual void onRtnDepthMarketData(dict data) {};

	virtual void onForceLogout(dict data) {};

	virtual void onRspOrderInsert(dict data, dict error, int id, bool last) {};

	virtual void onErrRtnOrderInsert(dict data, dict error) {};

	virtual void onRtnOrder(dict data) {};

	virtual void onRspOrderAction(dict data, dict error, int id, bool last) {};

	virtual void onErrRtnOrderAction(dict data, dict error) {};

	virtual void onRtnTrade(dict data) {};

	virtual void onRspQryTradingAccount(dict data, dict error, int id, bool last) {};

	virtual void onRspQryOrder(dict data, dict error, int id, bool last) {};

	virtual void onRspQryTrade(dict data, dict error, int id, bool last) {};

	virtual void onRspQryInvestorPosition(dict data, dict error, int id, bool last) {};

	virtual void onRspQryClientStorage(dict data, dict error, int id, bool last) {};

	virtual void onRspSubMarketData(dict data, dict error, int id, bool last) {};

	//-------------------------------------------------------------------------------------
	//req:���������������ֵ�
	//-------------------------------------------------------------------------------------

	void createGoldTraderApi();

	void release();

	int init(bool flag);

	void join();

	int exit();

	void registerFront(string pszFrontAddress);

	int reqUserLogin(dict req, int nRequestID);

	int reqUserLogout(dict req, int nRequestID);

	int reqUserReLogin();

	int subscribeMarketData(string instrumentID);

	int unSubscribeMarketData(string instrumentID);

	int reqQryInstrument(dict req, int nRequestID);

	int reqOrderInsert(dict req, int nRequestID);

	int reqOrderAction(dict req, int nRequestID);

	int reqQryInvestorPosition(dict req, int nRequestID);

	int reqQryTradingAccount(dict req, int nRequestID);

	int reqQryTrade(dict req, int nRequestID);

	int reqQryOrder(dict req, int nRequestID);

	int reqQryStorage(dict req, int nRequestID);
};

