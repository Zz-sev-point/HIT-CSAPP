#include <stdio.h>
#include <stdlib.h>
#define M 100
int fib(int x);

void main()
{
    for(int i=0;i<M;i++)
        printf("%5d: %d\n",i,fib(i));
}
int fib(int x)
{
    if(x==1|x==0)
        return 1;
    else
        return fib(x-1)+fib(x-2);
}
