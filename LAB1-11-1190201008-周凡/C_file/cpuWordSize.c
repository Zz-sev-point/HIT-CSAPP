#include <stdio.h>
#define b 8

int cpuWordSize()
{
    return sizeof(char*)*b;
}

int main()
{
    printf("%d",cpuWordSize());
    return 0;
}
