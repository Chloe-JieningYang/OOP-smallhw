/* 2050598 通信 杨洁宁 */ 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
//允许添加需要的系统头文件 
using namespace std;

#define FAIL_OPEN        -1

#define SINGLE_NOTE      1
#define MULTIPLE_NOTE    2
#define ERROR_NOTE       3//不是//开头或不是同一行/*

#define SPECIAL_TYPE     4//特判 指/**/类型

/* 1、允许自定义类型
   2、不允许定义全局变量（不含只读及宏定义） 
   3、允许自定义函数，但所有的自定义函数中（含second_line_check中的read_stulist等五个函数）不允许任何的cout出现 
   4、除main函数外，不允许使用goto语句 
*/

struct partner {
	int no;
	char name[40] = { '\0' };
};

struct student {
	int class_no;//课号
	int no;//学号
	char name[33] = { '\0' };//姓名
	int g_ok;//原始程序（b2)的正确性
	int c_ok;//检查程序(b3)正确性
	int c_de_point1 = 0;//检查程序扣分1
	int c_de_point2 = 0;//检查程序扣分2
	int partner_num = 0;//互查的人数
	partner check_group[20];//用来存放互验同学的信息
};

/***************************************************************************
  函数名称：
  功    能：读取课号.dat文件
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int read_stulist(char filename[], ostringstream& msg, student stu[], int& stu_num)
{
	ifstream fin;
	int line_count = 1;//行数
	int stu_count = 0;//读入学生数 也是当前stu数组下标数
	fin.open(filename, ios::in | ios::binary);
	if (!fin.is_open())
	{
		return FAIL_OPEN;
	}
	while (!fin.eof())
	{
		char class_no[10] = { '\0' };
		char stu_no[10] = { '\0' };
		char info[500] = { '\0' };
		fin.getline(info, 400, '\n');

		if (strlen(info) == 0)
			break;

		if (info[0] == '#')//如果是注释行
		{
			msg << "\t--> 学生名单[" << filename << "]中的第[" << line_count << "]行为注释行，忽略" << endl;
			line_count++;
			continue;
		}
	
		istringstream in(info);
		in >> class_no >> stu_no >> stu[stu_count].name >> stu[stu_count].g_ok >> stu[stu_count].c_ok;
		stu[stu_count].class_no = atoi(class_no);
		stu[stu_count].no = atoi(stu_no);
		if (stu[stu_count].g_ok != 0)
			stu[stu_count].g_ok = 1;
		if (stu[stu_count].c_ok != 0)
			stu[stu_count].c_ok = 1;

		bool re_stu = 0;//是否重复
		if (stu_count > 0)//检查重复
		{
			for (int n = 0; n <= stu_count - 1; n++)
			{
				if (stu[n].no == stu[stu_count].no)
				{
					re_stu = 1;
				}
			}
		}

		if (re_stu == 0)
		{
			line_count++;
			stu_count++;
		}
		else
		{
			msg << "\t--> 学生名单[" << filename << "]中的第[" << line_count << "]行学号[" << stu[stu_count].no << "]重复，忽略" << endl;
			line_count++;
		}
	}

	stu_num = stu_count;
	msg << "读取完成，共[" << line_count - 1 << "]行有内容，去重后学生总数[" << stu_count << "]个";

	fin.close();
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：排序打印
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_stulist(student stu[], int stu_num, ostringstream& msg)
{
	for (int i = 0; i <= stu_num - 2; i++)//先按照学号排序
	{
		for (int j = i + 1; j <= stu_num - 1; j++)
		{
			if (stu[i].no > stu[j].no)
			{
				student temp;
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}

	for (int i = 0; i < stu_num - 1; i++)//按照课号冒泡排序
	{
		for (int j = 0; j < stu_num - i - 1; j++)
		{
			if (stu[j].class_no > stu[j + 1].class_no)
			{
				student temp;
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
	msg << "序号\t课号\t学号\t姓名\t原始程序正确\t校验程序正确" << endl;
	for (int n = 0; n <= stu_num - 1; n++)
	{
		msg << n + 1 << "#\t" << stu[n].class_no << "\t" << stu[n].no << "\t" << stu[n].name << "\t" << stu[n].g_ok << "\t" << stu[n].c_ok;
		if (n != stu_num - 1)
			msg << endl;
	}

}

/***************************************************************************
  函数名称：
  功    能：判断是否是空行
  输入参数：
  返 回 值：是空行返回0 不是空行返回1
  说    明：
***************************************************************************/
bool JudgeCh(char ch[])
{
	if (strlen(ch) == 0)
		return 0;
	for (int i = 0; i <= (int)strlen(ch) - 1; i++)
	{
		if (ch[i] != '\r' && ch[i] != '\n' && ch[i] != ' ' && ch[i] != 0x09)
			return 1;
	}
	return 0;
}


/***************************************************************************
  函数名称：
  功    能：判断一行之中是否以//或 / *开头,如果以/ *开头又是否有对应结尾 以及判
			断开头与第一个字符串、删除最后一个字符串与结尾之间的空格/制表符和结尾
  输入参数：
  返 回 值：注释类型（一行or多行） 参数返回是否有空格或\t 1为有空格 0为无空格
  说    明：
***************************************************************************/
int Analyse2nd(char (& ch)[350], bool& begin_blank)
{
	int length = strlen(ch);
	int type;
	int p;
	for (p = 0; p <= length - 1; p++)
	{
		if (ch[p] != '\t' && ch[p] != ' ')
			break;
	}
	//p指向第一个不为空格或\t的字符
	if (ch[p] != '/')
		return ERROR_NOTE;

	if (length == p + 1)//如果长度不够
		return ERROR_NOTE;

	if (ch[p + 1] == '*')
	{
		type = MULTIPLE_NOTE;
		if (length == p + 2)
			return ERROR_NOTE;
		if (ch[p + 2] != ' ' && ch[p + 2] != '\t')//如果//后面紧跟的是有效字符
			begin_blank = 0;
		else
			begin_blank = 1;
	}
	else if (ch[p + 1] == '/')
	{
		type = SINGLE_NOTE;
		if (length == p + 2)
			return ERROR_NOTE;
		if (ch[p + 2] != ' ' && ch[p + 2] != '\t')//如果//后面紧跟的是有效字符
			begin_blank = 0;
		else
			begin_blank = 1;
		/*把换行符和空格去掉*/
		int sp = sizeof(ch) - 1;
		for (int i = 0; i <= (int)sizeof(ch) - 1; i++)
		{
			if (ch[i] == '\n' || ch[i] == '\r')
			{
				ch[i] = '\0';
				sp = i;
			}
		}
		/*把换行前的空格去掉*/
		int j = sp - 1;
		while (1)
		{
			if (ch[j] != '\r' && ch[j] != '\n' && ch[j] != '\t' && ch[j] != ' ')
				break;
			if (ch[j] == ' ' || ch[j] == '\t')
				ch[j] = '\0';
			j--;
		}
		return type;
	}
	else
		return ERROR_NOTE;

	p += 2;

	bool find = 0;
	bool all_blank = 1;//判断中间是否全是空格
	for (; p <= length - 2; p++)
	{
		if (ch[p] == '*' && ch[p + 1] == '/')
		{
			find = 1;
			break;
		}
		if (ch[p] != ' ' && ch[p] != '\t')
			all_blank = 0;//如果有别的字符就不是全是空格
	}
	if (find == 0)
		return ERROR_NOTE;
	if (all_blank == 1)//如果当中全是空格
		return SPECIAL_TYPE;
	
	int p2 = p - 1;
	//把*/包括后面的全变成\0
	int s = sizeof(ch);
	for (; p <= s - 1; p++)
		ch[p] = '\0';

	//把*/前面的空格全去掉
	while (1)
	{
		if (ch[p2] != ' ' && ch[p2] != '\t')
			break;
		ch[p2] = '\0';
		p2--;
	}
	return MULTIPLE_NOTE;
}

/***************************************************************************
  函数名称：
  功    能：读第二行
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int read_2nd_line(char filename[], student stu[], int stu_num, ostringstream& msg)
{	
	msg << "序号\t课号\t学号\t姓名\t文件名\t分析结果" << endl;

	for (int s = 0; s < stu_num; s++)//所有学生循环
	{
		ifstream fin;//写在里面，这样getline读入错误时不用重置状态
		char note[350] = { '\0' };//用来装一行的注释
		int fault = 0;//错误的个数（用来看错误输出是否要加\t）

		msg << s + 1 << "#\t" << stu[s].class_no << "\t" << stu[s].no << "\t" << stu[s].name << "\t" << filename << "\t";

		char fn[100] = { '\0' };//真正的filename
		sprintf(fn, "./source/%d-%s/%d-%s-%s", stu[s].class_no, filename, stu[s].no, stu[s].name, filename);
		fin.open(fn, ios::in | ios::binary);
		if (!fin.is_open())
		{
			msg << "未提交" << endl;
			stu[s].c_ok = 0;//检查程序原始分为0
			continue;
		}

		bool overfl = 0;
		while (1)//把前面的空行和第一行读完
		{
			char rubbish[300] = { '\0' };
			fin.getline(rubbish, 290, '\n');
			if (strlen(rubbish) >= 255)
			{
				msg << "非空行超过了合理长度[256]字节." << endl;
				overfl = 1;
				fin.close();
				break;
			}
			if (JudgeCh(rubbish) == 1)
				break;
		}
		if (overfl == 1)
			continue;

		overfl = 0;
		while (1)
		{
			for (int n = 0; n <= (int)sizeof(note) - 1; n++)
				note[n] = '\0';
			fin.getline(note, 340, '\n');//读入第二行
			if (!fin.good())
			{
				fin.clear();
			}
			if (strlen(note) >= 255)
			{
				msg << "非空行超过了合理长度[256]字节." << endl;
				fin.close();
				overfl = 1;
				break;
			}
			if (JudgeCh(note) == 1)
				break;
		}

		if (overfl == 1)
			continue;

		bool begin_blank;
		int analyse = Analyse2nd(note, begin_blank);


		if (analyse == ERROR_NOTE)
		{
			msg << "第2行信息有错[不是//或/*开头，或者以/*开头但*/不在同一行]" << endl;
			fin.close();
			continue;
		}

		if (analyse == SPECIAL_TYPE)
		{
			msg << "ok" << endl;
			fin.close();
			continue;
		}

		istringstream in(note);
		int count = 0;//互验学生的个数

		while (in.good())//按学生数读入
		{
			char no[260] = { '\0' };
			char name[260] = { '\0' };
			int noi;

			if (count == 0)//如果读入第一个
			{
				if (begin_blank == 1)//如果//与后面之间有空格
				{
					char rub[260];
					in >> rub >> no;
					
				}
				else {
					in >> no;
					
					int len = (int)(strlen(no));
					for (int i = 2; i <= len - 1; i++)//整个往前挪2位 踢掉//
					{
						no[i - 2] = no[i];
						no[i] = '\0';
					}
				}
			}
			else
				in >> no;
						
			if (strlen(no) > 63)
			{
				int len = strlen(no);
				for (int n = 63; n <= len - 1; n++)
					name[n - 63] = no[n];
				no[63] = '\0';			
			}
			else if (!in.good())//已经到文件末尾了
			{
				fault++;//多了一个错误
				if (fault > 1)
					msg << "\t\t\t\t\t";
				msg << "第[" << count << "]个学生后面的信息不全，忽略" << endl;
				in.clear();
				break;
			}
			else
				in >> name;//读入姓名
			/*
			if (strlen(name) == 2 && name[0] == '*' && name[1] == '/')
			{
				fault++;//多了一个错误
				if (fault > 1)
					msg << "\t\t\t\t\t";
				msg << "第[" << count << "]个学生后面的信息不全，忽略" << endl;
				break;
			}
			*/
			
			count++;//加学生个数
			noi = atoi(no);
			bool find = 0;
			int i;

			if (noi == stu[s].no)
			{
				fault++;//多了一个错误
				if (fault > 1)
					msg << "\t\t\t\t\t";
				msg << "第[" << count << "]项写了自己，耍无赖么？" << endl;
				break;
			}

			for (i = 0; i <= stu_num - 1; i++)//在所有学生中找这个学生
			{
				if (stu[i].no == noi)
				{
					find = 1;
					break;
				}
			}

			if (find == 1 && strcmp(name, stu[i].name) == 0)//找到并且名字一样
			{	
				bool restu = 0;
				for (int j = 0; j < stu[s].partner_num; j++)//检查是否重复写同一个人
				{
					if (noi == stu[s].check_group[j].no)//如果重复
					{
						fault++;//多了一个错误
						if (fault > 1)
							msg << "\t\t\t\t\t";
						msg << "互验列表第[" << count << "]项的学号[" << noi << "]重复，忽略" << endl;
						restu = 1;
						break;
					}
				}
				if (restu == 1)//如果是重复的学生
					continue;//读下一个
				

				stu[s].partner_num++;//互查人数加一			

				stu[s].check_group[stu[s].partner_num - 1].no = noi;//添加新值
				strcpy(stu[s].check_group[stu[s].partner_num - 1].name, name);
			
			}
			else
			{
				fault++;
				if (fault > 1)
					msg << "\t\t\t\t\t";
				msg << "第[" << count << "]项的学号[" << no << "]/姓名[" << name << "]不正确，忽略" << endl;
			}
		}
		if (stu[s].partner_num == 0)
			continue;
		if (fault == 0)
			msg << "ok" << endl;
		msg << "\t读到的正确互验者" << endl;
		/*先按学号排个序*/
		for (int m = 0; m <= stu[s].partner_num - 1 - 1; m++)
		{
			for (int n = m + 1; n <= stu[s].partner_num - 1; n++)
			{
				if (stu[s].check_group[m].no > stu[s].check_group[n].no)
				{
					partner temp;
					temp = stu[s].check_group[m];
					stu[s].check_group[m] = stu[s].check_group[n];
					stu[s].check_group[n] = temp;
				}
			}
		}
		/*输出*/
		for (int n = 0; n <= stu[s].partner_num - 1; n++)
		{
			msg << "\t" << n + 1 << "\t" << stu[s].check_group[n].no << "\t" << stu[s].check_group[n].name << endl;
		}
		
		fin.close();
	}

	return 0;
}

/***************************************************************************
  函数名称：
  功    能：输出第二行匹配结果
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_2nd_line(student stu[], int stu_num, ostringstream& msg)
{
	msg << "序号\t课号\t学号\t姓名" << endl;
	for (int s = 0; s <= stu_num - 1; s++)//对所有学生进行循环
	{
		msg << s + 1 << "#\t" << stu[s].class_no << "\t" << stu[s].no << "\t" << stu[s].name;
		if (stu[s].partner_num == 0)//如果互查的人是0
		{
			msg << "\t无有效匹配项" << endl;
			stu[s].c_de_point2 -= 5 * 20;
			continue;
		}
		if (stu[s].partner_num < 5)//如果互查人数小于5人
		{
			stu[s].c_de_point2 -= (5 - stu[s].partner_num) * 20;
		}

		msg << endl;
		/*检查互查小组每个人是否抛弃了你*/
		for (int p = 0; p <= stu[s].partner_num - 1; p++)//遍历小组成员
		{
			msg << "\t$" << p + 1 << "\t" << stu[s].check_group[p].no << "\t" << stu[s].check_group[p].name << "\t";
			int i;
			bool find = 0;
			for (i = 0; i <= stu_num - 1; i++)//stu数组里找这个小组成员
			{
				if (stu[i].no == stu[s].check_group[p].no)
					break;
			}
			//i指向stu数组里小组成员所在的下标
			if (stu[i].partner_num == 0)//如果对方没有互验成员
			{
				msg << "抛弃了你" << endl;
				stu[s].c_de_point1 -= 100;//相当于未经允许写别人名字
				continue;
			}
			
			for (int j = 0; j <= stu[i].partner_num - 1; j++)
			{
				if (stu[i].check_group[j].no == stu[s].no)//如果对方的check_group里有自己的学号
				{
					find = 1;//找到
					break;
				}
			}
			if (find == 1)//对方和你是互验关系
			{
				msg << "ok" << endl;
				if (stu[i].g_ok == 0)//如果对方的b2不正确
					stu[s].c_de_point2 -= 20;
			}
			else//对方check_group里没有你
			{
				msg << "抛弃了你" << endl;
				stu[s].c_de_point1 -= 100;//相当于未经允许写别人名字
			}
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：输出最终得分
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_finalscore(student stu[], int stu_num, ostringstream& msg)
{
	msg << "序号\t课号\t学号\t姓名\t原始程序得分\t检查程序原始分\t检查程序扣分1\t检查程序扣分2\t检查程序总分" << endl;
	for (int s = 0; s <= stu_num - 1; s++)
	{
		msg << s + 1 << "#\t" << stu[s].class_no << "\t" << stu[s].no << "\t" << stu[s].name << "\t" << 100 * stu[s].g_ok
			<< "\t" << 100 * stu[s].c_ok << "\t" << stu[s].c_de_point1 << "\t" << stu[s].c_de_point2
			<< "\t" << 100 * stu[s].c_ok + stu[s].c_de_point1 + stu[s].c_de_point2 << endl;
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：除了5句cout之外，不允许任何的cout语句 
***************************************************************************/
static int second_line_check(char *argv[], char debug[5], student stu[]) //参数自行约定，其中有一个是debug[5] 
{
	ostringstream msg;
	int stu_num;

    /* 允许加入其它语句，但不能有cout */ 
	char filename[50];
	strcpy(filename, "./source/");
	strcat(filename, argv[3]);
	strcat(filename, ".dat");
	/* 读课号.dat */
	msg << "1.读取课号配置文件" << endl;
	int read_result = read_stulist(filename, msg, stu, stu_num); //允许带返回值（也可以不要），参数自行约定，其中有一个是msg 
	if (read_result == FAIL_OPEN)
	{
		msg << "\t--> 无法打开" << filename << endl;
	}
	/* 允许加入其它语句(也可以不要)，但不能有cout */ 
	if (debug[0] == '1')
	{
		if (debug[1] == '1' || debug[2] == '1' || debug[3] == '1' || debug[4] == '1')
			msg << endl;
		cout << msg.str() << endl;
	}

    /* 允许加入其它语句，但不能有cout */ 

	msg.str(""); //清空msg中的信息
	msg << "2.按课号+学号排序的学生名单" << endl;
	print_stulist(stu, stu_num, msg); //允许带返回值（也可以不要），参数自行约定，其中有一个是msg 
    /* 允许加入其它语句(也可以不要)，但不能有cout */ 
	if (debug[1] == '1')
	{
		if (debug[2] == '1' || debug[3] == '1' || debug[4] == '1')
			msg << endl;
		cout << msg.str() << endl;
	}

    /* 允许加入其它语句，但不能有cout */ 

	msg.str(""); //清空msg中的信息
	msg << "3.所有学生读取第2行的解析信息" << endl;
	read_2nd_line(argv[5], stu, stu_num, msg); //允许带返回值（也可以不要），参数自行约定，其中有一个是msg 
    /* 允许加入其它语句(也可以不要)，但不能有cout */ 
	if (debug[2] == '1')
	{
		if (debug[3] == '1' || debug[4] == '1')
			msg << endl;
		cout << msg.str();
	}

    /* 允许加入其它语句，但不能有cout */ 

	/* 将双方进行信息匹配 */
	msg.str(""); //清空msg中的信息
	msg << "4.所有学生的第2行互验匹配结果" << endl;
	print_2nd_line(stu, stu_num, msg); //允许带返回值（也可以不要），参数自行约定，其中有一个是msg 
    /* 允许加入其它语句(也可以不要)，但不能有cout */ 
	if (debug[3] == '1')
	{
		if (debug[4] == '1')
			msg << endl;
		cout << msg.str();
	}

    /* 允许加入其它语句，但不能有cout */ 

	/* 再根据通过与否进行检查 */
	msg.str(""); //清空msg中的信息
	msg << "5.所有学生的第2行互验最终得分" << endl;
	print_finalscore(stu, stu_num, msg); //允许带返回值（也可以不要），参数自行约定，其中有一个是msg 
    /* 允许加入其它语句(也可以不要)，但不能有cout */ 
	if (debug[4] == '1')
	{
		cout << msg.str();
	}

    /* 允许加入其它语句，但不能有cout */ 

	return 0;
}

/***************************************************************************
  函数名称：
  功    能：用ostringstream的示例 
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
static void usage(const char* const procname)
{
	ostringstream msg;
	const int wopt = 7 + strlen(procname) + 4;
	cout << endl;

	msg << "Usage: " << procname << " [ --secondline | --courseid cid | --filename name/all ] | --debug xxxxx" << endl;
	msg << setw(wopt) << ' ' << "--secondline   : 次行检查" << endl;
	msg << setw(wopt) << ' ' << "--courseid     : 课号" << endl;
	msg << setw(wopt) << ' ' << "--filename     : 文件名(不支持all)" << endl;
	msg << setw(wopt) << ' ' << "--debug xxxxx  : 跟5位0/1，从左到右依次表示需要打印[读课号文件 | 学生名单 | 第2行解析 | 互验匹配 | 最终结果]的信息，默认00000" << endl;
	msg << endl;

	msg << "e.g.   " << procname << " --secondline --courseid 100692 --filename 5-b14.c --debug 11111 : 检查100692课程的5-b14.c的第二行(打印所有信息)" << endl;
	msg << "       " << procname << " --secondline --courseid 100692 --filename 5-b14.c --debug 00100 : 检查100692课程的5-b14.c的第二行(打印解析信息)" << endl;
	msg << endl;
	cout << msg.str() << endl;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、main函数中如果有输出，也仅限一句cout
            2、受1的限制，如果有需要，允许使用 goto END;(不允许再增加语句标号) 
***************************************************************************/
int main(int argc, char** argv)
{
	ostringstream msg;

	char debug[5] = { '0','0','0','0','0' };
	student stu[1000];
	/* 进行参数的分析，可以写在main中，也可以写自定义函数(带msg参数进去，函数中不允许cout)，如果有需要，允许goto  */ 
	
	if (argc == 1)
	{
		usage(argv[0]);
		msg << "必须指定参数[--secondline]" << endl;
		goto END;
	}
	if (argc >= 2)
	{
		if (strcmp(argv[1], "--secondline") != 0)
		{
			msg << "参数[" << argv[1] << "]非法." << endl;
			goto END;
		}
		if (argc == 2)
		{
			usage(argv[0]);
			msg << "必须指定参数[--courseid]" << endl;
			goto END;
		}
	}
		
	if (argc >= 3)
	{
		if (strcmp(argv[2], "--courseid") != 0)
		{
			msg << "参数[" << argv[2] << "]非法." << endl;
			goto END;
		}
		if (argc == 3)
		{
			msg << "参数[--courseid]的附加参数不足(类型:string)" << endl;
			goto END;
		}
	}
	if (argc == 4)
	{
		if (argv[3][0] == '-')
		{
			msg << "参数[--courseid]缺少附加参数. (类型:string)" << endl;
			goto END;
		}
		usage(argv[0]);
		msg << "必须指定参数[--filename]" << endl;
		goto END;
	}
	if (argc >= 5)
	{
		if (strcmp(argv[4], "--filename") != 0)
		{
			msg << "参数[" << argv[4] << "]非法." << endl;
			goto END;
		}
		if (argc == 5)
		{
			msg << "参数[--filename]的附加参数不足 (类型:string)" << endl;
			goto END;
		}
	}

	if (argc >= 6)
	{
		if (argv[5][0] == '-')
		{
			msg << "参数[--filename]缺少附加参数. (类型:string)" << endl;
			goto END;
		}
	}
		
	if (argc >= 7)
	{
		if (strcmp(argv[6], "--debug") != 0)
		{
			msg << "参数[" << argv[6] << "]非法." << endl;
			goto END;
		}
		if (argc == 7)
		{
			msg << "参数[" << argv[6] << "]缺少附加参数. (类型:string)" << endl;
			goto END;
		}
	}
	if (argc >= 8)
	{
		if (strlen(argv[7]) != 5)
		{
			usage(argv[0]);
			msg << "参数[--debug]必须为5位0/1" << endl;
			goto END;
		}

		for (int n = 0; n <= 4; n++)
		{
			if (argv[7][n] != '0' && argv[7][n] != '1')
			{
				usage(argv[0]);
				msg << "参数[--debug]的第[" << n + 1 << "]位不是0/1" << endl;
				goto END;
			}
			else
				debug[n] = argv[7][n];
		}
	}
	

	/* 如果参数分析正确，则调用此函数进行检查(具体参数按需设置) */ 
	second_line_check(argv, debug, stu);

    /* 允许加入其它语句，但不能有cout，如果有需要，允许goto */ 

END:
    cout << msg.str() << endl;

	return 0;
}

