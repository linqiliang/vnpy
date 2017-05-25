/////////////////////////////////////////////////////////////////////////
///@company shanghai liber information Technology Co.,Ltd
///@file SecurityFtdcTraderApi.h
///@brief ����ͻ��˽ӿ�
/////////////////////////////////////////////////////////////////////////

#if !defined(SECURITY_FTDCTRADERAPI_H)
#define SECURITY_FTDCTRADERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SecurityFtdcUserApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_TRADER_API_EXPORT
#define TRADER_API_EXPORT __declspec(dllexport)
#else
#define TRADER_API_EXPORT __declspec(dllimport)
#endif
#else
#define TRADER_API_EXPORT 
#endif

class CSecurityFtdcTraderSpi
{
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected(){};
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason){};
		
	///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
	///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
	virtual void OnHeartBeatWarning(int nTimeLapse){};	

	///����Ӧ��
	virtual void OnRspError(CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��¼������Ӧ
	virtual void OnRspUserLogin(CSecurityFtdcRspUserLoginField *pRspUserLogin, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CSecurityFtdcUserLogoutField *pUserLogout, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��ȡ��֤�����������Ӧ
	virtual void OnRspFetchAuthRandCode(CSecurityFtdcAuthRandCodeField *pAuthRandCode, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����¼��������Ӧ
	virtual void OnRspOrderInsert(CSecurityFtdcInputOrderField *pInputOrder, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��������������Ӧ
	virtual void OnRspOrderAction(CSecurityFtdcInputOrderActionField *pInputOrderAction, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�û��������������Ӧ
	virtual void OnRspUserPasswordUpdate(CSecurityFtdcUserPasswordUpdateField *pUserPasswordUpdate, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ʽ��˻��������������Ӧ
	virtual void OnRspTradingAccountPasswordUpdate(CSecurityFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����֪ͨ
	virtual void OnRtnOrder(CSecurityFtdcOrderField *pOrder) {};

	///�ɽ�֪ͨ
	virtual void OnRtnTrade(CSecurityFtdcTradeField *pTrade) {};

	///����¼�����ر�
	virtual void OnErrRtnOrderInsert(CSecurityFtdcInputOrderField *pInputOrder, CSecurityFtdcRspInfoField *pRspInfo) {};

	///������������ر�
	virtual void OnErrRtnOrderAction(CSecurityFtdcOrderActionField *pOrderAction, CSecurityFtdcRspInfoField *pRspInfo) {};

	///Liber�������Ӧ��
	virtual void OnRspFundOutByLiber(CSecurityFtdcInputFundTransferField *pInputFundTransfer, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Liber�������֪ͨ
	virtual void OnRtnFundOutByLiber(CSecurityFtdcFundTransferField *pFundTransfer) {};

	///Liber����������ر�
	virtual void OnErrRtnFundOutByLiber(CSecurityFtdcInputFundTransferField *pInputFundTransfer, CSecurityFtdcRspInfoField *pRspInfo) {};

	///���з������֪ͨ
	virtual void OnRtnFundInByBank(CSecurityFtdcFundTransferField *pFundTransfer) {};

	///�ʽ���תӦ��
	virtual void OnRspFundInterTransfer(CSecurityFtdcFundInterTransferField *pFundInterTransfer, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ʽ���ת��ˮ֪ͨ
	virtual void OnRtnFundInterTransferSerial(CSecurityFtdcFundInterTransferSerialField *pFundInterTransferSerial) {};

	///�ʽ���ת����ر�
	virtual void OnErrRtnFundInterTransfer(CSecurityFtdcFundInterTransferField *pFundInterTransfer, CSecurityFtdcRspInfoField *pRspInfo) {};
};

#ifndef WINDOWS
	#if __GNUC__ >= 4
		#pragma GCC visibility push(default)
	#endif
#endif

class TRADER_API_EXPORT CSecurityFtdcTraderApi
{
public:
	///����TraderApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@return ��������UserApi
	static CSecurityFtdcTraderApi *CreateFtdcTraderApi(const char *pszFlowPath = "");
	
	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;
	
	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual void Init() = 0;
	
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
	
	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CSecurityFtdcTraderSpi *pSpi) = 0;
	
	///����˽������
	///@param nResumeType ˽�����ش���ʽ  
	///        SECURITY_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        SECURITY_TERT_RESUME:���ϴ��յ�������
	///        SECURITY_TERT_QUICK:ֻ���͵�¼��˽����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	virtual void SubscribePrivateTopic(SECURITY_TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ĺ�������
	///@param nResumeType �������ش���ʽ  
	///        SECURITY_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        SECURITY_TERT_RESUME:���ϴ��յ�������
	///        SECURITY_TERT_QUICK:ֻ���͵�¼�󹫹���������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
	virtual void SubscribePublicTopic(SECURITY_TE_RESUME_TYPE nResumeType) = 0;

	///�û���¼����
	virtual int ReqUserLogin(CSecurityFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;
	

	///�ǳ�����
	virtual int ReqUserLogout(CSecurityFtdcUserLogoutField *pUserLogout, int nRequestID) = 0;

	///��ȡ��֤���������
	virtual int ReqFetchAuthRandCode(CSecurityFtdcAuthRandCodeField *pAuthRandCode, int nRequestID) = 0;

	///����¼������
	virtual int ReqOrderInsert(CSecurityFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	///������������
	virtual int ReqOrderAction(CSecurityFtdcInputOrderActionField *pInputOrderAction, int nRequestID) = 0;

	///�û������������
	virtual int ReqUserPasswordUpdate(CSecurityFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

	///�ʽ��˻������������
	virtual int ReqTradingAccountPasswordUpdate(CSecurityFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID) = 0;

	///Liber�����������
	virtual int ReqFundOutByLiber(CSecurityFtdcInputFundTransferField *pInputFundTransfer, int nRequestID) = 0;

	///�ʽ���ת����
	virtual int ReqFundInterTransfer(CSecurityFtdcFundInterTransferField *pFundInterTransfer, int nRequestID) = 0;
protected:
	~CSecurityFtdcTraderApi(){};
};
  
#ifndef WINDOWS
	#if __GNUC__ >= 4
		#pragma GCC visibility pop
	#endif
#endif

#endif
