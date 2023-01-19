/* 2050598 通信 杨洁宁 */
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

	//以读方式打开文件
	infile = fopen("list.txt", "r");
	if (infile == NULL)
	{
		printf("打开文件失败\n");
		return -1;
	}

	head = (struct student*)malloc(sizeof(struct student));//生成头结点
	if (head == NULL)
	{
		printf("申请空间失败\n");
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
			printf("申请空间失败\n");
			return -1;
		}
		new->no = no_;
		new->score = score_;
		strcpy(new->name, name_);//赋值完毕

		ps->next = new;
		ps = new;//ps始终指向最后一个

	}
	ps->next = NULL;//链表结束的标志

	//开始输出
	ps = head->next;//ps指向头结点的下一个节点，因为头结点没有值
	while (ps != NULL)
	{
		printf("%d %s %d\n", ps->no, ps->name, ps->score);
		ps = ps->next;
	}

	//开始释放
	while (head != NULL)
	{
		ps = head;
		head = head->next;
		free(ps);
	}

	fclose(infile);//关闭文件

	return 0;
}