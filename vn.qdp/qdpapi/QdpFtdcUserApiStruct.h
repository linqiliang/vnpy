/////////////////////////////////////////////////////////////////////////
///@system QuantDo Platform
///@company �Ϻ���Ͷ����Ƽ����޹�˾
///@file QdpFtdcUserApiStruct.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ�����ݽṹ
///@history 
/////////////////////////////////////////////////////////////////////////

#if !defined(Qdp_FTDCSTRUCT_H)
#define Qdp_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QdpFtdcUserApiDataType.h"

///ϵͳ�û���¼����
struct CQdpFtdcReqUserLoginField
{
	///������
	TQdpFtdcDateType	TradingDay;
	///�����û�����
	TQdpFtdcUserIDType	UserID;
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///����
	TQdpFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TQdpFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TQdpFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TQdpFtdcProtocolInfoType	ProtocolInfo;
	///IP��ַ
	TQdpFtdcIPAddressType	IPAddress;
	///Mac��ַ
	TQdpFtdcMacAddressType	MacAddress;
	///�������Ĵ���
	TQdpFtdcDataCenterIDType	DataCenterID;
	///��̬����
	TQdpFtdcPasswordType	OneTimePassword;
	///�ն�IP��ַ
	TQdpFtdcIPAddressType	ClientIPAddress;
};

///ϵͳ�û���¼Ӧ��
struct CQdpFtdcRspUserLoginField
{
	///������
	TQdpFtdcDateType	TradingDay;
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdpFtdcUserIDType	UserID;
	///��¼�ɹ�ʱ��
	TQdpFtdcTimeType	LoginTime;
	///�û���󱾵ر�����
	TQdpFtdcUserOrderLocalIDType	MaxOrderLocalID;
	///����ϵͳ����
	TQdpFtdcTradingSystemNameType	TradingSystemName;
	///�������Ĵ���
	TQdpFtdcDataCenterIDType	DataCenterID;
	///��Ա˽������ǰ����
	TQdpFtdcSequenceNoType	PrivateFlowSize;
	///����Ա˽������ǰ����
	TQdpFtdcSequenceNoType	UserFlowSize;
	///�Ự���
	TQdpFtdcSessionIDType	SessionID;
	///ǰ�ñ��
	TQdpFtdcFrontIDType	FrontID;
};

///�û��ǳ�����
struct CQdpFtdcReqUserLogoutField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdpFtdcUserIDType	UserID;
};

///�û��ǳ�����
struct CQdpFtdcRspUserLogoutField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdpFtdcUserIDType	UserID;
};

///ǿ���û��˳�
struct CQdpFtdcForceUserExitField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdpFtdcUserIDType	UserID;
};

///�û������޸�
struct CQdpFtdcUserPasswordUpdateField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdpFtdcUserIDType	UserID;
	///������
	TQdpFtdcPasswordType	OldPassword;
	///������
	TQdpFtdcPasswordType	NewPassword;
};

///���뱨��
struct CQdpFtdcInputOrderField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TQdpFtdcOrderSysIDType	OrderSysID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdpFtdcUserIDType	UserID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///�û����ر�����
	TQdpFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�۸�����
	TQdpFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TQdpFtdcDirectionType	Direction;
	///��ƽ��־
	TQdpFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdpFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TQdpFtdcPriceType	LimitPrice;
	///����
	TQdpFtdcVolumeType	Volume;
	///��Ч������
	TQdpFtdcTimeConditionType	TimeCondition;
	///GTD����
	TQdpFtdcDateType	GTDDate;
	///�ɽ�������
	TQdpFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TQdpFtdcVolumeType	MinVolume;
	///ֹ���
	TQdpFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TQdpFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TQdpFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TQdpFtdcBusinessUnitType	BusinessUnit;
	///�û��Զ�����`
	TQdpFtdcCustomType	UserCustom;
	///Ӫҵ������
	TQdpFtdcBranchIDType	BranchID;
	///��¼���
	TQdpFtdcSequenceNoType	RecNum;
	///ҵ�����
	TQdpFtdcBusinessTypeType	BusinessType;
};

///��������
struct CQdpFtdcOrderActionField
{
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///�������
	TQdpFtdcOrderSysIDType	OrderSysID;
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdpFtdcUserIDType	UserID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///���γ��������ı��ر��
	TQdpFtdcUserOrderLocalIDType	UserOrderActionLocalID;
	///���������ı��ر������
	TQdpFtdcUserOrderLocalIDType	UserOrderLocalID;
	///����������־
	TQdpFtdcActionFlagType	ActionFlag;
	///�۸�
	TQdpFtdcPriceType	LimitPrice;
	///�����仯
	TQdpFtdcVolumeType	VolumeChange;
	///��¼���
	TQdpFtdcSequenceNoType	RecNum;
	///ǰ�ñ��
	TQdpFtdcFrontIDType	FrontID;
	///�Ự���
	TQdpFtdcSessionIDType	SessionID;
};

///�ڴ����
struct CQdpFtdcMemDbField
{
	///�ڴ����
	TQdpFtdcMemTableNameType	MemTableName;
};

///Ͷ�����ʽ��ʻ����������
struct CQdpFtdcReqAccountDepositField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�ʽ���ˮ��
	TQdpFtdcAccountSeqNoType	AccountSeqNo;
	///�ʽ��ʺ�
	TQdpFtdcAccountIDType	AccountID;
	///�������������ʽ���ˮ��
	TQdpFtdcAccountSeqNoType	AccountInsideSeqNo;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///���
	TQdpFtdcMoneyType	Amount;
	///�������
	TQdpFtdcAccountDirectionType	AmountDirection;
	///�û�����
	TQdpFtdcUserIDType	UserID;
};

///Ͷ�����ʽ��ʻ������Ӧ��
struct CQdpFtdcRspAccountDepositField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TQdpFtdcAccountIDType	AccountID;
	///�ʽ���ˮ��
	TQdpFtdcAccountSeqNoType	AccountSeqNo;
	///�������������ʽ���ˮ��
	TQdpFtdcAccountSeqNoType	AccountInsideSeqNo;
	///���
	TQdpFtdcMoneyType	Amount;
	///�������
	TQdpFtdcAccountDirectionType	AmountDirection;
	///�����ʽ�
	TQdpFtdcMoneyType	Available;
	///����׼����
	TQdpFtdcMoneyType	Balance;
	///�û�����
	TQdpFtdcUserIDType	UserID;
};

///�ڻ�����ת������
struct CQdpFtdcReqTransferField
{
	///ҵ������
	TQdpFtdcTradeCodeType	TradeCode;
	///���д���
	TQdpFtdcBankIDType	BankID;
	///���з�֧��������
	TQdpFtdcBankBrchIDType	BankBrchID;
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TQdpFtdcBranchIDType	BrokerBranchID;
	///��������
	TQdpFtdcTradingDayType	TradeDate;
	///����ʱ��
	TQdpFtdcTimeType	TradingTime;
	///������ˮ��
	TQdpFtdcSerialType	BankSerial;
	///����ϵͳ����
	TQdpFtdcTradingDayType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TQdpFtdcSequenceNoType	PlateSerial;
	///����Ƭ��־
	TQdpFtdcYesNoIndicatorType	LastFragment;
	///�Ự��
	TQdpFtdcSessionIDType	SessionID;
	///�ͻ�����
	TQdpFtdcClientNameType	CustomerName;
	///֤������
	TQdpFtdcIdentifiedCardTypeType	IdCardType;
	///֤������
	TQdpFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TQdpFtdcClientTypeType	CustType;
	///�����˺�
	TQdpFtdcBankAccountType	BankAccount;
	///��������
	TQdpFtdcPasswordType	BankPassWord;
	///�ʽ��˺�
	TQdpFtdcAccountIDType	AccountID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�ڻ�����
	TQdpFtdcPasswordType	Password;
	///��װ���
	TQdpFtdcSequenceNoType	InstallID;
	///�ڻ���˾��ˮ��
	TQdpFtdcSequenceNoType	FutureSerial;
	///����Ա
	TQdpFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TQdpFtdcUserIDType	VerifyCertNoFlag;
	///���ִ���
	TQdpFtdcCurrencyIDType	Currency;
	///ת�˽��
	TQdpFtdcMoneyType	TradeAmount;
	///�ڻ���ȡ���
	TQdpFtdcMoneyType	FutureFetchAmount;
	///����֧����־
	TQdpFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TQdpFtdcFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TQdpFtdcFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TQdpFtdcAbstractType	Message;
	///ժҪ
	TQdpFtdcAbstractType	Digest;
	///�����˺�����
	TQdpFtdcBankAccTypeType	BankAccType;
	///������־
	TQdpFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�˺�����
	TQdpFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TQdpFtdcBankCodingForFutureType	BankCodingForFuture;
	///�ڻ���λ�˺�
	TQdpFtdcBankAccountType	BankSecuAcc;
	///���������־
	TQdpFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TQdpFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TQdpFtdcUserIDType	OperNo;
	///������
	TQdpFtdcRequestIDType	RequestID;
	///����ID
	TQdpFtdcTIDType	TID;
	///ת�˽���״̬
	TQdpFtdcTransferStatusType	TransferStatus;
};

///�ڻ�����ת��֪ͨ
struct CQdpFtdcRspTransferField
{
	///ҵ������
	TQdpFtdcTradeCodeType	TradeCode;
	///���д���
	TQdpFtdcBankIDType	BankID;
	///���з�֧��������
	TQdpFtdcBankBrchIDType	BankBrchID;
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TQdpFtdcBranchIDType	BrokerBranchID;
	///��������
	TQdpFtdcTradingDayType	TradeDate;
	///����ʱ��
	TQdpFtdcTimeType	TradingTime;
	///������ˮ��
	TQdpFtdcSerialType	BankSerial;
	///����ϵͳ����
	TQdpFtdcTradingDayType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TQdpFtdcSequenceNoType	PlateSerial;
	///����Ƭ��־
	TQdpFtdcYesNoIndicatorType	LastFragment;
	///�Ự��
	TQdpFtdcSessionIDType	SessionID;
	///�ͻ�����
	TQdpFtdcClientNameType	CustomerName;
	///֤������
	TQdpFtdcIdentifiedCardTypeType	IdCardType;
	///֤������
	TQdpFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TQdpFtdcClientTypeType	CustType;
	///�����˺�
	TQdpFtdcBankAccountType	BankAccount;
	///��������
	TQdpFtdcPasswordType	BankPassWord;
	///�ʽ��˺�
	TQdpFtdcAccountIDType	AccountID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�ڻ�����
	TQdpFtdcPasswordType	Password;
	///��װ���
	TQdpFtdcSequenceNoType	InstallID;
	///�ڻ���˾��ˮ��
	TQdpFtdcSequenceNoType	FutureSerial;
	///����Ա
	TQdpFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TQdpFtdcUserIDType	VerifyCertNoFlag;
	///���ִ���
	TQdpFtdcCurrencyIDType	Currency;
	///ת�˽��
	TQdpFtdcMoneyType	TradeAmount;
	///�ڻ���ȡ���
	TQdpFtdcMoneyType	FutureFetchAmount;
	///����֧����־
	TQdpFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TQdpFtdcFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TQdpFtdcFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TQdpFtdcAbstractType	Message;
	///ժҪ
	TQdpFtdcAbstractType	Digest;
	///�����˺�����
	TQdpFtdcBankAccTypeType	BankAccType;
	///������־
	TQdpFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�˺�����
	TQdpFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TQdpFtdcBankCodingForFutureType	BankCodingForFuture;
	///�ڻ���λ�˺�
	TQdpFtdcBankAccountType	BankSecuAcc;
	///���������־
	TQdpFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TQdpFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TQdpFtdcUserIDType	OperNo;
	///������
	TQdpFtdcRequestIDType	RequestID;
	///����ID
	TQdpFtdcTIDType	TID;
	///ת�˽���״̬
	TQdpFtdcTransferStatusType	TransferStatus;
	///�������
	TQdpFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdpFtdcErrorMsgType	ErrorMsg;
};

///�ڻ������ѯ�������֪ͨ
struct CQdpFtdcNotifyQueryAccountField
{
	///ҵ������
	TQdpFtdcTradeCodeType	TradeCode;
	///���д���
	TQdpFtdcBankIDType	BankID;
	///���з����Ĵ���
	TQdpFtdcBankBrchIDType	BankBrchID;
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TQdpFtdcBranchIDType	BrokerBranchID;
	///��������
	TQdpFtdcTradingDayType	TradeDate;
	///����ʱ��
	TQdpFtdcTimeType	TradeTime;
	///������ˮ��
	TQdpFtdcSerialType	BankSerial;
	///����ϵͳ����
	TQdpFtdcTradingDayType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TQdpFtdcSequenceNoType	PlateSerial;
	///����Ƭ��־
	TQdpFtdcYesNoIndicatorType	LastFragment;
	///�Ự��
	TQdpFtdcSessionIDType	SessionID;
	///�ͻ�����
	TQdpFtdcClientNameType	CustomerName;
	///֤������
	TQdpFtdcIdentifiedCardTypeType	IdCardType;
	///֤������
	TQdpFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TQdpFtdcClientTypeType	CustType;
	///�����˺�
	TQdpFtdcBankAccountType	BankAccount;
	///��������
	TQdpFtdcPasswordType	BankPassWord;
	///�ʽ��˺�
	TQdpFtdcAccountIDType	AccountID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�ڻ�����
	TQdpFtdcPasswordType	Password;
	///�ڻ���˾��ˮ��
	TQdpFtdcSequenceNoType	FutureSerial;
	///��װ���
	TQdpFtdcSequenceNoType	InstallID;
	///����Ա
	TQdpFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TQdpFtdcUserIDType	VerifyCertNoFlag;
	///���ִ���
	TQdpFtdcCurrencyIDType	Currency;
	///ժҪ
	TQdpFtdcAbstractType	Digest;
	///�����˺�����
	TQdpFtdcBankAccTypeType	BankAccType;
	///������־
	TQdpFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�˺�����
	TQdpFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TQdpFtdcBankCodingForFutureType	BankCodingForFuture;
	///�ڻ���λ�˺�
	TQdpFtdcBankAccountType	BankSecuAcc;
	///���������־
	TQdpFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TQdpFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TQdpFtdcUserIDType	OperNo;
	///������
	TQdpFtdcRequestIDType	RequestID;
	///����ID
	TQdpFtdcTIDType	TID;
	///���п��ý��
	TQdpFtdcMoneyType	BankUseAmount;
	///���п�ȡ���
	TQdpFtdcMoneyType	BankFetchAmount;
	///�������
	TQdpFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdpFtdcErrorMsgType	ErrorMsg;
};

///��Ӧ��Ϣ
struct CQdpFtdcRspInfoField
{
	///�������
	TQdpFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdpFtdcErrorMsgType	ErrorMsg;
};

///������ѯ
struct CQdpFtdcQryOrderField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdpFtdcUserIDType	UserID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�������
	TQdpFtdcOrderSysIDType	OrderSysID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
};

///�ɽ���ѯ
struct CQdpFtdcQryTradeField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdpFtdcUserIDType	UserID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�ɽ����
	TQdpFtdcTradeIDType	TradeID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
};

///��Լ��ѯ
struct CQdpFtdcQryInstrumentField
{
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TQdpFtdcProductIDType	ProductID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
};

///��Լ��ѯӦ��
struct CQdpFtdcRspInstrumentField
{
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TQdpFtdcProductIDType	ProductID;
	///Ʒ������
	TQdpFtdcProductNameType	ProductName;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TQdpFtdcInstrumentNameType	InstrumentName;
	///�������
	TQdpFtdcYearType	DeliveryYear;
	///������
	TQdpFtdcMonthType	DeliveryMonth;
	///�޼۵�����µ���
	TQdpFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TQdpFtdcVolumeType	MinLimitOrderVolume;
	///�м۵�����µ���
	TQdpFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TQdpFtdcVolumeType	MinMarketOrderVolume;
	///��������
	TQdpFtdcVolumeMultipleType	VolumeMultiple;
	///���۵�λ
	TQdpFtdcPriceTickType	PriceTick;
	///����
	TQdpFtdcCurrencyType	Currency;
	///��ͷ�޲�
	TQdpFtdcVolumeType	LongPosLimit;
	///��ͷ�޲�
	TQdpFtdcVolumeType	ShortPosLimit;
	///��ͣ���
	TQdpFtdcPriceType	LowerLimitPrice;
	///��ͣ���
	TQdpFtdcPriceType	UpperLimitPrice;
	///�����
	TQdpFtdcPriceType	PreSettlementPrice;
	///��Լ����״̬
	TQdpFtdcInstrumentStatusType	InstrumentStatus;
	///������
	TQdpFtdcDateType	CreateDate;
	///������
	TQdpFtdcDateType	OpenDate;
	///������
	TQdpFtdcDateType	ExpireDate;
	///��ʼ������
	TQdpFtdcDateType	StartDelivDate;
	///��󽻸���
	TQdpFtdcDateType	EndDelivDate;
	///���ƻ�׼��
	TQdpFtdcPriceType	BasisPrice;
	///��ǰ�Ƿ���
	TQdpFtdcBoolType	IsTrading;
	///������Ʒ����
	TQdpFtdcInstrumentIDType	UnderlyingInstrID;
	///������Ʒ����
	TQdpFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///�ֲ�����
	TQdpFtdcPositionTypeType	PositionType;
	///ִ�м�
	TQdpFtdcPriceType	StrikePrice;
	///��Ȩ����
	TQdpFtdcOptionsTypeType	OptionsType;
	///��Ʒ����
	TQdpFtdcProductClassType	ProductClass;
};

///��Լ״̬
struct CQdpFtdcInstrumentStatusField
{
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TQdpFtdcProductIDType	ProductID;
	///Ʒ������
	TQdpFtdcProductNameType	ProductName;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///��Լ����
	TQdpFtdcInstrumentNameType	InstrumentName;
	///�������
	TQdpFtdcYearType	DeliveryYear;
	///������
	TQdpFtdcMonthType	DeliveryMonth;
	///�޼۵�����µ���
	TQdpFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TQdpFtdcVolumeType	MinLimitOrderVolume;
	///�м۵�����µ���
	TQdpFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TQdpFtdcVolumeType	MinMarketOrderVolume;
	///��������
	TQdpFtdcVolumeMultipleType	VolumeMultiple;
	///���۵�λ
	TQdpFtdcPriceTickType	PriceTick;
	///����
	TQdpFtdcCurrencyType	Currency;
	///��ͷ�޲�
	TQdpFtdcVolumeType	LongPosLimit;
	///��ͷ�޲�
	TQdpFtdcVolumeType	ShortPosLimit;
	///��ͣ���
	TQdpFtdcPriceType	LowerLimitPrice;
	///��ͣ���
	TQdpFtdcPriceType	UpperLimitPrice;
	///�����
	TQdpFtdcPriceType	PreSettlementPrice;
	///��Լ����״̬
	TQdpFtdcInstrumentStatusType	InstrumentStatus;
	///������
	TQdpFtdcDateType	CreateDate;
	///������
	TQdpFtdcDateType	OpenDate;
	///������
	TQdpFtdcDateType	ExpireDate;
	///��ʼ������
	TQdpFtdcDateType	StartDelivDate;
	///��󽻸���
	TQdpFtdcDateType	EndDelivDate;
	///���ƻ�׼��
	TQdpFtdcPriceType	BasisPrice;
	///��ǰ�Ƿ���
	TQdpFtdcBoolType	IsTrading;
	///������Ʒ����
	TQdpFtdcInstrumentIDType	UnderlyingInstrID;
	///������Ʒ����
	TQdpFtdcUnderlyingMultipleType	UnderlyingMultiple;
	///�ֲ�����
	TQdpFtdcPositionTypeType	PositionType;
	///ִ�м�
	TQdpFtdcPriceType	StrikePrice;
	///��Ȩ����
	TQdpFtdcOptionsTypeType	OptionsType;
	///��Ʒ����
	TQdpFtdcProductClassType	ProductClass;
};

///Ͷ�����ʽ��ѯ
struct CQdpFtdcQryInvestorAccountField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdpFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
};

///Ͷ�����ʽ�Ӧ��
struct CQdpFtdcRspInvestorAccountField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TQdpFtdcAccountIDType	AccountID;
	///�ϴν���׼����
	TQdpFtdcMoneyType	PreBalance;
	///���տ����ʽ�
	TQdpFtdcMoneyType	PreAvailable;
	///�����
	TQdpFtdcMoneyType	Deposit;
	///������
	TQdpFtdcMoneyType	Withdraw;
	///ռ�ñ�֤��
	TQdpFtdcMoneyType	Margin;
	///��ȨȨ������֧
	TQdpFtdcMoneyType	Premium;
	///������
	TQdpFtdcMoneyType	Fee;
	///����ı�֤��
	TQdpFtdcMoneyType	FrozenMargin;
	///����Ȩ����
	TQdpFtdcMoneyType	FrozenPremium;
	///����������
	TQdpFtdcMoneyType	FrozenFee;
	///ƽ��ӯ��
	TQdpFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TQdpFtdcMoneyType	PositionProfit;
	///�����ʽ�
	TQdpFtdcMoneyType	Available;
	///����׼����
	TQdpFtdcMoneyType	Balance;
	///��ͷռ�ñ�֤��
	TQdpFtdcMoneyType	LongMargin;
	///��ͷռ�ñ�֤��
	TQdpFtdcMoneyType	ShortMargin;
	///��ͷ����ı�֤��
	TQdpFtdcMoneyType	LongFrozenMargin;
	///��ͷ����ı�֤��
	TQdpFtdcMoneyType	ShortFrozenMargin;
	///��̬Ȩ��
	TQdpFtdcMoneyType	DynamicRights;
	///���ն�
	TQdpFtdcMoneyType	Risk;
	///��������
	TQdpFtdcMoneyType	OtherFee;
	///��Ѻ���
	TQdpFtdcMoneyType	Mortgage;
	///����
	TQdpFtdcCurrencyIDType	Currency;
};

///����Ͷ���߲�ѯ
struct CQdpFtdcQryUserInvestorField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdpFtdcUserIDType	UserID;
};

///����Ͷ����Ӧ��
struct CQdpFtdcRspUserInvestorField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�����û�����
	TQdpFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
};

///���ױ����ѯ
struct CQdpFtdcQryTradingCodeField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdpFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
};

///���ױ����ѯ
struct CQdpFtdcRspTradingCodeField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TQdpFtdcAccountIDType	AccountID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///��Ա���
	TQdpFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQdpFtdcClientIDType	ClientID;
	///�ͻ�����Ȩ��
	TQdpFtdcTradingRightType	ClientRight;
	///�ͻ�����
	TQdpFtdcClientTypeType	ClientType;
	///�ͻ���ֵ����
	TQdpFtdcClientHedgeFlagType	ClientHedgeFlag;
	///�Ƿ��Ծ
	TQdpFtdcIsActiveType	IsActive;
};

///��������ѯ����
struct CQdpFtdcQryExchangeField
{
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
};

///��������ѯӦ��
struct CQdpFtdcRspExchangeField
{
	///������
	TQdpFtdcTradingDayType	TradingDay;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///����������
	TQdpFtdcExchangeNameType	ExchangeName;
};

///Ͷ���ֲֲ߳�ѯ����
struct CQdpFtdcQryInvestorPositionField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdpFtdcUserIDType	UserID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
};

///Ͷ���ֲֲ߳�ѯӦ��
struct CQdpFtdcRspInvestorPositionField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///��Ա���
	TQdpFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TQdpFtdcClientIDType	ClientID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdpFtdcDirectionType	Direction;
	///Ͷ���ױ���־
	TQdpFtdcHedgeFlagType	HedgeFlag;
	///ռ�ñ�֤��
	TQdpFtdcMoneyType	UsedMargin;
	///�ֲܳ���
	TQdpFtdcVolumeType	Position;
	///���ճֲֳɱ�
	TQdpFtdcPriceType	PositionCost;
	///��ֲ���(����ֵ)
	TQdpFtdcVolumeType	YdPosition;
	///���ճֲֳɱ�
	TQdpFtdcMoneyType	YdPositionCost;
	///����ı�֤��
	TQdpFtdcMoneyType	FrozenMargin;
	///���ֶ���ֲ�
	TQdpFtdcVolumeType	FrozenPosition;
	///ƽ�ֶ���ֲ�
	TQdpFtdcVolumeType	FrozenClosing;
	///�����Ȩ����
	TQdpFtdcMoneyType	FrozenPremium;
	///���һ�ʳɽ����
	TQdpFtdcTradeIDType	LastTradeID;
	///���һ�ʱ��ر������
	TQdpFtdcOrderLocalIDType	LastOrderLocalID;
	///����
	TQdpFtdcCurrencyIDType	Currency;
	///�ֲ�ӯ��
	TQdpFtdcMoneyType	PositionProfit;
	///��ֲ���
	TQdpFtdcVolumeType	TodayPosition;
	///���ƽ�ֶ���
	TQdpFtdcVolumeType	FrozenTodayClosing;
};

///�û���ѯ
struct CQdpFtdcQryUserField
{
	///�����û�����
	TQdpFtdcUserIDType	StartUserID;
	///�����û�����
	TQdpFtdcUserIDType	EndUserID;
};

///�û�
struct CQdpFtdcUserField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdpFtdcUserIDType	UserID;
	///�û���¼����
	TQdpFtdcPasswordType	Password;
	///�Ƿ��Ծ
	TQdpFtdcIsActiveType	IsActive;
	///�û�����
	TQdpFtdcUserNameType	UserName;
	///�û�����
	TQdpFtdcUserTypeType	UserType;
	///Ӫҵ��
	TQdpFtdcDepartmentType	Department;
	///��Ȩ���ܼ�
	TQdpFtdcGrantFuncSetType	GrantFuncSet;
};

///Ͷ�����������ʲ�ѯ
struct CQdpFtdcQryInvestorFeeField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdpFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TQdpFtdcHedgeFlagType	HedgeFlag;
};

///Ͷ������������
struct CQdpFtdcInvestorFeeField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱���
	TQdpFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TQdpFtdcHedgeFlagType	HedgeFlag;
	///���������Ѱ�����
	TQdpFtdcRatioType	OpenFeeRate;
	///���������Ѱ�����
	TQdpFtdcRatioType	OpenFeeAmt;
	///ƽ�������Ѱ�����
	TQdpFtdcRatioType	OffsetFeeRate;
	///ƽ�������Ѱ�����
	TQdpFtdcRatioType	OffsetFeeAmt;
	///ƽ��������Ѱ�����
	TQdpFtdcRatioType	OTFeeRate;
	///ƽ��������Ѱ�����
	TQdpFtdcRatioType	OTFeeAmt;
};

///Ͷ���߱�֤���ʲ�ѯ
struct CQdpFtdcQryInvestorMarginField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�û�����
	TQdpFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TQdpFtdcHedgeFlagType	HedgeFlag;
};

///Ͷ���߱�֤����
struct CQdpFtdcInvestorMarginField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///Ͷ���߱���
	TQdpFtdcInvestorIDType	InvestorID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TQdpFtdcHedgeFlagType	HedgeFlag;
	///��ͷռ�ñ�֤�𰴱���
	TQdpFtdcRatioType	LongMarginRate;
	///��ͷ��֤������
	TQdpFtdcRatioType	LongMarginAmt;
	///��ͷռ�ñ�֤�𰴱���
	TQdpFtdcRatioType	ShortMarginRate;
	///��ͷ��֤������
	TQdpFtdcRatioType	ShortMarginAmt;
};

///������ʱ��ƫ���ѯ����
struct CQdpFtdcQryExchangeDiffTimeField
{
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
};

///������ʱ��ƫ���ѯӦ��
struct CQdpFtdcRspExchangeDiffTimeField
{
	///������
	TQdpFtdcTradingDayType	TradingDay;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///������ʱ��
	TQdpFtdcTimeType	ExchangeTime;
	///ƫ��ʱ��
	TQdpFtdcDiffSndType	DiffSnd;
};

///��ѯǩԼ��������
struct CQdpFtdcQryContractBankField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///����Ա
	TQdpFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///����
	TQdpFtdcCurrencyIDType	Currency;
	///���д���
	TQdpFtdcBankIDType	BankID;
	///���з����Ĵ���
	TQdpFtdcBankBrchIDType	BankBrchID;
};

///��ѯǩԼ����Ӧ��
struct CQdpFtdcContractBankField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�ʽ��˺�
	TQdpFtdcAccountIDType	AccountID;
	///����
	TQdpFtdcCurrencyIDType	Currency;
	///���д���
	TQdpFtdcBankIDType	BankID;
	///���з����Ĵ���
	TQdpFtdcBankBrchIDType	BankBrchID;
	///���м��
	TQdpFtdcNameType	BankName;
};

///�ڻ������ѯ�����������
struct CQdpFtdcReqQueryAccountField
{
	///ҵ������
	TQdpFtdcTradeCodeType	TradeCode;
	///���д���
	TQdpFtdcBankIDType	BankID;
	///���з����Ĵ���
	TQdpFtdcBankBrchIDType	BankBrchID;
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TQdpFtdcBranchIDType	BrokerBranchID;
	///��������
	TQdpFtdcTradingDayType	TradeDate;
	///����ʱ��
	TQdpFtdcTimeType	TradeTime;
	///������ˮ��
	TQdpFtdcSerialType	BankSerial;
	///����ϵͳ����
	TQdpFtdcTradingDayType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TQdpFtdcSequenceNoType	PlateSerial;
	///����Ƭ��־
	TQdpFtdcYesNoIndicatorType	LastFragment;
	///�Ự��
	TQdpFtdcSessionIDType	SessionID;
	///�ͻ�����
	TQdpFtdcClientNameType	CustomerName;
	///֤������
	TQdpFtdcIdentifiedCardTypeType	IdCardType;
	///֤������
	TQdpFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TQdpFtdcClientTypeType	CustType;
	///�����˺�
	TQdpFtdcBankAccountType	BankAccount;
	///��������
	TQdpFtdcPasswordType	BankPassWord;
	///�ʽ��˺�
	TQdpFtdcAccountIDType	AccountID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�ڻ�����
	TQdpFtdcPasswordType	Password;
	///�ڻ���˾��ˮ��
	TQdpFtdcSequenceNoType	FutureSerial;
	///��װ���
	TQdpFtdcSequenceNoType	InstallID;
	///����Ա
	TQdpFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TQdpFtdcUserIDType	VerifyCertNoFlag;
	///���ִ���
	TQdpFtdcCurrencyIDType	Currency;
	///ժҪ
	TQdpFtdcAbstractType	Digest;
	///�����˺�����
	TQdpFtdcBankAccTypeType	BankAccType;
	///������־
	TQdpFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�˺�����
	TQdpFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TQdpFtdcBankCodingForFutureType	BankCodingForFuture;
	///�ڻ���λ�˺�
	TQdpFtdcBankAccountType	BankSecuAcc;
	///���������־
	TQdpFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TQdpFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TQdpFtdcUserIDType	OperNo;
	///������
	TQdpFtdcRequestIDType	RequestID;
	///����ID
	TQdpFtdcTIDType	TID;
};

///��ѯת����ˮ����
struct CQdpFtdcQryTransferSerialField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///����Ա
	TQdpFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�ʽ��˺�
	TQdpFtdcAccountIDType	AccountID;
	///���д���
	TQdpFtdcBankIDType	BankID;
	///���ִ���
	TQdpFtdcCurrencyIDType	Currency;
};

///��ѯת����ˮӦ��
struct CQdpFtdcTransferSerialField
{
	///����ƽ̨��Ϣ��ˮ��
	TQdpFtdcSequenceNoType	PlateSerial;
	///��������
	TQdpFtdcTradingDayType	TradeDate;
	///����ϵͳ����
	TQdpFtdcTradingDayType	TradingDay;
	///����ʱ��
	TQdpFtdcTimeType	TradingTime;
	///ҵ������
	TQdpFtdcTradeCodeType	TradeCode;
	///�Ự��
	TQdpFtdcSessionIDType	SessionID;
	///���д���
	TQdpFtdcBankIDType	BankID;
	///���з�֧��������
	TQdpFtdcBankBrchIDType	BankBrchID;
	///�����˺�����
	TQdpFtdcBankAccTypeType	BankAccType;
	///�����˺�
	TQdpFtdcBankAccountType	BankAccount;
	///���ִ���
	TQdpFtdcCurrencyIDType	Currency;
	///������ˮ��
	TQdpFtdcSerialType	BankSerial;
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TQdpFtdcBranchIDType	BrokerBranchID;
	///�ڻ���˾�˺�����
	TQdpFtdcBankAccTypeType	FutureAccType;
	///�ʽ��˺�
	TQdpFtdcAccountIDType	AccountID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�ڻ���˾��ˮ��
	TQdpFtdcSequenceNoType	FutureSerial;
	///֤������
	TQdpFtdcIdentifiedCardTypeType	IdCardType;
	///֤������
	TQdpFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///���׽��
	TQdpFtdcMoneyType	TradeAmount;
	///Ӧ�տͻ�����
	TQdpFtdcFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TQdpFtdcFeeType	BrokerFee;
	///��Ч��־
	TQdpFtdcAvailabilityFlagType	AvailabilityFlag;
	///����Ա
	TQdpFtdcUserIDType	OperatorCode;
	///�������˺�
	TQdpFtdcBankAccountType	BankNewAccount;
	///�������
	TQdpFtdcErrorIDType	ErrorID;
	///������Ϣ
	TQdpFtdcErrorMsgType	ErrorMsg;
};

///ʵʱ�����ѯ����
struct CQdpFtdcQryMarketDataField
{
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
};

///ʵʱ�����ѯӦ��
struct CQdpFtdcMarketDataField
{
	///������
	TQdpFtdcTradingDayType	TradingDay;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///����
	TQdpFtdcPriceType	OpenPrice;
	///��߼�
	TQdpFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdpFtdcPriceType	LowestPrice;
	///���¼�
	TQdpFtdcPriceType	LastPrice;
	///����
	TQdpFtdcVolumeType	Volume;
	///�ɽ����
	TQdpFtdcMoneyType	Turnover;
	///��ͣ���
	TQdpFtdcPriceType	LowerLimitPrice;
	///��ͣ���
	TQdpFtdcPriceType	UpperLimitPrice;
	///�ֲ���
	TQdpFtdcVolumeType	OpenInterest;
	///������
	TQdpFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdpFtdcVolumeType	PreOpenInterest;
	///�����
	TQdpFtdcPriceType	PreSettlementPrice;
	///�����
	TQdpFtdcPriceType	SettlementPrice;
	///����޸ĺ���
	TQdpFtdcMillisecType	UpdateMillisec;
	///����޸�ʱ��
	TQdpFtdcTimeType	UpdateTime;
};

///�����ѯӦ��
struct CQdpFtdcRspMarketDataField
{
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///������
	TQdpFtdcTradingDayType	TradingDay;
	///���������
	TQdpFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQdpFtdcSettlementIDType	SettlementID;
	///�����
	TQdpFtdcPriceType	PreSettlementPrice;
	///������
	TQdpFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdpFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdpFtdcRatioType	PreDelta;
	///����
	TQdpFtdcPriceType	OpenPrice;
	///��߼�
	TQdpFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdpFtdcPriceType	LowestPrice;
	///������
	TQdpFtdcPriceType	ClosePrice;
	///��ͣ���
	TQdpFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdpFtdcPriceType	LowerLimitPrice;
	///�����
	TQdpFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQdpFtdcRatioType	CurrDelta;
	///���¼�
	TQdpFtdcPriceType	LastPrice;
	///����
	TQdpFtdcVolumeType	Volume;
	///�ɽ����
	TQdpFtdcMoneyType	Turnover;
	///�ֲ���
	TQdpFtdcLargeVolumeType	OpenInterest;
	///�����һ
	TQdpFtdcPriceType	BidPrice1;
	///������һ
	TQdpFtdcVolumeType	BidVolume1;
	///������һ
	TQdpFtdcPriceType	AskPrice1;
	///������һ
	TQdpFtdcVolumeType	AskVolume1;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdpFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdpFtdcMillisecType	UpdateMillisec;
};

///�ͻ�����ѯ
struct CQdpFtdcQryInventoryField
{
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///Ʒ�ִ���
	TQdpFtdcProductIDType	ProductID;
};

///�ͻ�����ѯӦ��
struct CQdpFtdcInventoryField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///Ʒ�ִ���
	TQdpFtdcProductIDType	ProductID;
	///�������
	TQdpFtdcInventoryType	TotalInventory;
	///���ÿ��
	TQdpFtdcInventoryType	AvailInventory;
	///������
	TQdpFtdcInventoryType	FrozenInventory;
};

///�������ӷ��ʲ�ѯ����
struct CQdpFtdcQrySGEDeferRateField
{
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
};

///�������ӷ��ʲ�ѯӦ��
struct CQdpFtdcSGEDeferRateField
{
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///��������
	TQdpFtdcTradingDayType	TradeDate;
	///֧������
	TQdpFtdcPayDirectionType	Direction;
	///���ӷ���
	TQdpFtdcRatioType	DeferRate;
};

///�ɽ�
struct CQdpFtdcTradeField
{
	///������
	TQdpFtdcTradingDayType	TradingDay;
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///��Ա���
	TQdpFtdcParticipantIDType	ParticipantID;
	///�µ�ϯλ��
	TQdpFtdcSeatIDType	SeatID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�ͻ���
	TQdpFtdcClientIDType	ClientID;
	///�û����
	TQdpFtdcUserIDType	UserID;
	///�ɽ����
	TQdpFtdcTradeIDType	TradeID;
	///�������
	TQdpFtdcOrderSysIDType	OrderSysID;
	///���ر������
	TQdpFtdcUserOrderLocalIDType	UserOrderLocalID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///��������
	TQdpFtdcDirectionType	Direction;
	///��ƽ��־
	TQdpFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdpFtdcHedgeFlagType	HedgeFlag;
	///�ɽ��۸�
	TQdpFtdcPriceType	TradePrice;
	///�ɽ�����
	TQdpFtdcVolumeType	TradeVolume;
	///�ɽ�ʱ��
	TQdpFtdcTimeType	TradeTime;
	///�����Ա���
	TQdpFtdcParticipantIDType	ClearingPartID;
	///�ɽ����
	TQdpFtdcMoneyType	TradeAmnt;
	///��¼���
	TQdpFtdcSequenceNoType	RecNum;
};

///����
struct CQdpFtdcOrderField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///ϵͳ�������
	TQdpFtdcOrderSysIDType	OrderSysID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�û�����
	TQdpFtdcUserIDType	UserID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///�û����ر�����
	TQdpFtdcUserOrderLocalIDType	UserOrderLocalID;
	///�۸�����
	TQdpFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TQdpFtdcDirectionType	Direction;
	///��ƽ��־
	TQdpFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TQdpFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TQdpFtdcPriceType	LimitPrice;
	///����
	TQdpFtdcVolumeType	Volume;
	///��Ч������
	TQdpFtdcTimeConditionType	TimeCondition;
	///GTD����
	TQdpFtdcDateType	GTDDate;
	///�ɽ�������
	TQdpFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TQdpFtdcVolumeType	MinVolume;
	///ֹ���
	TQdpFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TQdpFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TQdpFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TQdpFtdcBusinessUnitType	BusinessUnit;
	///�û��Զ�����
	TQdpFtdcCustomType	UserCustom;
	///Ӫҵ������
	TQdpFtdcBranchIDType	BranchID;
	///��¼���
	TQdpFtdcSequenceNoType	RecNum;
	///ҵ�����
	TQdpFtdcBusinessTypeType	BusinessType;
	///������
	TQdpFtdcTradingDayType	TradingDay;
	///��Ա���
	TQdpFtdcParticipantIDType	ParticipantID;
	///�ͻ���
	TQdpFtdcClientIDType	ClientID;
	///�µ�ϯλ��
	TQdpFtdcSeatIDType	SeatID;
	///����ʱ��
	TQdpFtdcTimeType	InsertTime;
	///���ر������
	TQdpFtdcOrderLocalIDType	OrderLocalID;
	///������Դ
	TQdpFtdcOrderSourceType	OrderSource;
	///����״̬
	TQdpFtdcOrderStatusType	OrderStatus;
	///����ʱ��
	TQdpFtdcTimeType	CancelTime;
	///�����û����
	TQdpFtdcUserIDType	CancelUserID;
	///��ɽ�����
	TQdpFtdcVolumeType	VolumeTraded;
	///ʣ������
	TQdpFtdcVolumeType	VolumeRemain;
	///ǰ�ñ��
	TQdpFtdcFrontIDType	FrontID;
	///�Ự���
	TQdpFtdcSessionIDType	SessionID;
};

///����������
struct CQdpFtdcFlowMessageCancelField
{
	///����ϵ�к�
	TQdpFtdcSequenceSeriesType	SequenceSeries;
	///������
	TQdpFtdcDateType	TradingDay;
	///�������Ĵ���
	TQdpFtdcDataCenterIDType	DataCenterID;
	///������ʼ���к�
	TQdpFtdcSequenceNoType	StartSequenceNo;
	///���˽������к�
	TQdpFtdcSequenceNoType	EndSequenceNo;
};

///��Ϣ�ַ�
struct CQdpFtdcDisseminationField
{
	///����ϵ�к�
	TQdpFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TQdpFtdcSequenceNoType	SequenceNo;
};

///�������
struct CQdpFtdcInvestorAccountDepositResField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///�ʽ��ʺ�
	TQdpFtdcAccountIDType	AccountID;
	///�ʽ���ˮ��
	TQdpFtdcAccountSeqNoType	AccountSeqNo;
	///�������������ʽ���ˮ��
	TQdpFtdcAccountSeqNoType	AccountInsideSeqNo;
	///���
	TQdpFtdcMoneyType	Amount;
	///�������
	TQdpFtdcAccountDirectionType	AmountDirection;
	///�����ʽ�
	TQdpFtdcMoneyType	Available;
	///����׼����
	TQdpFtdcMoneyType	Balance;
	///�û�����
	TQdpFtdcUserIDType	UserID;
};

///QDP������Ϣ֪ͨ
struct CQdpFtdcMessageNotifyInfoField
{
	///���͹�˾���
	TQdpFtdcBrokerIDType	BrokerID;
	///�޸��û����
	TQdpFtdcUserIDType	UserID;
	///Ͷ���߱��
	TQdpFtdcInvestorIDType	InvestorID;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///�ۼӴ���
	TQdpFtdcTotalNumsType	Nums;
	///ҵ�����
	TQdpFtdcBusinessTypeType	BusinessType;
	///������Ϣ
	TQdpFtdcErrorMsgType	WarnMsg;
};

///�����������
struct CQdpFtdcMarketDataBaseField
{
	///������
	TQdpFtdcTradingDayType	TradingDay;
	///���������
	TQdpFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQdpFtdcSettlementIDType	SettlementID;
	///�����
	TQdpFtdcPriceType	PreSettlementPrice;
	///������
	TQdpFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdpFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdpFtdcRatioType	PreDelta;
};

///���龲̬����
struct CQdpFtdcMarketDataStaticField
{
	///����
	TQdpFtdcPriceType	OpenPrice;
	///��߼�
	TQdpFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdpFtdcPriceType	LowestPrice;
	///������
	TQdpFtdcPriceType	ClosePrice;
	///��ͣ���
	TQdpFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdpFtdcPriceType	LowerLimitPrice;
	///�����
	TQdpFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQdpFtdcRatioType	CurrDelta;
};

///�������³ɽ�����
struct CQdpFtdcMarketDataLastMatchField
{
	///���¼�
	TQdpFtdcPriceType	LastPrice;
	///����
	TQdpFtdcVolumeType	Volume;
	///�ɽ����
	TQdpFtdcMoneyType	Turnover;
	///�ֲ���
	TQdpFtdcLargeVolumeType	OpenInterest;
};

///�������ż�����
struct CQdpFtdcMarketDataBestPriceField
{
	///�����һ
	TQdpFtdcPriceType	BidPrice1;
	///������һ
	TQdpFtdcVolumeType	BidVolume1;
	///������һ
	TQdpFtdcPriceType	AskPrice1;
	///������һ
	TQdpFtdcVolumeType	AskVolume1;
};

///�����������������
struct CQdpFtdcMarketDataBid23Field
{
	///����۶�
	TQdpFtdcPriceType	BidPrice2;
	///��������
	TQdpFtdcVolumeType	BidVolume2;
	///�������
	TQdpFtdcPriceType	BidPrice3;
	///��������
	TQdpFtdcVolumeType	BidVolume3;
};

///������������������
struct CQdpFtdcMarketDataAsk23Field
{
	///�����۶�
	TQdpFtdcPriceType	AskPrice2;
	///��������
	TQdpFtdcVolumeType	AskVolume2;
	///��������
	TQdpFtdcPriceType	AskPrice3;
	///��������
	TQdpFtdcVolumeType	AskVolume3;
};

///���������ġ�������
struct CQdpFtdcMarketDataBid45Field
{
	///�������
	TQdpFtdcPriceType	BidPrice4;
	///��������
	TQdpFtdcVolumeType	BidVolume4;
	///�������
	TQdpFtdcPriceType	BidPrice5;
	///��������
	TQdpFtdcVolumeType	BidVolume5;
};

///���������ġ�������
struct CQdpFtdcMarketDataAsk45Field
{
	///��������
	TQdpFtdcPriceType	AskPrice4;
	///��������
	TQdpFtdcVolumeType	AskVolume4;
	///��������
	TQdpFtdcPriceType	AskPrice5;
	///��������
	TQdpFtdcVolumeType	AskVolume5;
};

///�������ʱ������
struct CQdpFtdcMarketDataUpdateTimeField
{
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdpFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdpFtdcMillisecType	UpdateMillisec;
};

///�������
struct CQdpFtdcDepthMarketDataField
{
	///������
	TQdpFtdcTradingDayType	TradingDay;
	///���������
	TQdpFtdcSettlementGroupIDType	SettlementGroupID;
	///������
	TQdpFtdcSettlementIDType	SettlementID;
	///�����
	TQdpFtdcPriceType	PreSettlementPrice;
	///������
	TQdpFtdcPriceType	PreClosePrice;
	///��ֲ���
	TQdpFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TQdpFtdcRatioType	PreDelta;
	///����
	TQdpFtdcPriceType	OpenPrice;
	///��߼�
	TQdpFtdcPriceType	HighestPrice;
	///��ͼ�
	TQdpFtdcPriceType	LowestPrice;
	///������
	TQdpFtdcPriceType	ClosePrice;
	///��ͣ���
	TQdpFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TQdpFtdcPriceType	LowerLimitPrice;
	///�����
	TQdpFtdcPriceType	SettlementPrice;
	///����ʵ��
	TQdpFtdcRatioType	CurrDelta;
	///���¼�
	TQdpFtdcPriceType	LastPrice;
	///����
	TQdpFtdcVolumeType	Volume;
	///�ɽ����
	TQdpFtdcMoneyType	Turnover;
	///�ֲ���
	TQdpFtdcLargeVolumeType	OpenInterest;
	///�����һ
	TQdpFtdcPriceType	BidPrice1;
	///������һ
	TQdpFtdcVolumeType	BidVolume1;
	///������һ
	TQdpFtdcPriceType	AskPrice1;
	///������һ
	TQdpFtdcVolumeType	AskVolume1;
	///����۶�
	TQdpFtdcPriceType	BidPrice2;
	///��������
	TQdpFtdcVolumeType	BidVolume2;
	///�������
	TQdpFtdcPriceType	BidPrice3;
	///��������
	TQdpFtdcVolumeType	BidVolume3;
	///�����۶�
	TQdpFtdcPriceType	AskPrice2;
	///��������
	TQdpFtdcVolumeType	AskVolume2;
	///��������
	TQdpFtdcPriceType	AskPrice3;
	///��������
	TQdpFtdcVolumeType	AskVolume3;
	///�������
	TQdpFtdcPriceType	BidPrice4;
	///��������
	TQdpFtdcVolumeType	BidVolume4;
	///�������
	TQdpFtdcPriceType	BidPrice5;
	///��������
	TQdpFtdcVolumeType	BidVolume5;
	///��������
	TQdpFtdcPriceType	AskPrice4;
	///��������
	TQdpFtdcVolumeType	AskVolume4;
	///��������
	TQdpFtdcPriceType	AskPrice5;
	///��������
	TQdpFtdcVolumeType	AskVolume5;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TQdpFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TQdpFtdcMillisecType	UpdateMillisec;
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
};

///���ĺ�Լ�������Ϣ
struct CQdpFtdcSpecificInstrumentField
{
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
};

///�����ڴ������ѯ
struct CQdpFtdcShmDepthMarketDataField
{
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///IP��ַ
	TQdpFtdcIPAddressType	IPAddress;
	///���ĺ�
	TQdpFtdcTopicIDType	TopicID;
};

///����������
struct CQdpFtdcMarketDataExchangeIDField
{
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
};

///TOPIC��ѯ
struct CQdpFtdcTopicSearchField
{
	///���ĺ�
	TQdpFtdcTopicIDType	TopicID;
};

///��Լ״̬
struct CQdpFtdcQmdInstrumentStateField
{
	///����������
	TQdpFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TQdpFtdcInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TQdpFtdcInstrumentStatusType	InstrumentStatus;
};



#endif
