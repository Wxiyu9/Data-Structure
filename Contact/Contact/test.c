#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
#include "SeqList.h"


int main()
{
	Contact con;

	ContactInit(&con);

	//ͨѶ¼�������
	ContactAdd(&con);
	ContactAdd(&con);
	ContactAdd(&con);

	//ͨѶ¼ɾ������
	ContactDel(&con);

	//ͨѶ¼���޸�
	ContactModify(&con);

	//ͨѶ¼����
	ContactFind(&con);

	//��ӡͨѶ¼����
	//ContactShow(&con);

	//�����ֲ�����ϵ��
	//FindByName(Contact * con, char name[]);
	return 0;
}