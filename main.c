#include <stdio.h>
#include <stdlib.h>

int global0, global1, global2;

void stack(int n) {
  if (n < 0) return;
  int local;
  printf("local%d |    %p    |    %d\n", n, &local, &local);
  stack(n - 1);
}

int main(void) {
  // int stack0, stack1, stack2;

  printf("STACK TEST\n");
  printf(" name  |   addr (hex)   |   addr (dec)\n");
  stack(2);
  printf("\n");

  int* heap0 = malloc(sizeof(int));
  int* heap1 = malloc(sizeof(int));
  int* heap2 = malloc(sizeof(int));

  printf("HEAP TEST\n");
  printf(" name  |   addr (hex)   |   addr (dec)\n");
  printf("heap0  |    %p    |    %d\n", heap0, heap0);
  printf("heap1  |    %p    |    %d\n", heap1, heap1);
  printf("heap2  |    %p    |    %d\n", heap2, heap2);
  printf("\n");

  free(heap0);
  free(heap1);
  free(heap2);

  printf("DATA/BSS TEST\n");
  printf(" name  |   addr (hex)   |   addr (dec)\n");
  printf("data0  |    %p    |    %d\n", &global0, &global0);
  printf("data1  |    %p    |    %d\n", &global1, &global1);
  printf("data2  |    %p    |    %d\n", &global2, &global2);

  return 0;
}