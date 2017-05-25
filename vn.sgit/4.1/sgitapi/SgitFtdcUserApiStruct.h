/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////

#if !defined(Sgit_FTDCSTRUCT_H)
#define Sgit_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SgitFtdcUserApiDataType.h"

///��Ϣ�ַ�
struct CSgitFtdcDisseminationField
{
	///����ϵ�к�
	TSgitFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TSgitFtdcSequenceNoType	SequenceNo;
};

///�û���¼����
struct CSgitFtdcReqUserLoginField
{
	///������
	TSgitFtdcDateType	TradingDay;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///����
	TSgitFtdcPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TSgitFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TSgitFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TSgitFtdcProtocolInfoType	ProtocolInfo;
	///Mac��ַ
	TSgitFtdcMacAddressType	MacAddress;
	///��̬����
	TSgitFtdcPasswordType	OneTimePassword;
	///�ն�IP��ַ
	TSgitFtdcIPAddressType	ClientIPAddress;
};

///�û���¼Ӧ��
struct CSgitFtdcRspUserLoginField
{
	///������
	TSgitFtdcDateType	TradingDay;
	///��¼�ɹ�ʱ��
	TSgitFtdcTimeType	LoginTime;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///����ϵͳ����
	TSgitFtdcSystemNameType	SystemName;
	///ǰ�ñ��
	TSgitFtdcFrontIDType	FrontID;
	///�Ự���
	TSgitFtdcSessionIDType	SessionID;
	///��󱨵�����
	TSgitFtdcOrderRefType	MaxOrderRef;
	///������ʱ��
	TSgitFtdcTimeType	SHFETime;
	///������ʱ��
	TSgitFtdcTimeType	DCETime;
	///֣����ʱ��
	TSgitFtdcTimeType	CZCETime;
	///�н���ʱ��
	TSgitFtdcTimeType	FFEXTime;
};

///�û��ǳ�����
struct CSgitFtdcUserLogoutField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
};

///ǿ�ƽ���Ա�˳�
struct CSgitFtdcForceUserLogoutField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
};

///�ͻ�����֤����
struct CSgitFtdcReqAuthenticateField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///�û��˲�Ʒ��Ϣ
	TSgitFtdcProductInfoType	UserProductInfo;
	///��֤��
	TSgitFtdcAuthCodeType	AuthCode;
};

///�ͻ�����֤��Ӧ
struct CSgitFtdcRspAuthenticateField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///�û��˲�Ʒ��Ϣ
	TSgitFtdcProductInfoType	UserProductInfo;
};

///�ͻ�����֤��Ϣ
struct CSgitFtdcAuthenticationInfoField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///�û��˲�Ʒ��Ϣ
	TSgitFtdcProductInfoType	UserProductInfo;
	///��֤��Ϣ
	TSgitFtdcAuthInfoType	AuthInfo;
	///�Ƿ�Ϊ��֤���
	TSgitFtdcBoolType	IsResult;
};

///����ת�ʱ���ͷ
struct CSgitFtdcTransferHeaderField
{
	///�汾�ţ�������1.0
	TSgitFtdcVersionType	Version;
	///���״��룬����
	TSgitFtdcTradeCodeType	TradeCode;
	///�������ڣ������ʽ��yyyymmdd
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ�䣬�����ʽ��hhmmss
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ�ţ�N/A
	TSgitFtdcTradeSerialType	TradeSerial;
	///�ڻ���˾���룬����
	TSgitFtdcFutureIDType	FutureID;
	///���д��룬���ݲ�ѯ���еõ�������
	TSgitFtdcBankIDType	BankID;
	///���з����Ĵ��룬���ݲ�ѯ���еõ�������
	TSgitFtdcBankBrchIDType	BankBrchID;
	///����Ա��N/A
	TSgitFtdcOperNoType	OperNo;
	///�����豸���ͣ�N/A
	TSgitFtdcDeviceIDType	DeviceID;
	///��¼����N/A
	TSgitFtdcRecordNumType	RecordNum;
	///�Ự��ţ�N/A
	TSgitFtdcSessionIDType	SessionID;
	///�����ţ�N/A
	TSgitFtdcRequestIDType	RequestID;
};

///�����ʽ�ת�ڻ�����TradeCode=202001
struct CSgitFtdcTransferBankToFutureReqField
{
	///�ڻ��ʽ��˻�
	TSgitFtdcAccountIDType	FutureAccount;
	///�����־
	TSgitFtdcFuturePwdFlagType	FuturePwdFlag;
	///����
	TSgitFtdcFutureAccPwdType	FutureAccPwd;
	///ת�˽��
	TSgitFtdcMoneyType	TradeAmt;
	///�ͻ�������
	TSgitFtdcMoneyType	CustFee;
	///���֣�RMB-����� USD-��Բ HKD-��Ԫ
	TSgitFtdcCurrencyCodeType	CurrencyCode;
};

///�����ʽ�ת�ڻ�������Ӧ
struct CSgitFtdcTransferBankToFutureRspField
{
	///��Ӧ����
	TSgitFtdcRetCodeType	RetCode;
	///��Ӧ��Ϣ
	TSgitFtdcRetInfoType	RetInfo;
	///�ʽ��˻�
	TSgitFtdcAccountIDType	FutureAccount;
	///ת�ʽ��
	TSgitFtdcMoneyType	TradeAmt;
	///Ӧ�տͻ�������
	TSgitFtdcMoneyType	CustFee;
	///����
	TSgitFtdcCurrencyCodeType	CurrencyCode;
};

///�ڻ��ʽ�ת��������TradeCode=202002
struct CSgitFtdcTransferFutureToBankReqField
{
	///�ڻ��ʽ��˻�
	TSgitFtdcAccountIDType	FutureAccount;
	///�����־
	TSgitFtdcFuturePwdFlagType	FuturePwdFlag;
	///����
	TSgitFtdcFutureAccPwdType	FutureAccPwd;
	///ת�˽��
	TSgitFtdcMoneyType	TradeAmt;
	///�ͻ�������
	TSgitFtdcMoneyType	CustFee;
	///���֣�RMB-����� USD-��Բ HKD-��Ԫ
	TSgitFtdcCurrencyCodeType	CurrencyCode;
};

///�ڻ��ʽ�ת����������Ӧ
struct CSgitFtdcTransferFutureToBankRspField
{
	///��Ӧ����
	TSgitFtdcRetCodeType	RetCode;
	///��Ӧ��Ϣ
	TSgitFtdcRetInfoType	RetInfo;
	///�ʽ��˻�
	TSgitFtdcAccountIDType	FutureAccount;
	///ת�ʽ��
	TSgitFtdcMoneyType	TradeAmt;
	///Ӧ�տͻ�������
	TSgitFtdcMoneyType	CustFee;
	///����
	TSgitFtdcCurrencyCodeType	CurrencyCode;
};

///��ѯ�����ʽ�����TradeCode=204002
struct CSgitFtdcTransferQryBankReqField
{
	///�ڻ��ʽ��˻�
	TSgitFtdcAccountIDType	FutureAccount;
	///�����־
	TSgitFtdcFuturePwdFlagType	FuturePwdFlag;
	///����
	TSgitFtdcFutureAccPwdType	FutureAccPwd;
	///���֣�RMB-����� USD-��Բ HKD-��Ԫ
	TSgitFtdcCurrencyCodeType	CurrencyCode;
};

///��ѯ�����ʽ�������Ӧ
struct CSgitFtdcTransferQryBankRspField
{
	///��Ӧ����
	TSgitFtdcRetCodeType	RetCode;
	///��Ӧ��Ϣ
	TSgitFtdcRetInfoType	RetInfo;
	///�ʽ��˻�
	TSgitFtdcAccountIDType	FutureAccount;
	///�������
	TSgitFtdcMoneyType	TradeAmt;
	///���п������
	TSgitFtdcMoneyType	UseAmt;
	///���п�ȡ���
	TSgitFtdcMoneyType	FetchAmt;
	///����
	TSgitFtdcCurrencyCodeType	CurrencyCode;
};

///��ѯ���н�����ϸ����TradeCode=204999
struct CSgitFtdcTransferQryDetailReqField
{
	///�ڻ��ʽ��˻�
	TSgitFtdcAccountIDType	FutureAccount;
};

///��ѯ���н�����ϸ������Ӧ
struct CSgitFtdcTransferQryDetailRspField
{
	///��������
	TSgitFtdcDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///���״���
	TSgitFtdcTradeCodeType	TradeCode;
	///�ڻ���ˮ��
	TSgitFtdcTradeSerialNoType	FutureSerial;
	///�ڻ���˾����
	TSgitFtdcFutureIDType	FutureID;
	///�ʽ��ʺ�
	TSgitFtdcFutureAccountType	FutureAccount;
	///������ˮ��
	TSgitFtdcTradeSerialNoType	BankSerial;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з����Ĵ���
	TSgitFtdcBankBrchIDType	BankBrchID;
	///�����˺�
	TSgitFtdcBankAccountType	BankAccount;
	///֤������
	TSgitFtdcCertCodeType	CertCode;
	///���Ҵ���
	TSgitFtdcCurrencyCodeType	CurrencyCode;
	///�������
	TSgitFtdcMoneyType	TxAmount;
	///��Ч��־
	TSgitFtdcTransferValidFlagType	Flag;
};

///��Ӧ��Ϣ
struct CSgitFtdcRspInfoField
{
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///������
struct CSgitFtdcExchangeField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///����������
	TSgitFtdcExchangeNameType	ExchangeName;
	///����������
	TSgitFtdcExchangePropertyType	ExchangeProperty;
};

///��Ʒ
struct CSgitFtdcProductField
{
	///��Ʒ����
	TSgitFtdcInstrumentIDType	ProductID;
	///��Ʒ����
	TSgitFtdcProductNameType	ProductName;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Ʒ����
	TSgitFtdcProductClassType	ProductClass;
	///��Լ��������
	TSgitFtdcVolumeMultipleType	VolumeMultiple;
	///��С�䶯��λ
	TSgitFtdcPriceType	PriceTick;
	///�м۵�����µ���
	TSgitFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TSgitFtdcVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	TSgitFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TSgitFtdcVolumeType	MinLimitOrderVolume;
	///�ֲ�����
	TSgitFtdcPositionTypeType	PositionType;
	///�ֲ���������
	TSgitFtdcPositionDateTypeType	PositionDateType;
};

///��Լ
struct CSgitFtdcInstrumentField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TSgitFtdcInstrumentNameType	InstrumentName;
	///��Լ�ڽ������Ĵ���
	TSgitFtdcExchangeInstIDType	ExchangeInstID;
	///��Ʒ����
	TSgitFtdcInstrumentIDType	ProductID;
	///��Ʒ����
	TSgitFtdcProductClassType	ProductClass;
	///�������
	TSgitFtdcYearType	DeliveryYear;
	///������
	TSgitFtdcMonthType	DeliveryMonth;
	///�м۵�����µ���
	TSgitFtdcVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TSgitFtdcVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	TSgitFtdcVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TSgitFtdcVolumeType	MinLimitOrderVolume;
	///��Լ��������
	TSgitFtdcVolumeMultipleType	VolumeMultiple;
	///��С�䶯��λ
	TSgitFtdcPriceType	PriceTick;
	///������
	TSgitFtdcDateType	CreateDate;
	///������
	TSgitFtdcDateType	OpenDate;
	///������
	TSgitFtdcDateType	ExpireDate;
	///��ʼ������
	TSgitFtdcDateType	StartDelivDate;
	///����������
	TSgitFtdcDateType	EndDelivDate;
	///��Լ��������״̬
	TSgitFtdcInstLifePhaseType	InstLifePhase;
	///��ǰ�Ƿ���
	TSgitFtdcBoolType	IsTrading;
	///�ֲ�����
	TSgitFtdcPositionTypeType	PositionType;
	///�ֲ���������
	TSgitFtdcPositionDateTypeType	PositionDateType;
	///��ͷ��֤����
	TSgitFtdcRatioType	LongMarginRatio;
	///��ͷ��֤����
	TSgitFtdcRatioType	ShortMarginRatio;
};

///���͹�˾
struct CSgitFtdcBrokerField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///���͹�˾���
	TSgitFtdcBrokerAbbrType	BrokerAbbr;
	///���͹�˾����
	TSgitFtdcBrokerNameType	BrokerName;
	///�Ƿ��Ծ
	TSgitFtdcBoolType	IsActive;
};

///����������Ա
struct CSgitFtdcTraderField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///����
	TSgitFtdcPasswordType	Password;
	///��װ����
	TSgitFtdcInstallCountType	InstallCount;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
};

///Ͷ����
struct CSgitFtdcInvestorField
{
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���߷������
	TSgitFtdcInvestorIDType	InvestorGroupID;
	///Ͷ��������
	TSgitFtdcPartyNameType	InvestorName;
	///֤������
	TSgitFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ƿ��Ծ
	TSgitFtdcBoolType	IsActive;
	///��ϵ�绰
	TSgitFtdcTelephoneType	Telephone;
	///ͨѶ��ַ
	TSgitFtdcAddressType	Address;
	///��������
	TSgitFtdcDateType	OpenDate;
	///�ֻ�
	TSgitFtdcMobileType	Mobile;
	///��������ģ�����
	TSgitFtdcInvestorIDType	CommModelID;
};

///���ױ���
struct CSgitFtdcTradingCodeField
{
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�ͻ�����
	TSgitFtdcClientIDType	ClientID;
	///�Ƿ��Ծ
	TSgitFtdcBoolType	IsActive;
	///���ױ�������
	TSgitFtdcClientIDTypeType	ClientIDType;
};

///��Ա����;��͹�˾������ձ�
struct CSgitFtdcPartBrokerField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///�Ƿ��Ծ
	TSgitFtdcBoolType	IsActive;
};

///�����û�
struct CSgitFtdcSuperUserField
{
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///�û�����
	TSgitFtdcUserNameType	UserName;
	///����
	TSgitFtdcPasswordType	Password;
	///�Ƿ��Ծ
	TSgitFtdcBoolType	IsActive;
};

///�����û�����Ȩ��
struct CSgitFtdcSuperUserFunctionField
{
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///���ܴ���
	TSgitFtdcFunctionCodeType	FunctionCode;
};

///Ͷ������
struct CSgitFtdcInvestorGroupField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���߷������
	TSgitFtdcInvestorIDType	InvestorGroupID;
	///Ͷ���߷�������
	TSgitFtdcInvestorGroupNameType	InvestorGroupName;
};

///�ʽ��˻�
struct CSgitFtdcTradingAccountField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ϴ���Ѻ���
	TSgitFtdcMoneyType	PreMortgage;
	///�ϴ����ö��
	TSgitFtdcMoneyType	PreCredit;
	///�ϴδ���
	TSgitFtdcMoneyType	PreDeposit;
	///�ϴν���׼����
	TSgitFtdcMoneyType	PreBalance;
	///�ϴ�ռ�õı�֤��
	TSgitFtdcMoneyType	PreMargin;
	///��Ϣ����
	TSgitFtdcMoneyType	InterestBase;
	///��Ϣ����
	TSgitFtdcMoneyType	Interest;
	///�����
	TSgitFtdcMoneyType	Deposit;
	///������
	TSgitFtdcMoneyType	Withdraw;
	///����ı�֤��
	TSgitFtdcMoneyType	FrozenMargin;
	///������ʽ�
	TSgitFtdcMoneyType	FrozenCash;
	///�����������
	TSgitFtdcMoneyType	FrozenCommission;
	///��ǰ��֤���ܶ�
	TSgitFtdcMoneyType	CurrMargin;
	///�ʽ���
	TSgitFtdcMoneyType	CashIn;
	///������
	TSgitFtdcMoneyType	Commission;
	///ƽ��ӯ��
	TSgitFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TSgitFtdcMoneyType	PositionProfit;
	///�ڻ�����׼����
	TSgitFtdcMoneyType	Balance;
	///�����ʽ�
	TSgitFtdcMoneyType	Available;
	///��ȡ�ʽ�
	TSgitFtdcMoneyType	WithdrawQuota;
	///����׼����
	TSgitFtdcMoneyType	Reserve;
	///������
	TSgitFtdcDateType	TradingDay;
	///������
	TSgitFtdcSettlementIDType	SettlementID;
	///���ö��
	TSgitFtdcMoneyType	Credit;
	///��Ѻ���
	TSgitFtdcMoneyType	Mortgage;
	///��������֤��
	TSgitFtdcMoneyType	ExchangeMargin;
	///Ͷ���߽��֤��
	TSgitFtdcMoneyType	DeliveryMargin;
	///���������֤��
	TSgitFtdcMoneyType	ExchangeDeliveryMargin;
};

///Ͷ���ֲ߳�
struct CSgitFtdcInvestorPositionField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///�ֲֶ�շ���
	TSgitFtdcPosiDirectionType	PosiDirection;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
	///�ֲ�����
	TSgitFtdcPositionDateType	PositionDate;
	///���ճֲ�
	TSgitFtdcVolumeType	YdPosition;
	///���ճֲ�
	TSgitFtdcVolumeType	Position;
	///��ͷ����
	TSgitFtdcVolumeType	LongFrozen;
	///��ͷ����
	TSgitFtdcVolumeType	ShortFrozen;
	///���ֶ�����
	TSgitFtdcMoneyType	LongFrozenAmount;
	///���ֶ�����
	TSgitFtdcMoneyType	ShortFrozenAmount;
	///������
	TSgitFtdcVolumeType	OpenVolume;
	///ƽ����
	TSgitFtdcVolumeType	CloseVolume;
	///���ֽ��
	TSgitFtdcMoneyType	OpenAmount;
	///ƽ�ֽ��
	TSgitFtdcMoneyType	CloseAmount;
	///�ֲֳɱ�
	TSgitFtdcMoneyType	PositionCost;
	///�ϴ�ռ�õı�֤��
	TSgitFtdcMoneyType	PreMargin;
	///ռ�õı�֤��
	TSgitFtdcMoneyType	UseMargin;
	///����ı�֤��
	TSgitFtdcMoneyType	FrozenMargin;
	///������ʽ�
	TSgitFtdcMoneyType	FrozenCash;
	///�����������
	TSgitFtdcMoneyType	FrozenCommission;
	///�ʽ���
	TSgitFtdcMoneyType	CashIn;
	///������
	TSgitFtdcMoneyType	Commission;
	///ƽ��ӯ��
	TSgitFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TSgitFtdcMoneyType	PositionProfit;
	///�ϴν����
	TSgitFtdcPriceType	PreSettlementPrice;
	///���ν����
	TSgitFtdcPriceType	SettlementPrice;
	///������
	TSgitFtdcDateType	TradingDay;
	///������
	TSgitFtdcSettlementIDType	SettlementID;
	///���ֳɱ�
	TSgitFtdcMoneyType	OpenCost;
	///��������֤��
	TSgitFtdcMoneyType	ExchangeMargin;
	///��ϳɽ��γɵĳֲ�
	TSgitFtdcVolumeType	CombPosition;
	///��϶�ͷ����
	TSgitFtdcVolumeType	CombLongFrozen;
	///��Ͽ�ͷ����
	TSgitFtdcVolumeType	CombShortFrozen;
	///���ն���ƽ��ӯ��
	TSgitFtdcMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TSgitFtdcMoneyType	CloseProfitByTrade;
	///���ճֲ�
	TSgitFtdcVolumeType	TodayPosition;
	///��֤����
	TSgitFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TSgitFtdcRatioType	MarginRateByVolume;
};

///��Լ��֤����
struct CSgitFtdcInstrumentMarginRateField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TSgitFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TSgitFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TSgitFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TSgitFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TSgitFtdcMoneyType	ShortMarginRatioByVolume;
	///�Ƿ���Խ�������ȡ
	TSgitFtdcBoolType	IsRelative;
};

///��Լ��������
struct CSgitFtdcInstrumentCommissionRateField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TSgitFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///������������
	TSgitFtdcRatioType	OpenRatioByMoney;
	///����������
	TSgitFtdcRatioType	OpenRatioByVolume;
	///ƽ����������
	TSgitFtdcRatioType	CloseRatioByMoney;
	///ƽ��������
	TSgitFtdcRatioType	CloseRatioByVolume;
	///ƽ����������
	TSgitFtdcRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TSgitFtdcRatioType	CloseTodayRatioByVolume;
};

///�������
struct CSgitFtdcDepthMarketDataField
{
	///������
	TSgitFtdcDateType	TradingDay;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TSgitFtdcExchangeInstIDType	ExchangeInstID;
	///���¼�
	TSgitFtdcPriceType	LastPrice;
	///�ϴν����
	TSgitFtdcPriceType	PreSettlementPrice;
	///������
	TSgitFtdcPriceType	PreClosePrice;
	///��ֲ���
	TSgitFtdcLargeVolumeType	PreOpenInterest;
	///����
	TSgitFtdcPriceType	OpenPrice;
	///��߼�
	TSgitFtdcPriceType	HighestPrice;
	///��ͼ�
	TSgitFtdcPriceType	LowestPrice;
	///����
	TSgitFtdcVolumeType	Volume;
	///�ɽ����
	TSgitFtdcMoneyType	Turnover;
	///�ֲ���
	TSgitFtdcLargeVolumeType	OpenInterest;
	///������
	TSgitFtdcPriceType	ClosePrice;
	///���ν����
	TSgitFtdcPriceType	SettlementPrice;
	///��ͣ���
	TSgitFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TSgitFtdcPriceType	LowerLimitPrice;
	///����ʵ��
	TSgitFtdcRatioType	PreDelta;
	///����ʵ��
	TSgitFtdcRatioType	CurrDelta;
	///����޸�ʱ��
	TSgitFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TSgitFtdcMillisecType	UpdateMillisec;
	///�����һ
	TSgitFtdcPriceType	BidPrice1;
	///������һ
	TSgitFtdcVolumeType	BidVolume1;
	///������һ
	TSgitFtdcPriceType	AskPrice1;
	///������һ
	TSgitFtdcVolumeType	AskVolume1;
	///����۶�
	TSgitFtdcPriceType	BidPrice2;
	///��������
	TSgitFtdcVolumeType	BidVolume2;
	///�����۶�
	TSgitFtdcPriceType	AskPrice2;
	///��������
	TSgitFtdcVolumeType	AskVolume2;
	///�������
	TSgitFtdcPriceType	BidPrice3;
	///��������
	TSgitFtdcVolumeType	BidVolume3;
	///��������
	TSgitFtdcPriceType	AskPrice3;
	///��������
	TSgitFtdcVolumeType	AskVolume3;
	///�������
	TSgitFtdcPriceType	BidPrice4;
	///��������
	TSgitFtdcVolumeType	BidVolume4;
	///��������
	TSgitFtdcPriceType	AskPrice4;
	///��������
	TSgitFtdcVolumeType	AskVolume4;
	///�������
	TSgitFtdcPriceType	BidPrice5;
	///��������
	TSgitFtdcVolumeType	BidVolume5;
	///��������
	TSgitFtdcPriceType	AskPrice5;
	///��������
	TSgitFtdcVolumeType	AskVolume5;
	///���վ���
	TSgitFtdcPriceType	AveragePrice;
};

///Ͷ���ߺ�Լ����Ȩ��
struct CSgitFtdcInstrumentTradingRightField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TSgitFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///����Ȩ��
	TSgitFtdcTradingRightType	TradingRight;
};

///���͹�˾�û�
struct CSgitFtdcBrokerUserField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///�û�����
	TSgitFtdcUserNameType	UserName;
	///�û�����
	TSgitFtdcUserTypeType	UserType;
	///�Ƿ��Ծ
	TSgitFtdcBoolType	IsActive;
	///�Ƿ�ʹ������
	TSgitFtdcBoolType	IsUsingOTP;
};

///���͹�˾�û�����
struct CSgitFtdcBrokerUserPasswordField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///����
	TSgitFtdcPasswordType	Password;
};

///���͹�˾�û�����Ȩ��
struct CSgitFtdcBrokerUserFunctionField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///���͹�˾���ܴ���
	TSgitFtdcBrokerFunctionCodeType	BrokerFunctionCode;
};

///����������Ա���̻�
struct CSgitFtdcTraderOfferField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///����
	TSgitFtdcPasswordType	Password;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///���ر������
	TSgitFtdcOrderLocalIDType	OrderLocalID;
	///����������Ա����״̬
	TSgitFtdcTraderConnectStatusType	TraderConnectStatus;
	///�����������������
	TSgitFtdcDateType	ConnectRequestDate;
	///�������������ʱ��
	TSgitFtdcTimeType	ConnectRequestTime;
	///�ϴα�������
	TSgitFtdcDateType	LastReportDate;
	///�ϴα���ʱ��
	TSgitFtdcTimeType	LastReportTime;
	///�����������
	TSgitFtdcDateType	ConnectDate;
	///�������ʱ��
	TSgitFtdcTimeType	ConnectTime;
	///��������
	TSgitFtdcDateType	StartDate;
	///����ʱ��
	TSgitFtdcTimeType	StartTime;
	///������
	TSgitFtdcDateType	TradingDay;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///��ϯλ���ɽ����
	TSgitFtdcTradeIDType	MaxTradeID;
	///��ϯλ��󱨵�����
	TSgitFtdcReturnCodeType	MaxOrderMessageReference;
};

///Ͷ���߽�����
struct CSgitFtdcSettlementInfoField
{
	///������
	TSgitFtdcDateType	TradingDay;
	///������
	TSgitFtdcSettlementIDType	SettlementID;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///���
	TSgitFtdcSequenceNoType	SequenceNo;
	///��Ϣ����
	TSgitFtdcContentType	Content;
};

///��Լ��֤���ʵ���
struct CSgitFtdcInstrumentMarginRateAdjustField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TSgitFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TSgitFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TSgitFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TSgitFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TSgitFtdcMoneyType	ShortMarginRatioByVolume;
	///�Ƿ���Խ�������ȡ
	TSgitFtdcBoolType	IsRelative;
};

///��������֤����
struct CSgitFtdcExchangeMarginRateField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TSgitFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TSgitFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TSgitFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TSgitFtdcMoneyType	ShortMarginRatioByVolume;
};

///��������֤���ʵ���
struct CSgitFtdcExchangeMarginRateAdjustField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
	///���潻����Ͷ���߶�ͷ��֤����
	TSgitFtdcRatioType	LongMarginRatioByMoney;
	///���潻����Ͷ���߶�ͷ��֤���
	TSgitFtdcMoneyType	LongMarginRatioByVolume;
	///���潻����Ͷ���߿�ͷ��֤����
	TSgitFtdcRatioType	ShortMarginRatioByMoney;
	///���潻����Ͷ���߿�ͷ��֤���
	TSgitFtdcMoneyType	ShortMarginRatioByVolume;
	///��������ͷ��֤����
	TSgitFtdcRatioType	ExchLongMarginRatioByMoney;
	///��������ͷ��֤���
	TSgitFtdcMoneyType	ExchLongMarginRatioByVolume;
	///��������ͷ��֤����
	TSgitFtdcRatioType	ExchShortMarginRatioByMoney;
	///��������ͷ��֤���
	TSgitFtdcMoneyType	ExchShortMarginRatioByVolume;
	///�����潻����Ͷ���߶�ͷ��֤����
	TSgitFtdcRatioType	NoLongMarginRatioByMoney;
	///�����潻����Ͷ���߶�ͷ��֤���
	TSgitFtdcMoneyType	NoLongMarginRatioByVolume;
	///�����潻����Ͷ���߿�ͷ��֤����
	TSgitFtdcRatioType	NoShortMarginRatioByMoney;
	///�����潻����Ͷ���߿�ͷ��֤���
	TSgitFtdcMoneyType	NoShortMarginRatioByVolume;
};

///��������
struct CSgitFtdcSettlementRefField
{
	///������
	TSgitFtdcDateType	TradingDay;
	///������
	TSgitFtdcSettlementIDType	SettlementID;
};

///��ǰʱ��
struct CSgitFtdcCurrentTimeField
{
	///��ǰ����
	TSgitFtdcDateType	CurrDate;
	///��ǰʱ��
	TSgitFtdcTimeType	CurrTime;
	///��ǰʱ�䣨���룩
	TSgitFtdcMillisecType	CurrMillisec;
};

///ͨѶ�׶�
struct CSgitFtdcCommPhaseField
{
	///������
	TSgitFtdcDateType	TradingDay;
	///ͨѶʱ�α��
	TSgitFtdcCommPhaseNoType	CommPhaseNo;
};

///��¼��Ϣ
struct CSgitFtdcLoginInfoField
{
	///ǰ�ñ��
	TSgitFtdcFrontIDType	FrontID;
	///�Ự���
	TSgitFtdcSessionIDType	SessionID;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///��¼����
	TSgitFtdcDateType	LoginDate;
	///��¼ʱ��
	TSgitFtdcTimeType	LoginTime;
	///IP��ַ
	TSgitFtdcIPAddressType	IPAddress;
	///�û��˲�Ʒ��Ϣ
	TSgitFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TSgitFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TSgitFtdcProtocolInfoType	ProtocolInfo;
	///ϵͳ����
	TSgitFtdcSystemNameType	SystemName;
	///����
	TSgitFtdcPasswordType	Password;
	///��󱨵�����
	TSgitFtdcOrderRefType	MaxOrderRef;
	///������ʱ��
	TSgitFtdcTimeType	SHFETime;
	///������ʱ��
	TSgitFtdcTimeType	DCETime;
	///֣����ʱ��
	TSgitFtdcTimeType	CZCETime;
	///�н���ʱ��
	TSgitFtdcTimeType	FFEXTime;
	///Mac��ַ
	TSgitFtdcMacAddressType	MacAddress;
	///��̬����
	TSgitFtdcPasswordType	OneTimePassword;
};

///��¼��Ϣ
struct CSgitFtdcLogoutAllField
{
	///ǰ�ñ��
	TSgitFtdcFrontIDType	FrontID;
	///�Ự���
	TSgitFtdcSessionIDType	SessionID;
	///ϵͳ����
	TSgitFtdcSystemNameType	SystemName;
};

///ǰ��״̬
struct CSgitFtdcFrontStatusField
{
	///ǰ�ñ��
	TSgitFtdcFrontIDType	FrontID;
	///�ϴα�������
	TSgitFtdcDateType	LastReportDate;
	///�ϴα���ʱ��
	TSgitFtdcTimeType	LastReportTime;
	///�Ƿ��Ծ
	TSgitFtdcBoolType	IsActive;
};

///�û�������
struct CSgitFtdcUserPasswordUpdateField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///ԭ���Ŀ���
	TSgitFtdcPasswordType	OldPassword;
	///�µĿ���
	TSgitFtdcPasswordType	NewPassword;
};

///���뱨��
struct CSgitFtdcInputOrderField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///��������
	TSgitFtdcOrderRefType	OrderRef;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///�����۸�����
	TSgitFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TSgitFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TSgitFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TSgitFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TSgitFtdcPriceType	LimitPrice;
	///����
	TSgitFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TSgitFtdcTimeConditionType	TimeCondition;
	///GTD����
	TSgitFtdcDateType	GTDDate;
	///�ɽ�������
	TSgitFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TSgitFtdcVolumeType	MinVolume;
	///��������
	TSgitFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TSgitFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TSgitFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TSgitFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TSgitFtdcBusinessUnitType	BusinessUnit;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///�û�ǿ����־
	TSgitFtdcBoolType	UserForceClose;
};

///����
struct CSgitFtdcOrderField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///��������
	TSgitFtdcOrderRefType	OrderRef;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///�����۸�����
	TSgitFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TSgitFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TSgitFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TSgitFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TSgitFtdcPriceType	LimitPrice;
	///����
	TSgitFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TSgitFtdcTimeConditionType	TimeCondition;
	///GTD����
	TSgitFtdcDateType	GTDDate;
	///�ɽ�������
	TSgitFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TSgitFtdcVolumeType	MinVolume;
	///��������
	TSgitFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TSgitFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TSgitFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TSgitFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TSgitFtdcBusinessUnitType	BusinessUnit;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///���ر������
	TSgitFtdcOrderLocalIDType	OrderLocalID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TSgitFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TSgitFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�����ύ״̬
	TSgitFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TSgitFtdcSequenceNoType	NotifySequence;
	///������
	TSgitFtdcDateType	TradingDay;
	///������
	TSgitFtdcSettlementIDType	SettlementID;
	///�������
	TSgitFtdcOrderSysIDType	OrderSysID;
	///������Դ
	TSgitFtdcOrderSourceType	OrderSource;
	///����״̬
	TSgitFtdcOrderStatusType	OrderStatus;
	///��������
	TSgitFtdcOrderTypeType	OrderType;
	///��ɽ�����
	TSgitFtdcVolumeType	VolumeTraded;
	///ʣ������
	TSgitFtdcVolumeType	VolumeTotal;
	///��������
	TSgitFtdcDateType	InsertDate;
	///ί��ʱ��
	TSgitFtdcTimeType	InsertTime;
	///����ʱ��
	TSgitFtdcTimeType	ActiveTime;
	///����ʱ��
	TSgitFtdcTimeType	SuspendTime;
	///����޸�ʱ��
	TSgitFtdcTimeType	UpdateTime;
	///����ʱ��
	TSgitFtdcTimeType	CancelTime;
	///����޸Ľ���������Ա����
	TSgitFtdcTraderIDType	ActiveTraderID;
	///�����Ա���
	TSgitFtdcParticipantIDType	ClearingPartID;
	///���
	TSgitFtdcSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TSgitFtdcFrontIDType	FrontID;
	///�Ự���
	TSgitFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TSgitFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TSgitFtdcErrorMsgType	StatusMsg;
	///�û�ǿ����־
	TSgitFtdcBoolType	UserForceClose;
	///�����û�����
	TSgitFtdcUserIDType	ActiveUserID;
	///���͹�˾�������
	TSgitFtdcSequenceNoType	BrokerOrderSeq;
	///��ر���
	TSgitFtdcOrderSysIDType	RelativeOrderSysID;
};

///����������
struct CSgitFtdcExchangeOrderField
{
	///�����۸�����
	TSgitFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TSgitFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TSgitFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TSgitFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TSgitFtdcPriceType	LimitPrice;
	///����
	TSgitFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TSgitFtdcTimeConditionType	TimeCondition;
	///GTD����
	TSgitFtdcDateType	GTDDate;
	///�ɽ�������
	TSgitFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TSgitFtdcVolumeType	MinVolume;
	///��������
	TSgitFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TSgitFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TSgitFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TSgitFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TSgitFtdcBusinessUnitType	BusinessUnit;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///���ر������
	TSgitFtdcOrderLocalIDType	OrderLocalID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TSgitFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TSgitFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�����ύ״̬
	TSgitFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TSgitFtdcSequenceNoType	NotifySequence;
	///������
	TSgitFtdcDateType	TradingDay;
	///������
	TSgitFtdcSettlementIDType	SettlementID;
	///�������
	TSgitFtdcOrderSysIDType	OrderSysID;
	///������Դ
	TSgitFtdcOrderSourceType	OrderSource;
	///����״̬
	TSgitFtdcOrderStatusType	OrderStatus;
	///��������
	TSgitFtdcOrderTypeType	OrderType;
	///��ɽ�����
	TSgitFtdcVolumeType	VolumeTraded;
	///ʣ������
	TSgitFtdcVolumeType	VolumeTotal;
	///��������
	TSgitFtdcDateType	InsertDate;
	///ί��ʱ��
	TSgitFtdcTimeType	InsertTime;
	///����ʱ��
	TSgitFtdcTimeType	ActiveTime;
	///����ʱ��
	TSgitFtdcTimeType	SuspendTime;
	///����޸�ʱ��
	TSgitFtdcTimeType	UpdateTime;
	///����ʱ��
	TSgitFtdcTimeType	CancelTime;
	///����޸Ľ���������Ա����
	TSgitFtdcTraderIDType	ActiveTraderID;
	///�����Ա���
	TSgitFtdcParticipantIDType	ClearingPartID;
	///���
	TSgitFtdcSequenceNoType	SequenceNo;
};

///��������������ʧ��
struct CSgitFtdcExchangeOrderInsertErrorField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///���ر������
	TSgitFtdcOrderLocalIDType	OrderLocalID;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///���뱨������
struct CSgitFtdcInputOrderActionField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///������������
	TSgitFtdcOrderActionRefType	OrderActionRef;
	///��������
	TSgitFtdcOrderRefType	OrderRef;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TSgitFtdcFrontIDType	FrontID;
	///�Ự���
	TSgitFtdcSessionIDType	SessionID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�������
	TSgitFtdcOrderSysIDType	OrderSysID;
	///������־
	TSgitFtdcActionFlagType	ActionFlag;
	///�۸�
	TSgitFtdcPriceType	LimitPrice;
	///�����仯
	TSgitFtdcVolumeType	VolumeChange;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
};

///��������
struct CSgitFtdcOrderActionField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///������������
	TSgitFtdcOrderActionRefType	OrderActionRef;
	///��������
	TSgitFtdcOrderRefType	OrderRef;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TSgitFtdcFrontIDType	FrontID;
	///�Ự���
	TSgitFtdcSessionIDType	SessionID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�������
	TSgitFtdcOrderSysIDType	OrderSysID;
	///������־
	TSgitFtdcActionFlagType	ActionFlag;
	///�۸�
	TSgitFtdcPriceType	LimitPrice;
	///�����仯
	TSgitFtdcVolumeType	VolumeChange;
	///��������
	TSgitFtdcDateType	ActionDate;
	///����ʱ��
	TSgitFtdcTimeType	ActionTime;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///���ر������
	TSgitFtdcOrderLocalIDType	OrderLocalID;
	///�������ر��
	TSgitFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TSgitFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TSgitFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TSgitFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///״̬��Ϣ
	TSgitFtdcErrorMsgType	StatusMsg;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
};

///��������������
struct CSgitFtdcExchangeOrderActionField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�������
	TSgitFtdcOrderSysIDType	OrderSysID;
	///������־
	TSgitFtdcActionFlagType	ActionFlag;
	///�۸�
	TSgitFtdcPriceType	LimitPrice;
	///�����仯
	TSgitFtdcVolumeType	VolumeChange;
	///��������
	TSgitFtdcDateType	ActionDate;
	///����ʱ��
	TSgitFtdcTimeType	ActionTime;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///���ر������
	TSgitFtdcOrderLocalIDType	OrderLocalID;
	///�������ر��
	TSgitFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TSgitFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TSgitFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TSgitFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TSgitFtdcUserIDType	UserID;
};

///��������������ʧ��
struct CSgitFtdcExchangeOrderActionErrorField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�������
	TSgitFtdcOrderSysIDType	OrderSysID;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///���ر������
	TSgitFtdcOrderLocalIDType	OrderLocalID;
	///�������ر��
	TSgitFtdcOrderLocalIDType	ActionLocalID;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///�������ɽ�
struct CSgitFtdcExchangeTradeField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�ɽ����
	TSgitFtdcTradeIDType	TradeID;
	///��������
	TSgitFtdcDirectionType	Direction;
	///�������
	TSgitFtdcOrderSysIDType	OrderSysID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TSgitFtdcClientIDType	ClientID;
	///���׽�ɫ
	TSgitFtdcTradingRoleType	TradingRole;
	///��Լ�ڽ������Ĵ���
	TSgitFtdcExchangeInstIDType	ExchangeInstID;
	///��ƽ��־
	TSgitFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TSgitFtdcPriceType	Price;
	///����
	TSgitFtdcVolumeType	Volume;
	///�ɽ�ʱ��
	TSgitFtdcDateType	TradeDate;
	///�ɽ�ʱ��
	TSgitFtdcTimeType	TradeTime;
	///�ɽ�����
	TSgitFtdcTradeTypeType	TradeType;
	///�ɽ�����Դ
	TSgitFtdcPriceSourceType	PriceSource;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
	///���ر������
	TSgitFtdcOrderLocalIDType	OrderLocalID;
	///�����Ա���
	TSgitFtdcParticipantIDType	ClearingPartID;
	///ҵ��Ԫ
	TSgitFtdcBusinessUnitType	BusinessUnit;
	///���
	TSgitFtdcSequenceNoType	SequenceNo;
	///�ɽ���Դ
	TSgitFtdcTradeSourceType	TradeSource;
};

///�ɽ�
struct CSgitFtdcTradeField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///��������
	TSgitFtdcOrderRefType	OrderRef;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�ɽ����
	TSgitFtdcTradeIDType	TradeID;
	///��������
	TSgitFtdcDirectionType	Direction;
	///�������
	TSgitFtdcOrderSysIDType	OrderSysID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TSgitFtdcClientIDType	ClientID;
	///���׽�ɫ
	TSgitFtdcTradingRoleType	TradingRole;
	///��Լ�ڽ������Ĵ���
	TSgitFtdcExchangeInstIDType	ExchangeInstID;
	///��ƽ��־
	TSgitFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
	///�۸�
	TSgitFtdcPriceType	Price;
	///����
	TSgitFtdcVolumeType	Volume;
	///�ɽ�ʱ��
	TSgitFtdcDateType	TradeDate;
	///�ɽ�ʱ��
	TSgitFtdcTimeType	TradeTime;
	///�ɽ�����
	TSgitFtdcTradeTypeType	TradeType;
	///�ɽ�����Դ
	TSgitFtdcPriceSourceType	PriceSource;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
	///���ر������
	TSgitFtdcOrderLocalIDType	OrderLocalID;
	///�����Ա���
	TSgitFtdcParticipantIDType	ClearingPartID;
	///ҵ��Ԫ
	TSgitFtdcBusinessUnitType	BusinessUnit;
	///���
	TSgitFtdcSequenceNoType	SequenceNo;
	///������
	TSgitFtdcDateType	TradingDay;
	///������
	TSgitFtdcSettlementIDType	SettlementID;
	///���͹�˾�������
	TSgitFtdcSequenceNoType	BrokerOrderSeq;
	///�ɽ���Դ
	TSgitFtdcTradeSourceType	TradeSource;
};

///�û��Ự
struct CSgitFtdcUserSessionField
{
	///ǰ�ñ��
	TSgitFtdcFrontIDType	FrontID;
	///�Ự���
	TSgitFtdcSessionIDType	SessionID;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///��¼����
	TSgitFtdcDateType	LoginDate;
	///��¼ʱ��
	TSgitFtdcTimeType	LoginTime;
	///IP��ַ
	TSgitFtdcIPAddressType	IPAddress;
	///�û��˲�Ʒ��Ϣ
	TSgitFtdcProductInfoType	UserProductInfo;
	///�ӿڶ˲�Ʒ��Ϣ
	TSgitFtdcProductInfoType	InterfaceProductInfo;
	///Э����Ϣ
	TSgitFtdcProtocolInfoType	ProtocolInfo;
	///Mac��ַ
	TSgitFtdcMacAddressType	MacAddress;
};

///��ѯ��󱨵�����
struct CSgitFtdcQueryMaxOrderVolumeField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///��������
	TSgitFtdcDirectionType	Direction;
	///��ƽ��־
	TSgitFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
	///�������������
	TSgitFtdcVolumeType	MaxVolume;
};

///Ͷ���߽�����ȷ����Ϣ
struct CSgitFtdcSettlementInfoConfirmField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///ȷ������
	TSgitFtdcDateType	ConfirmDate;
	///ȷ��ʱ��
	TSgitFtdcTimeType	ConfirmTime;
};

///�����ͬ��
struct CSgitFtdcSyncDepositField
{
	///�������ˮ��
	TSgitFtdcDepositSeqNoType	DepositSeqNo;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///�����
	TSgitFtdcMoneyType	Deposit;
	///�Ƿ�ǿ�ƽ���
	TSgitFtdcBoolType	IsForce;
};

///���͹�˾ͬ��
struct CSgitFtdcBrokerSyncField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
};

///����ͬ���е�Ͷ����
struct CSgitFtdcSyncingInvestorField
{
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���߷������
	TSgitFtdcInvestorIDType	InvestorGroupID;
	///Ͷ��������
	TSgitFtdcPartyNameType	InvestorName;
	///֤������
	TSgitFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ƿ��Ծ
	TSgitFtdcBoolType	IsActive;
	///��ϵ�绰
	TSgitFtdcTelephoneType	Telephone;
	///ͨѶ��ַ
	TSgitFtdcAddressType	Address;
	///��������
	TSgitFtdcDateType	OpenDate;
	///�ֻ�
	TSgitFtdcMobileType	Mobile;
	///��������ģ�����
	TSgitFtdcInvestorIDType	CommModelID;
};

///����ͬ���еĽ��״���
struct CSgitFtdcSyncingTradingCodeField
{
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�ͻ�����
	TSgitFtdcClientIDType	ClientID;
	///�Ƿ��Ծ
	TSgitFtdcBoolType	IsActive;
	///���ױ�������
	TSgitFtdcClientIDTypeType	ClientIDType;
};

///����ͬ���е�Ͷ���߷���
struct CSgitFtdcSyncingInvestorGroupField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���߷������
	TSgitFtdcInvestorIDType	InvestorGroupID;
	///Ͷ���߷�������
	TSgitFtdcInvestorGroupNameType	InvestorGroupName;
};

///����ͬ���еĽ����˺�
struct CSgitFtdcSyncingTradingAccountField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ϴ���Ѻ���
	TSgitFtdcMoneyType	PreMortgage;
	///�ϴ����ö��
	TSgitFtdcMoneyType	PreCredit;
	///�ϴδ���
	TSgitFtdcMoneyType	PreDeposit;
	///�ϴν���׼����
	TSgitFtdcMoneyType	PreBalance;
	///�ϴ�ռ�õı�֤��
	TSgitFtdcMoneyType	PreMargin;
	///��Ϣ����
	TSgitFtdcMoneyType	InterestBase;
	///��Ϣ����
	TSgitFtdcMoneyType	Interest;
	///�����
	TSgitFtdcMoneyType	Deposit;
	///������
	TSgitFtdcMoneyType	Withdraw;
	///����ı�֤��
	TSgitFtdcMoneyType	FrozenMargin;
	///������ʽ�
	TSgitFtdcMoneyType	FrozenCash;
	///�����������
	TSgitFtdcMoneyType	FrozenCommission;
	///��ǰ��֤���ܶ�
	TSgitFtdcMoneyType	CurrMargin;
	///�ʽ���
	TSgitFtdcMoneyType	CashIn;
	///������
	TSgitFtdcMoneyType	Commission;
	///ƽ��ӯ��
	TSgitFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TSgitFtdcMoneyType	PositionProfit;
	///�ڻ�����׼����
	TSgitFtdcMoneyType	Balance;
	///�����ʽ�
	TSgitFtdcMoneyType	Available;
	///��ȡ�ʽ�
	TSgitFtdcMoneyType	WithdrawQuota;
	///����׼����
	TSgitFtdcMoneyType	Reserve;
	///������
	TSgitFtdcDateType	TradingDay;
	///������
	TSgitFtdcSettlementIDType	SettlementID;
	///���ö��
	TSgitFtdcMoneyType	Credit;
	///��Ѻ���
	TSgitFtdcMoneyType	Mortgage;
	///��������֤��
	TSgitFtdcMoneyType	ExchangeMargin;
	///Ͷ���߽��֤��
	TSgitFtdcMoneyType	DeliveryMargin;
	///���������֤��
	TSgitFtdcMoneyType	ExchangeDeliveryMargin;
};

///����ͬ���е�Ͷ���ֲ߳�
struct CSgitFtdcSyncingInvestorPositionField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///�ֲֶ�շ���
	TSgitFtdcPosiDirectionType	PosiDirection;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
	///�ֲ�����
	TSgitFtdcPositionDateType	PositionDate;
	///���ճֲ�
	TSgitFtdcVolumeType	YdPosition;
	///���ճֲ�
	TSgitFtdcVolumeType	Position;
	///��ͷ����
	TSgitFtdcVolumeType	LongFrozen;
	///��ͷ����
	TSgitFtdcVolumeType	ShortFrozen;
	///���ֶ�����
	TSgitFtdcMoneyType	LongFrozenAmount;
	///���ֶ�����
	TSgitFtdcMoneyType	ShortFrozenAmount;
	///������
	TSgitFtdcVolumeType	OpenVolume;
	///ƽ����
	TSgitFtdcVolumeType	CloseVolume;
	///���ֽ��
	TSgitFtdcMoneyType	OpenAmount;
	///ƽ�ֽ��
	TSgitFtdcMoneyType	CloseAmount;
	///�ֲֳɱ�
	TSgitFtdcMoneyType	PositionCost;
	///�ϴ�ռ�õı�֤��
	TSgitFtdcMoneyType	PreMargin;
	///ռ�õı�֤��
	TSgitFtdcMoneyType	UseMargin;
	///����ı�֤��
	TSgitFtdcMoneyType	FrozenMargin;
	///������ʽ�
	TSgitFtdcMoneyType	FrozenCash;
	///�����������
	TSgitFtdcMoneyType	FrozenCommission;
	///�ʽ���
	TSgitFtdcMoneyType	CashIn;
	///������
	TSgitFtdcMoneyType	Commission;
	///ƽ��ӯ��
	TSgitFtdcMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TSgitFtdcMoneyType	PositionProfit;
	///�ϴν����
	TSgitFtdcPriceType	PreSettlementPrice;
	///���ν����
	TSgitFtdcPriceType	SettlementPrice;
	///������
	TSgitFtdcDateType	TradingDay;
	///������
	TSgitFtdcSettlementIDType	SettlementID;
	///���ֳɱ�
	TSgitFtdcMoneyType	OpenCost;
	///��������֤��
	TSgitFtdcMoneyType	ExchangeMargin;
	///��ϳɽ��γɵĳֲ�
	TSgitFtdcVolumeType	CombPosition;
	///��϶�ͷ����
	TSgitFtdcVolumeType	CombLongFrozen;
	///��Ͽ�ͷ����
	TSgitFtdcVolumeType	CombShortFrozen;
	///���ն���ƽ��ӯ��
	TSgitFtdcMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TSgitFtdcMoneyType	CloseProfitByTrade;
	///���ճֲ�
	TSgitFtdcVolumeType	TodayPosition;
	///��֤����
	TSgitFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TSgitFtdcRatioType	MarginRateByVolume;
};

///����ͬ���еĺ�Լ��֤����
struct CSgitFtdcSyncingInstrumentMarginRateField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TSgitFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
	///��ͷ��֤����
	TSgitFtdcRatioType	LongMarginRatioByMoney;
	///��ͷ��֤���
	TSgitFtdcMoneyType	LongMarginRatioByVolume;
	///��ͷ��֤����
	TSgitFtdcRatioType	ShortMarginRatioByMoney;
	///��ͷ��֤���
	TSgitFtdcMoneyType	ShortMarginRatioByVolume;
	///�Ƿ���Խ�������ȡ
	TSgitFtdcBoolType	IsRelative;
};

///����ͬ���еĺ�Լ��������
struct CSgitFtdcSyncingInstrumentCommissionRateField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TSgitFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///������������
	TSgitFtdcRatioType	OpenRatioByMoney;
	///����������
	TSgitFtdcRatioType	OpenRatioByVolume;
	///ƽ����������
	TSgitFtdcRatioType	CloseRatioByMoney;
	///ƽ��������
	TSgitFtdcRatioType	CloseRatioByVolume;
	///ƽ����������
	TSgitFtdcRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TSgitFtdcRatioType	CloseTodayRatioByVolume;
};

///����ͬ���еĺ�Լ����Ȩ��
struct CSgitFtdcSyncingInstrumentTradingRightField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TSgitFtdcInvestorRangeType	InvestorRange;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///����Ȩ��
	TSgitFtdcTradingRightType	TradingRight;
};

///��ѯ����
struct CSgitFtdcQryOrderField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�������
	TSgitFtdcOrderSysIDType	OrderSysID;
	///��ʼʱ��
	TSgitFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TSgitFtdcTimeType	InsertTimeEnd;
};

///��ѯ�ɽ�
struct CSgitFtdcQryTradeField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�ɽ����
	TSgitFtdcTradeIDType	TradeID;
	///��ʼʱ��
	TSgitFtdcTimeType	TradeTimeStart;
	///����ʱ��
	TSgitFtdcTimeType	TradeTimeEnd;
};

///��ѯͶ���ֲ߳�
struct CSgitFtdcQryInvestorPositionField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
};

///��ѯ�ʽ��˻�
struct CSgitFtdcQryTradingAccountField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
};

///��ѯͶ����
struct CSgitFtdcQryInvestorField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
};

///��ѯ���ױ���
struct CSgitFtdcQryTradingCodeField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�ͻ�����
	TSgitFtdcClientIDType	ClientID;
	///���ױ�������
	TSgitFtdcClientIDTypeType	ClientIDType;
};

///��ѯ���ױ���
struct CSgitFtdcQryInvestorGroupField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
};

///��ѯ���ױ���
struct CSgitFtdcQryInstrumentMarginRateField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
};

///��ѯ���ױ���
struct CSgitFtdcQryInstrumentCommissionRateField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
};

///��ѯ���ױ���
struct CSgitFtdcQryInstrumentTradingRightField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
};

///��ѯ���͹�˾
struct CSgitFtdcQryBrokerField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
};

///��ѯ����Ա
struct CSgitFtdcQryTraderField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
};

///��ѯ���͹�˾��Ա����
struct CSgitFtdcQryPartBrokerField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
};

///��ѯ�����û�����Ȩ��
struct CSgitFtdcQrySuperUserFunctionField
{
	///�û�����
	TSgitFtdcUserIDType	UserID;
};

///��ѯ�û��Ự
struct CSgitFtdcQryUserSessionField
{
	///ǰ�ñ��
	TSgitFtdcFrontIDType	FrontID;
	///�Ự���
	TSgitFtdcSessionIDType	SessionID;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
};

///��ѯǰ��״̬
struct CSgitFtdcQryFrontStatusField
{
	///ǰ�ñ��
	TSgitFtdcFrontIDType	FrontID;
};

///��ѯ����������
struct CSgitFtdcQryExchangeOrderField
{
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TSgitFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TSgitFtdcExchangeInstIDType	ExchangeInstID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
};

///��ѯ��������
struct CSgitFtdcQryOrderActionField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
};

///��ѯ��������������
struct CSgitFtdcQryExchangeOrderActionField
{
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TSgitFtdcClientIDType	ClientID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
};

///��ѯ�����û�
struct CSgitFtdcQrySuperUserField
{
	///�û�����
	TSgitFtdcUserIDType	UserID;
};

///��ѯ������
struct CSgitFtdcQryExchangeField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
};

///��ѯ��Ʒ
struct CSgitFtdcQryProductField
{
	///��Ʒ����
	TSgitFtdcInstrumentIDType	ProductID;
};

///��ѯ��Լ
struct CSgitFtdcQryInstrumentField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TSgitFtdcExchangeInstIDType	ExchangeInstID;
	///��Ʒ����
	TSgitFtdcInstrumentIDType	ProductID;
};

///��ѯ����
struct CSgitFtdcQryDepthMarketDataField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
};

///��ѯ���͹�˾�û�
struct CSgitFtdcQryBrokerUserField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
};

///��ѯ���͹�˾�û�Ȩ��
struct CSgitFtdcQryBrokerUserFunctionField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
};

///��ѯ����Ա���̻�
struct CSgitFtdcQryTraderOfferField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
};

///��ѯ�������ˮ
struct CSgitFtdcQrySyncDepositField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�������ˮ��
	TSgitFtdcDepositSeqNoType	DepositSeqNo;
};

///��ѯͶ���߽�����
struct CSgitFtdcQrySettlementInfoField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///������
	TSgitFtdcDateType	TradingDay;
};

///��ѯ����
struct CSgitFtdcQryHisOrderField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�������
	TSgitFtdcOrderSysIDType	OrderSysID;
	///��ʼʱ��
	TSgitFtdcTimeType	InsertTimeStart;
	///����ʱ��
	TSgitFtdcTimeType	InsertTimeEnd;
	///������
	TSgitFtdcDateType	TradingDay;
	///������
	TSgitFtdcSettlementIDType	SettlementID;
};

///�г�����
struct CSgitFtdcMarketDataField
{
	///������
	TSgitFtdcDateType	TradingDay;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TSgitFtdcExchangeInstIDType	ExchangeInstID;
	///���¼�
	TSgitFtdcPriceType	LastPrice;
	///�ϴν����
	TSgitFtdcPriceType	PreSettlementPrice;
	///������
	TSgitFtdcPriceType	PreClosePrice;
	///��ֲ���
	TSgitFtdcLargeVolumeType	PreOpenInterest;
	///����
	TSgitFtdcPriceType	OpenPrice;
	///��߼�
	TSgitFtdcPriceType	HighestPrice;
	///��ͼ�
	TSgitFtdcPriceType	LowestPrice;
	///����
	TSgitFtdcVolumeType	Volume;
	///�ɽ����
	TSgitFtdcMoneyType	Turnover;
	///�ֲ���
	TSgitFtdcLargeVolumeType	OpenInterest;
	///������
	TSgitFtdcPriceType	ClosePrice;
	///���ν����
	TSgitFtdcPriceType	SettlementPrice;
	///��ͣ���
	TSgitFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TSgitFtdcPriceType	LowerLimitPrice;
	///����ʵ��
	TSgitFtdcRatioType	PreDelta;
	///����ʵ��
	TSgitFtdcRatioType	CurrDelta;
	///����޸�ʱ��
	TSgitFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TSgitFtdcMillisecType	UpdateMillisec;
};

///�����������
struct CSgitFtdcMarketDataBaseField
{
	///������
	TSgitFtdcDateType	TradingDay;
	///�ϴν����
	TSgitFtdcPriceType	PreSettlementPrice;
	///������
	TSgitFtdcPriceType	PreClosePrice;
	///��ֲ���
	TSgitFtdcLargeVolumeType	PreOpenInterest;
	///����ʵ��
	TSgitFtdcRatioType	PreDelta;
};

///���龲̬����
struct CSgitFtdcMarketDataStaticField
{
	///����
	TSgitFtdcPriceType	OpenPrice;
	///��߼�
	TSgitFtdcPriceType	HighestPrice;
	///��ͼ�
	TSgitFtdcPriceType	LowestPrice;
	///������
	TSgitFtdcPriceType	ClosePrice;
	///��ͣ���
	TSgitFtdcPriceType	UpperLimitPrice;
	///��ͣ���
	TSgitFtdcPriceType	LowerLimitPrice;
	///���ν����
	TSgitFtdcPriceType	SettlementPrice;
	///����ʵ��
	TSgitFtdcRatioType	CurrDelta;
};

///�������³ɽ�����
struct CSgitFtdcMarketDataLastMatchField
{
	///���¼�
	TSgitFtdcPriceType	LastPrice;
	///����
	TSgitFtdcVolumeType	Volume;
	///�ɽ����
	TSgitFtdcMoneyType	Turnover;
	///�ֲ���
	TSgitFtdcLargeVolumeType	OpenInterest;
};

///�������ż�����
struct CSgitFtdcMarketDataBestPriceField
{
	///�����һ
	TSgitFtdcPriceType	BidPrice1;
	///������һ
	TSgitFtdcVolumeType	BidVolume1;
	///������һ
	TSgitFtdcPriceType	AskPrice1;
	///������һ
	TSgitFtdcVolumeType	AskVolume1;
};

///�����������������
struct CSgitFtdcMarketDataBid23Field
{
	///����۶�
	TSgitFtdcPriceType	BidPrice2;
	///��������
	TSgitFtdcVolumeType	BidVolume2;
	///�������
	TSgitFtdcPriceType	BidPrice3;
	///��������
	TSgitFtdcVolumeType	BidVolume3;
};

///������������������
struct CSgitFtdcMarketDataAsk23Field
{
	///�����۶�
	TSgitFtdcPriceType	AskPrice2;
	///��������
	TSgitFtdcVolumeType	AskVolume2;
	///��������
	TSgitFtdcPriceType	AskPrice3;
	///��������
	TSgitFtdcVolumeType	AskVolume3;
};

///���������ġ�������
struct CSgitFtdcMarketDataBid45Field
{
	///�������
	TSgitFtdcPriceType	BidPrice4;
	///��������
	TSgitFtdcVolumeType	BidVolume4;
	///�������
	TSgitFtdcPriceType	BidPrice5;
	///��������
	TSgitFtdcVolumeType	BidVolume5;
};

///���������ġ�������
struct CSgitFtdcMarketDataAsk45Field
{
	///��������
	TSgitFtdcPriceType	AskPrice4;
	///��������
	TSgitFtdcVolumeType	AskVolume4;
	///��������
	TSgitFtdcPriceType	AskPrice5;
	///��������
	TSgitFtdcVolumeType	AskVolume5;
};

///�������ʱ������
struct CSgitFtdcMarketDataUpdateTimeField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///����޸�ʱ��
	TSgitFtdcTimeType	UpdateTime;
	///����޸ĺ���
	TSgitFtdcMillisecType	UpdateMillisec;
};

///���齻������������
struct CSgitFtdcMarketDataExchangeField
{
	///����������
	TSgitFtdcPriceType	ExchangeID;
};

///ָ���ĺ�Լ
struct CSgitFtdcSpecificInstrumentField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
};

///��Լ״̬
struct CSgitFtdcInstrumentStatusField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TSgitFtdcExchangeInstIDType	ExchangeInstID;
	///���������
	TSgitFtdcSettlementGroupIDType	SettlementGroupID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TSgitFtdcInstrumentStatusType	InstrumentStatus;
	///���׽׶α��
	TSgitFtdcTradingSegmentSNType	TradingSegmentSN;
	///���뱾״̬ʱ��
	TSgitFtdcTimeType	EnterTime;
	///���뱾״̬ԭ��
	TSgitFtdcInstStatusEnterReasonType	EnterReason;
};

///��ѯ��Լ״̬
struct CSgitFtdcQryInstrumentStatusField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Լ�ڽ������Ĵ���
	TSgitFtdcExchangeInstIDType	ExchangeInstID;
};

///Ͷ�����˻�
struct CSgitFtdcInvestorAccountField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
};

///����ӯ���㷨
struct CSgitFtdcPositionProfitAlgorithmField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///ӯ���㷨
	TSgitFtdcAlgorithmType	Algorithm;
	///��ע
	TSgitFtdcMemoType	Memo;
};

///��Ա�ʽ��ۿ�
struct CSgitFtdcDiscountField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���߷�Χ
	TSgitFtdcInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///�ʽ��ۿ۱���
	TSgitFtdcRatioType	Discount;
};

///��ѯת������
struct CSgitFtdcQryTransferBankField
{
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з����Ĵ���
	TSgitFtdcBankBrchIDType	BankBrchID;
};

///ת������
struct CSgitFtdcTransferBankField
{
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з����Ĵ���
	TSgitFtdcBankBrchIDType	BankBrchID;
	///��������
	TSgitFtdcBankNameType	BankName;
	///�Ƿ��Ծ
	TSgitFtdcBoolType	IsActive;
};

///��ѯͶ���ֲ߳���ϸ
struct CSgitFtdcQryInvestorPositionDetailField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
};

///Ͷ���ֲ߳���ϸ
struct CSgitFtdcInvestorPositionDetailField
{
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
	///����
	TSgitFtdcDirectionType	Direction;
	///��������
	TSgitFtdcDateType	OpenDate;
	///�ɽ����
	TSgitFtdcTradeIDType	TradeID;
	///����
	TSgitFtdcVolumeType	Volume;
	///���ּ�
	TSgitFtdcPriceType	OpenPrice;
	///������
	TSgitFtdcDateType	TradingDay;
	///������
	TSgitFtdcSettlementIDType	SettlementID;
	///�ɽ�����
	TSgitFtdcTradeTypeType	TradeType;
	///��Ϻ�Լ����
	TSgitFtdcInstrumentIDType	CombInstrumentID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///���ն���ƽ��ӯ��
	TSgitFtdcMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TSgitFtdcMoneyType	CloseProfitByTrade;
	///���ն��гֲ�ӯ��
	TSgitFtdcMoneyType	PositionProfitByDate;
	///��ʶԳ�ֲ�ӯ��
	TSgitFtdcMoneyType	PositionProfitByTrade;
	///Ͷ���߱�֤��
	TSgitFtdcMoneyType	Margin;
	///��������֤��
	TSgitFtdcMoneyType	ExchMargin;
	///��֤����
	TSgitFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TSgitFtdcRatioType	MarginRateByVolume;
	///������
	TSgitFtdcPriceType	LastSettlementPrice;
	///�����
	TSgitFtdcPriceType	SettlementPrice;
	///ƽ����
	TSgitFtdcVolumeType	CloseVolume;
	///ƽ�ֽ��
	TSgitFtdcMoneyType	CloseAmount;
};

///�ʽ��˻�������
struct CSgitFtdcTradingAccountPasswordField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///����
	TSgitFtdcPasswordType	Password;
};

///���������鱨�̻�
struct CSgitFtdcMDTraderOfferField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///����
	TSgitFtdcPasswordType	Password;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///���ر������
	TSgitFtdcOrderLocalIDType	OrderLocalID;
	///����������Ա����״̬
	TSgitFtdcTraderConnectStatusType	TraderConnectStatus;
	///�����������������
	TSgitFtdcDateType	ConnectRequestDate;
	///�������������ʱ��
	TSgitFtdcTimeType	ConnectRequestTime;
	///�ϴα�������
	TSgitFtdcDateType	LastReportDate;
	///�ϴα���ʱ��
	TSgitFtdcTimeType	LastReportTime;
	///�����������
	TSgitFtdcDateType	ConnectDate;
	///�������ʱ��
	TSgitFtdcTimeType	ConnectTime;
	///��������
	TSgitFtdcDateType	StartDate;
	///����ʱ��
	TSgitFtdcTimeType	StartTime;
	///������
	TSgitFtdcDateType	TradingDay;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///��ϯλ���ɽ����
	TSgitFtdcTradeIDType	MaxTradeID;
	///��ϯλ��󱨵�����
	TSgitFtdcReturnCodeType	MaxOrderMessageReference;
};

///��ѯ���鱨�̻�
struct CSgitFtdcQryMDTraderOfferField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
};

///��ѯ�ͻ�֪ͨ
struct CSgitFtdcQryNoticeField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
};

///�ͻ�֪ͨ
struct CSgitFtdcNoticeField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///��Ϣ����
	TSgitFtdcContentType	Content;
	///���͹�˾֪ͨ�������к�
	TSgitFtdcSequenceLabelType	SequenceLabel;
};

///�û�Ȩ��
struct CSgitFtdcUserRightField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///�ͻ�Ȩ������
	TSgitFtdcUserRightTypeType	UserRightType;
	///�Ƿ��ֹ
	TSgitFtdcBoolType	IsForbidden;
};

///��ѯ������Ϣȷ����
struct CSgitFtdcQrySettlementInfoConfirmField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
};

///װ�ؽ�����Ϣ
struct CSgitFtdcLoadSettlementInfoField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
};

///���͹�˾�����ʽ��㷨��
struct CSgitFtdcBrokerWithdrawAlgorithmField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�����ʽ��㷨
	TSgitFtdcAlgorithmType	WithdrawAlgorithm;
	///�ʽ�ʹ����
	TSgitFtdcRatioType	UsingRatio;
	///�����Ƿ����ƽ��ӯ��
	TSgitFtdcIncludeCloseProfitType	IncludeCloseProfit;
	///�����޲����޳ɽ��ͻ��Ƿ��ܿ����������
	TSgitFtdcAllWithoutTradeType	AllWithoutTrade;
	///�����Ƿ����ƽ��ӯ��
	TSgitFtdcIncludeCloseProfitType	AvailIncludeCloseProfit;
	///�Ƿ������û��¼�
	TSgitFtdcBoolType	IsBrokerUserEvent;
};

///�ʽ��˻���������
struct CSgitFtdcTradingAccountPasswordUpdateV1Field
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///ԭ���Ŀ���
	TSgitFtdcPasswordType	OldPassword;
	///�µĿ���
	TSgitFtdcPasswordType	NewPassword;
};

///�ʽ��˻���������
struct CSgitFtdcTradingAccountPasswordUpdateField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///ԭ���Ŀ���
	TSgitFtdcPasswordType	OldPassword;
	///�µĿ���
	TSgitFtdcPasswordType	NewPassword;
};

///��ѯ��Ϻ�Լ����
struct CSgitFtdcQryCombinationLegField
{
	///��Ϻ�Լ����
	TSgitFtdcInstrumentIDType	CombInstrumentID;
	///���ȱ��
	TSgitFtdcLegIDType	LegID;
	///���Ⱥ�Լ����
	TSgitFtdcInstrumentIDType	LegInstrumentID;
};

///��ѯ��Ϻ�Լ����
struct CSgitFtdcQrySyncStatusField
{
	///������
	TSgitFtdcDateType	TradingDay;
};

///��Ͻ��׺�Լ�ĵ���
struct CSgitFtdcCombinationLegField
{
	///��Ϻ�Լ����
	TSgitFtdcInstrumentIDType	CombInstrumentID;
	///���ȱ��
	TSgitFtdcLegIDType	LegID;
	///���Ⱥ�Լ����
	TSgitFtdcInstrumentIDType	LegInstrumentID;
	///��������
	TSgitFtdcDirectionType	Direction;
	///���ȳ���
	TSgitFtdcLegMultipleType	LegMultiple;
	///��������
	TSgitFtdcImplyLevelType	ImplyLevel;
};

///����ͬ��״̬
struct CSgitFtdcSyncStatusField
{
	///������
	TSgitFtdcDateType	TradingDay;
	///����ͬ��״̬
	TSgitFtdcDataSyncStatusType	DataSyncStatus;
};

///��ѯ��ϵ��
struct CSgitFtdcQryLinkManField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
};

///��ϵ��
struct CSgitFtdcLinkManField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��ϵ������
	TSgitFtdcPersonTypeType	PersonType;
	///֤������
	TSgitFtdcIdCardTypeType	IdentifiedCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///����
	TSgitFtdcPartyNameType	PersonName;
	///��ϵ�绰
	TSgitFtdcTelephoneType	Telephone;
	///ͨѶ��ַ
	TSgitFtdcAddressType	Address;
	///��������
	TSgitFtdcZipCodeType	ZipCode;
	///���ȼ�
	TSgitFtdcPriorityType	Priority;
};

///��ѯ���͹�˾�û��¼�
struct CSgitFtdcQryBrokerUserEventField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///�û��¼�����
	TSgitFtdcUserEventTypeType	UserEventType;
};

///��ѯ���͹�˾�û��¼�
struct CSgitFtdcBrokerUserEventField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///�û��¼�����
	TSgitFtdcUserEventTypeType	UserEventType;
	///�û��¼����
	TSgitFtdcSequenceNoType	EventSequenceNo;
	///�¼���������
	TSgitFtdcDateType	EventDate;
	///�¼�����ʱ��
	TSgitFtdcTimeType	EventTime;
	///�û��¼���Ϣ
	TSgitFtdcUserEventInfoType	UserEventInfo;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
};

///��ѯǩԼ��������
struct CSgitFtdcQryContractBankField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з����Ĵ���
	TSgitFtdcBankBrchIDType	BankBrchID;
};

///��ѯǩԼ������Ӧ
struct CSgitFtdcContractBankField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з����Ĵ���
	TSgitFtdcBankBrchIDType	BankBrchID;
	///��������
	TSgitFtdcBankNameType	BankName;
};

///Ͷ������ϳֲ���ϸ
struct CSgitFtdcInvestorPositionCombineDetailField
{
	///������
	TSgitFtdcDateType	TradingDay;
	///��������
	TSgitFtdcDateType	OpenDate;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///������
	TSgitFtdcSettlementIDType	SettlementID;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��ϱ��
	TSgitFtdcTradeIDType	ComTradeID;
	///��ϱ��
	TSgitFtdcTradeIDType	TradeID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
	///����
	TSgitFtdcDirectionType	Direction;
	///�ֲ���
	TSgitFtdcVolumeType	TotalAmt;
	///Ͷ���߱�֤��
	TSgitFtdcMoneyType	Margin;
	///��������֤��
	TSgitFtdcMoneyType	ExchMargin;
	///��֤����
	TSgitFtdcRatioType	MarginRateByMoney;
	///��֤����(������)
	TSgitFtdcRatioType	MarginRateByVolume;
	///���ȱ��
	TSgitFtdcLegIDType	LegID;
	///���ȳ���
	TSgitFtdcLegMultipleType	LegMultiple;
	///��ϳֲֺ�Լ����
	TSgitFtdcInstrumentIDType	CombInstrumentID;
};

///Ԥ��
struct CSgitFtdcParkedOrderField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///��������
	TSgitFtdcOrderRefType	OrderRef;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///�����۸�����
	TSgitFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TSgitFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TSgitFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TSgitFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TSgitFtdcPriceType	LimitPrice;
	///����
	TSgitFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TSgitFtdcTimeConditionType	TimeCondition;
	///GTD����
	TSgitFtdcDateType	GTDDate;
	///�ɽ�������
	TSgitFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TSgitFtdcVolumeType	MinVolume;
	///��������
	TSgitFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TSgitFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TSgitFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TSgitFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TSgitFtdcBusinessUnitType	BusinessUnit;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///�û�ǿ����־
	TSgitFtdcBoolType	UserForceClose;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///Ԥ�񱨵����
	TSgitFtdcParkedOrderIDType	ParkedOrderID;
	///�û�����
	TSgitFtdcUserTypeType	UserType;
	///Ԥ��״̬
	TSgitFtdcParkedOrderStatusType	Status;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///����Ԥ�񵥲���
struct CSgitFtdcParkedOrderActionField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///������������
	TSgitFtdcOrderActionRefType	OrderActionRef;
	///��������
	TSgitFtdcOrderRefType	OrderRef;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TSgitFtdcFrontIDType	FrontID;
	///�Ự���
	TSgitFtdcSessionIDType	SessionID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�������
	TSgitFtdcOrderSysIDType	OrderSysID;
	///������־
	TSgitFtdcActionFlagType	ActionFlag;
	///�۸�
	TSgitFtdcPriceType	LimitPrice;
	///�����仯
	TSgitFtdcVolumeType	VolumeChange;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///Ԥ�񳷵������
	TSgitFtdcParkedOrderActionIDType	ParkedOrderActionID;
	///�û�����
	TSgitFtdcUserTypeType	UserType;
	///Ԥ�񳷵�״̬
	TSgitFtdcParkedOrderStatusType	Status;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///��ѯԤ��
struct CSgitFtdcQryParkedOrderField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
};

///��ѯԤ�񳷵�
struct CSgitFtdcQryParkedOrderActionField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
};

///ɾ��Ԥ��
struct CSgitFtdcRemoveParkedOrderField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///Ԥ�񱨵����
	TSgitFtdcParkedOrderIDType	ParkedOrderID;
};

///ɾ��Ԥ�񳷵�
struct CSgitFtdcRemoveParkedOrderActionField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///Ԥ�񳷵����
	TSgitFtdcParkedOrderActionIDType	ParkedOrderActionID;
};

///���͹�˾�����ʽ��㷨��
struct CSgitFtdcInvestorWithdrawAlgorithmField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���߷�Χ
	TSgitFtdcInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///�����ʽ����
	TSgitFtdcRatioType	UsingRatio;
};

///��ѯ��ϳֲ���ϸ
struct CSgitFtdcQryInvestorPositionCombineDetailField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��ϳֲֺ�Լ����
	TSgitFtdcInstrumentIDType	CombInstrumentID;
};

///�ɽ�����
struct CSgitFtdcMarketDataAveragePriceField
{
	///���վ���
	TSgitFtdcPriceType	AveragePrice;
};

///У��Ͷ��������
struct CSgitFtdcVerifyInvestorPasswordField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///����
	TSgitFtdcPasswordType	Password;
};

///�û�IP
struct CSgitFtdcUserIPField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///IP��ַ
	TSgitFtdcIPAddressType	IPAddress;
	///IP��ַ����
	TSgitFtdcIPAddressType	IPMask;
	///Mac��ַ
	TSgitFtdcMacAddressType	MacAddress;
};

///�û��¼�֪ͨ��Ϣ
struct CSgitFtdcTradingNoticeInfoField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///����ʱ��
	TSgitFtdcTimeType	SendTime;
	///��Ϣ����
	TSgitFtdcContentType	FieldContent;
	///����ϵ�к�
	TSgitFtdcSequenceSeriesType	SequenceSeries;
	///���к�
	TSgitFtdcSequenceNoType	SequenceNo;
};

///�û��¼�֪ͨ
struct CSgitFtdcTradingNoticeField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���߷�Χ
	TSgitFtdcInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///����ϵ�к�
	TSgitFtdcSequenceSeriesType	SequenceSeries;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///����ʱ��
	TSgitFtdcTimeType	SendTime;
	///���к�
	TSgitFtdcSequenceNoType	SequenceNo;
	///��Ϣ����
	TSgitFtdcContentType	FieldContent;
};

///��ѯ�����¼�֪ͨ
struct CSgitFtdcQryTradingNoticeField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
};

///��ѯ���󱨵�
struct CSgitFtdcQryErrOrderField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
};

///���󱨵�
struct CSgitFtdcErrOrderField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///��������
	TSgitFtdcOrderRefType	OrderRef;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///�����۸�����
	TSgitFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TSgitFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TSgitFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TSgitFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TSgitFtdcPriceType	LimitPrice;
	///����
	TSgitFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TSgitFtdcTimeConditionType	TimeCondition;
	///GTD����
	TSgitFtdcDateType	GTDDate;
	///�ɽ�������
	TSgitFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TSgitFtdcVolumeType	MinVolume;
	///��������
	TSgitFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TSgitFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TSgitFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TSgitFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TSgitFtdcBusinessUnitType	BusinessUnit;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///�û�ǿ����־
	TSgitFtdcBoolType	UserForceClose;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///��ѯ���󱨵�����
struct CSgitFtdcErrorConditionalOrderField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///��������
	TSgitFtdcOrderRefType	OrderRef;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///�����۸�����
	TSgitFtdcOrderPriceTypeType	OrderPriceType;
	///��������
	TSgitFtdcDirectionType	Direction;
	///��Ͽ�ƽ��־
	TSgitFtdcCombOffsetFlagType	CombOffsetFlag;
	///���Ͷ���ױ���־
	TSgitFtdcCombHedgeFlagType	CombHedgeFlag;
	///�۸�
	TSgitFtdcPriceType	LimitPrice;
	///����
	TSgitFtdcVolumeType	VolumeTotalOriginal;
	///��Ч������
	TSgitFtdcTimeConditionType	TimeCondition;
	///GTD����
	TSgitFtdcDateType	GTDDate;
	///�ɽ�������
	TSgitFtdcVolumeConditionType	VolumeCondition;
	///��С�ɽ���
	TSgitFtdcVolumeType	MinVolume;
	///��������
	TSgitFtdcContingentConditionType	ContingentCondition;
	///ֹ���
	TSgitFtdcPriceType	StopPrice;
	///ǿƽԭ��
	TSgitFtdcForceCloseReasonType	ForceCloseReason;
	///�Զ������־
	TSgitFtdcBoolType	IsAutoSuspend;
	///ҵ��Ԫ
	TSgitFtdcBusinessUnitType	BusinessUnit;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///���ر������
	TSgitFtdcOrderLocalIDType	OrderLocalID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TSgitFtdcClientIDType	ClientID;
	///��Լ�ڽ������Ĵ���
	TSgitFtdcExchangeInstIDType	ExchangeInstID;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�����ύ״̬
	TSgitFtdcOrderSubmitStatusType	OrderSubmitStatus;
	///������ʾ���
	TSgitFtdcSequenceNoType	NotifySequence;
	///������
	TSgitFtdcDateType	TradingDay;
	///������
	TSgitFtdcSettlementIDType	SettlementID;
	///�������
	TSgitFtdcOrderSysIDType	OrderSysID;
	///������Դ
	TSgitFtdcOrderSourceType	OrderSource;
	///����״̬
	TSgitFtdcOrderStatusType	OrderStatus;
	///��������
	TSgitFtdcOrderTypeType	OrderType;
	///��ɽ�����
	TSgitFtdcVolumeType	VolumeTraded;
	///ʣ������
	TSgitFtdcVolumeType	VolumeTotal;
	///��������
	TSgitFtdcDateType	InsertDate;
	///ί��ʱ��
	TSgitFtdcTimeType	InsertTime;
	///����ʱ��
	TSgitFtdcTimeType	ActiveTime;
	///����ʱ��
	TSgitFtdcTimeType	SuspendTime;
	///����޸�ʱ��
	TSgitFtdcTimeType	UpdateTime;
	///����ʱ��
	TSgitFtdcTimeType	CancelTime;
	///����޸Ľ���������Ա����
	TSgitFtdcTraderIDType	ActiveTraderID;
	///�����Ա���
	TSgitFtdcParticipantIDType	ClearingPartID;
	///���
	TSgitFtdcSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TSgitFtdcFrontIDType	FrontID;
	///�Ự���
	TSgitFtdcSessionIDType	SessionID;
	///�û��˲�Ʒ��Ϣ
	TSgitFtdcProductInfoType	UserProductInfo;
	///״̬��Ϣ
	TSgitFtdcErrorMsgType	StatusMsg;
	///�û�ǿ����־
	TSgitFtdcBoolType	UserForceClose;
	///�����û�����
	TSgitFtdcUserIDType	ActiveUserID;
	///���͹�˾�������
	TSgitFtdcSequenceNoType	BrokerOrderSeq;
	///��ر���
	TSgitFtdcOrderSysIDType	RelativeOrderSysID;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///��ѯ���󱨵�����
struct CSgitFtdcQryErrOrderActionField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
};

///���󱨵�����
struct CSgitFtdcErrOrderActionField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///������������
	TSgitFtdcOrderActionRefType	OrderActionRef;
	///��������
	TSgitFtdcOrderRefType	OrderRef;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///ǰ�ñ��
	TSgitFtdcFrontIDType	FrontID;
	///�Ự���
	TSgitFtdcSessionIDType	SessionID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�������
	TSgitFtdcOrderSysIDType	OrderSysID;
	///������־
	TSgitFtdcActionFlagType	ActionFlag;
	///�۸�
	TSgitFtdcPriceType	LimitPrice;
	///�����仯
	TSgitFtdcVolumeType	VolumeChange;
	///��������
	TSgitFtdcDateType	ActionDate;
	///����ʱ��
	TSgitFtdcTimeType	ActionTime;
	///����������Ա����
	TSgitFtdcTraderIDType	TraderID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///���ر������
	TSgitFtdcOrderLocalIDType	OrderLocalID;
	///�������ر��
	TSgitFtdcOrderLocalIDType	ActionLocalID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///�ͻ�����
	TSgitFtdcClientIDType	ClientID;
	///ҵ��Ԫ
	TSgitFtdcBusinessUnitType	BusinessUnit;
	///��������״̬
	TSgitFtdcOrderActionStatusType	OrderActionStatus;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///״̬��Ϣ
	TSgitFtdcErrorMsgType	StatusMsg;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///��ѯ������״̬
struct CSgitFtdcQryExchangeSequenceField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
};

///������״̬
struct CSgitFtdcExchangeSequenceField
{
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///���
	TSgitFtdcSequenceNoType	SequenceNo;
	///��Լ����״̬
	TSgitFtdcInstrumentStatusType	MarketStatus;
};

///���ݼ۸��ѯ��󱨵�����
struct CSgitFtdcQueryMaxOrderVolumeWithPriceField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///��������
	TSgitFtdcDirectionType	Direction;
	///��ƽ��־
	TSgitFtdcOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
	///�������������
	TSgitFtdcVolumeType	MaxVolume;
	///�����۸�
	TSgitFtdcPriceType	Price;
};

///��ѯ���͹�˾���ײ���
struct CSgitFtdcQryBrokerTradingParamsField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
};

///���͹�˾���ײ���
struct CSgitFtdcBrokerTradingParamsField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///��֤��۸�����
	TSgitFtdcMarginPriceTypeType	MarginPriceType;
	///ӯ���㷨
	TSgitFtdcAlgorithmType	Algorithm;
	///�����Ƿ����ƽ��ӯ��
	TSgitFtdcIncludeCloseProfitType	AvailIncludeCloseProfit;
};

///��ѯ���͹�˾�����㷨
struct CSgitFtdcQryBrokerTradingAlgosField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
};

///���͹�˾�����㷨
struct CSgitFtdcBrokerTradingAlgosField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///�ֲִ����㷨���
	TSgitFtdcHandlePositionAlgoIDType	HandlePositionAlgoID;
	///Ѱ�ұ�֤�����㷨���
	TSgitFtdcFindMarginRateAlgoIDType	FindMarginRateAlgoID;
	///�ʽ����㷨���
	TSgitFtdcHandleTradingAccountAlgoIDType	HandleTradingAccountAlgoID;
};

///��ѯ���͹�˾�ʽ�
struct CSgitFtdcQueryBrokerDepositField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
};

///���͹�˾�ʽ�
struct CSgitFtdcBrokerDepositField
{
	///��������
	TSgitFtdcTradeDateType	TradingDay;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///��Ա����
	TSgitFtdcParticipantIDType	ParticipantID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///�ϴν���׼����
	TSgitFtdcMoneyType	PreBalance;
	///��ǰ��֤���ܶ�
	TSgitFtdcMoneyType	CurrMargin;
	///ƽ��ӯ��
	TSgitFtdcMoneyType	CloseProfit;
	///�ڻ�����׼����
	TSgitFtdcMoneyType	Balance;
	///�����
	TSgitFtdcMoneyType	Deposit;
	///������
	TSgitFtdcMoneyType	Withdraw;
	///�����ʽ�
	TSgitFtdcMoneyType	Available;
	///����׼����
	TSgitFtdcMoneyType	Reserve;
	///����ı�֤��
	TSgitFtdcMoneyType	FrozenMargin;
};

///��ѯ��֤����ϵͳ���͹�˾��Կ
struct CSgitFtdcQryCFMMCBrokerKeyField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
};

///��֤����ϵͳ���͹�˾��Կ
struct CSgitFtdcCFMMCBrokerKeyField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///���͹�˾ͳһ����
	TSgitFtdcParticipantIDType	ParticipantID;
	///��Կ��������
	TSgitFtdcDateType	CreateDate;
	///��Կ����ʱ��
	TSgitFtdcTimeType	CreateTime;
	///��Կ���
	TSgitFtdcSequenceNoType	KeyID;
	///��̬��Կ
	TSgitFtdcCFMMCKeyType	CurrentKey;
	///��̬��Կ����
	TSgitFtdcCFMMCKeyKindType	KeyKind;
};

///��֤����ϵͳ���͹�˾�ʽ��˻���Կ
struct CSgitFtdcCFMMCTradingAccountKeyField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///���͹�˾ͳһ����
	TSgitFtdcParticipantIDType	ParticipantID;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///��Կ���
	TSgitFtdcSequenceNoType	KeyID;
	///��̬��Կ
	TSgitFtdcCFMMCKeyType	CurrentKey;
};

///�����ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ
struct CSgitFtdcQryCFMMCTradingAccountKeyField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
};

///�û���̬���Ʋ���
struct CSgitFtdcBrokerUserOTPParamField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///��̬�����ṩ��
	TSgitFtdcOTPVendorsIDType	OTPVendorsID;
	///��̬�������к�
	TSgitFtdcSerialNumberType	SerialNumber;
	///������Կ
	TSgitFtdcAuthKeyType	AuthKey;
	///Ư��ֵ
	TSgitFtdcLastDriftType	LastDrift;
	///�ɹ�ֵ
	TSgitFtdcLastSuccessType	LastSuccess;
	///��̬��������
	TSgitFtdcOTPTypeType	OTPType;
};

///�ֹ�ͬ���û���̬����
struct CSgitFtdcManualSyncBrokerUserOTPField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///��̬��������
	TSgitFtdcOTPTypeType	OTPType;
	///��һ����̬����
	TSgitFtdcPasswordType	FirstOTP;
	///�ڶ�����̬����
	TSgitFtdcPasswordType	SecondOTP;
};

///Ͷ������������ģ��
struct CSgitFtdcCommRateModelField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///��������ģ�����
	TSgitFtdcInvestorIDType	CommModelID;
	///ģ������
	TSgitFtdcCommModelNameType	CommModelName;
};

///�����ѯͶ������������ģ��
struct CSgitFtdcQryCommRateModelField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///��������ģ�����
	TSgitFtdcInvestorIDType	CommModelID;
};

///�ֵ��۵���Ϣ
struct CSgitFtdcEWarrantOffsetField
{
	///��������
	TSgitFtdcTradeDateType	TradingDay;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
	///��������
	TSgitFtdcDirectionType	Direction;
	///Ͷ���ױ���־
	TSgitFtdcHedgeFlagType	HedgeFlag;
	///����
	TSgitFtdcVolumeType	Volume;
};

///��ѯ�ֵ��۵���Ϣ
struct CSgitFtdcQryEWarrantOffsetField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///����������
	TSgitFtdcExchangeIDType	ExchangeID;
	///��Լ����
	TSgitFtdcInstrumentIDType	InstrumentID;
};

///ת�ʿ�������
struct CSgitFtdcReqOpenAccountField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TSgitFtdcGenderType	Gender;
	///���Ҵ���
	TSgitFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///��ַ
	TSgitFtdcAddressType	Address;
	///�ʱ�
	TSgitFtdcZipCodeType	ZipCode;
	///�绰����
	TSgitFtdcTelephoneType	Telephone;
	///�ֻ�
	TSgitFtdcMobilePhoneType	MobilePhone;
	///����
	TSgitFtdcFaxType	Fax;
	///�����ʼ�
	TSgitFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TSgitFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TSgitFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///�㳮��־
	TSgitFtdcCashExchangeCodeType	CashExchangeCode;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TSgitFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TSgitFtdcBankAccountType	BankSecuAcc;
	///���������־
	TSgitFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TSgitFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///����ID
	TSgitFtdcTIDType	TID;
};

///ת����������
struct CSgitFtdcReqCancelAccountField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TSgitFtdcGenderType	Gender;
	///���Ҵ���
	TSgitFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///��ַ
	TSgitFtdcAddressType	Address;
	///�ʱ�
	TSgitFtdcZipCodeType	ZipCode;
	///�绰����
	TSgitFtdcTelephoneType	Telephone;
	///�ֻ�
	TSgitFtdcMobilePhoneType	MobilePhone;
	///����
	TSgitFtdcFaxType	Fax;
	///�����ʼ�
	TSgitFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TSgitFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TSgitFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///�㳮��־
	TSgitFtdcCashExchangeCodeType	CashExchangeCode;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TSgitFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TSgitFtdcBankAccountType	BankSecuAcc;
	///���������־
	TSgitFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TSgitFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///����ID
	TSgitFtdcTIDType	TID;
};

///��������˻�����
struct CSgitFtdcReqChangeAccountField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TSgitFtdcGenderType	Gender;
	///���Ҵ���
	TSgitFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///��ַ
	TSgitFtdcAddressType	Address;
	///�ʱ�
	TSgitFtdcZipCodeType	ZipCode;
	///�绰����
	TSgitFtdcTelephoneType	Telephone;
	///�ֻ�
	TSgitFtdcMobilePhoneType	MobilePhone;
	///����
	TSgitFtdcFaxType	Fax;
	///�����ʼ�
	TSgitFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TSgitFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///�������ʺ�
	TSgitFtdcBankAccountType	NewBankAccount;
	///����������
	TSgitFtdcPasswordType	NewBankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TSgitFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///���������־
	TSgitFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TSgitFtdcPwdFlagType	SecuPwdFlag;
	///����ID
	TSgitFtdcTIDType	TID;
	///ժҪ
	TSgitFtdcDigestType	Digest;
};

///ת������
struct CSgitFtdcReqTransferField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�ڻ���˾��ˮ��
	TSgitFtdcFutureSerialType	FutureSerial;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TSgitFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TSgitFtdcTradeAmountType	TradeAmount;
	///�ڻ���ȡ���
	TSgitFtdcTradeAmountType	FutureFetchAmount;
	///����֧����־
	TSgitFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TSgitFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TSgitFtdcFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TSgitFtdcAddInfoType	Message;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TSgitFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TSgitFtdcBankAccountType	BankSecuAcc;
	///���������־
	TSgitFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TSgitFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
	///ת�˽���״̬
	TSgitFtdcTransferStatusType	TransferStatus;
};

///���з��������ʽ�ת�ڻ���Ӧ
struct CSgitFtdcRspTransferField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�ڻ���˾��ˮ��
	TSgitFtdcFutureSerialType	FutureSerial;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TSgitFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TSgitFtdcTradeAmountType	TradeAmount;
	///�ڻ���ȡ���
	TSgitFtdcTradeAmountType	FutureFetchAmount;
	///����֧����־
	TSgitFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TSgitFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TSgitFtdcFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TSgitFtdcAddInfoType	Message;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TSgitFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TSgitFtdcBankAccountType	BankSecuAcc;
	///���������־
	TSgitFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TSgitFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
	///ת�˽���״̬
	TSgitFtdcTransferStatusType	TransferStatus;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///��������
struct CSgitFtdcReqRepealField
{
	///����ʱ����
	TSgitFtdcRepealTimeIntervalType	RepealTimeInterval;
	///�Ѿ���������
	TSgitFtdcRepealedTimesType	RepealedTimes;
	///���г�����־
	TSgitFtdcBankRepealFlagType	BankRepealFlag;
	///���̳�����־
	TSgitFtdcBrokerRepealFlagType	BrokerRepealFlag;
	///������ƽ̨��ˮ��
	TSgitFtdcPlateSerialType	PlateRepealSerial;
	///������������ˮ��
	TSgitFtdcBankSerialType	BankRepealSerial;
	///�������ڻ���ˮ��
	TSgitFtdcFutureSerialType	FutureRepealSerial;
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�ڻ���˾��ˮ��
	TSgitFtdcFutureSerialType	FutureSerial;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TSgitFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TSgitFtdcTradeAmountType	TradeAmount;
	///�ڻ���ȡ���
	TSgitFtdcTradeAmountType	FutureFetchAmount;
	///����֧����־
	TSgitFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TSgitFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TSgitFtdcFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TSgitFtdcAddInfoType	Message;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TSgitFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TSgitFtdcBankAccountType	BankSecuAcc;
	///���������־
	TSgitFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TSgitFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
	///ת�˽���״̬
	TSgitFtdcTransferStatusType	TransferStatus;
};

///������Ӧ
struct CSgitFtdcRspRepealField
{
	///����ʱ����
	TSgitFtdcRepealTimeIntervalType	RepealTimeInterval;
	///�Ѿ���������
	TSgitFtdcRepealedTimesType	RepealedTimes;
	///���г�����־
	TSgitFtdcBankRepealFlagType	BankRepealFlag;
	///���̳�����־
	TSgitFtdcBrokerRepealFlagType	BrokerRepealFlag;
	///������ƽ̨��ˮ��
	TSgitFtdcPlateSerialType	PlateRepealSerial;
	///������������ˮ��
	TSgitFtdcBankSerialType	BankRepealSerial;
	///�������ڻ���ˮ��
	TSgitFtdcFutureSerialType	FutureRepealSerial;
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�ڻ���˾��ˮ��
	TSgitFtdcFutureSerialType	FutureSerial;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TSgitFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TSgitFtdcTradeAmountType	TradeAmount;
	///�ڻ���ȡ���
	TSgitFtdcTradeAmountType	FutureFetchAmount;
	///����֧����־
	TSgitFtdcFeePayFlagType	FeePayFlag;
	///Ӧ�տͻ�����
	TSgitFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TSgitFtdcFutureFeeType	BrokerFee;
	///���ͷ������շ�����Ϣ
	TSgitFtdcAddInfoType	Message;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TSgitFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TSgitFtdcBankAccountType	BankSecuAcc;
	///���������־
	TSgitFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TSgitFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
	///ת�˽���״̬
	TSgitFtdcTransferStatusType	TransferStatus;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///��ѯ�˻���Ϣ����
struct CSgitFtdcReqQueryAccountField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///�ڻ���˾��ˮ��
	TSgitFtdcFutureSerialType	FutureSerial;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TSgitFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TSgitFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TSgitFtdcBankAccountType	BankSecuAcc;
	///���������־
	TSgitFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TSgitFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
};

///��ѯ�˻���Ϣ��Ӧ
struct CSgitFtdcRspQueryAccountField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///�ڻ���˾��ˮ��
	TSgitFtdcFutureSerialType	FutureSerial;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TSgitFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TSgitFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TSgitFtdcBankAccountType	BankSecuAcc;
	///���������־
	TSgitFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TSgitFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
	///���п��ý��
	TSgitFtdcTradeAmountType	BankUseAmount;
	///���п�ȡ���
	TSgitFtdcTradeAmountType	BankFetchAmount;
};

///����ǩ��ǩ��
struct CSgitFtdcFutureSignIOField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
};

///����ǩ����Ӧ
struct CSgitFtdcRspFutureSignInField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
	///PIN��Կ
	TSgitFtdcPasswordKeyType	PinKey;
	///MAC��Կ
	TSgitFtdcPasswordKeyType	MacKey;
};

///����ǩ������
struct CSgitFtdcReqFutureSignOutField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
};

///����ǩ����Ӧ
struct CSgitFtdcRspFutureSignOutField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///��ѯָ����ˮ�ŵĽ��׽������
struct CSgitFtdcReqQueryTradeResultBySerialField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///��ˮ��
	TSgitFtdcSerialType	Reference;
	///����ˮ�ŷ����ߵĻ�������
	TSgitFtdcInstitutionTypeType	RefrenceIssureType;
	///����ˮ�ŷ����߻�������
	TSgitFtdcOrganCodeType	RefrenceIssure;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TSgitFtdcTradeAmountType	TradeAmount;
	///ժҪ
	TSgitFtdcDigestType	Digest;
};

///��ѯָ����ˮ�ŵĽ��׽����Ӧ
struct CSgitFtdcRspQueryTradeResultBySerialField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
	///��ˮ��
	TSgitFtdcSerialType	Reference;
	///����ˮ�ŷ����ߵĻ�������
	TSgitFtdcInstitutionTypeType	RefrenceIssureType;
	///����ˮ�ŷ����߻�������
	TSgitFtdcOrganCodeType	RefrenceIssure;
	///ԭʼ���ش���
	TSgitFtdcReturnCodeType	OriginReturnCode;
	///ԭʼ����������
	TSgitFtdcDescrInfoForReturnCodeType	OriginDescrInfoForReturnCode;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///ת�ʽ��
	TSgitFtdcTradeAmountType	TradeAmount;
	///ժҪ
	TSgitFtdcDigestType	Digest;
};

///�����ļ���������
struct CSgitFtdcReqDayEndFileReadyField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�ļ�ҵ����
	TSgitFtdcFileBusinessCodeType	FileBusinessCode;
	///ժҪ
	TSgitFtdcDigestType	Digest;
};

///���ؽ��
struct CSgitFtdcReturnResultField
{
	///���ش���
	TSgitFtdcReturnCodeType	ReturnCode;
	///����������
	TSgitFtdcDescrInfoForReturnCodeType	DescrInfoForReturnCode;
};

///��֤�ڻ��ʽ�����
struct CSgitFtdcVerifyFuturePasswordField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///����ID
	TSgitFtdcTIDType	TID;
};

///��֤�ͻ���Ϣ
struct CSgitFtdcVerifyCustInfoField
{
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
};

///��֤�ڻ��ʽ�����Ϳͻ���Ϣ
struct CSgitFtdcVerifyFuturePasswordAndCustInfoField
{
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
};

///��֤�ڻ��ʽ�����Ϳͻ���Ϣ
struct CSgitFtdcDepositResultInformField
{
	///�������ˮ�ţ�����ˮ��Ϊ���ڱ��̷��ص���ˮ��
	TSgitFtdcDepositSeqNoType	DepositSeqNo;
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///�����
	TSgitFtdcMoneyType	Deposit;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///���ش���
	TSgitFtdcReturnCodeType	ReturnCode;
	///����������
	TSgitFtdcDescrInfoForReturnCodeType	DescrInfoForReturnCode;
};

///���׺��������ڱ��̷�����Կͬ������
struct CSgitFtdcReqSyncKeyField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///���׺��ĸ����ڱ��̵���Ϣ
	TSgitFtdcAddInfoType	Message;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
};

///���׺��������ڱ��̷�����Կͬ����Ӧ
struct CSgitFtdcRspSyncKeyField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///���׺��ĸ����ڱ��̵���Ϣ
	TSgitFtdcAddInfoType	Message;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///��ѯ�˻���Ϣ֪ͨ
struct CSgitFtdcNotifyQueryAccountField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///�ڻ���˾��ˮ��
	TSgitFtdcFutureSerialType	FutureSerial;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///��֤�ͻ�֤�������־
	TSgitFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TSgitFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TSgitFtdcBankAccountType	BankSecuAcc;
	///���������־
	TSgitFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TSgitFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
	///���п��ý��
	TSgitFtdcTradeAmountType	BankUseAmount;
	///���п�ȡ���
	TSgitFtdcTradeAmountType	BankFetchAmount;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///����ת�˽�����ˮ��
struct CSgitFtdcTransferSerialField
{
	///ƽ̨��ˮ��
	TSgitFtdcPlateSerialType	PlateSerial;
	///���׷�������
	TSgitFtdcTradeDateType	TradeDate;
	///��������
	TSgitFtdcDateType	TradingDay;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///���״���
	TSgitFtdcTradeCodeType	TradeCode;
	///�Ự���
	TSgitFtdcSessionIDType	SessionID;
	///���б���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///�ڻ���˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///�ڻ���˾�ʺ�����
	TSgitFtdcFutureAccTypeType	FutureAccType;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///Ͷ���ߴ���
	TSgitFtdcInvestorIDType	InvestorID;
	///�ڻ���˾��ˮ��
	TSgitFtdcFutureSerialType	FutureSerial;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///���׽��
	TSgitFtdcTradeAmountType	TradeAmount;
	///Ӧ�տͻ�����
	TSgitFtdcCustFeeType	CustFee;
	///Ӧ���ڻ���˾����
	TSgitFtdcFutureFeeType	BrokerFee;
	///��Ч��־
	TSgitFtdcAvailabilityFlagType	AvailabilityFlag;
	///����Ա
	TSgitFtdcOperatorCodeType	OperatorCode;
	///�������ʺ�
	TSgitFtdcBankAccountType	BankNewAccount;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///�����ѯת����ˮ
struct CSgitFtdcQryTransferSerialField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///���б���
	TSgitFtdcBankIDType	BankID;
};

///����ǩ��֪ͨ
struct CSgitFtdcNotifyFutureSignInField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
	///PIN��Կ
	TSgitFtdcPasswordKeyType	PinKey;
	///MAC��Կ
	TSgitFtdcPasswordKeyType	MacKey;
};

///����ǩ��֪ͨ
struct CSgitFtdcNotifyFutureSignOutField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///���׺��������ڱ��̷�����Կͬ����������֪ͨ
struct CSgitFtdcNotifySyncKeyField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///�û���ʶ
	TSgitFtdcUserIDType	UserID;
	///���׺��ĸ����ڱ��̵���Ϣ
	TSgitFtdcAddInfoType	Message;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///������
	TSgitFtdcRequestIDType	RequestID;
	///����ID
	TSgitFtdcTIDType	TID;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///�����ѯ����ǩԼ��ϵ
struct CSgitFtdcQryAccountregisterField
{
	///���͹�˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///���б���
	TSgitFtdcBankIDType	BankID;
};

///�ͻ���������Ϣ��
struct CSgitFtdcAccountregisterField
{
	///��������
	TSgitFtdcTradeDateType	TradeDay;
	///���б���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///�ڻ���˾����
	TSgitFtdcBrokerIDType	BrokerID;
	///�ڻ���˾��֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///���������
	TSgitFtdcOpenOrDestroyType	OpenOrDestroy;
	///ǩԼ����
	TSgitFtdcTradeDateType	RegDate;
	///��Լ����
	TSgitFtdcTradeDateType	OutDate;
	///����ID
	TSgitFtdcTIDType	TID;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
};

///���ڿ�����Ϣ
struct CSgitFtdcOpenAccountField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TSgitFtdcGenderType	Gender;
	///���Ҵ���
	TSgitFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///��ַ
	TSgitFtdcAddressType	Address;
	///�ʱ�
	TSgitFtdcZipCodeType	ZipCode;
	///�绰����
	TSgitFtdcTelephoneType	Telephone;
	///�ֻ�
	TSgitFtdcMobilePhoneType	MobilePhone;
	///����
	TSgitFtdcFaxType	Fax;
	///�����ʼ�
	TSgitFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TSgitFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TSgitFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///�㳮��־
	TSgitFtdcCashExchangeCodeType	CashExchangeCode;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TSgitFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TSgitFtdcBankAccountType	BankSecuAcc;
	///���������־
	TSgitFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TSgitFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///����ID
	TSgitFtdcTIDType	TID;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///����������Ϣ
struct CSgitFtdcCancelAccountField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TSgitFtdcGenderType	Gender;
	///���Ҵ���
	TSgitFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///��ַ
	TSgitFtdcAddressType	Address;
	///�ʱ�
	TSgitFtdcZipCodeType	ZipCode;
	///�绰����
	TSgitFtdcTelephoneType	Telephone;
	///�ֻ�
	TSgitFtdcMobilePhoneType	MobilePhone;
	///����
	TSgitFtdcFaxType	Fax;
	///�����ʼ�
	TSgitFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TSgitFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TSgitFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///�㳮��־
	TSgitFtdcCashExchangeCodeType	CashExchangeCode;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
	///������־
	TSgitFtdcDeviceIDType	DeviceID;
	///�ڻ���λ�ʺ�����
	TSgitFtdcBankAccTypeType	BankSecuAccType;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///�ڻ���λ�ʺ�
	TSgitFtdcBankAccountType	BankSecuAcc;
	///���������־
	TSgitFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TSgitFtdcPwdFlagType	SecuPwdFlag;
	///���׹�Ա
	TSgitFtdcOperNoType	OperNo;
	///����ID
	TSgitFtdcTIDType	TID;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///���ڱ�������˺���Ϣ
struct CSgitFtdcChangeAccountField
{
	///ҵ������
	TSgitFtdcTradeCodeType	TradeCode;
	///���д���
	TSgitFtdcBankIDType	BankID;
	///���з�֧��������
	TSgitFtdcBankBrchIDType	BankBranchID;
	///���̴���
	TSgitFtdcBrokerIDType	BrokerID;
	///���̷�֧��������
	TSgitFtdcFutureBranchIDType	BrokerBranchID;
	///��������
	TSgitFtdcTradeDateType	TradeDate;
	///����ʱ��
	TSgitFtdcTradeTimeType	TradeTime;
	///������ˮ��
	TSgitFtdcBankSerialType	BankSerial;
	///����ϵͳ���� 
	TSgitFtdcTradeDateType	TradingDay;
	///����ƽ̨��Ϣ��ˮ��
	TSgitFtdcSerialType	PlateSerial;
	///����Ƭ��־
	TSgitFtdcLastFragmentType	LastFragment;
	///�Ự��
	TSgitFtdcSessionIDType	SessionID;
	///�ͻ�����
	TSgitFtdcIndividualNameType	CustomerName;
	///֤������
	TSgitFtdcIdCardTypeType	IdCardType;
	///֤������
	TSgitFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///�Ա�
	TSgitFtdcGenderType	Gender;
	///���Ҵ���
	TSgitFtdcCountryCodeType	CountryCode;
	///�ͻ�����
	TSgitFtdcCustTypeType	CustType;
	///��ַ
	TSgitFtdcAddressType	Address;
	///�ʱ�
	TSgitFtdcZipCodeType	ZipCode;
	///�绰����
	TSgitFtdcTelephoneType	Telephone;
	///�ֻ�
	TSgitFtdcMobilePhoneType	MobilePhone;
	///����
	TSgitFtdcFaxType	Fax;
	///�����ʼ�
	TSgitFtdcEMailType	EMail;
	///�ʽ��˻�״̬
	TSgitFtdcMoneyAccountStatusType	MoneyAccountStatus;
	///�����ʺ�
	TSgitFtdcBankAccountType	BankAccount;
	///��������
	TSgitFtdcPasswordType	BankPassWord;
	///�������ʺ�
	TSgitFtdcBankAccountType	NewBankAccount;
	///����������
	TSgitFtdcPasswordType	NewBankPassWord;
	///Ͷ�����ʺ�
	TSgitFtdcAccountIDType	AccountID;
	///�ڻ�����
	TSgitFtdcPasswordType	Password;
	///�����ʺ�����
	TSgitFtdcBankAccTypeType	BankAccType;
	///��װ���
	TSgitFtdcInstallIDType	InstallID;
	///��֤�ͻ�֤�������־
	TSgitFtdcYesNoIndicatorType	VerifyCertNoFlag;
	///���ִ���
	TSgitFtdcCurrencyIDType	CurrencyID;
	///�ڻ���˾���б���
	TSgitFtdcBankCodingForFutureType	BrokerIDByBank;
	///���������־
	TSgitFtdcPwdFlagType	BankPwdFlag;
	///�ڻ��ʽ�����˶Ա�־
	TSgitFtdcPwdFlagType	SecuPwdFlag;
	///����ID
	TSgitFtdcTIDType	TID;
	///ժҪ
	TSgitFtdcDigestType	Digest;
	///�������
	TSgitFtdcErrorIDType	ErrorID;
	///������Ϣ
	TSgitFtdcErrorMsgType	ErrorMsg;
};

///�ֱ����Ľ���Ȩ��
struct CSgitFtdcUserRightsAssignField
{
	///Ӧ�õ�Ԫ����
	TSgitFtdcBrokerIDType	BrokerID;
	///�û�����
	TSgitFtdcUserIDType	UserID;
	///�������Ĵ���
	TSgitFtdcDRIdentityIDType	DRIdentityID;
};

///���ù�˾�Ƿ����ڱ���ʾ�Ľ���Ȩ��
struct CSgitFtdcBrokerUserRightAssignField
{
	///Ӧ�õ�Ԫ����
	TSgitFtdcBrokerIDType	BrokerID;
	///�������Ĵ���
	TSgitFtdcDRIdentityIDType	DRIdentityID;
	///�ܷ���
	TSgitFtdcBoolType	Tradeable;
};

///�ֱ�����ת������
struct CSgitFtdcDRTransferField
{
	///ԭ�������Ĵ���
	TSgitFtdcDRIdentityIDType	OrigDRIdentityID;
	///Ŀ�꽻�����Ĵ���
	TSgitFtdcDRIdentityIDType	DestDRIdentityID;
	///ԭӦ�õ�Ԫ����
	TSgitFtdcBrokerIDType	OrigBrokerID;
	///Ŀ�����õ�Ԫ����
	TSgitFtdcBrokerIDType	DestBrokerID;
};

//��Լ��λ��ѯ��
struct CSgitMBLQuotReq
{
	TSgitFtdcInstrumentIDType  StartContractID;     //��ʼ��Լ��
	TSgitFtdcInstrumentIDType  EndContractID;       //������Լ��
	TSgitFtdcDirectionType     BsFlag;              //������־
};

//��Լ��λ��
struct CSgitMBLQuotData
{
	TSgitFtdcInstrumentIDType  ContractID;          //��Լ��
	TSgitFtdcDirectionType     BsFlag;              //������־
	TSgitFtdcPriceType         Price;               //�۸�
	TSgitFtdcVolumeType        Qty;                 //����
};

//���ĺ�Լ��������
struct CSgitSubQuotField
{
	TSgitFtdcInstrumentIDType  ContractID;     //��Լ��
};

#endif
