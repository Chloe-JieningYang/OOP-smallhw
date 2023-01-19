/* 2050598 ����� ͨ�� */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <cmath>
/* �������Ҫ���˴��������ͷ�ļ� */
#include <climits>

using namespace std;

/* �����峣����/�궨�壬����������ȫ�ֱ��� */
#define   CLUB    5
#define   DIAMOND 4
#define   HEART   3
#define   SPADE   6

/* ��������Լ���Ҫ�ĺ��� */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������Ƶ���ţ���ӡ��һ����(�����ַ���
  ���������
  �� �� ֵ��
  ˵    ����
 ***************************************************************************/
void PrintOneCard(const int num)
{
	if (num > 54 || num < 1)
		return;
	if (num == 53)//С��
	{
		cout << "BJ ";
		return;
	}
	else if (num == 54)//����
	{
		cout << "RJ ";
		return;
	}
	if (num % 4 == 1)
		#if defined(_WIN32)
			cout << char(CLUB);
		#elif defined(__linux__)
			cout << 'C';
		#endif
	else if(num%4==2)
		#if defined(_WIN32)
			cout << char(DIAMOND);
		#elif defined(__linux__)
			cout << 'D';
		#endif
	else if(num%4==3)
		#if defined(_WIN32)
			cout << char(HEART);
		#elif defined(__linux__)
			cout << 'H';
		#endif
	else if(num%4==0)
		#if defined(_WIN32)
			cout << char(SPADE);
		#elif defined(__linux__)
			cout << 'S';
		#endif
	if ((num - 1) / 4 <= 6)
		cout << (num - 1) / 4 + 3;
	else if ((num - 1) / 4 == 7)
		cout << "T";
	else if ((num - 1) / 4 == 8)
		cout << "J";
	else if ((num - 1) / 4 == 9)
		cout << "Q";
	else if ((num - 1) / 4 == 10)
		cout << "K";
	else if ((num - 1) / 4 == 11)
		cout << "A";
	else if ((num - 1) / 4 == 12)
		cout << "2";
	cout << " ";
	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡĳ����ҵ�������Ϣ������ǵ���������ӱ��
  ���������
  �� �� ֵ��
  ˵    ����
 ***************************************************************************/
int print(const char *prompt, const bool landlord, const unsigned long long player)
{
	/* ֻ�����岻���������������͵ļ򵥱��������ܶ�������������ṹ�塢string�� */
	int i;
	cout << prompt;
	for (i = 1; i <= 54; i++)
	{
		int s = (int)(player / (unsigned long long)(pow(2, i - 1)) % 2);//0Ϊ�����������ƣ�1Ϊ����
		if (s == 1)
			PrintOneCard(i);
	}
	if (landlord)
		cout << "(����)";
	cout << endl;

	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ƣ����������������
  ���������
  �� �� ֵ��
  ˵    ����
 ***************************************************************************/
int deal(unsigned long long *player)
{
	/* ֻ�����岻����ʮ���������͵ļ򵥱��������ܶ�������������ṹ�塢string�� */
	srand(unsigned(time(NULL)));
	unsigned long long cards = ULLONG_MAX;//׼����һ����
	int i;
	for (i = 1; i <= 17; i++)//һ����17��
	{
		for (int person = 0; person <= 2; person++)//�������˷���
		{
			int card_num;
			while (1)
			{
				card_num = rand() % (54 - 1 + 1) + 1;//ȡ1-54����
				if (cards / (unsigned long long)(pow(2, card_num - 1)) % 2 == 1)//���δ�������л���������
					break;
			}
			unsigned long long change = ULLONG_MAX - (unsigned long long)(pow(2, card_num - 1));//ֻ��ѡ�е��ƴ���0���ı�ʣ�µ���
			cards = cards & change;
			change = (unsigned long long)(pow(2, card_num - 1));//ֻ��ѡ�е�����1���ı���ҵ���
			*(player + person) = *(player + person) | change;
		}
		cout << "��" << i << "�ֽ�����" << endl;
		print("�׵��ƣ�", 0, *(player + 0));
		print("�ҵ��ƣ�", 0, *(player + 1));
		print("�����ƣ�", 0, *(player + 2));
	}
	int landlord;
	while (1)
	{
		cout << endl;
		cout << "��ѡ��һ������[0-2]:" << endl;
		cin >> landlord;
		if (cin.good() && landlord >= 0 && landlord <= 2)
			break;
	}
	*(player + landlord) = *(player + landlord) | cards;

	return landlord; //�˴��޸�Ϊѡ���ĵ���(0-2)
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main��������׼�޸�
 ***************************************************************************/
int main()
{
	unsigned long long player[3] = { 0 }; //���������ҵķ�����Ϣ
	int landlord; //����0-2��ʾ�ĸ�����ǵ���

	cout << "���س�����ʼ����";
	while (getchar() != '\n')
		;

	landlord = deal(player);
	print("�׵��ƣ�", (landlord == 0), player[0]);
	print("�ҵ��ƣ�", (landlord == 1), player[1]);
	print("�����ƣ�", (landlord == 2), player[2]);

	return 0;
}
