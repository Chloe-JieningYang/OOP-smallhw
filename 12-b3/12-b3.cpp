/* 2050598 ����� ͨ�� */
#include <iostream>
using namespace std;

int main()
{
	int m;
	const char* month[] = { "January","February","March","April","May","June","July","August","September","October","November","December"};
	cout << "�������·�(1-12)" << endl;
	cin >> m;
	if (cin.fail() || m < 1 || m>12)
		cout << "Invalid" << endl;
	else
		cout << month[m - 1] << endl;
	return 0;
}