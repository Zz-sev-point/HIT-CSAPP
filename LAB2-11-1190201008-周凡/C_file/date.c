#include<stdio.h>
#include<time.h>
int main()
{
	struct tm *local;
	time_t t;
	t = time(NULL);//��ȡ��ǰʱ��
	local = localtime(&t);
	printf("%d/%d/%d %d:%d:%d\n",
        local->tm_year,local->tm_mon,local->tm_mday,
        local->tm_hour,local->tm_min,local->tm_sec);
    printf(asctime(local));
    printf("\n");
    local->tm_year = 8099;
    local->tm_mon = 11;
    local->tm_mday = 31;
    local->tm_hour = 23;
    local->tm_min = 59;
    local->tm_sec = 59;//��ʱ���޸�Ϊ9999/12/31 23:59:59
    printf("%d/%d/%d %d:%d:%d\n",
        local->tm_year,local->tm_mon,local->tm_mday,
        local->tm_hour,local->tm_min,local->tm_sec);
    printf(asctime(local));
    printf("\n");
    t = mktime(local);//��ʱ��ת��Ϊ����
    t++;//��ȡ��һ��ʱ��
    local = localtime(&t);
    printf("%d/%d/%d %d:%d:%d\n",
        local->tm_year,local->tm_mon,local->tm_mday,
        local->tm_hour,local->tm_min,local->tm_sec);
    printf(asctime(local));
}
