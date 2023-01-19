/* 2050598 ����� ͨ�� */
#include <iostream>
#include <iomanip>
using namespace std;

#define STUDENT_NUM	4
#define SCORE_NUM	5

/* --- �����������κ���ʽ��ȫ�ֱ��� --- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ����һ�ſε�ƽ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void average(int (*score)[STUDENT_NUM])
{
    /* ����������䲿�֣�
       1���������н��������� 1���򵥱��� + 1��ָ����� */
    double ave = 0;
    int* p;
    /* ����ִ����䲿�֣�
       1���������ٶ����κ����͵ı��������� for (int i=0;...������ʽ�������
       2��ѭ������������ָ���������������в���������[]��ʽ��������
          ��������int a[10], i;
                  for(i=0; i<10; i++)
                      cout << a[i];
          ����  ��int a[10], p;
                  for(p=a; p<a+10; p++)
                      cout << *p;          */

    for (p = *score; p <= *score + STUDENT_NUM - 1; p++)
    {
        ave += double(*p) / STUDENT_NUM;
    }
    cout << "��1�ſ�ƽ���֣�" << ave << endl;
    return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ҳ����������Ͽγ̲������ѧ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fail(int (*score)[STUDENT_NUM])
{
    /* ����������䲿�֣�
       1���������н��������� 3���򵥱��� + 1����ָ����� + 1����ָ����� */
    int(*ps)[STUDENT_NUM];
    int failcls = 0;
    int i;
    double ave;
    /* ����ִ����䲿�֣�Ҫ��ͬaverage��*/
    cout << "2�����ϲ������ѧ����" << endl;
    for (i = 0; i <= STUDENT_NUM - 1; i++)
    {
        failcls = 0;
        ave = 0;
        for (ps = score; ps <= score + SCORE_NUM-1; ps++)
        {
            ave += double(*(*ps + i)) / SCORE_NUM;
            if (*(*ps + i) < 60)
                failcls++;
        }
        if (failcls >= 2)
        {
            cout << "No��" << i + 1 << " ";
            for (ps = score; ps <= score + SCORE_NUM-1; ps++)
            {
                cout << *(*ps + i) << " ";
            }
            cout << "ƽ����" << ave << endl;
        }
    }
    return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ҳ�ƽ���ɼ���90�����ϻ�ȫ���ɼ���85�����ϵ�ѧ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void good(int (*score)[STUDENT_NUM])
{
    /* ����������䲿�֣�
       1���������н��������� 3���򵥱��� + 1����ָ����� + 1����ָ����� */
    int(*ps)[STUDENT_NUM];
    double ave;
    int i;
    bool above85;
    /* ����ִ����䲿�֣�Ҫ��ͬaverage��*/
    cout << "ƽ��90���ϻ�ȫ��85���ϵ�ѧ����" << endl;
    for (i = 0; i <= STUDENT_NUM - 1; i++)
    {
        ave = 0;
        above85 = 1;
        for (ps = score; ps <= score + SCORE_NUM - 1; ps++)
        {
            ave += double(*(*ps + i)) / SCORE_NUM;
            if (*(*ps + i) < 85)
                above85 = 0;
        }
        if (above85 == 1 || ave >= 90)
        {
            cout << "No��" << i + 1 << " ";
            for (ps = score; ps <= score + SCORE_NUM - 1; ps++)
            {
                cout << *(*ps + i) << " ";
            }
            cout << "ƽ����" << ave << endl;
        }
    }
    return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    int a[SCORE_NUM][STUDENT_NUM] = {
		{91,92,93,97},  //��1-4��ѧ���ĵ�1�ſγɼ�
		{81,82,83,85},  //��1-4��ѧ���ĵ�2�ſγɼ�
		{71,72,99,87},  //��1-4��ѧ���ĵ�3�ſγɼ�
		{61,32,80,91},  //��1-4��ѧ���ĵ�4�ſγɼ�
		{51,52,95,88} };//��1-4��ѧ���ĵ�5�ſγɼ�
    /* �������Ԥ�������⣬�������н��������� 1����ָ����� + 1����ָ����� */
    int* p;
    int(*ps)[STUDENT_NUM];
    /* ����ִ����䲿�֣�Ҫ��ͬaverage��*/
    for (ps = a; ps <= a + SCORE_NUM-1; ps++)
    {
        cout << "No.1-4ѧ���ĵ�" << ps - a + 1 << "�ſεĳɼ���";
        for (p = *ps; p <= *ps + STUDENT_NUM-1; p++)
        {
            cout << *p << " ";
        }
        cout << endl;
    }
    cout << endl;
    average(a);
    cout << endl;
    fail(a);
    cout << endl;
    good(a);

    return 0;
}