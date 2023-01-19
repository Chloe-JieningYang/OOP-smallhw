/* 通信  2050598  杨洁宁 */
#include <stdio.h>

int main()
{
   /* 三个条件编译的相互位置可互换（例：目前#if满足是输出VS2022，允许先换为Linux）*/
#if (_MSC_VER)
   printf("VS2022\n");
#elif (__GNUC__&&_WIN32)||(__GCC_IEC_559_COMPLEX&&_WIN32)
    printf("Dev\n");
#elif (__linux__)
   printf("Linux\n");
#endif

    return 0;
}
