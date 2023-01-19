/* 2050598 ����� ͨ�� */
/*2051553 ����һ 2152808 κ�躭 2051454 ���ݷ�*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "17-b1-TString.h"
#include "17-b1-TStringAdv.h"
using namespace std;

#if defined(__linux) || defined(__linux__)
#include <sys/time.h>
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "���س�������";
	while (getchar() != '\n')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
long get_cur_msec(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);

	return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

#else
#include <Windows.h>
#include <conio.h>
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "���س�������";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
long get_cur_msec(void)
{
	return GetTickCount(); //ȡ��ǰϵͳʱ�䣬��λ����
}

#endif


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	if (1) {
		const TStringAdv s1;                 //s1ΪNULL
		const TStringAdv s2("teststr2");      //s2Ϊ"teststr2"
		const TStringAdv s3="teststr3";       //s3Ϊ"teststr3"
		const TStringAdv s4=NULL;            //s4ΪNULL
		const TStringAdv s5="";              //s5ΪNULL

		cout << "������󲢳�ʼ������(NULL���ַ���������ʼ��)" << endl;

		cout << "s1Ӧ����<NULL>��  ʵ�������" << s1 << endl;
		cout << "s2Ӧ����teststr2��ʵ�������" << s2 << endl;
		cout << "s3Ӧ����teststr3��ʵ�������" << s3 << endl;
		cout << "s4Ӧ����<NULL>��  ʵ�������" << s4 << endl;
		cout << "s5Ӧ����<NULL>��  ʵ�������" << s5 << endl;

		wait_for_enter();
		}

	if (1) {
		const TStringAdv s0   = "teststr1";
		const char *str1   = "teststr2";
		const char  str2[] = "teststr3";
		const char *str3   = NULL;
		const char  str4[] = "";
		const TStringAdv s1=s0, s2=str1, s3=str2, s4=str3, s5=str4;

		cout << "������󲢳�ʼ������(TString�����ַ�ָ�롢�ַ�����)" << endl;

		cout << "s1Ӧ����teststr1��ʵ�������" << s1 << endl;
		cout << "s2Ӧ����teststr2��ʵ�������" << s2 << endl;
		cout << "s3Ӧ����teststr3��ʵ�������" << s3 << endl;
		cout << "s4Ӧ����<NULL>��  ʵ�������" << s4 << endl;
		cout << "s5Ӧ����<NULL>��  ʵ�������" << s5 << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s1;

		cout << "����cin����" << endl;

		cout << "���ڼ���������Hello" << endl;
		cin >> s1;
		cout << "s1Ӧ����Hello��ʵ�������" << s1 << endl;

		cout << "���ڼ���������Hello 123" << endl;
		cin >> s1;
		cout << "s1Ӧ����Hello��ʵ�������" << s1 << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s1("Hello"), s2;

		cout << "��ֵ��������" << endl;

		cout << "s1Ӧ����Hello�� ʵ�������" << s1 << endl;

		s2=s1;
		cout << "s2Ӧ����Hello�� ʵ�������" << s2 << endl;

		s1="Hi";
		cout << "s1Ӧ����Hi��    ʵ�������" << s1 << endl;

		s2="";
		cout << "s2Ӧ����<NULL>��ʵ�������" << s2 << endl;

		s1=NULL;
		cout << "s1Ӧ����<NULL>��ʵ�������" << s1 << endl;

		s1 = "Hello";
		cout << "s1Ӧ����Hello�� ʵ�������" << (s1 = s1) << endl;
		cout << "s1Ӧ����Hello�� ʵ�������" << (s1 = s1 = s1 = s1 = s1) << endl;
		cout << "s1Ӧ����Hello�� ʵ�������" << (((s1 = s1) = s1) = s1) << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s0, s1("tong"), s2("ji"), s3;

		cout << "����(+)����(����TStringAdv��)"<< endl;

		s3 = s1+s2;
		cout << "s3ӦΪtongji��ʵ�������" << s3 << endl;

		s3 = s2+s1;
		cout << "s3ӦΪjitong��ʵ�������" << s3 << endl;

		s3 = s1+s0;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = s0+s2;
		cout << "s3ӦΪji��    ʵ�������" << s3 << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s1("tong"), s2, s3;

		cout << "����(+)����(TStringAdv����ַ�������)"<< endl;

		s3 = s1+"ji";
		cout << "s3ӦΪtongji��ʵ�������" << s3 << endl;

		s3 = "ji"+s1;
		cout << "s3ӦΪjitong��ʵ�������" << s3 << endl;

		s3 = s1+"";
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = s1+ (char *)NULL;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = ""+s1;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = (char *)NULL+s1;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = s2+ (char *)NULL;
		cout << "s3ӦΪ<NULL>��ʵ�������" << s3 << endl;

		s3 = (char *)NULL+s2;
		cout << "s3ӦΪ<NULL>��ʵ�������" << s3 << endl;

		s3 = s2+"";
		cout << "s3ӦΪ<NULL>��ʵ�������" << s3 << endl;

		s3 = ""+s2;
		cout << "s3ӦΪ<NULL>��ʵ�������" << s3 << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s1("tong"), s3;
		const char *str1="ji", *str2="", *str3=NULL;

		cout << "����(+)����(TStringAdv����ַ�ָ��)"<< endl;

		s3 = s1+str1;
		cout << "s3ӦΪtongji��ʵ�������" << s3 << endl;

		s3 = str1+s1;
		cout << "s3ӦΪjitong��ʵ�������" << s3 << endl;

		s3 = s1+str2;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = str2+s1;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = s1+str3;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = str3+s1;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s1("tong"), s3;
		char str1[]="ji", str2[]="";

		cout << "����(+)����(TStringAdv����ַ�����)"<< endl;

		s3 = s1+str1;
		cout << "s3ӦΪtongji��ʵ�������" << s3 << endl;

		s3 = str1+s1;
		cout << "s3ӦΪjitong��ʵ�������" << s3 << endl;

		s3 = s1+str2;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		s3 = str2+s1;
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s1("Hello"), s3;
		char c = '!';

		cout << "����(+)����(TStringAdv����ַ�)" << endl;

		s3 = s1 + c;
		cout << "s3ӦΪHello!��ʵ�������" << s3 << endl;

		s3 = c + s1;
		cout << "s3ӦΪ!Hello��ʵ�������" << s3 << endl;

		s1 = "ello";
		cout << "s3ӦΪHello!��ʵ�������" << 'H'+s1+c << endl;

		s1 = "hina";
		cout << "s3ӦΪChina!��ʵ�������" << (s1 = 'C' + s1 + c) << endl;

		wait_for_enter();
	}

	if (1) {
		const TStringAdv s1("��"), s3="��", s5="Ҳ";
		TStringAdv s;
		const char *str2 = "��", str4[] = "��";
		const char c = '!';

		cout << "����(+)�ۺϲ���(TStringAdv���TStringAdv�ࡢ�ַ�ָ�롢�ַ����顢�ַ�)" << endl;
		s = s1 + str2 + s3 + str4 + s5 + c;
		cout << "sӦ���ǿ�������Ҳ!��ʵ�������" << s << endl;

		cout << "sӦ����Ҳ��������!��ʵ�������" << (s = s5 + s1 + str2 + s3 + str4[0] + str4[1] + c) << endl;
		cout << "sӦ������Ҳ������!��ʵ�������" << (s = str4 + s5 + s1.c_str() + str2 + s3 + c) << endl;
		cout << "sӦ��������Ҳ����!��ʵ�������" << (s = s3 + str4 + s5 + s1 + str2[0] + &str2[1] + c) << endl;
		cout << "sӦ����������Ҳ��!��ʵ�������" << (s = str2 + s3 + str4 + s5.c_str() + s1.c_str() + c) << endl;

		wait_for_enter();
	}

	if (1) {
		TStringAdv s1("tong"), s2="ji";
		const char *str3 = "tong", str4[] = "ji";

		cout << "������(+=)�򵥲���(TStringAdv���TStringAdv�ࡢ�ַ�ָ�롢�ַ����顢�ַ�)" << endl;

		s1 += s2;
		cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

		s1 = "tong";
		s2 += s1;
		cout << "s2ӦΪjitong��ʵ�������" << s2 << endl;

		s1 = "tong";
		s1 += "ji";
		cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

		s1 = "ji";
		s1 += str3;
		cout << "s1ӦΪjitong��ʵ�������" << s1 << endl;

		s1 = "tong";
		s1 += str4;
		cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

		s1 = "tong";
		s1 += 'j';
		s1 += 'i';
		cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

		wait_for_enter();
	}

	if (1) {
		TStringAdv s1("��"), s3 = "��", s5 = "Ҳ";
		TStringAdv s;
		const char *str2 = "��", str4[] = "��";
		const char c = '!';

		cout << "������(+=)�ۺϲ���(TStringAdv���TStringAdv�ࡢ�ַ�ָ�롢�ַ����顢�ַ�)" << endl;
		
		s = "1.";
		s += s1 + str2 + s3 + str4 + s5 + c;
		cout << "sӦ����1.��������Ҳ!��ʵ�������" << s << endl;

		s = "2.";
		cout << "sӦ����2.Ҳ��������!��ʵ�������" << (s += s5 + s1 + str2 + s3 + str4[0] + str4[1] + c) << endl;

		s = NULL;
		cout << "sӦ����3.��Ҳ������!��ʵ�������" << ((s = "3.") += str4 + s5 + s1.c_str() + str2 + s3 + c) << endl;

		s = NULL;
		cout << "sӦ����4.����Ҳ����!��ʵ�������" << (((s += "4." + s3) += (str4 + s5)) += (((s1 += str2[0]) += &str2[1]) += c) ) << endl;

		s = NULL;
		s += '5';
		s += '.';
		s1 = "��";
		cout << "sӦ����5.������Ҳ��!��ʵ�������" << ((((((s += str2) += s3) += str4) += s5.c_str()) += s1.c_str()) += c) << endl;

		wait_for_enter();
	}

	if (1) {
		TStringAdv s1("This is a pencil"), s2("is"), s3;

		cout << "ɾ��(-)����(TStringAdv���TStringAdv��)" << endl;

		cout << "s1ӦΪTh is a pencil��ʵ�������" << (s1 = s1 - s2) << endl;
		s3 = s1 - s2;
		cout << "s3ӦΪTh  a pencil��  ʵ�������" << s3 << endl;

		s1 = "This is a pencil";
		cout << "s1ӦΪTh  a pencil��  ʵ�������" << s1-s2-s2-s2-s2-s2 << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s1("This is a pencil"), s2;
		const char *str1 = "is";
		const char str2[] = "is";

		cout << "ɾ��(-)����(TStringAdv���charָ�뼰����)" << endl;

		cout << "s1ӦΪTh is a pencil��ʵ�������" << (s1 = s1 - str1) << endl;
		s2 = s1 - str1;
		cout << "s2ӦΪTh  a pencil��  ʵ�������" << s2 << endl;

		s1 = "This is a pencil";
		cout << "s1ӦΪTh is a pencil��ʵ�������" << (s1 = s1 - str2) << endl;
		s2 = s1 - str2;
		cout << "s2ӦΪTh  a pencil��  ʵ�������" << s2 << endl;

		s1 = "This is a pencil";
		cout << "s1ӦΪTh  a pencil��  ʵ�������" << s1 - str1 - str1 - str1 - str1 - str1 << endl;

		s1 = "This is a pencil";
		cout << "s1ӦΪTh  a pencil��  ʵ�������" << s1 - str2 - str2 - str2 - str2 - str2 << endl;

		wait_for_enter();
	}

	if (1) {
		TStringAdv s1("This is a pencil"), s2;
		char c1 = 'i';

		cout << "ɾ��(-)����(TStringAdv���char�ַ�)" << endl;

		cout << "s1ӦΪThs is a pencil��ʵ�������" << (s1 = s1 - c1) << endl;
		s2 = s1 - c1;
		cout << "s2ӦΪThs s a pencil�� ʵ�������" << s2 << endl;

		s1 = "This is a pencil";
		cout << "s2ӦΪThs s a pencl��  ʵ�������" << (s1 - c1 - c1 - c1 - c1 - c1 - c1 - c1) << endl;

		s1 = "This is a pencil";
		cout << "s1ӦΪThi is a pencil��ʵ�������" << (s1 = s1 - 's') << endl;
		s2 = s1 - 's';
		cout << "s2ӦΪThi i a pencil�� ʵ�������" << s2 << endl;

		s1 = "This is a pencil";
		cout << "s2ӦΪThi i a pencil�� ʵ�������" << (s1 - 's' - 's' - 's' - 's' - 's' - 's') << endl;

		wait_for_enter();
	}

	if (1) {
		TStringAdv s1;
		const TStringAdv s2 = "is";
		const char *str3 = "pen", str4[] = "a";
		const char c = ' ';

		cout << "��ɾ��(-=)�򵥲���(TStringAdv���TStringAdv�ࡢ�ַ�ָ�롢�ַ����顢�ַ�)" << endl;

		s1 = "This is a red pencil";
		cout << "s1ӦΪTh is a red pencil�� ʵ�������" << (s1-=s2) << endl;

		s1 = "This is a red pencil";
		cout << "s1ӦΪThis is a red cil��  ʵ�������" << (s1-=str3) << endl;

		s1 = "This is a red pencil";
		cout << "s1ӦΪThis is  red pencil��ʵ�������" << (s1 -= str4) << endl;

		s1 = "This is a red pencil";
		cout << "s1ӦΪThisis a red pencil��ʵ�������" << (s1 -= c) << endl;

		wait_for_enter();
	}

	if (1) {
		TStringAdv s1;
		const TStringAdv s2 = "is";
		const char *str3 = "pen", str4[] = "a";
		const char c = ' ';

		cout << "��ɾ��(-=)�ۺϲ���(TStringAdv���TStringAdv�ࡢ�ַ�ָ�롢�ַ����顢�ַ�)" << endl;

		s1 = "This is a red pencil";
		cout << "s1ӦΪTh  a red pencil��   ʵ�������" << ((s1 -= s2) -= s2) << endl;

		s1 = "This is a red pencil";
		cout << "s1ӦΪThis is  red cil��   ʵ�������" << ((s1 -= str3) -= str4) << endl;

		s1 = "This is a red pencil";
		cout << "s1ӦΪThisisaredpencil��   ʵ�������" << ((((s1 -= c) -= c) -= c) -= c) << endl;

		s1 = "This is a red pencil";
		cout << "s1ӦΪTh��                 ʵ�������" << ((((((((((((s1 -= s2) -= s2) -= str3) -= str4) -= c) -= c) -= c) -= c) -= "red") -= 'c') -= 'i') -= 'l') << endl;

		wait_for_enter();
	}

	if (1) {
		TStringAdv s1("Hello"), s2;

		cout << "����(*)����(TStringAdv���int)" << endl;

		s2 = s1*2;
		cout << "s2ӦΪHelloHello��     ʵ�������" << s2 << endl;
		cout << "s1ӦΪHelloHelloHello��ʵ�������" << (s1 = s1*3) << endl;

		TString s3;
		cout << "s3ӦΪ<NULL>��         ʵ�������" << (s3*5) << endl;
		cout << "s3ӦΪ<NULL>��         ʵ�������" << (s3 = s3 * 5) << endl;

		int i, n = 100;
		s1 = "Hello";
		s2 = s1 * n;
		for (i = 1; i < n; i++)
			s2 = s2 - s1;
		cout << "s2ӦΪHello��          ʵ�������" << s2 << endl;

		s1 = "Hello";
		s2 = s1 * n;
		for (i = 0; i < n; i++)
			s2 = s2 - 'l';
		for (i = 0; i < n; i++)
			s2 = s2 - 'l';
		for (i = 0; i < n; i++)
			s2 = s2 - 'o';
		for (i = 0; i < n; i++)
			s2 = s2 - 'H';
		for (i = 1; i < n; i++)  //ע�⣬ֻ�����ѭ���Ǵ�1��ʼ������1��
			s2 = s2 - 'e';
		cout << "s2ӦΪe��              ʵ�������" << s2 << endl;

		wait_for_enter();
	}

	if (1) {
		TStringAdv s1;

		cout << "�Ը���(*=)����(TStringAdv���int)" << endl;

		s1 = "Hello";
		cout << "s1ӦΪHelloHello��                       ʵ�������" << (s1 *= 2) << endl;
		s1 += '!';
		cout << "s1ӦΪHelloHello!HelloHello!HelloHello!��ʵ�������" << (s1 *= 3) << endl;

		s1 = "Hello";
		cout << "s1ӦΪHelloHello!HelloHello!HelloHello!��ʵ�������" << (((s1 *= 2) += '!')*=3) << endl;

//		�ر���ԣ����������е�ע�ͣ������������ᱨ���������������˵�����������⣬������Ԥ�ڵ����壨Ϊʲô����ϸ��!!!��
//		cout << "s1ӦΪHelloHello!HelloHello!HelloHello!��ʵ�������" << (((s1 *= 2) + '!') *= 3) << endl;

		s1 = NULL;
		cout << "s1ӦΪ<NULL>��                           ʵ�������" << (s1 *= 100) << endl;

		wait_for_enter();
	}

	if (1) {
		TStringAdv s1;

		cout << "������(+=)/��ɾ��(-=)/�Ը���(*=)�ۺϲ���" << endl;

		s1 = "Hello";
		cout << "s1ӦΪHello!Hello!Hello!��ʵ�������" << ((s1 += '!') *= 3) << endl;

		s1 = "Hello";
		cout << "s1ӦΪHeo!Heo!Heo!Heo!��  ʵ�������" << (((s1 += '!')-="ll")*=4) << endl;

		s1 = "Hello";
		cout << "s1ӦΪHellHello!��        ʵ�������" << (((s1 *= 2) -= 'o') += '!') << endl;

		wait_for_enter();
	}

	if (1) {
		TStringAdv s1("This is a pencil");

		cout << "��ת(!)����" << endl;

		cout << " s1ӦΪThis is a pencil��ʵ�������" << s1 << endl;
		cout << "!s1ӦΪlicnep a si sihT��ʵ�������" << !s1 << endl;
		cout << " s1��ΪThis is a pencil��ʵ�������" << s1 << endl;

		s1 = NULL;
		cout << " s1ӦΪ<NULL>��          ʵ�������" << s1 << endl;
		cout << "!s1ӦΪ<NULL>��          ʵ�������" << !s1 << endl;
		cout << " s1��Ϊ<NULL>��          ʵ�������" << s1 << endl;

		wait_for_enter();
	}

	if (1) {
		TStringAdv s1="house", s2="horse", s3="house", s4="", s5=NULL;

		cout << "�Ƚ��������(����TStringAdv��)" << endl;

		cout << "��1=" << s1 << " ��2=" << s2 << "  > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << "  >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << "  < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << "  <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << "  ==���ӦΪ0��ʵ�ʣ�" <<(s1 == s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << "  !=���ӦΪ1��ʵ�ʣ�" <<(s1 != s2) << endl;

		cout << "��1=" << s1 << " ��3=" << s3 << "  > ���ӦΪ0��ʵ�ʣ�" <<(s1 >  s3) << endl;
		cout << "��1=" << s1 << " ��3=" << s3 << "  >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= s3) << endl;
		cout << "��1=" << s1 << " ��3=" << s3 << "  < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  s3) << endl;
		cout << "��1=" << s1 << " ��3=" << s3 << "  <=���ӦΪ1��ʵ�ʣ�" <<(s1 <= s3) << endl;
		cout << "��1=" << s1 << " ��3=" << s3 << "  ==���ӦΪ1��ʵ�ʣ�" <<(s1 == s3) << endl;
		cout << "��1=" << s1 << " ��3=" << s3 << "  !=���ӦΪ0��ʵ�ʣ�" <<(s1 != s3) << endl;

		cout << "��1=" << s1 << " ��4=" << s4 << " > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  s4) << endl;
		cout << "��1=" << s1 << " ��4=" << s4 << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= s4) << endl;
		cout << "��1=" << s1 << " ��4=" << s4 << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  s4) << endl;
		cout << "��1=" << s1 << " ��4=" << s4 << " <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= s4) << endl;
		cout << "��1=" << s1 << " ��4=" << s4 << " ==���ӦΪ0��ʵ�ʣ�" <<(s1 == s4) << endl;
		cout << "��1=" << s1 << " ��4=" << s4 << " !=���ӦΪ1��ʵ�ʣ�" <<(s1 != s4) << endl;

		cout << "��1=" << s1 << " ��5=" << s5 << " > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  s5) << endl;
		cout << "��1=" << s1 << " ��5=" << s5 << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= s5) << endl;
		cout << "��1=" << s1 << " ��5=" << s5 << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  s5) << endl;
		cout << "��1=" << s1 << " ��5=" << s5 << " <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= s5) << endl;
		cout << "��1=" << s1 << " ��5=" << s5 << " ==���ӦΪ0��ʵ�ʣ�" <<(s1 == s5) << endl;
		cout << "��1=" << s1 << " ��5=" << s5 << " !=���ӦΪ1��ʵ�ʣ�" <<(s1 != s5) << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s1="house";

		cout << "�Ƚ��������(TStringAdv����ַ�������)" << endl;

		cout << "��1=" << s1 << " ����=horse" << "  > ���ӦΪ1��ʵ�ʣ�" << (s1 >  "horse") << endl;
		cout << "��1=" << s1 << " ����=horse" << "  >=���ӦΪ1��ʵ�ʣ�" << (s1 >= "horse") << endl;
		cout << "��1=" << s1 << " ����=horse" << "  < ���ӦΪ0��ʵ�ʣ�" << (s1 <  "horse") << endl;
		cout << "��1=" << s1 << " ����=horse" << "  <=���ӦΪ0��ʵ�ʣ�" << (s1 <= "horse") << endl;
		cout << "��1=" << s1 << " ����=horse" << "  ==���ӦΪ0��ʵ�ʣ�" << (s1 == "horse") << endl;
		cout << "��1=" << s1 << " ����=horse" << "  !=���ӦΪ1��ʵ�ʣ�" << (s1 != "horse") << endl;

		cout << "��1=" << s1 << " ����=house" << "  > ���ӦΪ0��ʵ�ʣ�" << (s1 >  "house") << endl;
		cout << "��1=" << s1 << " ����=house" << "  >=���ӦΪ1��ʵ�ʣ�" << (s1 >= "house") << endl;
		cout << "��1=" << s1 << " ����=house" << "  < ���ӦΪ0��ʵ�ʣ�" << (s1 <  "house") << endl;
		cout << "��1=" << s1 << " ����=house" << "  <=���ӦΪ1��ʵ�ʣ�" << (s1 <= "house") << endl;
		cout << "��1=" << s1 << " ����=house" << "  ==���ӦΪ1��ʵ�ʣ�" << (s1 == "house") << endl;
		cout << "��1=" << s1 << " ����=house" << "  !=���ӦΪ0��ʵ�ʣ�" << (s1 != "house") << endl;

		cout << "��1=" << s1 << " ����=" << "       > ���ӦΪ1��ʵ�ʣ�" << (s1 >  "") << endl;
		cout << "��1=" << s1 << " ����=" << "       >=���ӦΪ1��ʵ�ʣ�" << (s1 >= "") << endl;
		cout << "��1=" << s1 << " ����=" << "       < ���ӦΪ0��ʵ�ʣ�" << (s1 <  "") << endl;
		cout << "��1=" << s1 << " ����=" << "       <=���ӦΪ0��ʵ�ʣ�" << (s1 <= "") << endl;
		cout << "��1=" << s1 << " ����=" << "       ==���ӦΪ0��ʵ�ʣ�" << (s1 == "") << endl;
		cout << "��1=" << s1 << " ����=" << "       !=���ӦΪ1��ʵ�ʣ�" << (s1 != "") << endl;

		cout << "��1=" << s1 << " ����=<NULL>" << " > ���ӦΪ1��ʵ�ʣ�" << (s1 >  NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " >=���ӦΪ1��ʵ�ʣ�" << (s1 >= NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " < ���ӦΪ0��ʵ�ʣ�" << (s1 <  NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " <=���ӦΪ0��ʵ�ʣ�" << (s1 <= NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " ==���ӦΪ0��ʵ�ʣ�" << (s1 == NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " !=���ӦΪ1��ʵ�ʣ�" << (s1 != NULL) << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s1 = NULL, s2 = "";

		/* �յ�TString��NULL��"" ����Ϊ��ȣ������ϣ�NULL�ǵ�ַ��""�Ǵ���û�пɱ��ԣ����Ǵ˴������⴦���� */
		cout << "��1=" << s1 << " ��2=" << s2 << "  > ���ӦΪ0��ʵ�ʣ�" << (s1 >  s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << "  >=���ӦΪ1��ʵ�ʣ�" << (s1 >= s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << "  < ���ӦΪ0��ʵ�ʣ�" << (s1 <  s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << "  <=���ӦΪ1��ʵ�ʣ�" << (s1 <= s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << "  ==���ӦΪ1��ʵ�ʣ�" << (s1 == s2) << endl;
		cout << "��1=" << s1 << " ��2=" << s2 << "  !=���ӦΪ0��ʵ�ʣ�" << (s1 != s2) << endl;

		cout << "��1=" << s1 << " ����=" << "       > ���ӦΪ0��ʵ�ʣ�" << (s1 >  "") << endl;
		cout << "��1=" << s1 << " ����=" << "       >=���ӦΪ1��ʵ�ʣ�" << (s1 >= "") << endl;
		cout << "��1=" << s1 << " ����=" << "       < ���ӦΪ0��ʵ�ʣ�" << (s1 <  "") << endl;
		cout << "��1=" << s1 << " ����=" << "       <=���ӦΪ1��ʵ�ʣ�" << (s1 <= "") << endl;
		cout << "��1=" << s1 << " ����=" << "       ==���ӦΪ1��ʵ�ʣ�" << (s1 == "") << endl;
		cout << "��1=" << s1 << " ����=" << "       !=���ӦΪ0��ʵ�ʣ�" << (s1 != "") << endl;

		cout << "��1=" << s1 << " ����=<NULL>" << " > ���ӦΪ0��ʵ�ʣ�" << (s1 >  NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " >=���ӦΪ1��ʵ�ʣ�" << (s1 >= NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " < ���ӦΪ0��ʵ�ʣ�" << (s1 <  NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " <=���ӦΪ1��ʵ�ʣ�" << (s1 <= NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " ==���ӦΪ1��ʵ�ʣ�" << (s1 == NULL) << endl;
		cout << "��1=" << s1 << " ����=<NULL>" << " !=���ӦΪ0��ʵ�ʣ�" << (s1 != NULL) << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s1="house";
		const char *str2="horse", *str3="house", *str4="", *str5=NULL;

		cout << "�Ƚ��������(TStringAdv����ַ�ָ��)" << endl;

		cout << "��1=" << s1 << " ��2=" << str2 << "  > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << "  >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << "  < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << "  <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << "  ==���ӦΪ0��ʵ�ʣ�" <<(s1 == str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << "  !=���ӦΪ1��ʵ�ʣ�" <<(s1 != str2) << endl;

		cout << "��1=" << s1 << " ��3=" << str3 << "  > ���ӦΪ0��ʵ�ʣ�" <<(s1 >  str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << "  >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << "  < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << "  <=���ӦΪ1��ʵ�ʣ�" <<(s1 <= str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << "  ==���ӦΪ1��ʵ�ʣ�" <<(s1 == str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << "  !=���ӦΪ0��ʵ�ʣ�" <<(s1 != str3) << endl;

		cout << "��1=" << s1 << " ��4=" << str4 << "       > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << "       >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << "       < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << "       <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << "       ==���ӦΪ0��ʵ�ʣ�" <<(s1 == str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << "       !=���ӦΪ1��ʵ�ʣ�" <<(s1 != str4) << endl;

		cout << "��1=" << s1 << " ��5=<NULL>" << " > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  str5) << endl;
		cout << "��1=" << s1 << " ��5=<NULL>" << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= str5) << endl;
		cout << "��1=" << s1 << " ��5=<NULL>" << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  str5) << endl;
		cout << "��1=" << s1 << " ��5=<NULL>" << " <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= str5) << endl;
		cout << "��1=" << s1 << " ��5=<NULL>" << " ==���ӦΪ0��ʵ�ʣ�" <<(s1 == str5) << endl;
		cout << "��1=" << s1 << " ��5=<NULL>" << " !=���ӦΪ1��ʵ�ʣ�" <<(s1 != str5) << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s1="house";
		char str2[]="horse", str3[]="house", str4[]="";

		cout << "�Ƚ��������(TStringAdv����ַ�ָ��)" << endl;

		cout << "��1=" << s1 << " ��2=" << str2 << " > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " ==���ӦΪ0��ʵ�ʣ�" <<(s1 == str2) << endl;
		cout << "��1=" << s1 << " ��2=" << str2 << " !=���ӦΪ1��ʵ�ʣ�" <<(s1 != str2) << endl;

		cout << "��1=" << s1 << " ��3=" << str3 << " > ���ӦΪ0��ʵ�ʣ�" <<(s1 >  str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " <=���ӦΪ1��ʵ�ʣ�" <<(s1 <= str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " ==���ӦΪ1��ʵ�ʣ�" <<(s1 == str3) << endl;
		cout << "��1=" << s1 << " ��3=" << str3 << " !=���ӦΪ0��ʵ�ʣ�" <<(s1 != str3) << endl;

		cout << "��1=" << s1 << " ��4=" << str4 << "      > ���ӦΪ1��ʵ�ʣ�" <<(s1 >  str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << "      >=���ӦΪ1��ʵ�ʣ�" <<(s1 >= str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << "      < ���ӦΪ0��ʵ�ʣ�" <<(s1 <  str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << "      <=���ӦΪ0��ʵ�ʣ�" <<(s1 <= str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << "      ==���ӦΪ0��ʵ�ʣ�" <<(s1 == str4) << endl;
		cout << "��1=" << s1 << " ��4=" << str4 << "      !=���ӦΪ1��ʵ�ʣ�" <<(s1 != str4) << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s1="tong", s2;

		cout << "�󳤶Ȳ���(length()����)" << endl;

		cout << "s1Ϊtong��  ����ӦΪ4��ʵ�ʣ�" << s1.length() << endl;
		cout << "s2Ϊ<NULL>������ӦΪ0��ʵ�ʣ�" << s2.length() << endl;
		s2 = s1+"ji";
		cout << "s2Ϊtongji������ӦΪ6��ʵ�ʣ�" << s2.length() << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s1="tong", s2;

		cout << "�󳤶Ȳ���(TStringLen()����)" << endl;

		cout << "s1Ϊtong��  ����ӦΪ4��ʵ�ʣ�" << TStringLen(s1) << endl;
		cout << "s2Ϊ<NULL>������ӦΪ0��ʵ�ʣ�" << TStringLen(s2) << endl;
		cout << "��Ϊtongji������ӦΪ6��ʵ�ʣ�" << TStringLen(s1+(s2="ji")) << endl;
		cout << "��Ϊtongji������ӦΪ6��ʵ�ʣ�" << TStringLen(s1+"ji") << endl;
		cout << "��Ϊtongji������ӦΪ6��ʵ�ʣ�" << TStringLen(s2=s1+"ji") << endl;
		cout << "��Ϊtong��  ����ӦΪ4��ʵ�ʣ�" << TStringLen(s1+(char *)NULL) << endl;

		wait_for_enter();
		}

	if (1) {
		TStringAdv s1 = "house";
		TStringAdv s2[4] = { "yangpu", "sipingroad", "tongji", "shanghai" };
		int i, j;
		char ch = 'P';

		cout << "[]���������" << endl;

		cout << "��1��" << s1 << "�����δ�ӡ�ַ��Ľ���ǣ�";
		for (i = 0; i < s1.length(); i++)
			cout << s1[i] << ' ';
		cout << endl << endl;

		cout << "��1��" << s1 << "�����δ�ӡ�ַ�intֵ�Ľ���ǣ���Խ�磩��" << endl;
		for (i = -4; i < s1.length()+4; i++)
			cout << int(s1[i]) << ' ';
		cout << endl << endl;

		s1[0] = s1[0] - 32;
		cout << "��1��" << s1 << "�����δ�ӡ�ַ��Ľ���ǣ�";
		for (i = 0; i < s1.length(); i++)
			cout << s1[i] << ' ';
		cout << endl << endl;

		s1[1] = 'A';
		s1[2] = ch;
		ch += 32;
		s1[3] = ch;
		s1[4] = 'Y';
		cout << "��1��" << s1 << "�����δ�ӡ�ַ��Ľ���ǣ�";
		for (i = 0; i < s1.length(); i++)
			cout << s1[i] << ' ';
		cout << endl << endl;

		cout << "��2������4���ַ��������δ�ӡ�ַ��Ľ���ǣ�" << endl;
		for (i = 0; i < 4; i++) {
			cout << setw(16) << s2[i] << " => ";
			for (j = 0; j < s2[i].length(); j++)
				cout << s2[i][j] << ' ';
			cout << endl;
			}
		cout << endl;

		cout << "��2������4���ַ���������ĸ��д�����δ�ӡ�ַ��Ľ���ǣ�" << endl;
		for (i = 0; i < 4; i++) {
			s2[i][0] -= 32;
			cout << setw(16) << s2[i] << " => ";
			for (j = 0; j < s2[i].length(); j++)
				cout << s2[i][j] << ' ';
			cout << endl;
			}
		cout << endl;

		wait_for_enter();
		}

	if (1)
	{
		TStringAdv s1("Hello"), s2;

		cout << "assign����ֵ��������" << endl;

		cout << "s1Ӧ����Hello�� ʵ�������" << s1 << endl;

		s2.assign(s1);
		cout << "s2Ӧ����Hello�� ʵ�������" << s2 << endl;

		s1.assign("Hi");
		cout << "s1Ӧ����Hi��    ʵ�������" << s1 << endl;

		s2.assign("");
		cout << "s2Ӧ����<NULL>, ʵ�������" << s2 << endl;

		s1.assign(NULL);
		cout << "s1Ӧ����<NULL>��ʵ�������" << s1 << endl;

		wait_for_enter();
	}

	if (1)
	{
		TStringAdv s1("tong"), s2 = "ji";
		const char* str3 = "tong", str4[] = "ji";

		cout << "β��׷��(append)�򵥲���(TStringAdv���TStringAdv�ࡢ�ַ�ָ�롢�ַ����顢�ַ�)" << endl;

		s1.append(s2);
		cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

		s1.assign("tong");
		s1.append(str4);
		cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

		s1.assign("tong");
		s2.append(s1);
		cout << "s2ӦΪjitong��ʵ�������" << s2 << endl;

		s2.assign("ji");
		s2.append(str3);
		cout << "s2ӦΪjitong��ʵ�������" << s2 << endl;

		s1.assign("tong");
		s1.append('j');
		s1.append('i');
		cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

		wait_for_enter();
	}

	if (1)
	{
		TStringAdv s1("row the boat"), s2 = " row";
		const char* str3 = " row", str4[] = "Let's sing: ";

		cout << "����(insert)��ȷ����(����TStringAdv���ַ�ָ�롢�ַ����顢�ַ�)" << endl;

		cout << "s1ӦΪrow the boat��                     ʵ�������" << s1 << endl;

		s1.insert(s2, 4);
		cout << "s1ӦΪrow row the boat��                 ʵ�������" << s1 << endl;

		s1.insert(str3, 8);
		cout << "s1ӦΪrow row row the boat��             ʵ�������" << s1 << endl;

		s1.insert(str4, 1);
		cout << "s1ӦΪLet's sing: row row row the boat�� ʵ�������" << s1 << endl;

		s1.insert('!', 33);
		cout << "s1ӦΪLet's sing: row row row the boat!��ʵ�������" << s1 << endl;

		wait_for_enter();
	}

	if (1)
	{
		TStringAdv s1("row the boat"), s2 = " row", s3;
		const char* str4 = " row", str5[] = "Let's sing: ";

		cout << "����(insert)�Ƿ�����(�Ƿ�����TStringAdv���ַ�ָ�롢�ַ����顢�ַ�)" << endl;

		cout << "s1ӦΪrow the boat��ʵ�������" << s1 << endl;

		s1.insert(s2, -1);//posԽ��
		cout << "s1ӦΪrow the boat��ʵ�������" << s1 << endl;

		s1.insert(s2, 14);//posԽ��
		cout << "s1ӦΪrow the boat��ʵ�������" << s1 << endl;

		s1.insert(s3, 1);//����մ�
		cout << "s1ӦΪrow the boat��ʵ�������" << s1 << endl;

		s1.insert("", 1);//����մ�
		cout << "s1ӦΪrow the boat��ʵ�������" << s1 << endl;

		s1.insert(str4, 0);//posԽ��
		cout << "s1ӦΪrow the boat��ʵ�������" << s1 << endl;

		s1.insert(str5, 100);//posԽ��
		cout << "s1ӦΪrow the boat��ʵ�������" << s1 << endl;

		s1.insert('s', 0);//posԽ��
		cout << "s1ӦΪrow the boat��ʵ�������" << s1 << endl;

		wait_for_enter();
	}

	if (1)
	{
		TStringAdv s1("rowtheboat"), s2 = "row", s3;
		const char* str4 = "row", str5[] = "boat";

		cout << "ɾ��(erase)����(TStringAdv���ַ�ָ�롢�ַ������ַ�)" << endl;
		
		cout << "s1ӦΪrowtheboat��       ʵ�������" << s1 << endl;

		s1.erase(s2);
		cout << "s1ӦΪtheboat��          ʵ�������" << s1 << endl;

		s1.insert(s2, 8);
		s1.insert(s2, 1);
		s1.erase("row");
		cout << "s1ӦΪtheboatrow��       ʵ�������" << s1 << endl;

		s1.erase(s3);//ɾ���մ�
		cout << "s1ӦΪtheboatrow��       ʵ�������" << s1 << endl;

		s1.erase("");//ɾ���մ�
		cout << "s1ӦΪtheboatrow��       ʵ�������" << s1 << endl;

		s1.erase(str4);
		cout << "s1ӦΪtheboat��          ʵ�������" << s1 << endl;

		s1.erase(str5);
		cout << "s1ӦΪthe��              ʵ�������" << s1 << endl;

		s1.erase(str4);//�Ҳ���
		cout << "s1ӦΪthe��              ʵ�������" << s1 << endl;

		s1.erase('a');//�Ҳ���
		cout << "s1ӦΪthe��              ʵ�������" << s1 << endl;

		for (int k = 1; k <= 3; k++)
			s1.insert("why?", 1);
		for (int k = 1; k <= 2; k++)
			s1.erase('?');
		cout << "s1ӦΪwhywhywhy?the��    ʵ�������" << s1 << endl;

		wait_for_enter();
	}

	if (1)
	{
		TStringAdv s1("Five hundred-twenty five thousand six hundred minutes"), s2, s3;

		cout << "����ȡ�Ӵ�(substr)" << endl;

		s3 = s1.substr(6);//ȱʡȡ��ĩβ
		cout << "s3ӦΪhundred-twenty five thousand six hundred minutes,      ʵ�������" << s3 << endl;

		s3 = s1.substr(1, 4);
		cout << "s3ӦΪFive��                                                 ʵ�������" << s3 << endl;

		s3 = s1.substr(6, 14);
		cout << "s3ӦΪhundred-twenty��                                       ʵ�������" << s3 << endl;

		s3 = s1.substr(60);//pos������Χ
		cout << "s3ӦΪ<NULL>��                                               ʵ�������" << s3 << endl;

		s3 = s1.substr(100, 2);//pos������Χ
		cout << "s3ӦΪ<NULL>��                                               ʵ�������" << s3 << endl;

		s3 = s1.substr(1, 0);//lenΪ0
		cout << "s3ӦΪ<NULL>��                                               ʵ�������" << s3 << endl;

		s3 = s1.substr(1, -1);//lenΪ����
		cout << "s3ӦΪ<NULL>��                                               ʵ�������" << s3 << endl;

		s3 = s1.substr(1, 100);//len������Χ
		cout << "s3ӦΪFive hundred-twenty five thousand six hundred minutes��ʵ�������" << s3 << endl;

		s3 = s2.substr(1);//ȡ�մ����Ӵ�
		cout << "s3ӦΪ<NULL>��                                               ʵ�������" << s3 << endl;

		s3 = s2.substr(1, 1);//ȡ�մ����Ӵ�
		cout << "s3ӦΪ<NULL>��                                               ʵ�������" << s3 << endl;

		wait_for_enter();
	}

	if (1)
	{
		TStringAdv s1("horse");
		TStringAdv s2[4] = { "yangpu", "sipingroad", "tongji", "shanghai" };

		cout << "����ȡ�ַ�(at)" << endl;

		cout << "s1��" << s1 << "�����δ�ӡ�����ַ�Ϊ��";
		for (int i = 0; i < s1.length(); i++)
			cout << s1.at(i) << ' ';
		cout << endl << endl;

		cout << "s1��" << s1 << "�����δ�ӡ�ַ�intֵ�Ľ���ǣ���Խ�磩��" << endl;
		for (int i = -4; i < s1.length() + 4; i++)
			cout << int(s1.at(i)) << ' ';
		cout << endl << endl;

		s1.at(0) = s1.at(0) - 32;
		cout << "s1��" << s1 << "�����δ�ӡ�ַ��Ľ���ǣ�";
		for (int i = 0; i < s1.length(); i++)
			cout << s1.at(i) << ' ';
		cout << endl << endl;

		s1.at(2) = 'u';
		cout << "s1ӦΪHouse��ʵ�������" << s1 << endl;

		cout << "��2������4���ַ��������δ�ӡ�ַ��Ľ���ǣ�" << endl;
		for (int i = 0; i < 4; i++) {
			cout << setw(16) << s2[i] << " => ";
			for (int j = 0; j < s2[i].length(); j++)
				cout << s2[i].at(j) << ' ';
			cout << endl;
		}
		cout << endl << endl;

		cout << "��2������4���ַ���������ĸ��д�����δ�ӡ�ַ��Ľ���ǣ�" << endl;
		for (int i = 0; i < 4; i++) {
			s2[i].at(0) -= 32;
			cout << setw(16) << s2[i] << " => ";
			for (int j = 0; j < s2[i].length(); j++)
				cout << s2[i].at(j) << ' ';
			cout << endl;
		}
		cout << endl;
		
		wait_for_enter();
	}
#if !(defined(__linux) || defined(__linux__))
	system("pause"); //Linux����Ҫ
#endif

	return 0;
}