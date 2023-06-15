#include <stdio.h>

int isLittleEndian()//小端返回1，大端返回0
{
    int a = 0x1;
    char *p = (char *)&a;
    return *p;
}

int main()
{
    printf("%d",isLittleEndian());
    return 0;
}
