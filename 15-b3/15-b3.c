/*2050598 杨洁宁 通信*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define CONVERT_I_O  1
#define CONVERT_O_I  2

int usage(const char ch[])
{
	printf("%s%s", ch, " --infile hex格式文件 --outfile bin格式文件\n");
	printf("%s%s", ch, " --infile a.hex --outfile a.bin\n");
	return 0;
}

int Choice(char* ch[], const int arg)
{
	if (arg == 5 && strcmp(ch[1], "--infile") == 0 && strcmp(ch[3], "--outfile") == 0)
		return CONVERT_I_O;
	else if (arg == 5 && strcmp(ch[1], "--outfile") == 0 && strcmp(ch[3], "--infile") == 0)
		return CONVERT_O_I;
	return 0;
}

int main(int argc, char* argv[])
{
	int choice = Choice(argv, argc);

	FILE* fin, * fout;

	if (choice == CONVERT_I_O)
	{
		fin = fopen(argv[2], "rb");
		if (fin == NULL)
		{
			printf("打开文件失败\n");
			return 0;
		}
		fout = fopen(argv[4], "wb");
		if (fout == NULL)
		{
			printf("打开文件失败\n");
			fclose(fin);
			return 0;
		}
	}
	else if (choice == CONVERT_O_I)
	{
		fin = fopen(argv[4], "rb");
		if (fin == NULL)
		{
			printf("打开文件失败\n");
			return 0;
		}
		fout = fopen(argv[2], "wb");
		if (fout == NULL)
		{
			printf("打开文件失败\n");
			fclose(fin);
			return 0;
		}
	}
	else
	{
		usage(argv[0]);
		return 0;
	}

	int content;
	int rubbishi;
	char rubbishc;
	int line = -1;
	int pos = 0;
	long old_p, p;

	while (1)
	{
		if (feof(fin))
			break;

		if (pos % 34 == 0)
		{
			fscanf(fin, "%x", &rubbishi);
			line++;
		}
		else if ((pos >= 1 + line * 34 && pos <= 8 + line * 34) || (pos >= 10 + line * 34 && pos <= 17 + line * 34))
		{
			if (pos == 1 + line * 34)
			{
				if (fscanf(fin, "%x", &content) == 1)
				{
					fprintf(fout, "%c", (char)(content));
					old_p = ftell(fin);
				}
				else
				{
					break;
				}
			}
			else
			{				
				
				if (fscanf(fin, "%x", &content) == 1)
				{
					p = ftell(fin);
					if (p - old_p <= 4)
						fprintf(fout, "%c", (char)(content));
					old_p = p;
				}
				else
				{
					break;
				}
			}
		}
		else if (pos == 9 + line * 34)
		{
			fscanf(fin, "%c", &rubbishc);
			fscanf(fin, "%c", &rubbishc);
			old_p = ftell(fin);
		}
		else if (pos == 18 + line * 34)
		{
			for (int n = 1; n <= 6; n++)
				fscanf(fin, "%c", &rubbishc);
		}
		else
			fscanf(fin, "%c", &rubbishc);
		pos++;
	}
	fclose(fin);
	fclose(fout);
	
	return 0;
}