#include <stdio.h>

int main(void)
{
  void *a;

  int xs[5] = {1, 2, 3, 4, 5};

  a = &xs[0];

  printf("%d\n", *a);
  printf("%d\n", xs[0]);

  return 0;
}
