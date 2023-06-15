#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    char str[1000];
    printf("input:\n");
    gets(str);
    printf("len:%d",utf8len(str));
}

int utf8len(char *str)
{
    int len = 0;
    int step = 0;
    int a = strlen(str);
    for(int i=0;str[i]<a;i+=step){
        unsigned char c = str[i];
        if(c>=0xFC)
            len = 6;
        else if(c>=0xF8)
            len = 5;
        else if(c>=0xF0)
            len = 4;
        else if(c>=0xE0)
            len = 3;
        else if(c>=0xC0)
            len = 2;
        else
            len = 1;
        len++;
    }
    return len;
}
