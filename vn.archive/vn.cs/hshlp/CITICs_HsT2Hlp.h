#ifndef __CITICS_HSHLP_H__
#define __CITICS_HSHLP_H__

#ifdef WIN32
#ifdef CITICS_HSHLP_EXPORTS
#define CITICS_HSHLP_API __declspec(dllexport)
#else
#define CITICS_HSHLP_API __declspec(dllimport)
#endif

#define CITICSSTDCALL	__stdcall		/* ensure stcall calling convention on NT */
#else
#define CITICS_HSHLP_API
#define CITICSSTDCALL				    /* leave blank for other systems */
#endif

#define ERROR_MSG_SIZE 512
//////////////////////////////////////////////////////////////////////////

/**
* ͬ��ҵ�����
* ʹ�øñ�ʶ����ҵ��ʱ��ϵͳ��������״ֱ̬������Ӧ����Ϣ��ʱ
*/
#define BIZCALL_SYNC  0

/**
* �첽ҵ�����
* ʹ�øñ�ʶ����ҵ��ʱ��ϵͳ�������ض����ȴ�Ӧ����Ϣ��
* ��Ҫ����QueueGetMsg��ȡӦ������Ϣ 
*/
#define BIZCALL_ASYNC 1

/**
* ������Ϣ���ķ�������Ϣ��Ϣ
* ��ʶ��ҵ��Ϊ��Ϣ���������綩�ĳɽ��������ݡ�ϵͳ֪ͨ��Ϣ��
* ��Ҫ����QueueGetMsg��ȡ���ĵ���Ϣ
*/
#define BIZCALL_SUBSCRIBE 3

typedef void *HSHLPCFGHANDLE;
typedef void *HSHLPHANDLE;
typedef void *HSHLPASYNCMSG;

#pragma pack(1)

/* �첽�Ͷ�����Ϣ������Ϣ*/
typedef struct
{
	int nFlags;           // λ��ʶ��Ϣ��0x0:������Ϣ, >0:ϵͳ״̬��Ϣ
	int nFuncID;          // �첽�����ܺ�
	int nReqNo;           // �첽���������ţ����ݸ���ź͹��ܺŶ������Ӧ������ƥ��
	int nIssueType;       // ������Ϣ���
	int nErrorNo;         // ������� 
	HSHLPASYNCMSG HAsyncMsg;      // ��Ϣ���
	char szErrorInfo[ERROR_MSG_SIZE+1];     // ������Ϣ
}MSG_CTRL, *LPMSG_CTRL;

#pragma pack()


#ifdef __cplusplus
extern "C"
{
#endif
	
	// ��ʼ�������szConfigFileΪ��ʱ��ϵͳĬ��ֵ��ʼ����hConfigΪ����
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_InitConfig(HSHLPCFGHANDLE* hConfig, const char* szConfigFile=NULL);

	// ���������ļ�����Լ��ض����ͬ�������ļ������ز�ͬ�����þ������ͬ��InitConfig
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_LoadConfig(HSHLPCFGHANDLE* hConfig, const char* szConfigFile);
	
	// ���÷��������ӵ�ַ����ʽ��ip1:port1;ip2:port2;
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_ResetServer(HSHLPCFGHANDLE hConfig, const char* szAddr);

	// �������þ������ʼ��һ�����Ӷ���
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_Init(HSHLPHANDLE* HlpHandle, HSHLPCFGHANDLE hConfig);
	// �ͷ����Ӿ��ϵͳ��Դ
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_Exit(HSHLPHANDLE HlpHandle);

	// ���������������
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_ConnectServer(HSHLPHANDLE HlpHandle);
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_DisConnect(HSHLPHANDLE HlpHandle);

	// �ύҵ���������szParam����ΪNULL������Ϊ��ͨ��SetValue�������õ�������� 
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_BizCallAndCommit(HSHLPHANDLE HlpHandle, int iFuncID, const char* szParam=NULL, int nBizCallType=BIZCALL_SYNC, LPMSG_CTRL lpMsgCtrl=NULL);

	// ��ȡ��¼�С�����������ֵΪ�С�����
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_GetRowCount(HSHLPHANDLE HlpHandle, LPMSG_CTRL lpMsgCtrl=NULL);
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_GetColCount(HSHLPHANDLE HlpHandle, LPMSG_CTRL lpMsgCtrl=NULL);

	// ��ȡ�ֶ����ƣ������0Ϊ����
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_GetColName(HSHLPHANDLE HlpHandle, int iColumn, char* szColName, LPMSG_CTRL lpMsgCtrl=NULL);

	// ��ȡ��һ�м�¼����һ�ε��������ȴ򿪽���������ѵ�0����Ϊ��ǰ��¼��
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_GetNextRow(HSHLPHANDLE HlpHandle, LPMSG_CTRL lpMsgCtrl=NULL);

	// �����ֶ����ƣ���ȡ�ֶ�ֵ
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_GetValue(HSHLPHANDLE HlpHandle, const char* szKeyName, char* szValue, LPMSG_CTRL lpMsgCtrl=NULL);

	// �����ֶ���Ż�ȡ�ֶ�ֵ�������0Ϊ����
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_GetValueByIndex(HSHLPHANDLE HlpHandle, int iColumn, char* szValue, LPMSG_CTRL lpMsgCtrl=NULL);

	// ��ȡ��ǰ����������Ϣ
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_GetErrorMsg(HSHLPHANDLE HlpHandle, int* piErrorCode, char* szErrorMsg);


	/************************************************************************/
	// ��һ������������õķ�����һ��һ�������á�
	// ��ʼ���������
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_BeginParam(HSHLPHANDLE HlpHandle);
	// ����ÿ����������ֶ����ƺ�ֵ
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_SetValue(HSHLPHANDLE HlpHandle, const char* szKeyName, const char* szValue);
	
	
	/************************************************************************/
	// �첽�������Ϣ������غ���
	
	// ��ȡ�첽��Ϣ�����е���Ϣ����
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_QueueMsgCount(HSHLPHANDLE HlpHandle);
	
	// �Ӷ����ж�ȡһ����Ϣ�����������û�����ݣ��ú�����һֱ���������أ�ֱ��nWaitTime��ʱʱ���ŷ��ء�
	// nWaitTime: ��λ����
	//       = 0: �������أ�����������������򷵻�Msg����returnֵΪ 0������returnֵΪ-5(��ʱ����)
	//       =-1: ������ֱ�������������ݻ�ȡ��Msg �ŷ��ء��������������ȴ���returnֵΪ 0��
	//       = ����ֵ����ʱʱ�䣬������������������������أ�����ȴ�timeʱ��󷵻ء�returnֵΪ -5(��ʱ����)��
	// Return:  0: �������������һ�ȡ��Ϣ�ɹ���
	//         -5: ��ʱ�������趨��ʱ���ڶ�����û�����ݡ�
	// 	��������:	
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_QueueGetMsg(HSHLPHANDLE HlpHandle, LPMSG_CTRL lpMsgCtrl /*Out*/, int nWaitTime=0);
	
	// ������ɻ��߲���Ҫ����Ϣʱ��Ӧ��ʱɾ������Ϣ��������Ϣ��ռ�ô����ڴ档
	// �����ɾ���п���ÿ�ζ�Get��ͬһ����Ϣ
	CITICS_HSHLP_API int CITICSSTDCALL CITICs_HsHlp_QueueEraseMsg(HSHLPHANDLE HlpHandle, LPMSG_CTRL lpMsgCtrl /*In*/);
	

#ifdef __cplusplus
}
#endif


#endif 
