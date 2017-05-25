#pragma once

#include <map>
using namespace std;
#ifndef ShZdMessage_H
#define ShZdMessage_H

#ifdef DLL_FILE
 class _declspec(dllexport) CShZdMessage  //������CShZdMessage
#else
 class _declspec(dllimport) CShZdMessage  //������CShZdMessage
#endif
{
public:
	CShZdMessage(void);
	~CShZdMessage(void);
	bool SetTag(const int tag,const char* value);	
	char* GetString(int tag);
	bool SetAllRead(int read);//����������Ϣ�ṹ��Ϊ�Ѷ���δ��
	const char* GetMesgType();
	bool SetMsgType(const char *msgType);
	string GetAllString();//�������е��ַ���
private:	
	map<int,string> MsgBody;//��Ϣ��
};

#endif 