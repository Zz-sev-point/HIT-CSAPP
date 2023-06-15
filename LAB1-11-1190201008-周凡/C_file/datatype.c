#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len);
struct ST
{
    float data;
    char ch[4];
};
union UN
{
    int num;
    double data;
};
enum EN
{
    mon,tue,wed,thu,fri,sat,sun
};

int num = 1190201008;
char *name = "周凡";
char *s = "abcd";
float ID = 331023200106271457;
struct ST stru;
union UN uni = {77};
enum EN enu = wed;

int main()
{
    stru.data = 123456;
    strcpy(stru.ch,s);
    printf("num  %d:\n",num);
    show_bytes((byte_pointer)&num,sizeof(int));
    printf("name %s:\n",name);
    show_bytes((byte_pointer)name,strlen(name));
    printf("ID   %.0f:\n",ID);
    show_bytes((byte_pointer)&ID,sizeof(float));
    printf("stru data: %.0f  ch: %s:\n",stru.data,stru.ch);
    show_bytes((byte_pointer)&stru.data,sizeof(struct ST));
    printf("uni %d:\n",uni,&uni,uni);
    show_bytes((byte_pointer)&uni,sizeof(union UN));
    printf("enu %d:\n",enu);
    show_bytes((byte_pointer)&enu,sizeof(enum EN));
    return 0;
}
void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for(i=0;i<len;i++)
        printf("%p\t0x%.2x\n",&start[i],start[i]);
    printf("\n");
}
