#include <stdio.h>

#define print_arr(arr, length)     \
  for (int i = 0; i < length; i++) \
  {                                \
    printf("%d ", arr[i]);         \
  }                                \
  printf("\n");

typedef int (*condition)(int, int);

int increasing(int i, int j)
{
  return i > j;
}

int decreasing(int i, int j)
{
  return i < j;
}

void swap(int *arr, int i, int j)
{
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void sort(int *arr, int length, int (*cond)(int, int))
{
  for (int i = 0; i < length - 1; i++)
  {
    for (int j = 0; j < length - i - 1; j++)
    {
      if (cond(arr[j], arr[j + 1]))
      {
        swap(arr, j, j + 1);
      }
    }
  }
}

int main(void)
{

  int arr[5] = {4, 2, 1, 5, 3};

  printf("Without sorting:\n");
  print_arr(arr, 5);

  printf("Decreasing sorting:\n");
  sort(arr, 5, decreasing);
  print_arr(arr, 5);

  printf("Increasing sorting:\n");
  sort(arr, 5, increasing);
  print_arr(arr, 5);

  return 0;
}
