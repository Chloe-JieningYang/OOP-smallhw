/*2050598 杨洁宁 通信*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

#define   CHECK  1
#define   WTOL   2
#define   LTOW   3
#define   ERROR  -1

#define   TYPE_W    4
#define   TYPE_L    5
#define   TYPE_IDK  6//i don't know的类型

int usage(const char ch[])
{
	printf("Usage : %s --check 文件名 | --convert { wtol|ltow } 源文件名 目标文件名\n", ch);
	printf("        %s --check a.txt", ch);
	printf("        %s --convert wtol a.win.txt a.linux.txt", ch);
	printf("        %s --convert ltow a.linux.txt a.win.txt", ch);
	return 0;
}

int Choice(char* ch[], int argc)
{
	if (argc < 2)
		return 0;
	if (!strcmp(ch[1], "--check"))
		return CHECK;
	else if ((!strcmp(ch[1], "--convert")) && (!strcmp(ch[2], "wtol")))
		return WTOL;
	else if ((!strcmp(ch[1], "--convert")) && (!strcmp(ch[2], "ltow")))
		return LTOW;
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：判断文件类型
  输入参数：内容的ascii码数组，数组个数
  返 回 值：TYPE_W TYPE_L TYPE_IDK
  说    明：
***************************************************************************/
int Check(const int content[], const int num)
{
	int type = TYPE_IDK;
	for (int i = 0; i <= num - 1; i++)
	{
		if (content[i] == 0x0A)
		{
			if (i == 0)
				type = TYPE_L;
			if (i > 0 && content[i - 1] == 0x0D)//如果0A前面有0D
			{
				if (type == TYPE_L)//如果type已经标记为linux
					return TYPE_IDK;
				type = TYPE_W;
			}
			else//0A前面没有0D
			{
				if (type == TYPE_W)
					return TYPE_IDK;
				type = TYPE_L;
			}
		}
	}
	return type;
}

/***************************************************************************
  函数名称：
  功    能：转换Windows格式文件到Linux格式（删除0A前的一个0D）
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void ConvertWtoL(int content[], const int num, int* new_nump)
{
	*new_nump = num;
	for (int i = 0; i <= num - 1; i++)
	{
		if (content[i] == 0x0A && content[i - 1] == 0x0D)
		{
			for (int j = i - 1; j <= num - 2; j++)
			{
				content[j] = content[j + 1];
			}
			(*new_nump)--;
		}
	}
	printf("转换完成，去除%d个0x0D\n", num - (*new_nump));
}

int main(int argc, char* argv[])
{
	int choice = Choice(argv, argc);

	if (choice == 0)
	{
		usage(argv[0]);
		return 0;
	}

	if (choice == CHECK)
	{
		FILE* fin;
		fin = fopen(argv[2], "rb");
		if (fin == NULL)
		{
			printf("打开文件失败\n");
			return ERROR;
		}
		int content[10000];
		int num = 0;
		while (!feof(fin))//最后会读入-1
		{
			content[num] = fgetc(fin);
			num++;
		}
		int check = Check(content, num);
		if (check == TYPE_W)
			printf("Windows格式\n");
		else if (check == TYPE_L)
			printf("Linux格式\n");
		else if (check == TYPE_IDK)
			printf("文件格式无法识别\n");
		fclose(fin);
	}
	else if (choice == WTOL)
	{
		FILE* fin, * fout;
		fin = fopen(argv[3], "rb");
		if (fin == NULL)
		{
			printf("文件打开失败\n");
			return ERROR;
		}
		int content[10000];
		int num = 0;
		while (!feof(fin))//结尾会读入-1
		{
			content[num] = fgetc(fin);
			num++;
		}
		int check = Check(content, num);
		if (check != TYPE_W)
		{
			printf("文件格式无法识别\n");
			fclose(fin);
			return ERROR;
		}
		int new_num;
		ConvertWtoL(content, num, &new_num);
		fout = fopen(argv[4], "wb");
		if (fout == NULL)
		{
			printf("打开文件失败\n");
			fclose(fin);
			return ERROR;
		}
		for (int i = 0; i <= new_num - 2; i++)
			fputc((char)(content[i]), fout);

		fclose(fin);
		fclose(fout);
	}
	else if (choice == LTOW)
	{
		FILE* fin, * fout;
		fin = fopen(argv[3], "rb");
		if (fin == NULL)
		{
			printf("文件打开失败\n");
			return ERROR;
		}
		int content[10000];
		int num = 0;
		while (!feof(fin))//结尾会读入-1
		{
			content[num] = fgetc(fin);
			num++;
		}
		int check = Check(content, num);
		if (check != TYPE_L)
		{
			printf("文件格式无法识别\n");
			fclose(fin);
			return ERROR;
		}
		fout = fopen(argv[4], "w");
		if (fout == NULL)
		{
			printf("打开文件失败\n");
			fclose(fin);
			return ERROR;
		}
		int count = 0;
		for (int i = 0; i <= num - 2; i++)
		{
			if (content[i] == 0x0A)
			{
				count++;
#ifdef __linux__
				fputc((char)(0x0D), fout);
#endif
			}
			fputc((char)(content[i]), fout);
		}
		printf("转换完成，加入%d个0x0D\n", count);

		fclose(fin);
		fclose(fout);
	}
	return 0;
}