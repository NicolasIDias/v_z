#include <stdio.h>
#include <stdlib.h>

#define print_array(size, arr) for(int i=0;i<size;i++){printf("%d ", arr[i]);} printf("\n");

#define ARRAY_SIZE 10

typedef void (*map_func)(int *, int, int *, int(*transform)(int));
typedef int (*filter_func)(int *, int, int(*filter)(int));
typedef int (*reduce_func)(int *, int, int, int(*function)(int, int));

int double_values(int num)
{
	return num*2;
}
int is_odd(int num)
{
	return (num % 2 != 0) ? 1 : 0;
}
int combine(int x, int y)
{
	return ((x+y) % 2 == 0) ? x+(2*y) : (2*x)+y;
}

void map(int *origin, int size, int *dest, int(*transform)(int))
{
	for(int i=0;i<size;i++)
	{
		dest[i] = transform(origin[i]);
	}
}

int filter_count(int *origin, int size, int(*filter)(int))
{
	int counter = 0;
	for(int i=0;i<size;i++)
	{
		if(filter(origin[i])) counter++;
	}
	return counter;
}

int reduce(int *origin, int size, int initial, int(*function)(int, int))
{
	for(int i=0;i<size;i++)
	{
		initial = function(initial, origin[i]);
	}
	return initial;
}

int main(void)
{
	int nums[ARRAY_SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int nums2[ARRAY_SIZE];

	map_func mapper = map;
	mapper(nums, ARRAY_SIZE, nums2, double_values);

	filter_func fil = filter_count;
	int many_odds = fil(nums, ARRAY_SIZE, is_odd);
	printf("Many odds: %d\n", many_odds);

	reduce_func red = reduce;
	int reduced = red(nums, ARRAY_SIZE, 1, combine);
	printf("Reduced: %d\n", reduced);
	
	// After mapping, all the values should be 2x nums[i]
	print_array(ARRAY_SIZE, nums2);
	

	return 0;
}
