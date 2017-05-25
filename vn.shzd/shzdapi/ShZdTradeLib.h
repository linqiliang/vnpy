//================================================================================== 
//���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� SHZDTRADELIB_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// SHZDTRADELIB_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
// ������ 2013-03-22
//===================================================================================
#pragma once
#include "ShZdMessage.h"
#ifdef SHZDTRADELIB_EXPORTS
#define SHZDTRADELIB_API __declspec(dllexport)
#else
#define SHZDTRADELIB_API __declspec(dllimport)
#endif

#ifdef __cplusplus
//===================================================================================
// ���⵼���Ľӿ�
//===================================================================================
//������Ϣ������
class SHZDTRADELIB_API IShZdTradeOutLib
{
	public:
		virtual int OnReceiveTradeInfo(const CShZdMessage * re)=0;
		virtual int OnReceiveMarketInfo(const CShZdMessage * re)=0;
		virtual int OnReceiveErrorInfo(int errorCode,const char* re)=0;
};

typedef IShZdTradeOutLib* IShZdTradeOutLibHandler;
//������Ϣ������
class  SHZDTRADELIB_API IShZdTradeInLib
{
	public:
		virtual void Release() = 0;	
		virtual int InitShZdServer()=0;//��ʼ��������
		virtual int RegisterFront(const char *pszFrontAddress,int portNum)=0; //����ǰ�÷����� 
		virtual int RegisterMarket(const char *pszMarketAddress,int portNum)=0;//�������������
		virtual int ShZdSendInfoToTrade(const CShZdMessage *send)=0; //��ǰ�÷��������ͽ�������	
		virtual int ShZdSendInfoToMarket(const CShZdMessage *send)=0;//�����������������������
		virtual int RegisterOutLib(IShZdTradeOutLibHandler handler)=0;
};

typedef IShZdTradeInLib* ShZdTradeInLibHandle;
// �����Ǵ� ShZdTradeLib.dll ������
class SHZDTRADELIB_API CShZdTradeLib {
	public:			
};
#else  

#endif

#ifdef __cplusplus
#   define EXTERN_C     extern "C"
#else
#   define EXTERN_C
#endif

EXTERN_C SHZDTRADELIB_API ShZdTradeInLibHandle GetShZdTradeLib(void);
