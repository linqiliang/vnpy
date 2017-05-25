/////////////////////////////////////////////////////////////////////////
///@company shanghai liber information Technology Co.,Ltd
///@file SecurityFtdcQueryApi.h
///@brief ����ͻ��˽ӿ�
/////////////////////////////////////////////////////////////////////////

#if !defined(SECURITY_FTDCQUERYAPI_H)
#define SECURITY_FTDCQUERYAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SecurityFtdcUserApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_QUERY_API_EXPORT
#define QUERY_API_EXPORT __declspec(dllexport)
#else
#define QUERY_API_EXPORT __declspec(dllimport)
#endif
#else
#define QUERY_API_EXPORT 
#endif

class CSecurityFtdcQuerySpi
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

	///�����ѯ��������Ӧ
	virtual void OnRspQryExchange(CSecurityFtdcExchangeField *pExchange, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��Լ��Ӧ
	virtual void OnRspQryInstrument(CSecurityFtdcInstrumentField *pInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ������Ӧ
	virtual void OnRspQryInvestor(CSecurityFtdcInvestorField *pInvestor, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ���ױ�����Ӧ
	virtual void OnRspQryTradingCode(CSecurityFtdcTradingCodeField *pTradingCode, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�ʽ��˻���Ӧ
	virtual void OnRspQryTradingAccount(CSecurityFtdcTradingAccountField *pTradingAccount, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯծȯ��Ϣ��Ӧ
	virtual void OnRspQryBondInterest(CSecurityFtdcBondInterestField *pBondInterest, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��ֵ������Ϣ��Ӧ
	virtual void OnRspQryMarketRationInfo(CSecurityFtdcMarketRationInfoField *pMarketRationInfo, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��Լ����������Ӧ
	virtual void OnRspQryInstrumentCommissionRate(CSecurityFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯETF��Լ��Ӧ
	virtual void OnRspQryETFInstrument(CSecurityFtdcETFInstrumentField *pETFInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯETF��Ʊ����Ӧ
	virtual void OnRspQryETFBasket(CSecurityFtdcETFBasketField *pETFBasket, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯOF��Լ��Ӧ
	virtual void OnRspQryOFInstrument(CSecurityFtdcOFInstrumentField *pOFInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯSF��Լ��Ӧ
	virtual void OnRspQrySFInstrument(CSecurityFtdcSFInstrumentField *pSFInstrument, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��Լ���ֱ�֤����Ӧ
	virtual void OnRspQryInstrumentUnitMargin(CSecurityFtdcInstrumentUnitMarginField *pInstrumentUnitMargin, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯԤ������Ϣ��Ӧ
	virtual void OnRspQryPreDelivInfo(CSecurityFtdcPreDelivInfoField *pPreDelivInfo, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ����ȯ������Ϣ��Ӧ
	virtual void OnRspQryCreditStockAssignInfo(CSecurityFtdcCreditStockAssignInfoField *pCreditStockAssignInfo, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�����ʷ�����Ϣ��Ӧ
	virtual void OnRspQryCreditCashAssignInfo(CSecurityFtdcCreditCashAssignInfoField *pCreditCashAssignInfo, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ֤ȯ��������Ӧ
	virtual void OnRspQryConversionRate(CSecurityFtdcConversionRateField *pConversionRate, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ��ʷ���ø�ծ��Ϣ��Ӧ
	virtual void OnRspQryHisCreditDebtInfo(CSecurityFtdcHisCreditDebtInfoField *pHisCreditDebtInfo, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ���龲̬��Ϣ��Ӧ
	virtual void OnRspQryMarketDataStaticInfo(CSecurityFtdcMarketDataStaticInfoField *pMarketDataStaticInfo, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ���ڻع���Ϣ��Ӧ
	virtual void OnRspQryExpireRepurchInfo(CSecurityFtdcExpireRepurchInfoField *pExpireRepurchInfo, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯծȯ��ѺΪ��׼ȯ������Ӧ
	virtual void OnRspQryBondPledgeRate(CSecurityFtdcBondPledgeRateField *pBondPledgeRate, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯծȯ��Ѻ������չ�ϵ��Ӧ
	virtual void OnRspQryPledgeBond(CSecurityFtdcPledgeBondField *pPledgeBond, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ������Ӧ
	virtual void OnRspQryOrder(CSecurityFtdcOrderField *pOrder, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�ɽ���Ӧ
	virtual void OnRspQryTrade(CSecurityFtdcTradeField *pTrade, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ���ֲ߳���Ӧ
	virtual void OnRspQryInvestorPosition(CSecurityFtdcInvestorPositionField *pInvestorPosition, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ʽ�ת�˲�ѯӦ��
	virtual void OnRspQryFundTransferSerial(CSecurityFtdcFundTransferField *pFundTransfer, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ʽ���ת��ˮ��ѯӦ��
	virtual void OnRspQryFundInterTransferSerial(CSecurityFtdcFundInterTransferSerialField *pFundInterTransferSerial, CSecurityFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
};

#ifndef WINDOWS
	#if __GNUC__ >= 4
		#pragma GCC visibility push(default)
	#endif
#endif

class QUERY_API_EXPORT CSecurityFtdcQueryApi
{
public:
	///����QueryApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///@return ��������UserApi
	static CSecurityFtdcQueryApi *CreateFtdcQueryApi(const char *pszFlowPath = "");
	
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
	virtual void RegisterSpi(CSecurityFtdcQuerySpi *pSpi) = 0;
	
	///�û���¼����
	virtual int ReqUserLogin(CSecurityFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;
	

	///�ǳ�����
	virtual int ReqUserLogout(CSecurityFtdcUserLogoutField *pUserLogout, int nRequestID) = 0;

	///��ȡ��֤���������
	virtual int ReqFetchAuthRandCode(CSecurityFtdcAuthRandCodeField *pAuthRandCode, int nRequestID) = 0;

	///�����ѯ������
	virtual int ReqQryExchange(CSecurityFtdcQryExchangeField *pQryExchange, int nRequestID) = 0;

	///�����ѯ��Լ
	virtual int ReqQryInstrument(CSecurityFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	///�����ѯͶ����
	virtual int ReqQryInvestor(CSecurityFtdcQryInvestorField *pQryInvestor, int nRequestID) = 0;

	///�����ѯ���ױ���
	virtual int ReqQryTradingCode(CSecurityFtdcQryTradingCodeField *pQryTradingCode, int nRequestID) = 0;

	///�����ѯ�ʽ��˻�
	virtual int ReqQryTradingAccount(CSecurityFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID) = 0;

	///�����ѯծȯ��Ϣ
	virtual int ReqQryBondInterest(CSecurityFtdcQryBondInterestField *pQryBondInterest, int nRequestID) = 0;

	///�����ѯ��ֵ������Ϣ
	virtual int ReqQryMarketRationInfo(CSecurityFtdcQryMarketRationInfoField *pQryMarketRationInfo, int nRequestID) = 0;

	///�����ѯ��Լ��������
	virtual int ReqQryInstrumentCommissionRate(CSecurityFtdcQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID) = 0;

	///�����ѯETF��Լ
	virtual int ReqQryETFInstrument(CSecurityFtdcQryETFInstrumentField *pQryETFInstrument, int nRequestID) = 0;

	///�����ѯETF��Ʊ��
	virtual int ReqQryETFBasket(CSecurityFtdcQryETFBasketField *pQryETFBasket, int nRequestID) = 0;

	///�����ѯOF��Լ
	virtual int ReqQryOFInstrument(CSecurityFtdcQryOFInstrumentField *pQryOFInstrument, int nRequestID) = 0;

	///�����ѯSF��Լ
	virtual int ReqQrySFInstrument(CSecurityFtdcQrySFInstrumentField *pQrySFInstrument, int nRequestID) = 0;

	///�����ѯ��Լ���ֱ�֤��
	virtual int ReqQryInstrumentUnitMargin(CSecurityFtdcQryInstrumentUnitMarginField *pQryInstrumentUnitMargin, int nRequestID) = 0;

	///�����ѯԤ������Ϣ
	virtual int ReqQryPreDelivInfo(CSecurityFtdcQryPreDelivInfoField *pQryPreDelivInfo, int nRequestID) = 0;

	///�����ѯ����ȯ������Ϣ
	virtual int ReqQryCreditStockAssignInfo(CSecurityFtdcQryCreditStockAssignInfoField *pQryCreditStockAssignInfo, int nRequestID) = 0;

	///�����ѯ�����ʷ�����Ϣ
	virtual int ReqQryCreditCashAssignInfo(CSecurityFtdcQryCreditCashAssignInfoField *pQryCreditCashAssignInfo, int nRequestID) = 0;

	///�����ѯ֤ȯ������
	virtual int ReqQryConversionRate(CSecurityFtdcQryConversionRateField *pQryConversionRate, int nRequestID) = 0;

	///�����ѯ��ʷ���ø�ծ��Ϣ
	virtual int ReqQryHisCreditDebtInfo(CSecurityFtdcQryHisCreditDebtInfoField *pQryHisCreditDebtInfo, int nRequestID) = 0;

	///�����ѯ���龲̬��Ϣ
	virtual int ReqQryMarketDataStaticInfo(CSecurityFtdcQryMarketDataStaticInfoField *pQryMarketDataStaticInfo, int nRequestID) = 0;

	///�����ѯ���ڻع���Ϣ
	virtual int ReqQryExpireRepurchInfo(CSecurityFtdcQryExpireRepurchInfoField *pQryExpireRepurchInfo, int nRequestID) = 0;

	///�����ѯծȯ��ѺΪ��׼ȯ����
	virtual int ReqQryBondPledgeRate(CSecurityFtdcQryBondPledgeRateField *pQryBondPledgeRate, int nRequestID) = 0;

	///�����ѯծȯ��Ѻ������չ�ϵ
	virtual int ReqQryPledgeBond(CSecurityFtdcQryPledgeBondField *pQryPledgeBond, int nRequestID) = 0;

	///�����ѯ����
	virtual int ReqQryOrder(CSecurityFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	///�����ѯ�ɽ�
	virtual int ReqQryTrade(CSecurityFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	///�����ѯͶ���ֲ߳�
	virtual int ReqQryInvestorPosition(CSecurityFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

	///�ʽ�ת�˲�ѯ����
	virtual int ReqQryFundTransferSerial(CSecurityFtdcQryFundTransferSerialField *pQryFundTransferSerial, int nRequestID) = 0;

	///�ʽ���ת��ˮ��ѯ����
	virtual int ReqQryFundInterTransferSerial(CSecurityFtdcQryFundInterTransferSerialField *pQryFundInterTransferSerial, int nRequestID) = 0;
protected:
	~CSecurityFtdcQueryApi(){};
};
  
#ifndef WINDOWS
	#if __GNUC__ >= 4
		#pragma GCC visibility pop
	#endif
#endif

#endif
