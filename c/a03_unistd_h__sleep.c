#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){

  fprintf(stdout, "\nPre Sleep\n");
  sleep(8);
  fprintf(stderr, "sleep necesita unistd.h ");
  return 0;
}
