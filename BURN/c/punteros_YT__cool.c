#include <stdio.h>

int main(void){

  int a = 4;
  int *a_ptr = &a;

  printf("\nThe value of the variable        a = %d\n", a);
  printf("\nThe address of the variable      a = %p\n", &a);
  printf("\nThe value of the variable    a_ptr = %p\n", a_ptr);
  printf("\nThe value pointed to by      a_ptr = %d\n", *a_ptr);

  return 0;
}
