#include <stdio.h>
#include <time.h>

#include <unistd.h>  // sleep(secondHere);  segundos

int main(int argc, char *argv[]){

  time_t begin_time, end_time;
  begin_time = time(NULL);

  fprintf(stdout, "\nPre-sleep_test\n");
  sleep(10);
  fprintf(stderr, "\nPost-sleep_test\n");

  end_time = time(NULL);
  printf("\n\t\t Execution time: %.2f\n", difftime(end_time, begin_time) );
  return 0;
}
