/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////

#if !defined(Sgit_FTDCMDAPI_H)
#define Sgit_FTDCMDAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SgitFtdcUserApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_MD_API_EXPORT
#define MD_API_EXPORT __declspec(dllexport)
#else
#define MD_API_EXPORT __declspec(dllimport)
#endif
#else
#define MD_API_EXPORT 
#endif

class CSgitFtdcMdSpi
{
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected(){};
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param pErrMsg ����ԭ��
	virtual void OnFrontDisconnected(char *pErrMsg){};	

	///��¼������Ӧ
	virtual void OnRspUserLogin(CSgitFtdcRspUserLoginField *pRspUserLogin, CSgitFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CSgitFtdcUserLogoutField *pUserLogout, CSgitFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CSgitFtdcDepthMarketDataField *pDepthMarketData) {};
};

class MD_API_EXPORT CSgitFtdcMdApi
{
public:
	///����MdApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@return ��������UserApi
	static CSgitFtdcMdApi *CreateFtdcMdApi(const char *pszFlowPath = "");
	
	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;
	
	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	///isLogged ��������ʱʹ��true�����Դ�ӡ���յ�����Ϣ������
	virtual void Init(bool isLogged) = 0;
	
	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	virtual int Join() = 0;
	
	///��ȡ��ǰ������
	///@retrun ��ȡ���Ľ�����
	///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
	virtual const char *GetTradingDay() = 0;
	
	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	virtual void RegisterFront(char *pszFrontAddress) = 0;

	/**�öಥʱTCP����Ҳ��Ҫ����
	*���øú�����Ĭ�ϲ���tcpģʽ��������
	*���öಥ������ MlCast://hostIP$multiaddress:port��
	*���ֻ��һ���������� MlCast://ANY$multiaddress:port	
	* @param szMlCastAddr ����ip��ַ���ಥ�鼰�˿�	
	*/
	virtual void SetMultiCastAddr(char *szMlCastAddr) = 0;
	
	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CSgitFtdcMdSpi *pSpi) = 0;
	///�����г�����
	///@param nResumeType �������ش���ʽ  
	///        Sgit_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        Sgit_TERT_RESUME:���ϴ��յ�������
	///        Sgit_TERT_QUICK:ֻ���͵�¼�󹫹���������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
	virtual void SubscribeMarketTopic(Sgit_TE_RESUME_TYPE nResumeType) = 0;

	///
	/// �������鶩��
	/// @param iRequestID �����
	/// @param pMBLQuotReq ���鶩��������
	/// @return 0��ʾ�ɹ�
	/// @return ������ʾʧ��
	///
	virtual int SubQuot(CSgitSubQuotField *pSgitSubQuotField)=0;
	///���;���ָ�ǰ��,֪ͨǰ�ÿ��Ը��Լ�����˽�����빫����
	/// @return 0��ʾ�ɹ�
	/// @return �����μ�������
	///
	virtual int Ready() = 0;

	///�û���¼����
	virtual int ReqUserLogin(CSgitFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	///�ǳ�����
	virtual int ReqUserLogout(CSgitFtdcUserLogoutField *pUserLogout, int nRequestID) = 0;
protected:
	~CSgitFtdcMdApi(){};
};

#endif
