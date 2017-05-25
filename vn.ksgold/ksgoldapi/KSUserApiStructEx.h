
#if !defined(KINSTARAPI_THOST_FTDCSTRUCT_H)
#define KINSTARAPI_THOST_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "KSUserApiDataTypeEx.h"

//namespace KingstarAPI
//{


///�û���¼����
struct CThostFtdcReqUserLoginField
{
	TThostFtdcTraderIDType   accountID;				//��¼�ʺ�
	TThostFtdcLoginType      loginType ;             //��¼����
	TThostFtdcMemberIDType   memberID;				//��Ա����
	TThostFtdcPasswordType   password;				//����
	TThostFtdcDateType       tradeDate;				//��������
};

///�û���¼Ӧ��
struct CThostFtdcRspUserLoginField
{
	TThostFtdcDateType       tradeDate;				//��������
	TThostFtdcOrderRefType  localOrderNo;			//��󱾵ر�����
	TThostFtdcLoginBatchType  loginbatch;			//��¼����
	TThostFtdcClientIDType  tradeCode;			   	//���ױ���		
	TThostFtdcClientIDType  clientID;         		//�ͻ���
	TThostFtdcSeatIDType    SeatNo ;				//ϯλ��
	TThostFtdcCSRCInvestorNameType clientName;		//�ͻ�����
	TThostFtdcIPAddressType	lastLoginIp;			//�ϴε�¼IP��ַ
	TThostFtdcDateType		lastLoginDate;			//�ϴε�¼����
	TThostFtdcTimeType		lastLoginTime;			//�ϴε�¼ʱ��
};
///�û��ǳ�����
struct CThostFtdcUserLogoutField
{
	TThostFtdcTraderIDType  traderID;				//�ͻ���
};




///��Լ
struct CThostFtdcInstrumentField
{
	TThostFtdcExchangeIDType     exchangeID;   //1		����������	��	
	TThostFtdcInstrumentIDType   instID;       //2		��Լ����	��	
	TThostFtdcRateType           lowerLimit;   //3		��ͣ����		
	TThostFtdcMarketIDType       marketID;     //4		�г�����	��	
	TThostFtdcVolumeType         maxHand;      //5		����걨����	��	
	TThostFtdcVolumeType         minHand;      //6		��С�걨����	��	
	TThostFtdcInstrumentNameType       name;         //7		��Լ����	��	
	TThostFtdcOpenFlagType       openFlag;     //8		��Ծ��־		1��Ծ2����Ծ3ֻƽ 4ֻ��
	TThostFtdcPriceType          tick;         //9		��С�䶯��λ		
	TThostFtdcInstStateFlagType  tradeState;	  //10		��Լ����״̬		
	TThostFtdInstUnitType        unit;         //11		���׵�λ����	��	
	TThostFtdcRateType           upperLimit;   //12		��ͣ����		
	TThostFtdcVarietyIDType      varietyID;    //13		����Ʒ�ִ���	��	
	TThostFtdcVarietyType    varietyType;  //14		Ʒ�����	
	TThostFtdcMarketType     marketType;   //�г���־���ֻ������ӡ���
	
};

//��ѯ�ʽ��˻�
struct CThostFtdcQryTradingAccountField
{
	TThostFtdcMSGType remian; //�����ֶ�	
};

///�ʽ��˻�
struct CThostFtdcTradingAccountField
{
	TThostFtdcMoneyType   availCap;        //2		�����ʽ�	��	
	TThostFtdcMoneyType   available;       //3		�����ʽ�	��	
	TThostFtdcMoneyType   posiMargin;      //4		�ֱֲ�֤��	��	
	TThostFtdcMoneyType	  buyPosiMargin;   //5		��ֱֲ�֤��	��	
	TThostFtdcMoneyType	  sellPosiMargin;  //6		���ֱֲ�֤��	��	
	TThostFtdcMoneyType	  storageMargin;   //8		�ִ���֤��	��	
	TThostFtdcMoneyType	  totalFee;;       //9		��������	��	
	TThostFtdcMoneyType   totalFrozen;     //10		�ܶ����ʽ�	��	
	TThostFtdcMoneyType   orderFrozen;     //11		ί�ж���	��	
	TThostFtdcMoneyType   spotSellFrozen;  //12		�ֻ���������	��	
	TThostFtdcMoneyType   todayIn;         //13		�������	��	
	TThostFtdcMoneyType   todayOut;        //14		���ճ���	��	
	TThostFtdcMoneyType   lastFrozen;      //17		���ն����ʽ�	��	
	TThostFtdcMoneyType   totalFrozenFee;  //18		�ܶ���������	��	
	TThostFtdcMoneyType   pickUpMargin;    // 19		�����֤��	��	
	TThostFtdcMoneyType   middleMargin;    //20		�����ֱ�֤��	��	
	

};

///Ͷ���ֲ߳�
struct CThostFtdcInvestorPositionField
{
	TThostFtdcInstrumentIDType    instID;			 //4		��Լ����	��	
	TThostFtdcVolumeType    longPosi;		 //5		������ֲ���	��	
	TThostFtdcPriceType     longPosiAvgPrice; //6		��־���	��	
	TThostFtdcVolumeType    shortPosi;		 //7		�������ֲ���	��	
	TThostFtdcPriceType     shortPosiAvgPrice;//8		���־���	��	
	TThostFtdcPriceType     longOpenAvgPrice; //9		�򿪾���	��	
	TThostFtdcPriceType     shortOpenAvgPrice;//10		��������	��	
	TThostFtdcVolumeType    longPosiFrozen;   //11		��ֲֶ���	��	
	TThostFtdcVolumeType    shortPosiFrozen;  //12		���ֲֶ���	��	
	TThostFtdcVolumeType    longPosiVol;      //13		��ֲ�����	��	
	TThostFtdcVolumeType    shortPosiVol;     //14		���ֲ�����	��	
	TThostFtdcVolumeType    todayLong;        //15		������	��	
	TThostFtdcVolumeType    todayShort;       //16		��������	��	
	TThostFtdcVolumeType    todayOffsetShort; //17		������ƽ	��	
	TThostFtdcVolumeType    todayOffsetLong;  //18		������ƽ	��	
	TThostFtdcVolumeType    lastLong;         //19		������ֲ�	��	
	TThostFtdcVolumeType    lastShort;        //20		�������ֲ�	��	
	

};



///��Ӧ��Ϣ
struct CThostFtdcRspInfoField
{
	///�������
	TThostFtdcErrorIDType	ErrorID;
	///������Ϣ
	TThostFtdcErrorMsgType	ErrorMsg;
};
///�������
struct CThostFtdcDepthMarketDataField
{
	TThostFtdcInstrumentIDType		InstID ;       	/**<��Լ���� */
	TThostFtdcInstrumentNameType	Name ;	    	/**<��Լ���� */
	TThostFtdcMarketNameType		MarketName ;	/**<�г����� */
	TThostFtdcPriceType				PreSettle ;			/**<����� */
	TThostFtdcPriceType				PreClose ;			/**<������ */
	TThostFtdcPriceType				Open ;				/**<���̼� */
	TThostFtdcPriceType				High ;				/**<��߼� */
	TThostFtdcPriceType				Low ;				/**<��ͼ� */
	TThostFtdcPriceType				Last ;				/**<���¼� */
	TThostFtdcPriceType				Close ;				/**<���̼� */
	TThostFtdcPriceType				Bid1 ;				/**<������һ */
	TThostFtdcVolumeType			BidLot1 ;			/**<�������һ */
	TThostFtdcPriceType				Ask1 ;				/**<�������һ */
	TThostFtdcVolumeType			AskLot1 ;			/**<�������һ */
	TThostFtdcPriceType				Bid2 ;				/**<�����۶� */
	TThostFtdcVolumeType			BidLot2 ;			/**<��������� */
	TThostFtdcPriceType				Ask2 ;				/**<������۶� */
	TThostFtdcVolumeType			AskLot2 ;			/**<��������� */
	TThostFtdcPriceType				Bid3 ;				/**<�������� */
	TThostFtdcVolumeType			BidLot3 ;			/**<��������� */
	TThostFtdcPriceType				Ask3 ;				/**<��������� */
	TThostFtdcVolumeType			AskLot3 ;			/**<��������� */
	TThostFtdcPriceType				Bid4 ;				/**<�������� */
	TThostFtdcVolumeType			BidLot4 ;			/**<��������� */
	TThostFtdcPriceType				Ask4 ;				/**<��������� */
	TThostFtdcVolumeType			AskLot4 ;			/**<��������� */
	TThostFtdcPriceType				Bid5 ;				/**<�������� */
	TThostFtdcVolumeType			BidLot5 ;			/**<��������� */
	TThostFtdcPriceType				Ask5 ;				/**<��������� */
	TThostFtdcVolumeType			AskLot5 ;			/**<��������� */
	TThostFtdcVolumeType			Volume ;			/**<�ɽ�����˫�ߣ� */
	TThostFtdcVolumeType			OpenInt ;			/**<�ֲ�����˫�ߣ� */
	TThostFtdcPriceType				UpDown ;			/**<�ǵ� */
	TThostFtdcMoneyType				Turnover ;			/**<�ɽ��� */
	TThostFtdcPriceType				Settle ;			/**<����� */
	TThostFtdcPriceType				Average ;			/**<���� */
	TThostFtdcDateType				QuoteDate ;			/**<�������� */
	TThostFtdcTimeType				QuoteTime ;			/**<����ʱ�� */
	TThostFtdcWeightType			weight;			//�ɽ���˫�ߣ�����
	TThostFtdcPriceType				highLimit;			//��ͣ��
	TThostFtdcPriceType				lowLimit;			//��ͣ��
	TThostFtdcRateType				UpDownRate;				//�ǵ�����
	

};


///���뱨��
struct CThostFtdcInputOrderField
{
	TThostFtdcSeatIDType			seatID;          //2		ϯλ��	��	
	TThostFtdcClientIDType			tradeCode;        //3		���ױ���	��		
	TThostFtdcInstrumentIDType      instID;          //5		Ʒ�ִ���	��	
	TThostFtdcBsFlagType			buyOrSell;       //6		��������	��
	TThostFtdcOffsetFlagType		offsetFlag;      //7		��ƽ��־	��	
	TThostFtdcVolumeType			amount;          //8		ί������	��	
	TThostFtdcByteType				middleFlag;      //9		�����ֱ�־	��	����Ϊ0	
	TThostFtdcByteType				priceFlag;       //11		����ί�м۸�����	��	
	TThostFtdcPriceType				price;           //12		Ԥί�м۸�	��	
	TThostFtdcPriceType				trigPrice;	      //13       Ԥί�д����۸�	��	
	TThostFtdcMarketIDType			marketID;        //14		�г�����	��	
	TThostFtdcOrderRefType			LocalOrderNo;	 //			���ر�����
	TThostFtdcTradeWayType			tradeWay;		 //19		��������	��	
};

///����
struct CThostFtdcOrderField
{
	TThostFtdcOrderNoType			orderNo;				//1		ϵͳ������	��	
	TThostFtdcOrderRefType			localOrderNo;;			//2		���ر�����	��	
	TThostFtdcMarketIDType			marketID;				//4		�г�����	��	
	TThostFtdcInstrumentIDType      instID;				//5		��Լ����	��	
	TThostFtdcBsFlagType			buyOrSell;				//7		��������	��	
	TThostFtdcOffsetFlagType		offsetFlag;			 //8		��ƽ��־	��	
	TThostFtdcVolumeType			amount;				//9		ί������	��	
	TThostFtdcWeightType			weight;				//10		ί������	��	����Ϊ0
	TThostFtdcPriceType				price;					//11		ί�м۸�	��	
	TThostFtdcVolumeType			matchQty;				//12		�ɽ�����	��	
	TThostFtdcWeightType			matchWeight;			 //13		�ɽ�����	��	
	TThostFtdcOrderStatusType		status;				//14       ί��״̬	��	
	TThostFtdcTimeType				entrustTime;				//15		ί��ʱ��	��	
	TThostFtdcByteType				forceoffset_flag;			 //16		ǿƽ��־	��	
	TThostFtdcVolumeType			cancelQty;			//17		��������	��	
	TThostFtdcTimeType				cancelTime;			 //18����ʱ��
	TThostFtdcTradeWayType			tradeWay;				//19		��������	��	
};

///���������ر�
struct CThostFtdcOrderRtnField
{
	TThostFtdcOrderNoType			orderNo;				//1		ϵͳ������	��	
	TThostFtdcOrderRefType			localOrderNo;;			//2		���ر�����	��	
	TThostFtdcOrderStatusType		status;					//14    ί��״̬	��	
	TThostFtdcVolumeType			cancelQty;				//17	��������	��
};


///���뱨������(cancel order)
struct CThostFtdcInputOrderActionField
{
	TThostFtdcOrderRefType		localOrderNo;     //1		���ر�����	��
	TThostFtdcMarketIDType		marketID;		  //2		�г�����	��
	TThostFtdcOrderStatusType	status;			  //14      ί��״̬	
};

///��������
struct CThostFtdcOrderActionField
{
	TThostFtdcOrderRefType		localOrderNo;     //1		���ر�����	��	
	TThostFtdcByteType			orderFlag;       //2		ί�б�־	��	
	TThostFtdcMarketIDType		marketID;		  //3		�г�����	��	
	TThostFtdcTraderIDType		traderID;         //6		��������Ա	��	
	TThostFtdcTradeWayType      tradeWay;         //7		ί������	��	д��"5"
	

};
///�ɽ�
struct CThostFtdcTradeField
{
	TThostFtdcOrderNoType			orderNo;           //1		ϵͳ������	��	
	TThostFtdcMatchNoType			matchNo;           //2		�ɽ������	��	
	TThostFtdcInstrumentIDType		instID;            //3		��Լ����	��	
	TThostFtdcBsFlagType			buyOrSell;	     //5		��������	��	
	TThostFtdcOffsetFlagType		offSetFlag;     //6		��ƽ��־	��	
	TThostFtdcPriceType				price;             //7		�ɽ��۸�	��	
	TThostFtdcVolumeType			volume;            //8		�ɽ�����	��	
	TThostFtdcMoneyType				amount;            //9		�ɽ����	��	
	TThostFtdcWeightType			weight;            //10		�ɽ�����	��	
	TThostFtdcByteType				order_flag;        //11		ί������	��	
	TThostFtdcDateType				matchDate;	     //12		�ɽ�����	��	
	TThostFtdcTimeType				matchTime;         //13		�ɽ�ʱ��	��	
	TThostFtdcOrderRefType			localOrderNo;	     //14		���ر�����	��	
	TThostFtdcMarketIDType			marketID;	     //15		�г�����	��	
	TThostFtdcMoneyType				trade_fee;         //16		������	��	
	TThostFtdcByteType				forceoffset_flag;  //17		ǿƽ��־	��	
	TThostFtdcVolumeType			forcebatchnum ;    //18		ǿƽ���κ�	��
	TThostFtdcTradeWayType			tradeWay;          //������־
};

///��ѯ��Լ
struct CThostFtdcQryInstrumentField
{
	TThostFtdcContractIDType  ContractID;          /*��Լ��*/
	TThostFtdcProductIDType   ProductID;           /*��Ʒ����*/


};


///��ѯ�ɽ�
struct CThostFtdcQryTradeField
{
	TThostFtdcMatchNoType		matchNo;			//�ɽ����
	TThostFtdcInstrumentIDType  instID;				//��Լ����
	TThostFtdcMarketIDType		marketID;			//�г�����
	TThostFtdcOrderRefType		localOrderNo;		//���ر������
};


///��ѯ����
struct CThostFtdcQryOrderField
{
	TThostFtdcInstrumentIDType  instID;				//��Լ����
	TThostFtdcMarketIDType		marketID;			//�г�����
	TThostFtdcOrderRefType		localOrderNo;		//���ر������
};




///��ѯͶ���ֲ߳�
struct CThostFtdcQryInvestorPositionField
{
	TThostFtdcMarketIDType		marketID;			//�г�����
	TThostFtdcInstrumentIDType	instID;         //��Լ����
};


///��ѯ���
struct CThostFtdcQryStorageField
{
	TThostFtdcVarietyIDType  varietyID;            //����Ʒ�ִ���
};

//���Ӧ��
struct CThostFtdcStorageField
{
	TThostFtdcVarietyIDType  varietyID;            //3		����Ʒ�ִ���	��	
	TThostFtdcAbbrType       varietyName;          //4		����Ʒ�ּ��	��	
	TThostFtdcWeightType     totalStorage;         //6		�������	��	
	TThostFtdcWeightType     availableStorage;     //7		���ÿ��	��	
	TThostFtdcWeightType     frozenStorage;	      //8		�ֻ�������	��	
	TThostFtdcWeightType     pendStorage;          //9		������	��	
	TThostFtdcWeightType     todayBuy;             //10		��������	��	
	TThostFtdcWeightType     todaySell;	          //11		��������	��	
	TThostFtdcWeightType     todayDeposit;         //12		���մ���	��	
	TThostFtdcWeightType     todayRealDeposit;     //13		�������	��	
	TThostFtdcWeightType     todayBorrow;          //14		���ս���	��	
	TThostFtdcWeightType     todayLend;	          //15		���ս��	��	
	TThostFtdcWeightType     impawnStorage;        //16		��Ѻ���	��	
	TThostFtdcWeightType     lawFrozen;            //17		���ɶ�����	��	
	TThostFtdcWeightType     bankFrozen;           //18		���ж�����	��	
	TThostFtdcByteType       customType;           //19		�ͻ����	��	
	TThostFtdcWeightType     storageCost;          //20		���ɱ�	��	
	TThostFtdcWeightType     impawnFrozen ;        //22		��Ѻ������	��	

};

//�г�״̬
struct CThostFtdcMarketStatusField
{
	TThostFtdcMktStatusType   MktStatus;           /*�г�״̬*/
	TThostFtdcMarketIDType    marketID  ;         /*�г�����*/
	//TThostFtdcExchCodeType   ExchCode;            /*����������*/
	//TThostFtdcMktChgTimeType  MktChgTime;          /*״̬����ʱ��*/

};
///ָ���ĺ�Լ
struct CThostFtdcSpecificInstrumentField
{
	///��Լ����
	TThostFtdcInstrumentIDType	InstrumentID;
};


//}	// end of namespace KingstarAPI

#endif
