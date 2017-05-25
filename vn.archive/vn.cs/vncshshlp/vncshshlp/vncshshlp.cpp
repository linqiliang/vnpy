// vncshshlp.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "vncshshlp.h"

//------------------------------------------------------------------------
//������������
//------------------------------------------------------------------------

//��ȡ�����ļ�
int CsHsHlp::loadConfig(string fileName)
{
	int i = CITICs_HsHlp_LoadConfig(&this->cfgHandle, fileName.c_str());
	return i;
};

//��ʼ��
int CsHsHlp::init()
{
	int i = CITICs_HsHlp_Init(&this->handle, this->cfgHandle);
	return i;
};

//���ӷ�����
int CsHsHlp::connectServer()
{
	int i = CITICs_HsHlp_ConnectServer(this->handle);
	return i;
};

//��ȡ������Ϣ
string CsHsHlp::getErrorMsg()
{
	char msg[512];
	CITICs_HsHlp_GetErrorMsg(this->handle, NULL, msg);
	string errorMsg = msg;
	return errorMsg;
};

//��ʼ����������
int CsHsHlp::beginParam()
{
	int i = CITICs_HsHlp_BeginParam(this->handle);
	return i;
};

//���÷����Ĳ����ֶ����ƺ�ֵ
int CsHsHlp::setValue(string key, string value)
{
	int i = CITICs_HsHlp_SetValue(this->handle, key.c_str(), value.c_str());
	return i;
};

//����
int CsHsHlp::bizCallAndCommit(int iFuncID)
{
	int i = CITICs_HsHlp_BizCallAndCommit(this->handle, iFuncID, NULL, BIZCALL_ASYNC);
	return i;
};

//�Ͽ�������
int CsHsHlp::disconnect()
{
	int i = CITICs_HsHlp_DisConnect(this->handle);
	return i;
};

//�˳�
int CsHsHlp::exit()
{
	int i = CITICs_HsHlp_Exit(this->handle);
	return i;
};


//------------------------------------------------------------------------
//�첽��Ϣ�����߳�
//------------------------------------------------------------------------

//�������е���Ϣ������
void CsHsHlp::processMsg()
{
	LPMSG_CTRL msg;
	int row = 0;
	int col = 0;
	char key[64] = {0};
	char value[512] = {0};
	memset(&msg, 0, sizeof(msg));

	while (1)
	{
		//��ȡ��Ϣ
		CITICs_HsHlp_QueueGetMsg(this->handle, msg, -1);

		//�����ֵ䲢���͵�Python��
		row = CITICs_HsHlp_GetRowCount(this->handle, msg);		//��ȡmsg�������ж��ٸ���Ӧ��
		col = CITICs_HsHlp_GetColCount(this->handle, msg);		//��ȡmsg����������Щ�ֶΣ�

		for (int i = 0; i < row; i++)
		{
			if (0 == CITICs_HsHlp_GetNextRow(this->handle, msg))
			{
				dict data;
				for (int j = 0; j < col; j++)
				{
					CITICs_HsHlp_GetColName(this->handle, j, key);
					CITICs_HsHlp_GetValueByIndex(this->handle, j, value);
					string str_key = key;
					string str_value = value;
					data[str_key] = str_value;
					this->onMsg(data);
				}
			}
		}

		//�Ӷ���ɾ����Ϣ
		CITICs_HsHlp_QueueEraseMsg(this->handle, msg);
	}
};



///-------------------------------------------------------------------------------------
///Boost.Python��װ
///-------------------------------------------------------------------------------------

struct CsHsHlpWrap : CsHsHlp, wrapper < CsHsHlp >
{
	virtual void onMsg(dict data)
	{
		//����python�����е��ûص�������������ǰ����Ҫ�Ȼ�ȡȫ����GIL����ֹ����������
		PyLock lock;

		//���µ�try...catch...����ʵ�ֲ�׽python�����д���Ĺ��ܣ���ֹC++ֱ�ӳ���ԭ��δ֪�ı���
		try
		{
			this->get_override("onMsg")(data);
		}
		catch (error_already_set const &)
		{
			PyErr_Print();
		}
	};
};


BOOST_PYTHON_MODULE(vncshshlp)
{
	PyEval_InitThreads();	//����ʱ���У���֤�ȴ���GIL

	class_<CsHsHlpWrap, boost::noncopyable>("CsHsHlp")
		.def("loadConfig", &CsHsHlpWrap::loadConfig)
		.def("init", &CsHsHlpWrap::init)
		.def("connectServer", &CsHsHlpWrap::connectServer)
		.def("getErrorMsg", &CsHsHlpWrap::getErrorMsg)
		.def("beginParam", &CsHsHlpWrap::beginParam)
		.def("setValue", &CsHsHlpWrap::setValue)
		.def("bizCallAndCommit", &CsHsHlpWrap::bizCallAndCommit)
		.def("disconnect", &CsHsHlpWrap::disconnect)
		.def("exit", &CsHsHlpWrap::exit)

		.def("onMsg", pure_virtual(&CsHsHlpWrap::onMsg))
		;
};