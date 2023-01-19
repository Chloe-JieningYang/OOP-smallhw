/* 2050598 ͨ�� ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct student {
		int no;
		char name[9];
		int score;
		int rank;
	};



int main()
{
	
	FILE* infile;
	int sum;
	struct student* ps;

	//�Զ���ʽ���ļ�
	infile = fopen("student.txt", "r");
	if (infile == NULL)
	{
		printf("���ļ�ʧ��\n");
		return -1;
	}

	fscanf(infile, "%d", &sum);//����ѧ������

	ps = (struct student*)malloc(sum * sizeof(struct student));//�����ڴ�
	if (ps == NULL)
	{
		printf("����ռ�ʧ��\n");
		return -1;
	}

	for (int i = 0; i <= sum - 1; i++)
	{
		fscanf(infile, "%d %s %d", &((ps + i)->no), (ps + i)->name, &((ps + i)->score));
	}

	fclose(infile);//�ر��ļ�

	//���ɼ�����
	for (int i = 0; i < sum - 1; i++)
	{
		for (int j = i + 1; j < sum; j++)
		{
			if ((ps + i)->score < (ps + j)->score)
			{
				struct student S;
				S = *(ps + j);
				*(ps + j) = *(ps + i);
				*(ps + i) = S;
			}
		}
	}//�Ӹߵ��Ͱ��ɼ��������

	for (int i = 0; i < sum; i++)
	{
		if (i > 0 && (ps + i)->score == (ps + i - 1)->score)
			(ps + i)->rank = (ps + i - 1)->rank;
		else
			(ps + i)->rank = i + 1;
	}//����������

	//��ѧ�Ŵ�С��������
	for (int i = 0; i < sum - 1; i++)
	{
		for (int j = i + 1; j < sum; j++)
		{
			if ((ps + i)->no > (ps + j)->no)
			{
				struct student S;
				S = *(ps + j);
				*(ps + j) = *(ps + i);
				*(ps + i) = S;
			}
		}
	}//��ѧ�Ŵ�С�����������

	for (int i = 0; i < sum; i++)
		printf("%d %s %d %d\n", (ps + i)->no, (ps + i)->name, (ps + i)->score, (ps + i)->rank);

	free(ps);

	return 0;
}


