/*2050598 通信 杨洁宁*/
#pragma once

#include <iostream>
using namespace std;


template<typename Elemtype, int Row, int Col>
class matrix
{
private:
	Elemtype value[Row][Col];
public:
	/*+的友元函数实现声明*/
	friend matrix<Elemtype,Row,Col> operator+(const matrix<Elemtype, Row, Col>& a, const matrix<Elemtype, Row, Col>& b)
	{
		matrix<Elemtype, Row, Col> sum;
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				sum.value[i][j] = a.value[i][j] + b.value[i][j];
			}
		}
		return sum;
	}


	friend ostream& operator << (ostream& out, const matrix<Elemtype, Row, Col>& mat)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
				out << mat.value[i][j] << " ";
			out << endl;
		}
		return out;
	}

	
	friend istream& operator >> (istream& in, matrix<Elemtype, Row, Col>& mat)
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				in >> mat.value[i][j];
			}
		}
		return in;
	}
};
