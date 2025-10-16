#include <stdio.h>
#include <time.h>

int main(void){

  time_t begin_time, end_time;
  begin_time = time(NULL);

  int mango;
  printf("\nIngrese un entero: ");
  scanf("%d", &mango); getchar();

  end_time = time(NULL);
  fprintf(stderr, "\n\tEl entero es %d  Execution time: %.2f", mango, difftime(end_time, begin_time) );

  return 0;
}
