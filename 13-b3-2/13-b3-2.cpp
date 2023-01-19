/* 2050598 ����� ͨ�� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct student {
	int* no;
	char* name;
	int* score;
	struct student* next;
};

int main()
{
	ifstream infile;
	infile.open("list.txt", ios::in);//���ļ�
	if (infile.is_open() == 0)
	{
		cout << "���ļ�ʧ��" << endl;
		return -1;
	}
	student* head, * ps, * newp;

	head = new(nothrow) student;
	if (head == NULL)//�ж�
	{
		return -1;
	}
	ps = head;

	int no_, score_;
	char name_[9];
	while (1)
	{
		infile >> no_ >> name_ >> score_;
		if (no_ == 9999999)
			break;
		newp = new(nothrow)student;
		if (newp == NULL)//�ж�
			return -1;

		newp->no = new(nothrow)int;
		if (newp->no == NULL)
			return -1;

		newp->score = new(nothrow)int;
		if (newp->score == NULL)
			return -1;

		newp->name = new(nothrow)char[(strlen(name_) + 1) * sizeof(char)];
		if (newp->name == NULL)
			return -1;

		*newp->no = no_;
		*newp->score = score_;
		strcpy(newp->name, name_);

		ps->next = newp;
		ps = newp;
	}
	ps->next = NULL;

	//��ʼ���
	ps = head->next;
	while (ps != NULL)
	{
		cout << *ps->no << " " << ps->name << " " << *ps->score << endl;
		ps = ps->next;
	}

	//��ʼ�ͷ�
	ps = head;
	head = head->next;
	delete ps;
	while (head != NULL)
	{
		ps = head;
		head = head->next;
		delete ps->no;
		delete ps->score;
		delete []ps->name;
		delete ps;
	}

	infile.close();//�ر��ļ�

	return 0;
}

