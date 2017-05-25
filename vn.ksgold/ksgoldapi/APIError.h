#ifndef API_ERROR_H
#define API_ERROR_H
#define ERR_SUCCESS				0	//�ɹ�
#define ERR_UNKNOWN				-1	//δ֪����
#define ERR_API_NOT_INITED		-2	//APIδ����
#define ERR_NOT_CONNECTED		-3	//δ����
#define ERR_NOT_LOGIN			-4	//δ��¼
#define ERR_ALREADY_LOGIN		-5	//�Ѿ���¼
#define ERR_TIME_OUT			-6	//��ʱ
#define ERR_STREAM_CONTROL		-7//�ܵ�����
#define ERR_LOGON_GATEWAY		-8//��½����ʧ��
#define ERR_REGISTER_QUOT		-9//ע���������ͷ���ʧ��
#define ERR_QUERY_QUOTSERVER_LIST   -10//��ѯ�������վ��ʧ��
#define ERR_LOGOUT_BACK         -11            //�ǳ�ʧ��,��̨����
#define ERR_LOGOUT_FORE         -12           //�ǳ�ʧ��,ǰ̨����
#define ERR_QRY_DATA            -13            //��ѯ����
#define ERR_ORDER_INSERT        -14            //�µ�ʧ��
#define ERR_ORDER_CANCEL        -15            //����ʧ��
#define ERR_EMPTY_PUBLICKEY		-16			   //��ԿΪ��
#define ERR_PASSWD_FORMAT       -17			   //�����ʽ����ȷ
#define ERR_REPEAT_INITED       -18         //api�ظ���ʼ��
#define ERR_NET_INIT            -19         //�����ʼ������
#define ERR_GATEWAY_INIT        -20         //���س�ʼ������
#define ERR_CHECK_VERSION       -21         //�汾��֤ʧ��
#endif
