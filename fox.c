#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

  fprintf(stdout, "\n\t\t FOX loading...\n");

  system("firefox >/dev/null 2>&1 &  ");

  fprintf(stdout, "\v\t\t fox CLOSING...\n");

  return 0;
}
