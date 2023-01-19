#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };

	//a[10] = 0xac;//此句越界 1
	a[11] = 0xcc;
	a[12] = 0xdd;
	a[13] = 0xee;
	a[14] = 0xaa;//此句越界
	a[15] = 0xbb;//此句越界
	//a[10] = 0xcccccccc;//此句越界 2
	cout << "addr:" << hex << (void*)(a) << endl;
	for (int i = -4; i < 16; i++) //注意，只有0-9是合理范围，其余都是越界读
		cout << hex << (void*)(a + i) << ":" << int(a[i]) << endl;

	return 0;
}
