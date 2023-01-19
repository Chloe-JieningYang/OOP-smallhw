/* 2050598 ͨ�� ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	int no;
	char name[9];
	int score;
	struct student* next;
};

int main()
{
	struct student* ps, * head, * new;
	FILE* infile;

	//�Զ���ʽ���ļ�
	infile = fopen("list.txt", "r");
	if (infile == NULL)
	{
		printf("���ļ�ʧ��\n");
		return -1;
	}

	head = (struct student*)malloc(sizeof(struct student));//����ͷ���
	if (head == NULL)
	{
		printf("����ռ�ʧ��\n");
		return -1;
	}
	ps = head;
	
	int no_, score_;
	char name_[9];
	while (fscanf(infile, "%d %s %d", &no_, name_, &score_) != EOF && no_ != 9999999)
	{
		new = (struct student*)malloc(sizeof(struct student));
		if (new == NULL)
		{
			printf("����ռ�ʧ��\n");
			return -1;
		}
		new->no = no_;
		new->score = score_;
		strcpy(new->name, name_);//��ֵ���

		ps->next = new;
		ps = new;//psʼ��ָ�����һ��

	}
	ps->next = NULL;//��������ı�־

	//��ʼ���
	ps = head->next;//psָ��ͷ������һ���ڵ㣬��Ϊͷ���û��ֵ
	while (ps != NULL)
	{
		printf("%d %s %d\n", ps->no, ps->name, ps->score);
		ps = ps->next;
	}

	//��ʼ�ͷ�
	while (head != NULL)
	{
		ps = head;
		head = head->next;
		free(ps);
	}

	fclose(infile);//�ر��ļ�

	return 0;
}