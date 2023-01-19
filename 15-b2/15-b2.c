/*2050598 杨洁宁 通信*/
//2051454 王逸菲 2152808 魏予涵 2051553 张天一
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

#define OUTPUT       1
#define CONVERT_I_O  2
#define CONVERT_O_I  3

int usage(const char ch[])
{
	printf("%s%s", ch, " --infile 原始文件 [ --outfile hex格式文件 ]\n");
	printf("%s%s", ch, " --infile a.docx\n");
	printf("%s%s", ch, " --infile a.docx --outfile a.hex\n");
	return 0;
}

int Choice(char* ch[],const int arg)
{
	if (arg < 3)
		return 0;
	if (arg == 3 && strcmp(ch[1], "--infile") == 0)
		return OUTPUT;
	if (arg == 5 && strcmp(ch[1], "--infile") == 0 && strcmp(ch[3], "--outfile") == 0)
		return CONVERT_I_O;
	if (arg == 5 && strcmp(ch[1], "--outfile") == 0 && strcmp(ch[3], "--infile") == 0)
		return CONVERT_O_I;
	return 0;
}


int main(int argc, char* argv[])
{
	int choice = Choice(argv, argc);
	FILE* fin;
	if (choice == 0)
	{
		usage(argv[0]);
		return 0;
	}
	fin = fopen(argv[2], "rb");
	if (fin == NULL)
	{
		printf("文件打开失败\n");
		return 0;
	}
	
	if (choice == OUTPUT)
	{
		int hang = 0;
		while (!feof(fin))//最后会读入-1
		{
			int count = 0;
			int content[16];
			for (int i = 0; i <= 15; i++)
			{
				if (!feof(fin))
				{
					content[i] = fgetc(fin);
					if (content[i] != EOF)
						count++;
				}
				else
					break;
			}
			printf("%07x0  ", hang);
			int j;
			for (j = 0; j <= count - 1; j++)
			{
				printf("%02x ", content[j]);
				if (j == 7)
					printf("- ");
			}
			if (!feof(fin))
				printf("    ");
			else if (j >= 8)
			{
				for (int n = 1; n <= 4 + (16 - j) * 3; n++)
					printf(" ");
			}
			else
			{
				for (int n = 1; n <= 6 + (16 - j) * 3; n++)
					printf(" ");
			}
			for (j = 0; j <= count - 1; j++)
			{
				if (content[j] >= 33 && content[j] <= 126)
					putchar((char)(content[j]));
				else
					putchar('.');
			}
			printf("\n");
			if (!feof(fin))
				hang++;
			else
				break;
		}	
		fclose(fin);
	}
	else if (choice != 0)
	{
		FILE* fout;
		if (choice == CONVERT_I_O)
		{
			fout = fopen(argv[4], "wb");
			if (fout == NULL)
			{
				printf("文件打开失败\n");
				fclose(fin);
				return 0;
			}
		}
		else if (choice == CONVERT_O_I)
		{
			fout = fopen(argv[2], "wb");
			if (fout == NULL)
			{
				printf("文件打开失败\n");
				fclose(fin);
				return 0;
			}
		}
		else
			return 0;

		int hang = 0;
		while (!feof(fin))//最后会读入-1
		{
			int count = 0;
			int content[16];
			for (int x = 0; x <= 15; x++)
				content[x] = 0;
			for (int i = 0; i <= 15; i++)
			{
				if (!feof(fin))
				{
					content[i] = fgetc(fin);
					if (content[i] != EOF)
						count++;
				}
				else
					break;
			}
			if (content[0] != EOF)
				fprintf(fout, "%07x0  ", hang);
			else
				break;
			int j;
			
			for (j = 0; j <= count - 1; j++)
			{
				fprintf(fout, "%02x ", content[j]);
				if (j == 7)
					fprintf(fout, "- ");
			}
			if (!feof(fin))
				fprintf(fout, "    ");
			else if (j >= 8)
			{
				for (int n = 1; n <= 4 + (16 - j) * 3; n++)
					fprintf(fout, " ");
			}
			else
			{
				for (int n = 1; n <= 6 + (16 - j) * 3; n++)
					fprintf(fout, " ");
			}
			for (j = 0; j <= count - 1; j++)
			{
				if (content[j] >= 33 && content[j] <= 126)
					fputc((char)(content[j]), fout);
				else
					fputc('.', fout);
			}
			if (!feof(fin))
				fprintf(fout, "\n");
			if (!feof(fin))
				hang++;
			else
				break;
		}


		fclose(fin);
		fclose(fout);
	}
	
	return 0;
}