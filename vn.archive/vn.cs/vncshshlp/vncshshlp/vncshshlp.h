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
#include "CITICs_HsT2Hlp.h"

//�����ռ�
using namespace std;
using namespace boost::python;
using namespace boost;


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



///-------------------------------------------------------------------------------------
///��װ��
///-------------------------------------------------------------------------------------

class CsHsHlp
{
private:
	HSHLPCFGHANDLE cfgHandle;		//����ָ��
	HSHLPHANDLE handle;				//��������ָ��
	thread *task_thread;			//�����߳�ָ�루��python���������ݣ�

public:
	CsHsHlp()
	{
		function0<void> f = boost::bind(&CsHsHlp::processMsg, this);
		//thread t(f);
		//this->task_thread = &t;
	};

	~CsHsHlp()
	{

	};

	//------------------------------------------------------------------------
	//������������
	//------------------------------------------------------------------------

	//��ȡ�����ļ�
	int loadConfig(string fileName);

	//��ʼ��
	int init();

	//���ӷ�����
	int connectServer();

	//��ȡ������Ϣ
	string getErrorMsg();

	//��ʼ����������
	int beginParam();

	//���÷����Ĳ����ֶ����ƺ�ֵ
	int setValue(string key, string value);

	//����
	int bizCallAndCommit(int iFuncID);

	//�Ͽ�������
	int disconnect();

	//�˳�
	int exit();

	//------------------------------------------------------------------------
	//�첽��Ϣ�����߳�
	//------------------------------------------------------------------------

	//�������е���Ϣ������
	void processMsg();

	//------------------------------------------------------------------------
	//Python�м̳еĻص�����
	//------------------------------------------------------------------------
	
	//��Python��������Ϣ�ĺ���
	virtual void onMsg(dict data) {};
};
