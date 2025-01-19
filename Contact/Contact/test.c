#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"
#include "SeqList.h"


int main()
{
	Contact con;

	ContactInit(&con);

	//通讯录添加数据
	ContactAdd(&con);
	ContactAdd(&con);
	ContactAdd(&con);

	//通讯录删除数据
	ContactDel(&con);

	//通讯录的修改
	ContactModify(&con);

	//通讯录查找
	ContactFind(&con);

	//打印通讯录內容
	//ContactShow(&con);

	//以名字查找联系人
	//FindByName(Contact * con, char name[]);
	return 0;
}