#include<stdio.h>
#define m 16
int main()
{
	FILE* fp = fopen("hello.c", "r");
	char x,y[m];
	int i = 0;
	do{
        x = fgetc(fp);
        if(feof(fp))
            break;
        if(x=='\n')
            printf("  \\n ");
        else if(x=='\t')
            printf("  \\t ");
        else
            printf("   %c ",x);
        y[i] = x;
		i++;
		if(i==m){
            printf("\n");
            for(int j=0;j<m;j++)
                printf("%4x ",y[j]);
            printf("\n");
            i = 0;
		}
	}while(1);
	printf("\n");
    for(int j=0;j<i;j++)
        printf("%4x ",y[j]);
    printf("\n");
	fclose(fp);
	return 0;
}
