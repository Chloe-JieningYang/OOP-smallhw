#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };

	//a[10] = 0xac;//�˾�Խ�� 1
	a[11] = 0xcc;
	a[12] = 0xdd;
	a[13] = 0xee;
	a[14] = 0xaa;//�˾�Խ��
	a[15] = 0xbb;//�˾�Խ��
	//a[10] = 0xcccccccc;//�˾�Խ�� 2
	cout << "addr:" << hex << (void*)(a) << endl;
	for (int i = -4; i < 16; i++) //ע�⣬ֻ��0-9�Ǻ���Χ�����඼��Խ���
		cout << hex << (void*)(a + i) << ":" << int(a[i]) << endl;

	return 0;
}
