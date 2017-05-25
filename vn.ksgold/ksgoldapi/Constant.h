#ifndef _NEWCONSTANT_H
#define _NEWCONSTANT_H
//�г����� ������:TMarketType
#define SPOT		"00"     //�ֻ�
#define DEFER		"10"     //����
#define FUTURES		"11"     //�ڻ�
#define FORWARD		"01"     //Զ��
#define DELIVERY	"AP"	 //����
#define MIDDLE		"MD"	 //������


//�г�״̬
#define M_INITING	'0'     //��ʼ����
#define M_INIT		'1'     //��ʼ�����
#define M_OPEN		'2'     //����
#define M_TRADE		'3'     //����
#define M_PAUSE		'4'     //��ͣ
#define M_CLOSE		'5'     //����

//ί�е�״̬
#define Entrust_Sending				'1'			//1���Ѿ����ͣ�
#define Entrust_Waiting				'2'			//2���ȴ�����
#define Entrust_In				'3'			//3���Ѿ����룻
#define Entrust_All_Cancel			'4'			//4��ȫ��������
#define Entrust_All_Done			'5'			//5��ȫ���ɽ���
#define Entrust_Part_Done			'6'			//6�����ֳɽ���
#define Entrust_Part_Done_Cancel		'7'			//7�����ɲ���
#define Entrust_Wait_Cancel			'8'			//�ȴ�����
#define Entrust_Error				'9'			//����ί��
#define Entrust_By_Exch				'A'			//���ڳ���
#define Entrust_By_Emergency			'B'			//Ӧ������


//��ƽ�ֱ�־ ������:TOffsetFlag
#define P_OPEN		    '0'     //����
#define p_OFFSET	    '1'     //ƽ��


//���������־ ������:TBSFlag
#define BUY		'0'     //��
#define SELL	'1'     //��

//ί������
#define  SPOT_ENTRUST     '0' //�ֻ�
#define  TN_ENTRUST       '4' //�ֻ�T+N
#define  DEFER_ENTRUST    '1' //�ֻ�����
#define  DELIVERY_ENTRUST '2' //����
#define  MIDDLE_ENTRUST   '3' //������

//��������
#define  COUNTER_CHANNEL  '1' //��̨
#define  TEL_CHANNEL      '2' //�绰����
#define  NET_CHANNEL      '3' //����
#define  TRADER_CHANNEL   '4' //����Ա
#define  SELF_CHANNEL	  '5' //�����ն�
#define  PHONE_CHANNEL	  '6' //�ֻ�����
#define  TRADEAPI_CHANNEL '7' //����API

//�ͻ����
#define CLIENT_SPOT    '0' //�ֻ�
#define CLIENT_FUTURE  '1' //�ڻ�
#define CLIENT_GENERAL '2' //ͨ��

//��¼����
#define BANKACC_TYPE   "1" //�����˺ŵ�¼
#define TRADECODE_TYPE "2" //���ױ����¼

//��Ծ��־
#define ACTIVITY_ON '1' //ѯ�ۺ�Լ

#endif _NEWCONSTANT_H
