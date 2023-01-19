/*2050598 杨洁宁 通信*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define   CHECK  1
#define   WTOL   2
#define   LTOW   3
#define   ERROR  -1

#define   TYPE_W    4
#define   TYPE_L    5
#define   TYPE_IDK  6//i don't know的类型

int usage(const char ch[])
{
	cout << "Usage : " << ch << " --check 文件名 | --convert { wtol|ltow } 源文件名 目标文件名" << endl;
	cout << "        " << ch << " --check a.txt" << endl;
	cout << "        " << ch << " --convert wtol a.win.txt a.linux.txt" << endl;
	cout << "        " << ch << " --convert ltow a.linux.txt a.win.txt" << endl;
	return 0;
}

int Choice(char *ch[],int argc)
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
void ConvertWtoL(int content[], const int num, int& new_num)
{
	new_num = num;
	for (int i = 0; i <= num - 1; i++)
	{
		if (content[i] == 0x0A && content[i - 1] == 0x0D)
		{
			for (int j = i - 1; j <= num - 2; j++)
			{
				content[j] = content[j + 1];
			}
			new_num--;
		}
	}
	cout << "转换完成，去除" << num - new_num << "个0x0D" << endl;
}

int main(int argc, char* argv[])
{
	int choice = Choice(argv, argc);

	if (choice == CHECK)
	{
		ifstream in(argv[2], ios::in | ios::binary);
		if (in.is_open() == 0)
		{
			cout << "文件打开失败" << endl;
			return ERROR;
		}
		int content[10000];
		int num = 0;
		while (!in.eof())//结尾会读入-1
		{
			content[num] = in.get();
			num++;
		}
		int check = Check(content, num);
		if (check == TYPE_W)
			cout << "Windows格式" << endl;
		else if (check == TYPE_L)
			cout << "Linux格式" << endl;
		else if (check == TYPE_IDK)
			cout << "文件格式无法识别" << endl;
		in.close();
	}
	else if (choice == WTOL)
	{
		ifstream in(argv[3], ios::in | ios::binary);
		if (in.is_open() == 0)
		{
			cout << "文件打开失败" << endl;
			return ERROR;
		}
		int content[10000];
		int num = 0;
		while (!in.eof())//结尾会读入-1
		{
			content[num] = in.get();
			num++;
		}
		int check = Check(content, num);
		if (check != TYPE_W)
		{
			cout << "文件格式无法识别" << endl;
			in.close();
			return ERROR;
		}
		int new_num;
		ConvertWtoL(content, num, new_num);

		ofstream out(argv[4], ios::out | ios::binary);
		if (!out.is_open())
		{
			cout << "文件打开失败" << endl;
			in.close();
			return ERROR;
		}
		for (int i = 0; i <= new_num - 2; i++)
			out.put(char(content[i]));

		in.close();
		out.close();
	}
	else if (choice == LTOW)
	{
		ifstream in(argv[3], ios::in | ios::binary);
		if (in.is_open() == 0)
		{
			cout << "文件打开失败" << endl;
			return ERROR;
		}
		int content[10000];
		int num = 0;
		while (!in.eof())//结尾会读入-1
		{
			content[num] = in.get();
			num++;
		}
		int check = Check(content, num);
		if (check != TYPE_L)
		{
			cout << "文件格式无法识别" << endl;
			in.close();
			return ERROR;
		}

		ofstream out(argv[4], ios::out);
		if (!out.is_open())
		{
			cout << "文件打开失败" << endl;
			in.close();
			return ERROR;
		}
		int count = 0;
		for (int i = 0; i <= num - 2; i++)
		{
			if (content[i] == 0x0A)
			{
				count++;
#ifdef __linux__
				out.put(char(0x0D));
#endif
			}
			out.put(char(content[i]));
		}
		cout << "转换完成，加入" << count << "个0x0D" << endl;
		in.close();
		out.close();
	}
	else
		usage(argv[0]);
	
	return 0;
}