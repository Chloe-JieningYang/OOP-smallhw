/* 2050598 杨洁宁 通信 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct student {
	int no;
	char name[9];
	int score;
	struct student* next;
};

int main()
{
	ifstream infile;
	infile.open("list.txt", ios::in);//打开文件
	if (infile.is_open() == 0)
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	student* head, * ps, * newp;

	head = new(nothrow) student;
	if (head == NULL)//判断
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
		if (newp == NULL)//判断
			return -1;

		newp->no = no_;
		newp->score = score_;
		strcpy(newp->name, name_);
		
		ps->next = newp;
		ps = newp;//ps始终指向最后
	}
	ps->next = NULL;

	//开始输出
	ps = head->next;
	while (ps != NULL)
	{
		cout << ps->no << " " << ps->name << " " << ps->score << endl;
		ps = ps->next;
	}

	//开始释放
	while (head != NULL)
	{
		ps = head;
		head = head->next;
		delete ps;
	}

	infile.close();//关闭文件

	return 0;
}