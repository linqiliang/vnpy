/////////////////////////////////////////////////////////////////////////
///@company shanghai liber information Technology Co.,Ltd
///@file SecurityFtdcL2MDUserApi.h
///@brief ����ͻ��˽ӿ�
/////////////////////////////////////////////////////////////////////////

#if !defined(SECURITY_L2MD_FTDCUSERAPI_H)
#define SECURITY_L2MD_FTDCUSERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SecurityFtdcL2MDUserApiStruct.h"

_LTS_NS_BEGIN_
#if defined(L2MD_USERAPI_IS_LIB) && defined(WINDOWS)
#ifdef LIB_L2MD_USER_API_EXPORT
#define L2MD_USER_API_EXPORT __declspec(dllexport)
#else
#define L2MD_USER_API_EXPORT __declspec(dllimport)
#endif
#else
#define L2MD_USER_API_EXPORT 
#endif

class CSecurityFtdcL2MDUserSpi
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
		
	///������ʱ����
	virtual void OnHeartBeatWarning(int nTimeLapse){};

	///����Ӧ��
	virtual void OnRspError(CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///��¼������Ӧ
	virtual void OnRspUserLogin(CSecurityFtdcUserLoginField *pUserLogin, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CSecurityFtdcUserLogoutField *pUserLogout, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����Level2����Ӧ��
	virtual void OnRspSubL2MarketData(CSecurityFtdcSpecificInstrumentField *pSpecificInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ȡ������Level2����Ӧ��
	virtual void OnRspUnSubL2MarketData(CSecurityFtdcSpecificInstrumentField *pSpecificInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����Level2ָ������Ӧ��
	virtual void OnRspSubL2Index(CSecurityFtdcSpecificInstrumentField *pSpecificInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ȡ������Level2ָ������Ӧ��
	virtual void OnRspUnSubL2Index(CSecurityFtdcSpecificInstrumentField *pSpecificInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Level2����֪ͨ
	virtual void OnRtnL2MarketData(CSecurityFtdcL2MarketDataField *pL2MarketData) {};

	///Level2ָ������֪ͨ
	virtual void OnRtnL2Index(CSecurityFtdcL2IndexField *pL2Index) {};

	///�������ί�м��ɽ�Ӧ��
	virtual void OnRspSubL2OrderAndTrade(CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///ȡ���������ί�м��ɽ�Ӧ��
	virtual void OnRspUnSubL2OrderAndTrade(CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///Level2ί��֪ͨ
	virtual void OnRtnL2Order(CSecurityFtdcL2OrderField *pL2Order) {};

	///Level2�ɽ�֪ͨ
	virtual void OnRtnL2Trade(CSecurityFtdcL2TradeField *pL2Trade) {};

	///֪ͨ����SSE����һ����������Ϊ0�ı���
	virtual void OnNtfCheckOrderList(TSecurityFtdcInstrumentIDType InstrumentID, TSecurityFtdcFunctionCodeType FunctionCode) {};
};

#ifndef WINDOWS
	#if __GNUC__ >= 4
		#pragma GCC visibility push(default)
	#endif
#endif
class L2MD_USER_API_EXPORT CSecurityFtdcL2MDUserApi
{
public:
	///����UserApi
	static CSecurityFtdcL2MDUserApi *CreateFtdcL2MDUserApi(const bool bIsMulticast=false);
	
	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release() = 0;
	
	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual void Init() = 0;
	
	///�ȴ��ӿ��߳̽�������
	virtual int Join() = 0;
	
	///��ȡ��ǰ������
	///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
	virtual const char *GetTradingDay() = 0;
	
	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CSecurityFtdcL2MDUserSpi *pSpi) = 0;
	
	virtual int SubscribeL2MarketData(char *ppInstrumentID[], int nCount, char* pExchageID) = 0;

	virtual int UnSubscribeL2MarketData(char *ppInstrumentID[], int nCount, char* pExchageID) = 0;
	
	virtual int SubscribeL2Index(char *ppInstrumentID[], int nCount, char* pExchageID) = 0;

	virtual int UnSubscribeL2Index(char *ppInstrumentID[], int nCount, char* pExchageID) = 0;	
	
	virtual int SubscribeL2OrderAndTrade() = 0;
	
	virtual int UnSubscribeL2OrderAndTrade() = 0;

	///��¼����
	virtual int ReqUserLogin(CSecurityFtdcUserLoginField *pUserLogin, int nRequestID) = 0;

	///�ǳ�����
	virtual int ReqUserLogout(CSecurityFtdcUserLogoutField *pUserLogout, int nRequestID) = 0;
protected:
	~CSecurityFtdcL2MDUserApi(){};
};
#ifndef WINDOWS
	#if __GNUC__ >= 4
		#pragma GCC visibility pop
	#endif
#endif
_LTS_NS_END_
#endif
