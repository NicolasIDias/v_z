#include <stdio.h>
#include <stdbool.h>

typedef unsigned int T_FLAG;
#define FLAG_A (1 << 0) // 00000001
#define FLAG_B (1 << 1) // 00000010
#define FLAG_C (1 << 2) // 00000100

// FLAG_A | FLAB_B == 000000011

int f(int x, T_FLAG flag)
{
	if (flag & FLAG_A)
	{
		x += x;
	}
	if (flag & FLAG_B)
	{
		x *= x;
	}
	if (flag & FLAG_C)
	{
		x = ~x;
	}
	return x;
}

int main(void)
{
	int x = 1234;
	printf("%d\n", f(x, 0));
	printf("%d\n", f(x, FLAG_A));
	printf("%d\n", f(x, FLAG_B | FLAG_C));

	return 0;
}
