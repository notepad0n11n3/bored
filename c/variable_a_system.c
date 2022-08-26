#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

  int retorno = system("ls");

  printf("Resultado: %d\n", retorno);

  return EXIT_SUCCESS;
}
