#define  _CRT_SECURE_NO_WARNINGS  //���scanf
#define _CRT_SECURE_NO_WARNINGS//���ð�ȫ��������
#pragma warning(disable:6031)//���� 6031 �İ�ȫ����

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
typedef struct student ST;
typedef struct activity SA;

void welcome();
void input();
void display();
void search_student(char _id[]);
void modify(char _xid[]);
void modify_test();

struct student //ѧ��
{
	char name[20];
	char id[30];
	char sex[20];
	char spty[20];
	char clas[20];
	char date[50];
};

struct activity // �
{
	char acname[60];
};

int main()
{
	char u[20], p[20];
	system("color 4");
	printf("*******************************************************\n");
	printf("*            <��ӭ����ѧ����Ϣ����ϵͳ>               *\n");
	printf("*******************************************************\n");
	printf("�������û���������(�Կո�ֿ�)$>");
	scanf("%s %s", u, p);
	
	if ((strcmp(u, "admin") == 0) && strcmp(p, "admin") == 0) //�û������ж�
	{
		while (1)
		{
			welcome();
			char x = _getch();
			switch (x)
{
case '1':
{
	input(); break;	
}
case '2':
{
	printf("������ѧ��$>");
	char _xid[25];
	scanf("%s", _xid);
	search_student(_xid); 
	break;
}
case '3':
{
	char pass[30];
	printf("���������Ա����$>");
	cin >> pass;
	
	if (strcmp(pass, "root33846") == 0)
	{
		printf("������ѧ��id:\n");
		char _xid[50];
		scanf("%s", _xid);
		modify(_xid);
		break;
	}
	else {
		printf("����Ա������� �޸�ʧ��!\n");
		system("pause");
	}break;
	
	
}
case '4':
{
	display(); break;
}
case '5':
{
	printf("ϵͳ���˳� ��ӭ�´�ʹ��(�밴������˳�)\n");
	exit(0);
} break;
	
	default: printf("������� ϵͳ�Զ��˳�!\n"); exit(0); break;
	
}
		}
	}
	else {
		cout << "�û������������ ϵͳ��¼ʧ��!" << endl;
	}
	return 0;
}

void welcome() //��ӭҳ
{
	system("color e3");
	system("cls");
	printf("*****************************************************\n");
	printf("*              ��ӭ����ѧ����Ϣ����ϵͳ             *\n");
	printf("*                     1.��Ϣ¼��                    *\n");
	printf("*                     2.��Ϣ����                    *\n");
	printf("*                     3.��Ϣ�޸�                    *\n");
	printf("*                     4.��Ϣ��ʾ                    *\n");
	printf("*                     5.�˳�ϵͳ                    *\n");
	printf("*****************************************************\n");
	printf("���������ִ��$>\n");
}

void input() //��Ϣ¼��
{
	ST st;
	SA sa;
	
	FILE* fp = fopen("student.txt", "a"); //���ļ�
	
	printf("����������:\n");
	scanf("%s", st.name);
	printf("������ѧ��:\n");
	scanf("%s", st.id);
	printf("�������Ա�:\n");
	scanf("%s", st.sex);
	printf("������רҵ:\n");
	scanf("%s", st.spty);
	printf("�������������:\n");
	scanf("%s", st.date);
	printf("������༶:\n");
	scanf("%s", st.clas);
	printf("����������\n");
	scanf("%s", sa.acname);
	
	if (fp == NULL)
	{
		printf("�ļ���ʧ�� ��Ϣδ¼��!\n");
		return;
	}
	else {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			st.name,st.id,st.sex,st.spty,st.date,st.clas,sa.acname);
		
		fclose(fp);
		printf("ѧ����Ϣ¼�����!\n");
		system("pause");
		system("cls");
	}
}

void search_student(char _id[]) //ѧ����Ϣ����
{
	ST st;
	SA sa;
	FILE* fp = fopen("student.txt", "r");
	
	if (fp == NULL)
	{
		printf("�ļ���ʧ�� ��Ϣ����ʧ��!\n");
		return;
	}
	else
	{
		while (fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",
			st.name, st.id, st.sex, st.spty, st.date, st.clas, sa.acname) != EOF)
		{
			if (strcmp(st.id, _id) == 0)
			{
				printf("����:%s  ѧ��:%s  �Ա�:%s  רҵ:%s  ��������:%s  �༶:%s  �����:%s\n",
					st.name, st.id, st.sex, st.spty, st.date, st.clas, sa.acname);
				fclose(fp);
				system("pause");
			}
			
		}
		
	}
}

void modify(char _xid[]) //�޸�
{
	int mod = 0;
	ST st;
	SA sa;
	FILE* xp = fopen("student.txt", "r");
	if (xp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	
	FILE* tem = fopen("tem.txt", "w");
	if (tem == NULL)
	{
		printf("�ļ���ʧ��\n");
		fclose(xp);
		return;
	}
	
	while (fscanf(xp, "%s %s %s %s %s %s %s\n",
		st.name, st.id, st.sex, st.spty, st.date, st.clas, sa.acname) != EOF)
	{
		if (strcmp(st.id, _xid) == 0)
		{ 
			modify_test();
			printf("�������Ӧ��Ÿ��ģ�");
			char x = _getch();
			switch (x)
{
case '1':
	printf("�������µ�����: ");
	scanf("%s", st.name);  break;
	
case '2':
	printf("�������µ�ѧ��: ");
	scanf("%s", st.id); break;
case '3':
	printf("�������µ�ѧ��: ");
	scanf("%s", st.id); break;
case '4':
	printf("�������µ��Ա�: ");
	scanf("%s", st.sex); break;
case '5':
	printf("�������µ�רҵ: ");
	scanf("%s", st.spty); break;
case '6':
	printf("�������µĳ�������: ");
	scanf("%s", st.date); break;
case '7':
	printf("�������µİ༶: ");
	scanf("%s", st.clas); break;
case '8':
	printf("�������µĻ��Ϣ: ");
	scanf("%s", sa.acname); break;
}
			mod = 1;
		}
		fprintf(tem, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			st.name, st.id, st.sex, st.spty, st.date, st.clas, sa.acname);
	}
	fclose(xp);
	fclose(tem);
	if (mod)
	{
		remove("student.txt");
		rename("tem.txt", "student.txt");
		printf("����޸�!\n");
		system("pause");
	}
	else
	{
		remove("tem.txt");
		printf("û�ҵ�ѧ��!\n");
	}
	
	
}

void display() //��Ϣ��ʾ
{
	char str[700];
	FILE* fp;
	fp = fopen("student.txt", "r");
	
	if (fp == nullptr) {
		printf("ѧ����Ϣ��ʾʧ��!\n");
	}
	while (fgets(str, 700, fp) != NULL)
	{
		printf("%s\n", str);
	};
	
	system("pause");
	fclose(fp);
}

void modify_test()
{
	printf("1.����  2.ѧ��  3.�Ա�\n");
	printf("4.רҵ  5.��������\n");
	printf("6.�༶  7.��Ϣ\n");
}


