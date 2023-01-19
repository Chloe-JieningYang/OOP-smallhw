/* 2050598 ͨ�� ����� */
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159

class Shape {
protected:
    //������Ҫ������Ӧ�ĳ�Ա��Ҳ����Ϊ��
public:
    virtual double area() const { return 0.0; }
    virtual void ShapeName() = 0; //�˾䲻׼��
    //������Ҫ������Ӧ�ĳ�Ա��Ҳ����Ϊ��
};

//�˴����������Ķ��弰ʵ��

/*Բ*/
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

/*������*/
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

/*������*/
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

/*����*/
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

/*������*/
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

/* -- �滻����� -- ���в�Ҫ���κθĶ� -- ���в�Ҫɾ�� -- �ڱ��е����治Ҫ�����κ��Լ�����䣬��ҵ�ύ��ӱ��п�ʼ�ᱻ�滻 -- �滻����� -- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    if (1) {
        Circle    c1(5.2);           //�뾶5.2�����<=0�����Ϊ0��
        Square    s1(5.2);           //�߳�5.2�����<=0�����Ϊ0��
        Rectangle r1(5.2, 3.7);      //�����������һ<=0�����Ϊ0��
        Trapezoid t1(2.3, 4.4, 3.8); //�ϵס��µס��ߣ������һ<=0�����Ϊ0��
        Triangle  t2(3, 4, 5);       //���߳��ȣ������һ<=0�򲻹��������Σ����Ϊ0��
        Shape* s[5] = { &c1, &s1, &r1, &t1, &t2 };

        int   i;
        for (i = 0; i < 5; i++) {
            s[i]->ShapeName(); //�ֱ��ӡ��ͬ��״ͼ�ε����ƣ���Ӣ�ľ��ɣ�
            cout << s[i]->area() << endl; //�ֱ��ӡ��ͬ��״ͼ�ε����
            cout << endl;
        }
    }

    if (1) {
        Circle    c1(-1);           //�뾶5.2�����<=0�����Ϊ0��
        Square    s1(-1);           //�߳�5.2�����<=0�����Ϊ0��
        Rectangle r1(5.2, -1);      //�����������һ<=0�����Ϊ0��
        Trapezoid t1(2.3, -1, 3.8); //�ϵס��µס��ߣ������һ<=0�����Ϊ0��
        Triangle  t2(3, 4, -1);       //���߳��ȣ������һ<=0�򲻹��������Σ����Ϊ0��
        Shape* s[5] = { &c1, &s1, &r1, &t1, &t2 };

        cout << "============" << endl;
        int   i;
        for (i = 0; i < 5; i++) {
            s[i]->ShapeName(); //�ֱ��ӡ��ͬ��״ͼ�ε����ƣ���Ӣ�ľ��ɣ�
            cout << s[i]->area() << endl; //�ֱ��ӡ��ͬ��״ͼ�ε����
            cout << endl;
        }
    }

    return 0;
}

