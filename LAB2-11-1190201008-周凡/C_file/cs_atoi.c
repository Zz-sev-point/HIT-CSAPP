#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char *str = "949846354";
    printf("string: %s\ncs_atoi: %d\natoi: %d",str,cs_atoi(str),atoi(str));
}
int cs_atoi(char *str)
{
    char *max = "2147483647";
    char *min = "-2147483648";
    int len = strlen(str)-1;
    char head = str[0];
    if(!str||head!='-'&&len>10||head=='-'&&len>9||
       len==9&&strcmp(str,max)||len==9&&strcmp(str,min)){
        printf("overflow!\n");
        exit(0);
    }
    int count = 1;
    int x = 0;
    int a;
    while(len>0){
        a = str[len];
        if(a>='0'&&a<='9'){
            x += (a-'0')*count;
            count *= 10;
            len--;
        }
        else{
            printf("ERROE!");
            exit(0);
        }
    }
    if(head=='-')
        x = -x;
    else
        x += (head-'0')*count;
    return x;
}
