#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };

	a[10] = 0xab;//�˾�Խ�� 1
	a[14] = 0xaa;//�˾�Խ��
	a[15] = 0xbb;//�˾�Խ��
	a[10] = 0xcccccccc;//�˾�Խ�� 2

	printf("addr:%p\n", a);
	for (int i = -4; i < 16; i++) //ע�⣬ֻ��0-9�Ǻ���Χ�����඼��Խ���
		printf("%p:%02x\n", (a + i), a[i]);

	return 0;
}