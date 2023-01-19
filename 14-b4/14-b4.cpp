/*2050598 ����� ͨ��*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

#define     IP_ERROR     1
#define     IP_CORRECT   2
#define     PN_ERROR     3//para name����
#define     APD_ERROR    4//û�и��Ӳ���
#define     NOT_VALID    5//������-��ͷ�ĺϷ�����
#define     PARA_CORRECT 6//������ȷ

#define     PARA_VALUE_END -999//������־

typedef struct parameter{
	const char name[3] = { '\0' };
	int append_num;//���Ӳ�������
	int append_para;//���Ӳ���
	const int min;
	const int max;
}PARAMETER;

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ж�һ���ַ����Ƿ�Ϊip
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int JudgeIP(char* ch)
{
	int mark1 = 0;
	int mark2 = 0;
	int mark3 = 0;//��ǵ��λ��
	int i, j, k;
	for (i = 0; ch[i] != '\0'; i++)
	{
		if (ch[i] == '.')
		{
			mark1 = i;
			break;
		}
	}
	for (j = i + 1; ch[j] != '\0'; j++)
	{
		if (ch[j] == '.')
		{
			mark2 = j;
			break;
		}
	}
	for (k = j + 1; ch[k] != '\0'; k++)
	{
		if (ch[k] == '.')
		{
			mark3 = k;
			break;
		}
	}
	if (mark1 == 0 || mark2 == 0 || mark3 == 0 || mark1 + 1 == mark2 || mark2 + 1 == mark3
		|| mark1 > 4 || mark2 - mark1 > 4 || mark3 - mark2 > 4)
	{
		return IP_ERROR;
	}
	char num_ch[4][4] = { '\0' };
	for (i = 0; i < mark1; i++)
	{
		if (ch[i] >= '0' && ch[i] <= '9')
			num_ch[0][i] = ch[i];
		else
		{
			return IP_ERROR;
		}
	}

	j = 0;
	for (i = mark1 + 1; i < mark2; i++)
	{
		if (ch[i] >= '0' && ch[i] <= '9')
		{
			num_ch[1][j] = ch[i];
			j++;
		}
		else
		{
			return IP_ERROR;
		}
	}

	j = 0;
	for (i = mark2 + 1; i < mark3; i++)
	{
		if (ch[i] >= '0' && ch[i] <= '9')
		{
			num_ch[2][j] = ch[i];
			j++;
		}
		else
		{
			return IP_ERROR;
		}
	}

	j = 0;
	for (i = mark3 + 1; ch[i] != '\0'; i++)
	{
		if (ch[i] >= '0' && ch[i] <= '9')
		{
			num_ch[3][j] = ch[i];
			j++;
		}
		else
		{
			return IP_ERROR;
		}
	}

	int num[4];
	for (i = 0; i <= 3; i++)
	{
		num[i] = atoi(num_ch[i]);
		if (num[i] < 0 || num[i] > 255)
		{
			return IP_ERROR;
		}
	}

	return IP_CORRECT;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��жϲ�������
  ���������main�����������������б�
  �� �� ֵ��
  ˵    ����c[arg-1]��IP��ַ
***************************************************************************/
int Judge(const int arg, char* c[], PARAMETER para[])
{
	int i = 1;
	int j;

	while (i < arg - 1)
	{
		if (c[i][0] == '-')//����ַ�����-��ͷ
		{
			bool find = 0;
			for (j = 0; para[j].append_num != PARA_VALUE_END; j++)
			{
				if (!strcmp(c[i], para[j].name))//���Ƿ��ж�Ӧ�Ĳ���
				{
					find = 1;
					break;
				}
			}
			if (find == 0)
			{
				cout << "����" << c[i] << "������" << endl;
				return PN_ERROR;
			}
			if ( para[j].append_num == 0)//���û�и��Ӳ���
			{
				para[j].append_para = 1;//�����˸��Ӳ�������1
				i++;
			}
			else
			{
				if (c[i + 1][0] == '-'|| i + 1 == arg - 1)
				{
					cout << "����" << c[i] << "û�к�������" << endl;
					return APD_ERROR;
				}
				int n = atoi(c[i + 1]);
				if (n != 0 || (n == 0 && !strcmp(c[i + 1], "0")))//���ת������Ч��
				{
					if (n >= para[j].min && n <= para[j].max)
						para[j].append_para = n;
				}
				i += 1 + para[j].append_num;
			}
		}
		else
		{
			cout << "������-��ͷ�ĺϷ�����" << endl;
			return NOT_VALID;
		}
	}
	return PARA_CORRECT;
}

//������������
int CountLength(int n)
{
	int length = 1;
	while (1)
	{
		n /= 10;
		if (n != 0)
			length++;
		else
			break;
	}
	return length;
}

void usage(PARAMETER para[], const char* const procname)
{
	cout << "Usage: " << procname << " [" << para[0].name << " ��С][" << para[1].name << " ����][" << para[2].name << "] IP��ַ" << endl;
	cout << setw(7) << " ";
	cout << setw(34) << setfill('=') << "=" << endl;
	cout << setw(8) << setfill(' ') << " ";
	cout << "���� ���Ӳ��� ��Χ        Ĭ��ֵ" << endl;
	for (int i = 0; para[i].append_num != PARA_VALUE_END; i++)
	{
		cout << setw(8) << setfill(' ') << " " << para[i].name << "   " << setiosflags(ios::left) << setw(9) << para[i].append_num << "[" << para[i].min << ".." << para[i].max << "]";
		if (4 + CountLength(para[i].min) + CountLength(para[i].max) < 12)
			cout << setfill(' ') << setw(8 - CountLength(para[i].min) - CountLength(para[i].max)) << " ";
		cout << para[i].append_para << endl;
	}
	cout << setfill(' ') << setw(7) << " ";
	cout << setw(34) << setfill('=') << "=" << endl;
}

int main(int argc, char* argv[])
{
	PARAMETER para[] = {
		{"-l",1,64,32,64000},
		{"-n",1,4,1,1024},
		{"-t",0,0,0,1},
		{"",PARA_VALUE_END,PARA_VALUE_END,PARA_VALUE_END,PARA_VALUE_END}//��β
	};
	if (argc == 1)
	{
		usage(para, argv[0]);
		return 0;
	}
	if (JudgeIP(argv[argc - 1]) == IP_ERROR)
	{
		cout << "IP��ַ����" << endl;
		return 0;
	}
	if (argc >= 3)
	{
		if (Judge(argc, argv, para) != PARA_CORRECT)
			return 0;
	}
	for (int i = 0; para[i].append_num != PARA_VALUE_END; i++)
		cout << para[i].name << " ������" << para[i].append_para << endl;
	cout << "IP��ַ��" << argv[argc - 1] << endl;
	return 0;
}