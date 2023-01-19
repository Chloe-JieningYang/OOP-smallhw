/* 2050598 通信 杨洁宁 */
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

	//以读方式打开文件
	infile = fopen("student.txt", "r");
	if (infile == NULL)
	{
		printf("打开文件失败\n");
		return -1;
	}

	fscanf(infile, "%d", &sum);//读入学生总数

	ps = (struct student*)malloc(sum * sizeof(struct student));//申请内存
	if (ps == NULL)
	{
		printf("申请空间失败\n");
		return -1;
	}

	for (int i = 0; i <= sum - 1; i++)
	{
		fscanf(infile, "%d %s %d", &((ps + i)->no), (ps + i)->name, &((ps + i)->score));
	}

	fclose(infile);//关闭文件

	//按成绩排序
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
	}//从高到低按成绩排序完成

	for (int i = 0; i < sum; i++)
	{
		if (i > 0 && (ps + i)->score == (ps + i - 1)->score)
			(ps + i)->rank = (ps + i - 1)->rank;
		else
			(ps + i)->rank = i + 1;
	}//排名填充完成

	//按学号从小到大排名
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
	}//按学号从小到大排名完成

	for (int i = 0; i < sum; i++)
		printf("%d %s %d %d\n", (ps + i)->no, (ps + i)->name, (ps + i)->score, (ps + i)->rank);

	free(ps);

	return 0;
}


