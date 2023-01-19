/* 2050598 杨洁宁 通信 */
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct student {
	int no;
	char name[9];
	int score;
	int rank;
};

int main()
{
	ifstream infile;
	infile.open("student.txt", ios::in);//打开文件
	if (infile.is_open() == 0)
	{
		cout << "打开文件失败" << endl;
		return -1;
	}

	int sum;
	infile >> sum;//获取学生总数

	struct student* ps;
	ps = new(nothrow) student[sum];
	if (ps == NULL)
	{
		cout << "申请空间失败" << endl;
		return -1;
	}

	for (int i = 0; i < sum; i++)
		infile >> (ps + i)->no >> (ps + i)->name >> (ps + i)->score;//读入数据

	infile.close();//关闭文件

	//按学号排序
	for (int i = 0; i < sum - 1; i++)
	{
		for (int j = i + 1; j <= sum - 1; j++)
		{
			if ((ps + i)->no > (ps + j)->no)
			{
				student S;
				S = *(ps + j);
				*(ps + j) = *(ps + i);
				*(ps + i) = S;
			}
		}
	}//按学号排序完成

	for (int i = 0; i < sum - 1; i++)
	{
		for (int j = i + 1; j <= sum - 1; j++)
		{
			if ((ps + i)->score < (ps + j)->score)
			{
				student S;
				S = *(ps + j);
				*(ps + j) = *(ps + i);
				*(ps + i) = S;
			}
		}
	}//按成绩排序完成

	for (int i = 0; i < sum; i++)
	{
		if (i > 0 && (ps + i)->score == (ps + i - 1)->score)
			(ps + i)->rank = (ps + i - 1)->rank;
		else
			(ps + i)->rank = i + 1;
	}//排名填充完成

	for (int i = 0; i <= sum - 1; i++)
	{
		cout << (ps + i)->no << " " << (ps + i)->name << " " << (ps + i)->score << " " << (ps + i)->rank << endl;
	}

	delete[]ps;
	
	return 0;
}