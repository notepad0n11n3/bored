#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

  // int   argc    es el numero de argumentos pasados al script al momento de ejecutar
  // char  argv[]  es la cadena de los argumentso pasados

  if( argc != 2){
    printf("\n\t[!] Uso:\t %s  <user_name> ...!!!\n\n", argv[0] );
    fprintf(stderr, "\n\t[!] Uso:\t %s  <user_name> ...!!!\n\n", argv[0] );
  }

  if( strcmp(argv[1], "x89p") == 0 ){
    printf("\n\tWelcome back x89p\n");
    fprintf(stderr, "\n\tWelcome back x89p\n");
  }

  return 0;
}
