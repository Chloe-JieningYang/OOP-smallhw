/* ͨ��  2050598  ����� */
#include <stdio.h>

int main()
{
   /* ��������������໥λ�ÿɻ���������Ŀǰ#if���������VS2022�������Ȼ�ΪLinux��*/
#if (_MSC_VER)
   printf("VS2022\n");
#elif (__GNUC__&&_WIN32)||(__GCC_IEC_559_COMPLEX&&_WIN32)
    printf("Dev\n");
#elif (__linux__)
   printf("Linux\n");
#endif

    return 0;
}
