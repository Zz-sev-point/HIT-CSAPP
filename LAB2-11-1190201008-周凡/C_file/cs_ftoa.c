#include <stdio.h>
#include <stdlib.h>
int cs_ftoa(double x, char *str, int be_point);
void main()
{
    double x = -21366.548;
    char y[100];
    cs_ftoa(x,y,6);
    printf("float:   %lf\ncs_ftoa: %s",x,y);
}
int cs_ftoa(double x, char *str, int be_point)
{
    int i=0, j=0, count=10;
    int a;
    char inte[20];
    if(x<0){
        str[j++] = '-';
        x = -x;
    }
    long long left = (int)x;
    double right = x-left;
    while(left){
        inte[i] = left%10 + '0';
        left /= 10;
        i++;
    }
    i--;
    while(i>=0){
        str[j] = inte[i];
        j++;
        i--;
    }
    str[j++] = '.';
    while(be_point){
        a = (int)(right*10);
        str[j++] = a+'0';
        right = right*10 - (int)(right*10);
        be_point--;
    }
    str[j] = '\0';
    return 0;
}
