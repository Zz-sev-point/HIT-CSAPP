#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
typedef unsigned char* byte_pointer;
void show_byte(byte_pointer start, size_t len)
{
	size_t i;
	printf("0x");
	for (i = 0; i < len; i++) {
		printf("%.2x", start[i]);
	}
	printf("\n");
}
int main()
{
	float a = +0.0f;
	float b = -0.0f;
	float c = FLT_TRUE_MIN;
	float d = FLT_MAX;
	float e = FLT_MIN;
	float f = INFINITY;
	float g = NAN;
	printf("+0:%e\n", a);
	printf("-0:%e\n", b);
	printf("最小浮点正数:%e\n", c);
	printf("最大浮点正数:%e\n", d);
	printf("最小正规格化数:%e\n", e);
	printf("正无穷大:%e\n", f);
	printf("\n十六进制\n");
	printf("+0:");
	show_byte((byte_pointer)&a, sizeof(float));
	printf("-0:");
	show_byte((byte_pointer)&b, sizeof(float));
	printf("最小浮点正数:");
	show_byte((byte_pointer)&c, sizeof(float));
	printf("最大浮点正数:");
	show_byte((byte_pointer)&d, sizeof(float));
	printf("最小正规格化数:");
	show_byte((byte_pointer)&e, sizeof(float));
	printf("正无穷大:");
	show_byte((byte_pointer)&f, sizeof(float));
	return 0;
}

