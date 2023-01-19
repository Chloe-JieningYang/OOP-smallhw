/*2050598 ����� ͨ��*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

#define   CHECK  1
#define   WTOL   2
#define   LTOW   3
#define   ERROR  -1

#define   TYPE_W    4
#define   TYPE_L    5
#define   TYPE_IDK  6//i don't know������

int usage(const char ch[])
{
	printf("Usage : %s --check �ļ��� | --convert { wtol|ltow } Դ�ļ��� Ŀ���ļ���\n", ch);
	printf("        %s --check a.txt", ch);
	printf("        %s --convert wtol a.win.txt a.linux.txt", ch);
	printf("        %s --convert ltow a.linux.txt a.win.txt", ch);
	return 0;
}

int Choice(char* ch[], int argc)
{
	if (argc < 2)
		return 0;
	if (!strcmp(ch[1], "--check"))
		return CHECK;
	else if ((!strcmp(ch[1], "--convert")) && (!strcmp(ch[2], "wtol")))
		return WTOL;
	else if ((!strcmp(ch[1], "--convert")) && (!strcmp(ch[2], "ltow")))
		return LTOW;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ж��ļ�����
  ������������ݵ�ascii�����飬�������
  �� �� ֵ��TYPE_W TYPE_L TYPE_IDK
  ˵    ����
***************************************************************************/
int Check(const int content[], const int num)
{
	int type = TYPE_IDK;
	for (int i = 0; i <= num - 1; i++)
	{
		if (content[i] == 0x0A)
		{
			if (i == 0)
				type = TYPE_L;
			if (i > 0 && content[i - 1] == 0x0D)//���0Aǰ����0D
			{
				if (type == TYPE_L)//���type�Ѿ����Ϊlinux
					return TYPE_IDK;
				type = TYPE_W;
			}
			else//0Aǰ��û��0D
			{
				if (type == TYPE_W)
					return TYPE_IDK;
				type = TYPE_L;
			}
		}
	}
	return type;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�ת��Windows��ʽ�ļ���Linux��ʽ��ɾ��0Aǰ��һ��0D��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void ConvertWtoL(int content[], const int num, int* new_nump)
{
	*new_nump = num;
	for (int i = 0; i <= num - 1; i++)
	{
		if (content[i] == 0x0A && content[i - 1] == 0x0D)
		{
			for (int j = i - 1; j <= num - 2; j++)
			{
				content[j] = content[j + 1];
			}
			(*new_nump)--;
		}
	}
	printf("ת����ɣ�ȥ��%d��0x0D\n", num - (*new_nump));
}

int main(int argc, char* argv[])
{
	int choice = Choice(argv, argc);

	if (choice == 0)
	{
		usage(argv[0]);
		return 0;
	}

	if (choice == CHECK)
	{
		FILE* fin;
		fin = fopen(argv[2], "rb");
		if (fin == NULL)
		{
			printf("���ļ�ʧ��\n");
			return ERROR;
		}
		int content[10000];
		int num = 0;
		while (!feof(fin))//�������-1
		{
			content[num] = fgetc(fin);
			num++;
		}
		int check = Check(content, num);
		if (check == TYPE_W)
			printf("Windows��ʽ\n");
		else if (check == TYPE_L)
			printf("Linux��ʽ\n");
		else if (check == TYPE_IDK)
			printf("�ļ���ʽ�޷�ʶ��\n");
		fclose(fin);
	}
	else if (choice == WTOL)
	{
		FILE* fin, * fout;
		fin = fopen(argv[3], "rb");
		if (fin == NULL)
		{
			printf("�ļ���ʧ��\n");
			return ERROR;
		}
		int content[10000];
		int num = 0;
		while (!feof(fin))//��β�����-1
		{
			content[num] = fgetc(fin);
			num++;
		}
		int check = Check(content, num);
		if (check != TYPE_W)
		{
			printf("�ļ���ʽ�޷�ʶ��\n");
			fclose(fin);
			return ERROR;
		}
		int new_num;
		ConvertWtoL(content, num, &new_num);
		fout = fopen(argv[4], "wb");
		if (fout == NULL)
		{
			printf("���ļ�ʧ��\n");
			fclose(fin);
			return ERROR;
		}
		for (int i = 0; i <= new_num - 2; i++)
			fputc((char)(content[i]), fout);

		fclose(fin);
		fclose(fout);
	}
	else if (choice == LTOW)
	{
		FILE* fin, * fout;
		fin = fopen(argv[3], "rb");
		if (fin == NULL)
		{
			printf("�ļ���ʧ��\n");
			return ERROR;
		}
		int content[10000];
		int num = 0;
		while (!feof(fin))//��β�����-1
		{
			content[num] = fgetc(fin);
			num++;
		}
		int check = Check(content, num);
		if (check != TYPE_L)
		{
			printf("�ļ���ʽ�޷�ʶ��\n");
			fclose(fin);
			return ERROR;
		}
		fout = fopen(argv[4], "w");
		if (fout == NULL)
		{
			printf("���ļ�ʧ��\n");
			fclose(fin);
			return ERROR;
		}
		int count = 0;
		for (int i = 0; i <= num - 2; i++)
		{
			if (content[i] == 0x0A)
			{
				count++;
#ifdef __linux__
				fputc((char)(0x0D), fout);
#endif
			}
			fputc((char)(content[i]), fout);
		}
		printf("ת����ɣ�����%d��0x0D\n", count);

		fclose(fin);
		fclose(fout);
	}
	return 0;
}