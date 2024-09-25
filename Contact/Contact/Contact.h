#pragma once
#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 13
#define ADDR_MAX 100

//����ͨѶ¼�ṹ������ͨѶ¼��ز�������

typedef struct personInfo
{
	char name[NAME_MAX];//����
	char gender[GENDER_MAX];//�Ա�
	int age;//����
	char tel[TEL_MAX];//�绰
	char addr[ADDR_MAX];//��ַ
}peoInfo;

//ǰ������������SeqList������
typedef struct SeqList Contact;

//ͨѶ¼�ĳ�ʼ��
void ContactInit(Contact* con);

//ͨѶ¼������
void ContactDestroy(Contact* con);

//ͨѶ¼�������
void ContactAdd(Contact* con);

//ͨѶ¼ɾ������
void ContactDel(Contact* con);

//ͨѶ¼���޸�
void ContactModify(Contact* con);

//ͨѶ¼����
void ContactFind(Contact* con);

//��ӡͨѶ¼����
void ContactShow(Contact* con);

//�����ֲ�����ϵ��
int FindByName(Contact* con, char name[]);
