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
#include "SecurityFtdcL2MDUserApi.h"
_USING_LTS_NS_

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
#define ONRSPSUBL2MARKETDATA 7
#define ONRSPUNSUBL2MARKETDATA 8
#define ONRSPSUBL2INDEX 9
#define ONRSPUNSUBL2INDEX 10
#define ONRTNL2MARKETDATA 11
#define ONRTNL2INDEX 12
#define ONRSPSUBL2ORDERANDTRADE 13
#define ONRSPUNSUBL2ORDERANDTRADE 14
#define ONRTNL2ORDER 15
#define ONRTNL2TRADE 16
#define ONNTFCHECKORDERLIST 17



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
class L2MdApi : public CSecurityFtdcL2MDUserSpi
{
private:
	CSecurityFtdcL2MDUserApi* api;		//API����
	thread *task_thread;				//�����߳�ָ�루��python���������ݣ�
	ConcurrentQueue<Task> task_queue;	//�������

public:
	L2MdApi()
	{
		function0<void> f = boost::bind(&L2MdApi::processTask, this);
		thread t(f);
		this->task_thread = &t;
	};

	~L2MdApi()
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

	///������ʱ����
	virtual void OnHeartBeatWarning(int nTimeLapse);

	///����Ӧ��
	virtual void OnRspError(CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///��¼������Ӧ
	virtual void OnRspUserLogin(CSecurityFtdcUserLoginField *pUserLogin, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CSecurityFtdcUserLogoutField *pUserLogout, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///����Level2����Ӧ��
	virtual void OnRspSubL2MarketData(CSecurityFtdcSpecificInstrumentField *pSpecificInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///ȡ������Level2����Ӧ��
	virtual void OnRspUnSubL2MarketData(CSecurityFtdcSpecificInstrumentField *pSpecificInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///����Level2ָ������Ӧ��
	virtual void OnRspSubL2Index(CSecurityFtdcSpecificInstrumentField *pSpecificInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///ȡ������Level2ָ������Ӧ��
	virtual void OnRspUnSubL2Index(CSecurityFtdcSpecificInstrumentField *pSpecificInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///Level2����֪ͨ
	virtual void OnRtnL2MarketData(CSecurityFtdcL2MarketDataField *pL2MarketData) ;

	///Level2ָ������֪ͨ
	virtual void OnRtnL2Index(CSecurityFtdcL2IndexField *pL2Index) ;

	///�������ί�м��ɽ�Ӧ��
	virtual void OnRspSubL2OrderAndTrade(CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///ȡ���������ί�м��ɽ�Ӧ��
	virtual void OnRspUnSubL2OrderAndTrade(CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

	///Level2ί��֪ͨ
	virtual void OnRtnL2Order(CSecurityFtdcL2OrderField *pL2Order) ;

	///Level2�ɽ�֪ͨ
	virtual void OnRtnL2Trade(CSecurityFtdcL2TradeField *pL2Trade) ;

	///֪ͨ����SSE����һ����������Ϊ0�ı���
	virtual void OnNtfCheckOrderList(TSecurityFtdcInstrumentIDType InstrumentID, TSecurityFtdcFunctionCodeType FunctionCode) ;


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

	void processRspSubL2MarketData(Task task);

	void processRspUnSubL2MarketData(Task task);

	void processRspSubL2Index(Task task);

	void processRspUnSubL2Index(Task task);

	void processRtnL2MarketData(Task task);

	void processRtnL2Index(Task task);

	void processRspSubL2OrderAndTrade(Task task);

	void processRspUnSubL2OrderAndTrade(Task task);

	void processRtnL2Order(Task task);

	void processRtnL2Trade(Task task);

	void processNtfCheckOrderList(Task task);


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

	virtual void onRspSubL2MarketData(dict data, dict error, int id, bool last) {};

	virtual void onRspUnSubL2MarketData(dict data, dict error, int id, bool last) {};

	virtual void onRspSubL2Index(dict data, dict error, int id, bool last) {};

	virtual void onRspUnSubL2Index(dict data, dict error, int id, bool last) {};

	virtual void onRtnL2MarketData(dict data) {};

	virtual void onRtnL2Index(dict data) {};

	virtual void onRspSubL2OrderAndTrade(dict error, int id, bool last) {};

	virtual void onRspUnSubL2OrderAndTrade(dict error, int id, bool last) {};

	virtual void onRtnL2Order(dict data) {};

	virtual void onRtnL2Trade(dict data) {};

	virtual void onNtfCheckOrderList(string instrumentID, string functionCode) {};


	//-------------------------------------------------------------------------------------
	//req:���������������ֵ�
	//-------------------------------------------------------------------------------------

	void createFtdcL2MDUserApi(string pszFlowPath = "");

	void release();

	void init();

	int join();

	int exit();

	string getTradingDay();

	void registerFront(string pszFrontAddress);

	int subscribeL2MarketData(dict req);

	int unSubscribeL2MarketData(dict req);

	int subscribeL2Index(dict req);

	int unSubscribeL2Index(dict req);

	int subscribeL2OrderAndTrade();

	int unSubscribeL2OrderAndTrade();

	int reqUserLogin(dict req, int nRequestID);

	int reqUserLogout(dict req, int nRequestID);
};

