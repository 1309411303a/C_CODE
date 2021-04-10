#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX 1000//方便于修改  -->存放人的数量

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

//枚举出各个选项：
enum Option
{
	EXIT,//0
    ADD,//1
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

//关于类型的定义：
struct PeoInfo//存放1000个人信息
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//通讯录的类型
struct Contact
{
	struct PeoInfo data[MAX];//存放一千个人信息
	int size;//记录当前已经有的元素个数
};

//声明函数：
//初始化通讯录的函数
void InitContact(struct Contact* ps);

//增加一个信息到通讯录
void AddContact(struct Contact* ps);

//打印通讯里中的信息
void ShowContact(const struct Contact* ps);//const保证检查时候不会修改内容

//删除指定的联系人
void DelContact(struct Contact* ps);

//查找指定的人的信息
void SearchContact(const struct Contact* ps);

//修改指定联系人
void ModifyContact(struct Contact* ps);
