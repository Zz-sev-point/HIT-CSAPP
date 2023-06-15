#include <stdio.h>
#include <stdlib.h>
#include <float.h>
void main()
{
    float x = 1.0;
    float y = FLT_TRUE_MIN;
    printf("MIN: %f\n",x/y);
    printf("ZERO: %f\n",x/0);
}
