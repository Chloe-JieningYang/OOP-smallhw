/* ͨ�� 2050598 ����� */
#include <iostream>
/* --���ĳ����������Ҫ���˴�������������ĸ�ʽ����ͷ�ļ� --*/
#if __linux__

#include <stdio.h>

#endif
using namespace std;


int main()
{  
   char a[80];

#if (__GNUC__&&_WIN32)||(__GCC_IEC_559_COMPLEX&&_WIN32)  //DevC++
   gets(a);
#elif (_MSC_VER)       //VS2022
   gets_s(a);
#elif (__linux__)       //Linux
   fgets(a, 80, stdin); //����Ҫ�������Ļس�
#endif

   cout << a << endl;
   return 0;
}
