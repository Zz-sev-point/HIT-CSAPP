#include <stdio.h>
#include <stdlib.h>
int cs_itoa(int x,char *str);
void main()
{
    int x = -12654684;
    char *y;
    cs_itoa(x,y);
    printf("int:     %d\ncs_itoa: %s",x,y);
}

int cs_itoa(int x,char *str)
{
    char in[15];
    int i = 1, j = 0, flag = 0;
    in[0] = '\0';
    if(x<0){
        flag = 1;
        x = -x;
    }
    while(x>0){
        in[i] = x%10+'0';
        x /= 10;
        i++;
    }
    if(flag)
        in[i] = '-';
    else
        i--;
    while(i>=0){
        str[j] = in[i];
        i--;
        j++;
    }
    return 1;//操作成功，返回1
}
