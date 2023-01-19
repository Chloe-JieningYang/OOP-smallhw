/* 2050598 ����� ͨ�� */
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
	infile.open("student.txt", ios::in);//���ļ�
	if (infile.is_open() == 0)
	{
		cout << "���ļ�ʧ��" << endl;
		return -1;
	}

	int sum;
	infile >> sum;//��ȡѧ������

	struct student* ps;
	ps = new(nothrow) student[sum];
	if (ps == NULL)
	{
		cout << "����ռ�ʧ��" << endl;
		return -1;
	}

	for (int i = 0; i < sum; i++)
		infile >> (ps + i)->no >> (ps + i)->name >> (ps + i)->score;//��������

	infile.close();//�ر��ļ�

	//��ѧ������
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
	}//��ѧ���������

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
	}//���ɼ��������

	for (int i = 0; i < sum; i++)
	{
		if (i > 0 && (ps + i)->score == (ps + i - 1)->score)
			(ps + i)->rank = (ps + i - 1)->rank;
		else
			(ps + i)->rank = i + 1;
	}//����������

	for (int i = 0; i <= sum - 1; i++)
	{
		cout << (ps + i)->no << " " << (ps + i)->name << " " << (ps + i)->score << " " << (ps + i)->rank << endl;
	}

	delete[]ps;
	
	return 0;
}