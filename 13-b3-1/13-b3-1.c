/* 2050598 ͨ�� ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	int *no;
	char *name;
	int *score;
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

	
	while (1)
	{
		int no_, score_;
		char name_[9] = { '\0' };
		fscanf(infile, "%d %s %d", &no_, name_, &score_);
		if (no_ == 9999999)
			break;
		
		new = (struct student*)malloc(sizeof(struct student));
		if (new == NULL)
		{
			printf("����ռ�ʧ��\n");
			return -1;
		}

		new->no = (int*)malloc(sizeof(int));
		if (new->no == NULL)
			return -1;

		new->score = (int*)malloc(sizeof(int));
		if (new->score == NULL)
			return -1;

		new->name = (char*)malloc((strlen(name_) + 1) * sizeof(char));
		if (new->name == NULL)
			return -1;

		*(new->no) = no_;
		*(new->score) = score_;
		strcpy(new->name, name_);//��ֵ����

		ps->next = new;
		ps = new;
	}
	ps->next = NULL;//������־

	//��ʼ���
	ps = head->next;//psָ��ͷ������һ���ڵ㣬��Ϊͷ���û��ֵ
	while (ps != NULL)
	{
		printf("%d %s %d\n", *(ps->no), ps->name, *(ps->score));
		ps = ps->next;
	}

	//��ʼ�ͷ�
	ps = head;
	head = head->next;
	free(ps);//ͷָ�������ͷţ���Ϊֻ��nextû������
	while (head != NULL)
	{
		ps = head;
		head = head->next;
		free(ps->name);
		free(ps->no);
		free(ps->score);
		free(ps);
	}
	
	fclose(infile);//�ر��ļ�

	return 0;
}