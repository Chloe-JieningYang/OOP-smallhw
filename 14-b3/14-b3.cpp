/*2050598 ����� ͨ��*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

#define   CHECK_NOT_NUMBER      1//���ѧ����ѧ�Ŵ���
#define   CHECK_NOT_SEVEN       2//���ѧ����ѧ�Ŵ���
#define   MATCH_NOT_NUMBER      3//ƥ��ѧ����ѧ�Ŵ���
#define   MATCH_NOT_SEVEN       4//ƥ��ѧ����ѧ�Ŵ���
#define   MATCH_NOT_DOUBLE_ALL  5//ƥ��ѧ����ѧ�Ŵ���
#define   NUM_CORRECT           6//ѧ�ż����ȷ

#define   FILENAME_EXCESS       7//�ļ�������32�ֽ�
#define   FILENAME_CORRECT      8//�ļ��������ȷ

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int usage(const char* const procname)
{
	cout << "Usage: " << procname << " Ҫ����ѧ��/all ƥ��ѧ��/all Դ������/all ���ƶȷ�ֵ(60-100) ���(filename/screen)" << endl << endl;
	cout << "e.g. : " << procname << " 2159999 2159998 all       80 screen" << endl;
	cout << "       " << procname << " 2159999 all     14-b1.cpp 75 result.txt" << endl;
	cout << "       " << procname << " all     all     14-b2.cpp 80 check.dat" << endl;
	cout << "       " << procname << " all     all     all       85 screen" << endl;

	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ѧ�Ŵ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int CheckNum(char* check, char* match)
{
	int i;
	if (strcmp(check, "all") == 0)//�����all��all
	{
		if (strcmp(match, "all"))//���match����all
			return MATCH_NOT_DOUBLE_ALL;
		else
			return NUM_CORRECT;//all to all
	}
	else
	{
		if (strlen(check) != 7)//��鱻���ѧ��ѧ���Ƿ�Ϊ7λ
			return CHECK_NOT_SEVEN;
		for (i = 0; check[i] != '\0'; i++)//��鱻���ѧ��ѧ���Ƿ�ȫΪ����
		{
			if (check[i] < '0' || check[i]>'9')
				return CHECK_NOT_NUMBER;
		}
		if (strcmp(match, "all") == 0)//�����ĳ��ѧ����all�Ƚ�
			return NUM_CORRECT;
		if (strlen(match) != 7)//��鱻���ѧ��ѧ���Ƿ�Ϊ7λ
			return MATCH_NOT_SEVEN;
		for (i = 0; match[i] != '\0'; i++)//��鱻���ѧ��ѧ���Ƿ�ȫΪ����
		{
			if (match[i] < '0' || match[i]>'9')
				return MATCH_NOT_NUMBER;
		}
		return NUM_CORRECT;
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ļ�������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int CheckFileName(char* filename)
{
	if (strlen(filename) + 1 > 32)
		return FILENAME_EXCESS;
	if (strcmp(filename, "all") == 0)
		return FILENAME_CORRECT;
	cout << strlen(filename) + 1 << endl;
	return FILENAME_CORRECT;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ƶ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int CheckSimilarity(char* s)
{
	int similar = atoi(s);
	if (similar < 60 || similar>100)
		similar = 80;
	return similar;
}


int main(int argc,char *argv[])
{
	if (argc < 6)
	{
		usage(argv[0]);
		return 0;
	}
	/*���ѧ��*/
	int check_num = CheckNum(argv[1], argv[2]);
	if (check_num == CHECK_NOT_NUMBER)
	{
		cout << "Ҫ����ѧ�Ų���7λ����" << endl;
		return 0;
	}
	else if (check_num == CHECK_NOT_SEVEN)
	{
		cout << "Ҫ����ѧ�Ų���7λ" << endl;
		return 0;
	}
	else if (check_num == MATCH_NOT_NUMBER)
	{
		cout << "Ҫƥ���ѧ�Ų���7λ����" << endl;
		return 0;
	}
	else if (check_num == MATCH_NOT_SEVEN)
	{
		cout << "Ҫƥ���ѧ�Ų���7λ" << endl;
		return 0;
	}
	else if (check_num == MATCH_NOT_DOUBLE_ALL)
	{
		cout << "���ѧ����all��ƥ��ѧ�ű�����all" << endl;
		return 0;
	}
	/*���Դ�����ļ���*/
	int check_filename_in = CheckFileName(argv[3]);
	if (check_filename_in == FILENAME_EXCESS)
	{
		cout << "Դ�����ļ���������32�ֽ�" << endl;
		return 0;
	}
	/*������ƶ�*/
	int similarity = CheckSimilarity(argv[4]);
	/*�������ļ���*/
	int check_filename_out= CheckFileName(argv[5]);
	if (check_filename_out == FILENAME_EXCESS)
	{
		cout << "�������ļ���������32�ֽ�" << endl;
		return 0;
	}

	cout << "������ͨ��" << endl;
	cout << "���ѧ�ţ�" << argv[1] << endl;
	cout << "ƥ��ѧ�ţ�" << argv[2] << endl;
	cout << "Դ�ļ�����" << argv[3] << endl;
	cout << "ƥ��Ԥ�ƣ�" << similarity << endl;
	cout << "���Ŀ�꣺" << argv[5] << endl;
	return 0;
}