/*2050598 杨洁宁 通信*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

#define   CHECK_NOT_NUMBER      1//检查学生的学号错误
#define   CHECK_NOT_SEVEN       2//检查学生的学号错误
#define   MATCH_NOT_NUMBER      3//匹配学生的学号错误
#define   MATCH_NOT_SEVEN       4//匹配学生的学号错误
#define   MATCH_NOT_DOUBLE_ALL  5//匹配学生的学号错误
#define   NUM_CORRECT           6//学号检查正确

#define   FILENAME_EXCESS       7//文件名超过32字节
#define   FILENAME_CORRECT      8//文件名检查正确

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int usage(const char* const procname)
{
	cout << "Usage: " << procname << " 要检查的学号/all 匹配学号/all 源程序名/all 相似度阀值(60-100) 输出(filename/screen)" << endl << endl;
	cout << "e.g. : " << procname << " 2159999 2159998 all       80 screen" << endl;
	cout << "       " << procname << " 2159999 all     14-b1.cpp 75 result.txt" << endl;
	cout << "       " << procname << " all     all     14-b2.cpp 80 check.dat" << endl;
	cout << "       " << procname << " all     all     all       85 screen" << endl;

	return 0;
}

/***************************************************************************
  函数名称：
  功    能：检查学号错误
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CheckNum(char* check, char* match)
{
	int i;
	if (strcmp(check, "all") == 0)//如果是all对all
	{
		if (strcmp(match, "all"))//如果match不是all
			return MATCH_NOT_DOUBLE_ALL;
		else
			return NUM_CORRECT;//all to all
	}
	else
	{
		if (strlen(check) != 7)//检查被检查学生学号是否为7位
			return CHECK_NOT_SEVEN;
		for (i = 0; check[i] != '\0'; i++)//检查被检查学生学号是否全为数字
		{
			if (check[i] < '0' || check[i]>'9')
				return CHECK_NOT_NUMBER;
		}
		if (strcmp(match, "all") == 0)//如果是某个学生和all比较
			return NUM_CORRECT;
		if (strlen(match) != 7)//检查被检查学生学号是否为7位
			return MATCH_NOT_SEVEN;
		for (i = 0; match[i] != '\0'; i++)//检查被检查学生学号是否全为数字
		{
			if (match[i] < '0' || match[i]>'9')
				return MATCH_NOT_NUMBER;
		}
		return NUM_CORRECT;
	}
}

/***************************************************************************
  函数名称：
  功    能：检查文件名错误
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CheckFileName(char* filename)
{
	if (strlen(filename) + 1 > 32)
		return FILENAME_EXCESS;
	if (strcmp(filename, "all") == 0)
		return FILENAME_CORRECT;
	cout << strlen(filename) + 1 << endl;
	return FILENAME_CORRECT;
}

/***************************************************************************
  函数名称：
  功    能：检查相似度
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int CheckSimilarity(char* s)
{
	int similar = atoi(s);
	if (similar < 60 || similar>100)
		similar = 80;
	return similar;
}


int main(int argc,char *argv[])
{
	if (argc < 6)
	{
		usage(argv[0]);
		return 0;
	}
	/*检查学号*/
	int check_num = CheckNum(argv[1], argv[2]);
	if (check_num == CHECK_NOT_NUMBER)
	{
		cout << "要检查的学号不是7位数字" << endl;
		return 0;
	}
	else if (check_num == CHECK_NOT_SEVEN)
	{
		cout << "要检查的学号不是7位" << endl;
		return 0;
	}
	else if (check_num == MATCH_NOT_NUMBER)
	{
		cout << "要匹配的学号不是7位数字" << endl;
		return 0;
	}
	else if (check_num == MATCH_NOT_SEVEN)
	{
		cout << "要匹配的学号不是7位" << endl;
		return 0;
	}
	else if (check_num == MATCH_NOT_DOUBLE_ALL)
	{
		cout << "检查学号是all，匹配学号必须是all" << endl;
		return 0;
	}
	/*检查源程序文件名*/
	int check_filename_in = CheckFileName(argv[3]);
	if (check_filename_in == FILENAME_EXCESS)
	{
		cout << "源程序文件名超过了32字节" << endl;
		return 0;
	}
	/*检查相似度*/
	int similarity = CheckSimilarity(argv[4]);
	/*检查输出文件名*/
	int check_filename_out= CheckFileName(argv[5]);
	if (check_filename_out == FILENAME_EXCESS)
	{
		cout << "输出结果文件名超过了32字节" << endl;
		return 0;
	}

	cout << "检查参数通过" << endl;
	cout << "检查学号：" << argv[1] << endl;
	cout << "匹配学号：" << argv[2] << endl;
	cout << "源文件名：" << argv[3] << endl;
	cout << "匹配预制：" << similarity << endl;
	cout << "输出目标：" << argv[5] << endl;
	return 0;
}