//˵������

//ϵͳ
#ifdef WIN32
#include "stdafx.h"
#endif
#include <string>
#include <queue>
#include <vector>

//Boost
#define BOOST_PYTHON_STATIC_LIB
#include <boost/python/module.hpp>		//python��װ
#include <boost/python/def.hpp>			//python��װ
#include <boost/python/dict.hpp>		//python��װ
#include <boost/python/list.hpp>		//python��װ
#include <boost/python/object.hpp>		//python��װ
#include <boost/python.hpp>				//python��װ
#include <boost/thread.hpp>				//������е��̹߳���
#include <boost/bind.hpp>				//������е��̹߳���
#include <boost/any.hpp>				//������е�����ʵ��
#include <boost/algorithm/string.hpp>	//�ַ���������

//API
#include "ShZdTradeLib.h"

//�����ռ�
using namespace std;
using namespace boost::python;
using namespace boost;

//����
#define ONRECEIVETRADEINFO 1
#define ONRECEIVEMARKETINFO 2
#define ONRECEIVEERRORINFO 3


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
	int task_name;			//�ص��������ƶ�Ӧ�ĳ���
	void* task_data;		//���ݽṹָ��
	string task_errmsg;		//�����ַ���
	int task_errcode;		//�������
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


///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class ShzdApi : public IShZdTradeOutLib
{
private:
	IShZdTradeInLib *api;				//API����
	thread *task_thread;				//�����߳�ָ�루��python���������ݣ�
	ConcurrentQueue<Task*> task_queue;	//�������

public:
	ShzdApi()
	{
		function0<void> f = boost::bind(&ShzdApi::processTask, this);
		thread t(f);
		this->task_thread = &t;
	};

	~ShzdApi()
	{
	};

	//-------------------------------------------------------------------------------------
	//API�ص�����
	//-------------------------------------------------------------------------------------

	virtual int OnReceiveTradeInfo(const CShZdMessage * re);

	virtual int OnReceiveMarketInfo(const CShZdMessage * re);
	
	virtual int OnReceiveErrorInfo(int errorCode, const char* re);

	//-------------------------------------------------------------------------------------
	//task������
	//-------------------------------------------------------------------------------------

	void processTask();

	void processTradeInfo(Task *task);

	void processMarketInfo(Task *task);

	void processErrorInfo(Task *task);


	//-------------------------------------------------------------------------------------
	//data���ص������������ֵ�
	//error���ص������Ĵ����ֵ�
	//id������id
	//last���Ƿ�Ϊ��󷵻�
	//i������
	//-------------------------------------------------------------------------------------

	virtual void onReceiveTradeInfo(dict data){};

	virtual void onReceiveMarketInfo(dict data){};

	virtual void onReceiveErrorInfo(int errcode, string errmsg){};

	//-------------------------------------------------------------------------------------
	//req:���������������ֵ�
	//-------------------------------------------------------------------------------------

	void release();

	int initShZdServer();

	int registerFront(string address, int port);

	int registerMarket(string address, int port);

	int shzdSendInfoToTrade(dict data);

	int shzdSendInfoToMarket(dict data);

};
