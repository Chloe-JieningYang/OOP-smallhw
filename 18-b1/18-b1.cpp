/* 2050598 通信 杨洁宁 */
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159

class Shape {
protected:
    //根据需要加入相应的成员，也可以为空
public:
    virtual double area() const { return 0.0; }
    virtual void ShapeName() = 0; //此句不准动
    //根据需要加入相应的成员，也可以为空
};

//此处给出五个类的定义及实现

/*圆*/
class Circle:public Shape {
protected:
    double r;
public:
    Circle(double r1);
    virtual void ShapeName();
    virtual double area() const;
};

Circle::Circle(double r1)
{
    if (r1 > 0)
        r = r1;
    else
        r = 0;
}

void Circle::ShapeName()
{
    cout << "Circle" << endl;
    return;
}

double Circle::area()const
{
    double s = PI * r * r;
    return s;
}

/*正方形*/
class Square :public Shape {
protected:
    double a;
public:
    Square(double a1);
    virtual void ShapeName();
    virtual double area() const;
};

Square::Square(double a1)
{
    if (a1 > 0)
        a = a1;
    else
        a = 0;
}

void Square::ShapeName()
{
    cout << "Square" << endl;
    return;
}

double Square::area() const
{
    return a * a;
}

/*长方形*/
class Rectangle :public Shape {
protected:
    double a;
    double b;
public:
    Rectangle(double a1, double b1);
    virtual void ShapeName();
    virtual double area() const;
};

Rectangle::Rectangle(double a1, double b1)
{
    if (a1 > 0 && b1 > 0)
    {
        a = a1;
        b = b1;
    }
    else
    {
        a = 0;
        b = 0;
    }
}

void Rectangle::ShapeName()
{
    cout << "Rectangle" << endl;
    return;
}

double Rectangle::area() const
{
    return a * b;
}

/*梯形*/
class Trapezoid :public Shape {
protected:
    double a;
    double b;
    double h;
public:
    Trapezoid(double a1, double b1, double h);
    virtual void ShapeName();
    virtual double area() const;
};

Trapezoid::Trapezoid(double a1, double b1, double h1)
{
    if (a1 > 0 && b1 > 0 && h1 > 0)
    {
        a = a1;
        b = b1;
        h = h1;
    }
    else
    {
        a = 0;
        b = 0;
        h = 0;
    }
}

void Trapezoid::ShapeName()
{
    cout << "Trapezoid" << endl;
    return;
}

double Trapezoid::area() const
{
    return (a + b) * h / 2;
}

/*三角形*/
class Triangle :public Shape {
protected:
    double a;
    double b;
    double c;
public:
    Triangle(double a1, double b1, double c1);
    virtual void ShapeName();
    virtual double area() const;
};

Triangle::Triangle(double a1, double b1, double c1)
{
    if (a1 > 0 && b1 > 0 && c1 > 0 && a1 + b1 > c1 && a1 + c1 > b1 && b1 + c1 > a1)
    {
        a = a1;
        b = b1;
        c = c1;
    }
    else
    {
        a = 0;
        b = 0;
        c = 0;
    }
}

void Triangle::ShapeName()
{
    cout << "Triangle" << endl;
    return;
}

double Triangle::area() const
{
    double p = (a + b + c) / 2;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    return area;
}

/* -- 替换标记行 -- 本行不要做任何改动 -- 本行不要删除 -- 在本行的下面不要加入任何自己的语句，作业提交后从本行开始会被替换 -- 替换标记行 -- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    if (1) {
        Circle    c1(5.2);           //半径5.2（如果<=0，面积为0）
        Square    s1(5.2);           //边长5.2（如果<=0，面积为0）
        Rectangle r1(5.2, 3.7);      //长、宽（如果任一<=0，面积为0）
        Trapezoid t1(2.3, 4.4, 3.8); //上底、下底、高（如果任一<=0，面积为0）
        Triangle  t2(3, 4, 5);       //三边长度（如果任一<=0或不构成三角形，面积为0）
        Shape* s[5] = { &c1, &s1, &r1, &t1, &t2 };

        int   i;
        for (i = 0; i < 5; i++) {
            s[i]->ShapeName(); //分别打印不同形状图形的名称（中英文均可）
            cout << s[i]->area() << endl; //分别打印不同形状图形的面积
            cout << endl;
        }
    }

    if (1) {
        Circle    c1(-1);           //半径5.2（如果<=0，面积为0）
        Square    s1(-1);           //边长5.2（如果<=0，面积为0）
        Rectangle r1(5.2, -1);      //长、宽（如果任一<=0，面积为0）
        Trapezoid t1(2.3, -1, 3.8); //上底、下底、高（如果任一<=0，面积为0）
        Triangle  t2(3, 4, -1);       //三边长度（如果任一<=0或不构成三角形，面积为0）
        Shape* s[5] = { &c1, &s1, &r1, &t1, &t2 };

        cout << "============" << endl;
        int   i;
        for (i = 0; i < 5; i++) {
            s[i]->ShapeName(); //分别打印不同形状图形的名称（中英文均可）
            cout << s[i]->area() << endl; //分别打印不同形状图形的面积
            cout << endl;
        }
    }

    return 0;
}

