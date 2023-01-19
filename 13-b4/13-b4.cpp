/* 2050598 杨洁宁 通信 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

struct student {
	int no;
	char name[12];
	char school[10];
};

int main()
{
	srand((unsigned)time(NULL));
	int M, N;
	student* ps;

	ifstream infile;
	infile.open("stulist.txt", ios::in);//打开文件
	if (infile.is_open() == 0)
	{
		cout << "打开文件失败" << endl;
		return -1;
	}

	ofstream outfile;
	outfile.open("result.txt", ios::out);
	if (outfile.is_open() == 0)
	{
		cout << "打开输出文件失败" << endl;
		infile.close();//关闭输入文件
		return -1;
	}

	infile >> N >> M;

	ps = new(nothrow)student[M];
	if (ps == NULL)
		return -1;
	
	for (int i = 0; i < M; i++)
		infile >> (ps + i)->no >> (ps + i)->name >> (ps + i)->school;

	for (int i = 0; i < M; i++)
	{
		int j = rand() % M;//随机取0-M-1中一个数
		student temp;
		temp = *(ps + i);
		*(ps + i) = *(ps + j);
		*(ps + j) = temp;//交换
	}//实现将学生排序打乱，这种方法可以避免抽取重复
	
	
	for (int i = 0; i < N; i++)//输出乱序的前N个
		outfile << (ps + i)->no << " " << (ps + i)->name << " " << (ps + i)->school << endl;

	delete[]ps;

	infile.close();//关闭文件
	outfile.close();
	
	return 0;
}

//申请连续空间当数组用，访问更为便利，方便实现任意两个位置的交换达到乱序的目的