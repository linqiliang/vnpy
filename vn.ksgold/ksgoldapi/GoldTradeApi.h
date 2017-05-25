#ifndef GOLD_TRADE_API_H
#define GOLD_TRADE_API_H

#ifdef GOLDTRADEAPI_EXPORTS
#define GOLDTRADEAPI_LIB __declspec(dllexport)
#else
#ifdef WIN32
#define GOLDTRADEAPI_LIB __declspec(dllimport)
#else
#define GOLDTRADEAPI_LIB 
#endif
#endif


#include <stdio.h>
#include "APIError.h"
#include "KSUserApiStructEx.h"
class CGoldTradeSpi	//�ص��ӿ�
{
 public:
	virtual ~CGoldTradeSpi(){};
	 //���ӽ���֪ͨ
	virtual void OnFrontConnected(){};

	//���ӶϿ�
	virtual void OnFrontDisconnected(int nReason){};


	///��¼������Ӧ
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�ǳ�������Ӧ
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	//�г�״̬֪ͨ
	virtual void OnNtyMktStatus(const CThostFtdcMarketStatusField *pfldMktStatus){};

	///�����ѯ��Լ��Ӧ
	virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};


	///�������֪ͨ
	virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData) {};

	///����¼��������Ӧ(����ϵͳ������
	virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����¼�����ر�(��������
	virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) {};

	///����֪ͨ
	virtual void OnRtnOrder(CThostFtdcOrderRtnField *pOrder) {};

	//ǿ��֪ͨ
	virtual void OnForceLogout(CThostFtdcUserLogoutField *pLogout) {}; 
	
	//����Ӧ��
	///��������������Ӧ(����ϵͳ���ذ����˴������ʹ�����Ϣ)
	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///������������ر�(����������)
	virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) {};

	///�ɽ�֪ͨ
	virtual void OnRtnTrade(CThostFtdcTradeField *pTrade) {};

	///�����ѯ�ʽ��˻���Ӧ
	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///�����ѯ������Ӧ
	virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯ�ɽ���Ӧ
	virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///�����ѯͶ���ֲ߳���Ӧ
	virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	//��ѯ�ͻ����Ӧ��
	virtual void OnRspQryClientStorage(CThostFtdcStorageField *pStorage, CThostFtdcRspInfoField *pRspInfo,int nRequestID,bool bIsLast){};

	///��������Ӧ��
	virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

	///����Ӧ��
	//virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

};



class GOLDTRADEAPI_LIB CGoldTradeApi 
{
public: 
	static CGoldTradeApi *CreateGoldTradeApi();
	//�ͷŽӿ�
	virtual void Release()=0;
	//ע��ǰ�õ�ַ
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	//ע��API�ص��ӿ�
	virtual void RegisterSpi(CGoldTradeSpi *pGeneralSpi)=0;	
	//����API�߳�
	virtual int Init(bool logflag=true)=0;	
	//ֹͣAPI�߳�
	virtual void Join()=0;	


	//�û���¼����
	virtual int ReqUserLogin(CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;

	//�û��ǳ�����
	virtual int ReqUserLogout(CThostFtdcUserLogoutField *pUserLogout, int nRequestID) = 0;

	//��������
	virtual int ReqUserReLogin() = 0;

	//��������
	virtual int SubscribeMarketData(char *ppInstrumentID[], int nCount) = 0;

	///�˶����顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int UnSubscribeMarketData(char *ppInstrumentID[], int nCount) = 0;

	//��ѯ�ڻ���Լ
	virtual int ReqQryInstrument(CThostFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

	//�µ�����
	virtual int ReqOrderInsert(CThostFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

	//������������(����)
	virtual int ReqOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, int nRequestID) = 0;

	//��ѯ�ֲ�����
	virtual int ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField *pInvestorPosition, int nRequestID) = 0;

	//��ѯ�ʽ�����
	virtual int ReqQryTradingAccount(CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID) = 0;

	//�ɽ���ѯ����
	virtual int ReqQryTrade(CThostFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

	//ί�в�ѯ����
	virtual int ReqQryOrder(CThostFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

	//��ѯ�ͻ��������
	virtual int ReqQryStorage(CThostFtdcQryStorageField *pfldStorage, int nRequestID)=0;


protected:
	virtual ~CGoldTradeApi();



};




#endif