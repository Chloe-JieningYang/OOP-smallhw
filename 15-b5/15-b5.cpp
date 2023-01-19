/* 2050598 ͨ�� ����� */ 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
//���������Ҫ��ϵͳͷ�ļ� 
using namespace std;

#define FAIL_OPEN        -1

#define SINGLE_NOTE      1
#define MULTIPLE_NOTE    2
#define ERROR_NOTE       3//����//��ͷ����ͬһ��/*

#define SPECIAL_TYPE     4//���� ָ/**/����

/* 1�������Զ�������
   2����������ȫ�ֱ���������ֻ�����궨�壩 
   3�������Զ��庯���������е��Զ��庯���У���second_line_check�е�read_stulist������������������κε�cout���� 
   4����main�����⣬������ʹ��goto��� 
*/

struct partner {
	int no;
	char name[40] = { '\0' };
};

struct student {
	int class_no;//�κ�
	int no;//ѧ��
	char name[33] = { '\0' };//����
	int g_ok;//ԭʼ����b2)����ȷ��
	int c_ok;//������(b3)��ȷ��
	int c_de_point1 = 0;//������۷�1
	int c_de_point2 = 0;//������۷�2
	int partner_num = 0;//���������
	partner check_group[20];//������Ż���ͬѧ����Ϣ
};

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ȡ�κ�.dat�ļ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int read_stulist(char filename[], ostringstream& msg, student stu[], int& stu_num)
{
	ifstream fin;
	int line_count = 1;//����
	int stu_count = 0;//����ѧ���� Ҳ�ǵ�ǰstu�����±���
	fin.open(filename, ios::in | ios::binary);
	if (!fin.is_open())
	{
		return FAIL_OPEN;
	}
	while (!fin.eof())
	{
		char class_no[10] = { '\0' };
		char stu_no[10] = { '\0' };
		char info[500] = { '\0' };
		fin.getline(info, 400, '\n');

		if (strlen(info) == 0)
			break;

		if (info[0] == '#')//�����ע����
		{
			msg << "\t--> ѧ������[" << filename << "]�еĵ�[" << line_count << "]��Ϊע���У�����" << endl;
			line_count++;
			continue;
		}
	
		istringstream in(info);
		in >> class_no >> stu_no >> stu[stu_count].name >> stu[stu_count].g_ok >> stu[stu_count].c_ok;
		stu[stu_count].class_no = atoi(class_no);
		stu[stu_count].no = atoi(stu_no);
		if (stu[stu_count].g_ok != 0)
			stu[stu_count].g_ok = 1;
		if (stu[stu_count].c_ok != 0)
			stu[stu_count].c_ok = 1;

		bool re_stu = 0;//�Ƿ��ظ�
		if (stu_count > 0)//����ظ�
		{
			for (int n = 0; n <= stu_count - 1; n++)
			{
				if (stu[n].no == stu[stu_count].no)
				{
					re_stu = 1;
				}
			}
		}

		if (re_stu == 0)
		{
			line_count++;
			stu_count++;
		}
		else
		{
			msg << "\t--> ѧ������[" << filename << "]�еĵ�[" << line_count << "]��ѧ��[" << stu[stu_count].no << "]�ظ�������" << endl;
			line_count++;
		}
	}

	stu_num = stu_count;
	msg << "��ȡ��ɣ���[" << line_count - 1 << "]�������ݣ�ȥ�غ�ѧ������[" << stu_count << "]��";

	fin.close();
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ������ӡ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void print_stulist(student stu[], int stu_num, ostringstream& msg)
{
	for (int i = 0; i <= stu_num - 2; i++)//�Ȱ���ѧ������
	{
		for (int j = i + 1; j <= stu_num - 1; j++)
		{
			if (stu[i].no > stu[j].no)
			{
				student temp;
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}

	for (int i = 0; i < stu_num - 1; i++)//���տκ�ð������
	{
		for (int j = 0; j < stu_num - i - 1; j++)
		{
			if (stu[j].class_no > stu[j + 1].class_no)
			{
				student temp;
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
	msg << "���\t�κ�\tѧ��\t����\tԭʼ������ȷ\tУ�������ȷ" << endl;
	for (int n = 0; n <= stu_num - 1; n++)
	{
		msg << n + 1 << "#\t" << stu[n].class_no << "\t" << stu[n].no << "\t" << stu[n].name << "\t" << stu[n].g_ok << "\t" << stu[n].c_ok;
		if (n != stu_num - 1)
			msg << endl;
	}

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ж��Ƿ��ǿ���
  ���������
  �� �� ֵ���ǿ��з���0 ���ǿ��з���1
  ˵    ����
***************************************************************************/
bool JudgeCh(char ch[])
{
	if (strlen(ch) == 0)
		return 0;
	for (int i = 0; i <= (int)strlen(ch) - 1; i++)
	{
		if (ch[i] != '\r' && ch[i] != '\n' && ch[i] != ' ' && ch[i] != 0x09)
			return 1;
	}
	return 0;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ��ж�һ��֮���Ƿ���//�� / *��ͷ,�����/ *��ͷ���Ƿ��ж�Ӧ��β �Լ���
			�Ͽ�ͷ���һ���ַ�����ɾ�����һ���ַ������β֮��Ŀո�/�Ʊ���ͽ�β
  ���������
  �� �� ֵ��ע�����ͣ�һ��or���У� ���������Ƿ��пո��\t 1Ϊ�пո� 0Ϊ�޿ո�
  ˵    ����
***************************************************************************/
int Analyse2nd(char (& ch)[350], bool& begin_blank)
{
	int length = strlen(ch);
	int type;
	int p;
	for (p = 0; p <= length - 1; p++)
	{
		if (ch[p] != '\t' && ch[p] != ' ')
			break;
	}
	//pָ���һ����Ϊ�ո��\t���ַ�
	if (ch[p] != '/')
		return ERROR_NOTE;

	if (length == p + 1)//������Ȳ���
		return ERROR_NOTE;

	if (ch[p + 1] == '*')
	{
		type = MULTIPLE_NOTE;
		if (length == p + 2)
			return ERROR_NOTE;
		if (ch[p + 2] != ' ' && ch[p + 2] != '\t')//���//�������������Ч�ַ�
			begin_blank = 0;
		else
			begin_blank = 1;
	}
	else if (ch[p + 1] == '/')
	{
		type = SINGLE_NOTE;
		if (length == p + 2)
			return ERROR_NOTE;
		if (ch[p + 2] != ' ' && ch[p + 2] != '\t')//���//�������������Ч�ַ�
			begin_blank = 0;
		else
			begin_blank = 1;
		/*�ѻ��з��Ϳո�ȥ��*/
		int sp = sizeof(ch) - 1;
		for (int i = 0; i <= (int)sizeof(ch) - 1; i++)
		{
			if (ch[i] == '\n' || ch[i] == '\r')
			{
				ch[i] = '\0';
				sp = i;
			}
		}
		/*�ѻ���ǰ�Ŀո�ȥ��*/
		int j = sp - 1;
		while (1)
		{
			if (ch[j] != '\r' && ch[j] != '\n' && ch[j] != '\t' && ch[j] != ' ')
				break;
			if (ch[j] == ' ' || ch[j] == '\t')
				ch[j] = '\0';
			j--;
		}
		return type;
	}
	else
		return ERROR_NOTE;

	p += 2;

	bool find = 0;
	bool all_blank = 1;//�ж��м��Ƿ�ȫ�ǿո�
	for (; p <= length - 2; p++)
	{
		if (ch[p] == '*' && ch[p + 1] == '/')
		{
			find = 1;
			break;
		}
		if (ch[p] != ' ' && ch[p] != '\t')
			all_blank = 0;//����б���ַ��Ͳ���ȫ�ǿո�
	}
	if (find == 0)
		return ERROR_NOTE;
	if (all_blank == 1)//�������ȫ�ǿո�
		return SPECIAL_TYPE;
	
	int p2 = p - 1;
	//��*/���������ȫ���\0
	int s = sizeof(ch);
	for (; p <= s - 1; p++)
		ch[p] = '\0';

	//��*/ǰ��Ŀո�ȫȥ��
	while (1)
	{
		if (ch[p2] != ' ' && ch[p2] != '\t')
			break;
		ch[p2] = '\0';
		p2--;
	}
	return MULTIPLE_NOTE;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ڶ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int read_2nd_line(char filename[], student stu[], int stu_num, ostringstream& msg)
{	
	msg << "���\t�κ�\tѧ��\t����\t�ļ���\t�������" << endl;

	for (int s = 0; s < stu_num; s++)//����ѧ��ѭ��
	{
		ifstream fin;//д�����棬����getline�������ʱ��������״̬
		char note[350] = { '\0' };//����װһ�е�ע��
		int fault = 0;//����ĸ�������������������Ƿ�Ҫ��\t��

		msg << s + 1 << "#\t" << stu[s].class_no << "\t" << stu[s].no << "\t" << stu[s].name << "\t" << filename << "\t";

		char fn[100] = { '\0' };//������filename
		sprintf(fn, "./source/%d-%s/%d-%s-%s", stu[s].class_no, filename, stu[s].no, stu[s].name, filename);
		fin.open(fn, ios::in | ios::binary);
		if (!fin.is_open())
		{
			msg << "δ�ύ" << endl;
			stu[s].c_ok = 0;//������ԭʼ��Ϊ0
			continue;
		}

		bool overfl = 0;
		while (1)//��ǰ��Ŀ��к͵�һ�ж���
		{
			char rubbish[300] = { '\0' };
			fin.getline(rubbish, 290, '\n');
			if (strlen(rubbish) >= 255)
			{
				msg << "�ǿ��г����˺�����[256]�ֽ�." << endl;
				overfl = 1;
				fin.close();
				break;
			}
			if (JudgeCh(rubbish) == 1)
				break;
		}
		if (overfl == 1)
			continue;

		overfl = 0;
		while (1)
		{
			for (int n = 0; n <= (int)sizeof(note) - 1; n++)
				note[n] = '\0';
			fin.getline(note, 340, '\n');//����ڶ���
			if (!fin.good())
			{
				fin.clear();
			}
			if (strlen(note) >= 255)
			{
				msg << "�ǿ��г����˺�����[256]�ֽ�." << endl;
				fin.close();
				overfl = 1;
				break;
			}
			if (JudgeCh(note) == 1)
				break;
		}

		if (overfl == 1)
			continue;

		bool begin_blank;
		int analyse = Analyse2nd(note, begin_blank);


		if (analyse == ERROR_NOTE)
		{
			msg << "��2����Ϣ�д�[����//��/*��ͷ��������/*��ͷ��*/����ͬһ��]" << endl;
			fin.close();
			continue;
		}

		if (analyse == SPECIAL_TYPE)
		{
			msg << "ok" << endl;
			fin.close();
			continue;
		}

		istringstream in(note);
		int count = 0;//����ѧ���ĸ���

		while (in.good())//��ѧ��������
		{
			char no[260] = { '\0' };
			char name[260] = { '\0' };
			int noi;

			if (count == 0)//��������һ��
			{
				if (begin_blank == 1)//���//�����֮���пո�
				{
					char rub[260];
					in >> rub >> no;
					
				}
				else {
					in >> no;
					
					int len = (int)(strlen(no));
					for (int i = 2; i <= len - 1; i++)//������ǰŲ2λ �ߵ�//
					{
						no[i - 2] = no[i];
						no[i] = '\0';
					}
				}
			}
			else
				in >> no;
						
			if (strlen(no) > 63)
			{
				int len = strlen(no);
				for (int n = 63; n <= len - 1; n++)
					name[n - 63] = no[n];
				no[63] = '\0';			
			}
			else if (!in.good())//�Ѿ����ļ�ĩβ��
			{
				fault++;//����һ������
				if (fault > 1)
					msg << "\t\t\t\t\t";
				msg << "��[" << count << "]��ѧ���������Ϣ��ȫ������" << endl;
				in.clear();
				break;
			}
			else
				in >> name;//��������
			/*
			if (strlen(name) == 2 && name[0] == '*' && name[1] == '/')
			{
				fault++;//����һ������
				if (fault > 1)
					msg << "\t\t\t\t\t";
				msg << "��[" << count << "]��ѧ���������Ϣ��ȫ������" << endl;
				break;
			}
			*/
			
			count++;//��ѧ������
			noi = atoi(no);
			bool find = 0;
			int i;

			if (noi == stu[s].no)
			{
				fault++;//����һ������
				if (fault > 1)
					msg << "\t\t\t\t\t";
				msg << "��[" << count << "]��д���Լ���ˣ����ô��" << endl;
				break;
			}

			for (i = 0; i <= stu_num - 1; i++)//������ѧ���������ѧ��
			{
				if (stu[i].no == noi)
				{
					find = 1;
					break;
				}
			}

			if (find == 1 && strcmp(name, stu[i].name) == 0)//�ҵ���������һ��
			{	
				bool restu = 0;
				for (int j = 0; j < stu[s].partner_num; j++)//����Ƿ��ظ�дͬһ����
				{
					if (noi == stu[s].check_group[j].no)//����ظ�
					{
						fault++;//����һ������
						if (fault > 1)
							msg << "\t\t\t\t\t";
						msg << "�����б��[" << count << "]���ѧ��[" << noi << "]�ظ�������" << endl;
						restu = 1;
						break;
					}
				}
				if (restu == 1)//������ظ���ѧ��
					continue;//����һ��
				

				stu[s].partner_num++;//����������һ			

				stu[s].check_group[stu[s].partner_num - 1].no = noi;//�����ֵ
				strcpy(stu[s].check_group[stu[s].partner_num - 1].name, name);
			
			}
			else
			{
				fault++;
				if (fault > 1)
					msg << "\t\t\t\t\t";
				msg << "��[" << count << "]���ѧ��[" << no << "]/����[" << name << "]����ȷ������" << endl;
			}
		}
		if (stu[s].partner_num == 0)
			continue;
		if (fault == 0)
			msg << "ok" << endl;
		msg << "\t��������ȷ������" << endl;
		/*�Ȱ�ѧ���Ÿ���*/
		for (int m = 0; m <= stu[s].partner_num - 1 - 1; m++)
		{
			for (int n = m + 1; n <= stu[s].partner_num - 1; n++)
			{
				if (stu[s].check_group[m].no > stu[s].check_group[n].no)
				{
					partner temp;
					temp = stu[s].check_group[m];
					stu[s].check_group[m] = stu[s].check_group[n];
					stu[s].check_group[n] = temp;
				}
			}
		}
		/*���*/
		for (int n = 0; n <= stu[s].partner_num - 1; n++)
		{
			msg << "\t" << n + 1 << "\t" << stu[s].check_group[n].no << "\t" << stu[s].check_group[n].name << endl;
		}
		
		fin.close();
	}

	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ڶ���ƥ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void print_2nd_line(student stu[], int stu_num, ostringstream& msg)
{
	msg << "���\t�κ�\tѧ��\t����" << endl;
	for (int s = 0; s <= stu_num - 1; s++)//������ѧ������ѭ��
	{
		msg << s + 1 << "#\t" << stu[s].class_no << "\t" << stu[s].no << "\t" << stu[s].name;
		if (stu[s].partner_num == 0)//������������0
		{
			msg << "\t����Чƥ����" << endl;
			stu[s].c_de_point2 -= 5 * 20;
			continue;
		}
		if (stu[s].partner_num < 5)//�����������С��5��
		{
			stu[s].c_de_point2 -= (5 - stu[s].partner_num) * 20;
		}

		msg << endl;
		/*��黥��С��ÿ�����Ƿ���������*/
		for (int p = 0; p <= stu[s].partner_num - 1; p++)//����С���Ա
		{
			msg << "\t$" << p + 1 << "\t" << stu[s].check_group[p].no << "\t" << stu[s].check_group[p].name << "\t";
			int i;
			bool find = 0;
			for (i = 0; i <= stu_num - 1; i++)//stu�����������С���Ա
			{
				if (stu[i].no == stu[s].check_group[p].no)
					break;
			}
			//iָ��stu������С���Ա���ڵ��±�
			if (stu[i].partner_num == 0)//����Է�û�л����Ա
			{
				msg << "��������" << endl;
				stu[s].c_de_point1 -= 100;//�൱��δ������д��������
				continue;
			}
			
			for (int j = 0; j <= stu[i].partner_num - 1; j++)
			{
				if (stu[i].check_group[j].no == stu[s].no)//����Է���check_group�����Լ���ѧ��
				{
					find = 1;//�ҵ�
					break;
				}
			}
			if (find == 1)//�Է������ǻ����ϵ
			{
				msg << "ok" << endl;
				if (stu[i].g_ok == 0)//����Է���b2����ȷ
					stu[s].c_de_point2 -= 20;
			}
			else//�Է�check_group��û����
			{
				msg << "��������" << endl;
				stu[s].c_de_point1 -= 100;//�൱��δ������д��������
			}
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������յ÷�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void print_finalscore(student stu[], int stu_num, ostringstream& msg)
{
	msg << "���\t�κ�\tѧ��\t����\tԭʼ����÷�\t������ԭʼ��\t������۷�1\t������۷�2\t�������ܷ�" << endl;
	for (int s = 0; s <= stu_num - 1; s++)
	{
		msg << s + 1 << "#\t" << stu[s].class_no << "\t" << stu[s].no << "\t" << stu[s].name << "\t" << 100 * stu[s].g_ok
			<< "\t" << 100 * stu[s].c_ok << "\t" << stu[s].c_de_point1 << "\t" << stu[s].c_de_point2
			<< "\t" << 100 * stu[s].c_ok + stu[s].c_de_point1 + stu[s].c_de_point2 << endl;
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ��������5��cout֮�⣬�������κε�cout��� 
***************************************************************************/
static int second_line_check(char *argv[], char debug[5], student stu[]) //��������Լ����������һ����debug[5] 
{
	ostringstream msg;
	int stu_num;

    /* �������������䣬��������cout */ 
	char filename[50];
	strcpy(filename, "./source/");
	strcat(filename, argv[3]);
	strcat(filename, ".dat");
	/* ���κ�.dat */
	msg << "1.��ȡ�κ������ļ�" << endl;
	int read_result = read_stulist(filename, msg, stu, stu_num); //���������ֵ��Ҳ���Բ�Ҫ������������Լ����������һ����msg 
	if (read_result == FAIL_OPEN)
	{
		msg << "\t--> �޷���" << filename << endl;
	}
	/* ��������������(Ҳ���Բ�Ҫ)����������cout */ 
	if (debug[0] == '1')
	{
		if (debug[1] == '1' || debug[2] == '1' || debug[3] == '1' || debug[4] == '1')
			msg << endl;
		cout << msg.str() << endl;
	}

    /* �������������䣬��������cout */ 

	msg.str(""); //���msg�е���Ϣ
	msg << "2.���κ�+ѧ�������ѧ������" << endl;
	print_stulist(stu, stu_num, msg); //���������ֵ��Ҳ���Բ�Ҫ������������Լ����������һ����msg 
    /* ��������������(Ҳ���Բ�Ҫ)����������cout */ 
	if (debug[1] == '1')
	{
		if (debug[2] == '1' || debug[3] == '1' || debug[4] == '1')
			msg << endl;
		cout << msg.str() << endl;
	}

    /* �������������䣬��������cout */ 

	msg.str(""); //���msg�е���Ϣ
	msg << "3.����ѧ����ȡ��2�еĽ�����Ϣ" << endl;
	read_2nd_line(argv[5], stu, stu_num, msg); //���������ֵ��Ҳ���Բ�Ҫ������������Լ����������һ����msg 
    /* ��������������(Ҳ���Բ�Ҫ)����������cout */ 
	if (debug[2] == '1')
	{
		if (debug[3] == '1' || debug[4] == '1')
			msg << endl;
		cout << msg.str();
	}

    /* �������������䣬��������cout */ 

	/* ��˫��������Ϣƥ�� */
	msg.str(""); //���msg�е���Ϣ
	msg << "4.����ѧ���ĵ�2�л���ƥ����" << endl;
	print_2nd_line(stu, stu_num, msg); //���������ֵ��Ҳ���Բ�Ҫ������������Լ����������һ����msg 
    /* ��������������(Ҳ���Բ�Ҫ)����������cout */ 
	if (debug[3] == '1')
	{
		if (debug[4] == '1')
			msg << endl;
		cout << msg.str();
	}

    /* �������������䣬��������cout */ 

	/* �ٸ���ͨ�������м�� */
	msg.str(""); //���msg�е���Ϣ
	msg << "5.����ѧ���ĵ�2�л������յ÷�" << endl;
	print_finalscore(stu, stu_num, msg); //���������ֵ��Ҳ���Բ�Ҫ������������Լ����������һ����msg 
    /* ��������������(Ҳ���Բ�Ҫ)����������cout */ 
	if (debug[4] == '1')
	{
		cout << msg.str();
	}

    /* �������������䣬��������cout */ 

	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ostringstream��ʾ�� 
  ���������
  �� �� ֵ��
  ˵    ����
 ***************************************************************************/
static void usage(const char* const procname)
{
	ostringstream msg;
	const int wopt = 7 + strlen(procname) + 4;
	cout << endl;

	msg << "Usage: " << procname << " [ --secondline | --courseid cid | --filename name/all ] | --debug xxxxx" << endl;
	msg << setw(wopt) << ' ' << "--secondline   : ���м��" << endl;
	msg << setw(wopt) << ' ' << "--courseid     : �κ�" << endl;
	msg << setw(wopt) << ' ' << "--filename     : �ļ���(��֧��all)" << endl;
	msg << setw(wopt) << ' ' << "--debug xxxxx  : ��5λ0/1�����������α�ʾ��Ҫ��ӡ[���κ��ļ� | ѧ������ | ��2�н��� | ����ƥ�� | ���ս��]����Ϣ��Ĭ��00000" << endl;
	msg << endl;

	msg << "e.g.   " << procname << " --secondline --courseid 100692 --filename 5-b14.c --debug 11111 : ���100692�γ̵�5-b14.c�ĵڶ���(��ӡ������Ϣ)" << endl;
	msg << "       " << procname << " --secondline --courseid 100692 --filename 5-b14.c --debug 00100 : ���100692�γ̵�5-b14.c�ĵڶ���(��ӡ������Ϣ)" << endl;
	msg << endl;
	cout << msg.str() << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��main����������������Ҳ����һ��cout
            2����1�����ƣ��������Ҫ������ʹ�� goto END;(�����������������) 
***************************************************************************/
int main(int argc, char** argv)
{
	ostringstream msg;

	char debug[5] = { '0','0','0','0','0' };
	student stu[1000];
	/* ���в����ķ���������д��main�У�Ҳ����д�Զ��庯��(��msg������ȥ�������в�����cout)���������Ҫ������goto  */ 
	
	if (argc == 1)
	{
		usage(argv[0]);
		msg << "����ָ������[--secondline]" << endl;
		goto END;
	}
	if (argc >= 2)
	{
		if (strcmp(argv[1], "--secondline") != 0)
		{
			msg << "����[" << argv[1] << "]�Ƿ�." << endl;
			goto END;
		}
		if (argc == 2)
		{
			usage(argv[0]);
			msg << "����ָ������[--courseid]" << endl;
			goto END;
		}
	}
		
	if (argc >= 3)
	{
		if (strcmp(argv[2], "--courseid") != 0)
		{
			msg << "����[" << argv[2] << "]�Ƿ�." << endl;
			goto END;
		}
		if (argc == 3)
		{
			msg << "����[--courseid]�ĸ��Ӳ�������(����:string)" << endl;
			goto END;
		}
	}
	if (argc == 4)
	{
		if (argv[3][0] == '-')
		{
			msg << "����[--courseid]ȱ�ٸ��Ӳ���. (����:string)" << endl;
			goto END;
		}
		usage(argv[0]);
		msg << "����ָ������[--filename]" << endl;
		goto END;
	}
	if (argc >= 5)
	{
		if (strcmp(argv[4], "--filename") != 0)
		{
			msg << "����[" << argv[4] << "]�Ƿ�." << endl;
			goto END;
		}
		if (argc == 5)
		{
			msg << "����[--filename]�ĸ��Ӳ������� (����:string)" << endl;
			goto END;
		}
	}

	if (argc >= 6)
	{
		if (argv[5][0] == '-')
		{
			msg << "����[--filename]ȱ�ٸ��Ӳ���. (����:string)" << endl;
			goto END;
		}
	}
		
	if (argc >= 7)
	{
		if (strcmp(argv[6], "--debug") != 0)
		{
			msg << "����[" << argv[6] << "]�Ƿ�." << endl;
			goto END;
		}
		if (argc == 7)
		{
			msg << "����[" << argv[6] << "]ȱ�ٸ��Ӳ���. (����:string)" << endl;
			goto END;
		}
	}
	if (argc >= 8)
	{
		if (strlen(argv[7]) != 5)
		{
			usage(argv[0]);
			msg << "����[--debug]����Ϊ5λ0/1" << endl;
			goto END;
		}

		for (int n = 0; n <= 4; n++)
		{
			if (argv[7][n] != '0' && argv[7][n] != '1')
			{
				usage(argv[0]);
				msg << "����[--debug]�ĵ�[" << n + 1 << "]λ����0/1" << endl;
				goto END;
			}
			else
				debug[n] = argv[7][n];
		}
	}
	

	/* �������������ȷ������ô˺������м��(���������������) */ 
	second_line_check(argv, debug, stu);

    /* �������������䣬��������cout���������Ҫ������goto */ 

END:
    cout << msg.str() << endl;

	return 0;
}

