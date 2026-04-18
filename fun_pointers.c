#include <stdio.h>

typedef int (*fun)(int, int);
typedef void (*fun2)(int *, int, int (*f)(int));

int foo(int x, int y)
{
	return x + y;
}

int sum(int x, int y) { return x + y; }
int mul(int x, int y) { return x * y; }

int operation(int x, int y, int (*op)(int, int))
{
	return op(x, y);
}

int pred(int x) { return (x % 2 == 0) ? 1 : 0; }

void print_if(int *xs, int length, int (*predicate)(int))
{
	// int size = sizeof(xs)/sizeof(xs[0]);
	// printf("Size: %d\n", size);
	for (int i = 0; i < length; i++)
	{
		if (predicate(xs[i]))
		{
			printf("%d\n", xs[i]);
		}
	}
}

int main(void)
{

	int xs[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int sizeXs = sizeof(xs) / sizeof(xs[0]);
	// printf("Size2: %d", sizeXs);
	//  Ponteiro pra a funcao foo, funcao que retorna um int
	//  f e um ponteiro que aponta para uma funcao que recebe dois ints e retorna um int
	int (*f)(int, int) = foo;

	fun function = foo;
	printf("type: %d\n", function(xs[0], xs[1]));

	printf("FUnction 2\n");

	fun2 function2 = print_if;
	function2(xs, sizeXs, pred);

	printf("Operation SUM: %d\n", operation(xs[8], xs[4], sum));
	printf("Operation MUL: %d\n", operation(xs[8], xs[4], mul));

	printf("-----------------------\n");

	printf("Foo: %d\n", f(xs[0], xs[1]));

	printf("PRINT_IF\n");

	print_if(xs, sizeXs, pred);

	return 0;
}
