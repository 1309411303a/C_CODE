
#include"contact.h";
//信息全部初始化成0
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));//内存存储函数 data是数组ps指向的数组的大小单位是字节，设置为0，第一个参数是要填充的内存块
	ps->size = 0;//设置通讯录最初只有0个元素
}

//添加信息
void AddContact(struct Contact*ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，无法增加\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[ps->size].name);
		//ps放到data数组下标为size的位置，ps指向con，con包含data,size, ps->data先找到数组，数组的下标是[ps->size],
		//成功找到数组的某一个元素了.name找到他的名字
		printf("请输入年龄:>");//需要取地址
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[ps->size].addr);
	
		ps->size++;
		printf("添加成功\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空格\n");
	}
	else
	{
		int i = 0;
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "名字", "年龄", "性别","电话", "地址");//把信息按照一定的格式先打印出来
		for (i = 0; i < ps->size; i++)
		{
			printf("%20s\t%4d\t%5s\t%12s\t%20s\n",//年龄是数字应该用%d
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

static int FindByName(const struct Contact* ps, char name[MAX_NAME])//static该函数只能在该源文件的内部来使用
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		//俩个字符串比较用strcmp
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}

	return -1;//找不到的情况
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字：>");
	scanf("%s", name);
	//1.查找要删除的人在什么位置
	//找到了返回名字所在的元素的下标
	//找不到了返回 -1
	int pos = FindByName(ps, name);
	

	//2.删除
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除数据
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchContact(const struct Contact* ps)//都要实现查找的功能，为了避免代码的冗余，可以使用函数来分装起来他们(见DEL，findbyname函数的功能）
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字：>");
	scanf("%s", name);
	//引用查找函数
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}

	else
	{
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话", "地址");//把信息按照一定的格式先打印出来
		//数据：
		printf("%20s\t%4d\t%5s\t%12s\t%20s\n",//年龄是数字应该用%d
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);

	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字：>");
	scanf("%s", name);
	int pos = FindByName(ps, name);//找到要修改人的名字,传递俩个信息
	if (pos == -1)
	{
		printf("要修改人的信息不存在\n");
	}
	else
		//修改人的信息
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[pos].name);
		//ps放到data数组下标为size的位置，ps指向con，con包含data,size, ps->data先找到数组，数组的下标是[ps->size],
		//成功找到数组的某一个元素了.name找到他的名字
		printf("请输入年龄:>");//需要取地址
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[pos].addr);
		printf("修改完成\n");
	}
}


//