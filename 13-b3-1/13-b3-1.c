/* 2050598 通信 杨洁宁 */
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
			printf("申请空间失败\n");
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
		strcpy(new->name, name_);//赋值结束

		ps->next = new;
		ps = new;
	}
	ps->next = NULL;//结束标志

	//开始输出
	ps = head->next;//ps指向头结点的下一个节点，因为头结点没有值
	while (ps != NULL)
	{
		printf("%d %s %d\n", *(ps->no), ps->name, *(ps->score));
		ps = ps->next;
	}

	//开始释放
	ps = head;
	head = head->next;
	free(ps);//头指针特殊释放，因为只有next没有内容
	while (head != NULL)
	{
		ps = head;
		head = head->next;
		free(ps->name);
		free(ps->no);
		free(ps->score);
		free(ps);
	}
	
	fclose(infile);//关闭文件

	return 0;
}