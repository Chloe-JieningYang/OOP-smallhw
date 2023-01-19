/*2050598 ����� ͨ��*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define   CHECK  1
#define   WTOL   2
#define   LTOW   3
#define   ERROR  -1

#define   TYPE_W    4
#define   TYPE_L    5
#define   TYPE_IDK  6//i don't know������

int usage(const char ch[])
{
	cout << "Usage : " << ch << " --check �ļ��� | --convert { wtol|ltow } Դ�ļ��� Ŀ���ļ���" << endl;
	cout << "        " << ch << " --check a.txt" << endl;
	cout << "        " << ch << " --convert wtol a.win.txt a.linux.txt" << endl;
	cout << "        " << ch << " --convert ltow a.linux.txt a.win.txt" << endl;
	return 0;
}

int Choice(char *ch[],int argc)
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
void ConvertWtoL(int content[], const int num, int& new_num)
{
	new_num = num;
	for (int i = 0; i <= num - 1; i++)
	{
		if (content[i] == 0x0A && content[i - 1] == 0x0D)
		{
			for (int j = i - 1; j <= num - 2; j++)
			{
				content[j] = content[j + 1];
			}
			new_num--;
		}
	}
	cout << "ת����ɣ�ȥ��" << num - new_num << "��0x0D" << endl;
}

int main(int argc, char* argv[])
{
	int choice = Choice(argv, argc);

	if (choice == CHECK)
	{
		ifstream in(argv[2], ios::in | ios::binary);
		if (in.is_open() == 0)
		{
			cout << "�ļ���ʧ��" << endl;
			return ERROR;
		}
		int content[10000];
		int num = 0;
		while (!in.eof())//��β�����-1
		{
			content[num] = in.get();
			num++;
		}
		int check = Check(content, num);
		if (check == TYPE_W)
			cout << "Windows��ʽ" << endl;
		else if (check == TYPE_L)
			cout << "Linux��ʽ" << endl;
		else if (check == TYPE_IDK)
			cout << "�ļ���ʽ�޷�ʶ��" << endl;
		in.close();
	}
	else if (choice == WTOL)
	{
		ifstream in(argv[3], ios::in | ios::binary);
		if (in.is_open() == 0)
		{
			cout << "�ļ���ʧ��" << endl;
			return ERROR;
		}
		int content[10000];
		int num = 0;
		while (!in.eof())//��β�����-1
		{
			content[num] = in.get();
			num++;
		}
		int check = Check(content, num);
		if (check != TYPE_W)
		{
			cout << "�ļ���ʽ�޷�ʶ��" << endl;
			in.close();
			return ERROR;
		}
		int new_num;
		ConvertWtoL(content, num, new_num);

		ofstream out(argv[4], ios::out | ios::binary);
		if (!out.is_open())
		{
			cout << "�ļ���ʧ��" << endl;
			in.close();
			return ERROR;
		}
		for (int i = 0; i <= new_num - 2; i++)
			out.put(char(content[i]));

		in.close();
		out.close();
	}
	else if (choice == LTOW)
	{
		ifstream in(argv[3], ios::in | ios::binary);
		if (in.is_open() == 0)
		{
			cout << "�ļ���ʧ��" << endl;
			return ERROR;
		}
		int content[10000];
		int num = 0;
		while (!in.eof())//��β�����-1
		{
			content[num] = in.get();
			num++;
		}
		int check = Check(content, num);
		if (check != TYPE_L)
		{
			cout << "�ļ���ʽ�޷�ʶ��" << endl;
			in.close();
			return ERROR;
		}

		ofstream out(argv[4], ios::out);
		if (!out.is_open())
		{
			cout << "�ļ���ʧ��" << endl;
			in.close();
			return ERROR;
		}
		int count = 0;
		for (int i = 0; i <= num - 2; i++)
		{
			if (content[i] == 0x0A)
			{
				count++;
#ifdef __linux__
				out.put(char(0x0D));
#endif
			}
			out.put(char(content[i]));
		}
		cout << "ת����ɣ�����" << count << "��0x0D" << endl;
		in.close();
		out.close();
	}
	else
		usage(argv[0]);
	
	return 0;
}