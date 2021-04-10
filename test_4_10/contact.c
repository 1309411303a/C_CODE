
#include"contact.h";
//��Ϣȫ����ʼ����0
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));//�ڴ�洢���� data������psָ�������Ĵ�С��λ���ֽڣ�����Ϊ0����һ��������Ҫ�����ڴ��
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
}

//�����Ϣ
void AddContact(struct Contact*ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷�����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[ps->size].name);
		//ps�ŵ�data�����±�Ϊsize��λ�ã�psָ��con��con����data,size, ps->data���ҵ����飬������±���[ps->size],
		//�ɹ��ҵ������ĳһ��Ԫ����.name�ҵ���������
		printf("����������:>");//��Ҫȡ��ַ
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[ps->size].addr);
	
		ps->size++;
		printf("��ӳɹ�\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�ո�\n");
	}
	else
	{
		int i = 0;
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�","�绰", "��ַ");//����Ϣ����һ���ĸ�ʽ�ȴ�ӡ����
		for (i = 0; i < ps->size; i++)
		{
			printf("%20s\t%4d\t%5s\t%12s\t%20s\n",//����������Ӧ����%d
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

static int FindByName(const struct Contact* ps, char name[MAX_NAME])//static�ú���ֻ���ڸ�Դ�ļ����ڲ���ʹ��
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		//�����ַ����Ƚ���strcmp
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}

	return -1;//�Ҳ��������
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���˵����֣�>");
	scanf("%s", name);
	//1.����Ҫɾ��������ʲôλ��
	//�ҵ��˷����������ڵ�Ԫ�ص��±�
	//�Ҳ����˷��� -1
	int pos = FindByName(ps, name);
	

	//2.ɾ��
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void SearchContact(const struct Contact* ps)//��Ҫʵ�ֲ��ҵĹ��ܣ�Ϊ�˱����������࣬����ʹ�ú�������װ��������(��DEL��findbyname�����Ĺ��ܣ�
{
	char name[MAX_NAME];
	printf("������Ҫ�����˵����֣�>");
	scanf("%s", name);
	//���ò��Һ���
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}

	else
	{
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");//����Ϣ����һ���ĸ�ʽ�ȴ�ӡ����
		//���ݣ�
		printf("%20s\t%4d\t%5s\t%12s\t%20s\n",//����������Ӧ����%d
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
	printf("������Ҫ�޸��˵����֣�>");
	scanf("%s", name);
	int pos = FindByName(ps, name);//�ҵ�Ҫ�޸��˵�����,����������Ϣ
	if (pos == -1)
	{
		printf("Ҫ�޸��˵���Ϣ������\n");
	}
	else
		//�޸��˵���Ϣ
	{
		printf("����������:>");
		scanf("%s", ps->data[pos].name);
		//ps�ŵ�data�����±�Ϊsize��λ�ã�psָ��con��con����data,size, ps->data���ҵ����飬������±���[ps->size],
		//�ɹ��ҵ������ĳһ��Ԫ����.name�ҵ���������
		printf("����������:>");//��Ҫȡ��ַ
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[pos].addr);
		printf("�޸����\n");
	}
}


//