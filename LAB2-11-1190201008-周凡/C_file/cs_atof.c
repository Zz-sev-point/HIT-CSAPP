#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double cs_atof(char *str);
void main()
{
    char *str = "125348.2136481547";
    printf("string:  %s\ncs_atof: %.10f\natof:    %.10f",str,cs_atof(str),atof(str));
}
double cs_atof(char *str)
{
    char head = str[0];
    int len = strlen(str)-1;
    int point = 0, count = 1;//point存储小数点位置
    int left = 0, right = 0;//小数点左右的数
    int a,i;
    double x;
    while(point<=len&&str[point]!='.')
        point++;
    i = len;
    while(i>point){
        a = str[i];
        if(a>='0'&&a<='9'){
            right += (a-'0')*count;
            count *= 10;
            i--;
        }
        else{
            printf("ERROE!");
            exit(0);
        }
    }
    i = point-1;
    count = 1;
    while(i>0){
        a = str[i];
        if(a>='0'&&a<='9'){
            left += (a-'0')*count;
            count *= 10;
            i--;
        }
        else{
            printf("ERROE!");
            exit(0);
        }
    }
    if(head=='-'){
        left = -left;
        right = -right;
    }
    else
        left += (head-'0')*count;
    x = (double)left + right/pow(10,len-point);
    return x;
}
