/* 2050598 ����� ͨ�� */
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
	infile.open("stulist.txt", ios::in);//���ļ�
	if (infile.is_open() == 0)
	{
		cout << "���ļ�ʧ��" << endl;
		return -1;
	}

	ofstream outfile;
	outfile.open("result.txt", ios::out);
	if (outfile.is_open() == 0)
	{
		cout << "������ļ�ʧ��" << endl;
		infile.close();//�ر������ļ�
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
		int j = rand() % M;//���ȡ0-M-1��һ����
		student temp;
		temp = *(ps + i);
		*(ps + i) = *(ps + j);
		*(ps + j) = temp;//����
	}//ʵ�ֽ�ѧ��������ң����ַ������Ա����ȡ�ظ�
	
	
	for (int i = 0; i < N; i++)//��������ǰN��
		outfile << (ps + i)->no << " " << (ps + i)->name << " " << (ps + i)->school << endl;

	delete[]ps;

	infile.close();//�ر��ļ�
	outfile.close();
	
	return 0;
}

//���������ռ䵱�����ã����ʸ�Ϊ����������ʵ����������λ�õĽ����ﵽ�����Ŀ��