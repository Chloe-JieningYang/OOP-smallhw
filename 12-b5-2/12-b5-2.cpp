/* 通信 2050598 杨洁宁 */
#include <iostream>
#include <iomanip>
using namespace std;

const char* sp = "=====================================";

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：每个数字宽度为8，右对齐
***************************************************************************/
template <typename T4, int i, int j>

void matrix_print(const char* ch, T4(&m)[i][j])	//将...替换为相应内容
{
	/* 按需增加内容 */
	cout << ch << endl;
	for (int i1 = 0; i1 <= i - 1; i1++)
	{
		for (int j1 = 0; j1 <= j - 1; j1++)
		{
			cout << setiosflags(ios::right) << setw(8) << *(*(m + i1) + j1);
		}
		cout << endl;
	}

	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
template <typename T,int ii,int jj>
void matrix_addition(T(&add)[ii][jj], T(&t1)[ii][jj], T(&t2)[ii][jj])	//将...替换为相应内容
{
	/* 按需增加内容 */
	cout << "源矩阵1 : 行=" << ii << " 列=" << jj << " 占用空间=" << sizeof(t1) << "字节" << endl;
	cout << "源矩阵2 : 行=" << ii << " 列=" << jj << " 占用空间=" << sizeof(t2) << "字节" << endl;
	cout << "和矩阵  : 行=" << ii << " 列=" << jj << " 占用空间=" << sizeof(add) << "字节" << endl;
	for (int i1 = 0; i1 <= ii - 1; i1++)
	{
		for (int j1 = 0; j1 <= jj - 1; j1++)
		{
			*(*(add + i1) + j1) = *(*(t1 + i1) + j1) + *(*(t2 + i1) + j1);
		}
	}

	return;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
template <typename T1, typename T2,typename T3, int muli,int mulj,int t1i,int t1j,int t2i,int t2j>
void matrix_multiplication(T1(&mul)[muli][mulj], T2(&t1)[t1i][t1j], T3(&t2)[t2i][t2j])	//将...替换为相应内容
{
	/* 按需增加内容 */
	cout << "源矩阵1 : 行=" << t1i << " 列=" << t1j << " 占用空间=" << sizeof(t1) << "字节" << endl;
	cout << "源矩阵2 : 行=" << t2i << " 列=" << t2j << " 占用空间=" << sizeof(t2) << "字节" << endl;
	cout << "积矩阵  : 行=" << muli << " 列=" << mulj << " 占用空间=" << sizeof(mul) << "字节" << endl;
	for (int j1 = 0; j1 <= t2j - 1; j1++)
	{
		for (int i1 = 0; i1 <= t1i - 1; i1++)
		{
			*(*(mul + i1) + j1) = 0;
			for (int n = 0; n <= t1j - 1; n++)
				*(*(mul + i1) + j1) += T1(*(*(t1 + i1) + n) * (*(*(t2 + n) + j1)));
		}
	}

	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准更改
***************************************************************************/
int main()
{
	int t1[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	int t2[3][4] = {
		{12,11,10,9},
		{8,7,6,5},
		{4,3,2,1}
	};
	int t3[4][2] = {
		{1, 2},
		{3, 4},
		{5, 6},
		{7, 8}
	};
	int t_add[3][4], t_mul[3][2];

	cout << sp << endl;
	matrix_print("加法运算，源矩阵1：", t1);
	matrix_print("加法运算，源矩阵2：", t2);
	matrix_addition(t_add, t1, t2);	//将t1和t2的和放入t_add中，人工保证三个矩阵行列一致
	matrix_print("加法运算，和矩阵 ：", t_add);
	cout << sp << endl;
	matrix_print("乘法运算，源矩阵1：", t1);
	matrix_print("乘法运算，源矩阵2：", t3);
	matrix_multiplication(t_mul, t1, t3);	//将t1和t2的和放入t_add中，人工保证三个矩阵行列一致
	matrix_print("乘法运算，积矩阵 ：", t_mul);
	cout << sp << endl;

	double d1[2][4] = {
		{1.1, 2.2, 3.3, 4.4},
		{5.5 ,6.6, 7.7, 8.8}
	};
	double d2[2][4] = {
		{8.8, 7.7, 6.6, 5.5},
		{4.4, 3.3, 2.2, 1.1}
	};
	double d_add[2][4];
	/* 不要问为什么矩阵乘法数据类型不同，故意的 */
	float f3[4][3] = {
		{12.12f, 11.11f, 10.10f},
		{9.9f, 8.8f, 7.7f},
		{6.6f, 5.5f, 4.4f},
		{3.3f, 2.2f, 1.1f}
	};
	int i_mul[2][3];

	matrix_print("加法运算，源矩阵1：", d1);
	matrix_print("加法运算，源矩阵2：", d2);
	matrix_addition(d_add, d1, d2);	//将d1和d2的和放入d_add中，人工保证三个矩阵行列一致
	matrix_print("加法运算，和矩阵 ：", d_add);
	cout << sp << endl;
	matrix_print("乘法运算，源矩阵1：", d1);
	matrix_print("乘法运算，源矩阵2：", f3);
	matrix_multiplication(i_mul, d1, f3);	//将t1和t2的和放入t_add中，人工保证三个矩阵行列一致
	matrix_print("乘法运算，积矩阵 ：", i_mul);
	cout << sp << endl;

	return 0;
}
