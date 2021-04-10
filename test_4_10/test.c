#define _CRT_SECURE_NO_WARNINGS 1
//Contact
//1.test.c  测试
//2.contact.c实现函数的功能
//3.contact.h声明函数

//1.存放1000个好友的信息
//
//名字
//电话
//性别
//住址
//年龄
//
//2.增加好友信息
//3.删除指定名字的好友信息
//4.查找好友信息
//5.修改好友信息
//6.打印好友信息
//7.排序

#include"contact.h"//contact.c方便引用
#include<stdio.h>
void menu()
{
	printf("**********************************\n");
	printf("*****1.add                   2.del\n");
	printf("*****3.search             4.modify\n");
	printf("*****5.show                 6.sort\n");
	printf("*****0.exit                       \n");
	printf("**********************************\n");

}
int main()
{
	int input = 0;
	//创建通讯录
	struct Contact con;//con就是通讯录，里面包含：1000的元素的数组和size
	//初始化通讯录
	InitContact(&con);//取地址才可以改变函数的值
	//

	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW://检查
			ShowContact(&con);//地址传参以防差错改变
			break;
		case SORT:
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}//case 枚举常量使得代码的可读性增加了，->枚举的好处一

	} while (input);
	return 0;
}