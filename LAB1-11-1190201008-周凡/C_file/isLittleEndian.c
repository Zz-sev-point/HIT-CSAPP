#include <stdio.h>

int isLittleEndian()//С�˷���1����˷���0
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
