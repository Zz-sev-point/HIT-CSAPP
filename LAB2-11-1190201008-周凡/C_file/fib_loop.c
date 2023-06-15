#include <stdio.h>
#include <stdlib.h>
#define M 100
int fib_cyc_int(int x);
long fib_cyc_long(int x);
unsigned int fib_cyc_uint(int x);
unsigned long fib_cyc_ulong(int x);
int fib(int x);

void main()
{
    for(int i=0;i<M;i++)
        printf("%5d: %12d %12ld %12u %12lu\n",i,fib_cyc_int(i),fib_cyc_long(i),
               fib_cyc_uint(i),fib_cyc_ulong(i));
}
int fib_cyc_int(int x)
{
    int a=0,b=1;
    for(int i=0;i<x/2;i++){
        a += b;
        b += a;
    }
    if(x%2)
        return a += b;
    else
        return b;
}
long fib_cyc_long(int x)
{
    long a=0,b=1;
    for(int i=0;i<x/2;i++){
        a += b;
        b += a;
    }
    if(x%2)
        return a += b;
    else
        return b;
}
unsigned int fib_cyc_uint(int x)
{
    unsigned int a=0,b=1;
    for(int i=0;i<x/2;i++){
        a += b;
        b += a;
    }
    if(x%2)
        return a += b;
    else
        return b;
}
unsigned long fib_cyc_ulong(int x)
{
    unsigned long a=0,b=1;
    for(int i=0;i<x/2;i++){
        a += b;
        b += a;
    }
    if(x%2)
        return a += b;
    else
        return b;
}
