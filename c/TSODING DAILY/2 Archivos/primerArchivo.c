#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){

  fprintf(stdout, "\nArchivo principal\n");
  if(argc < 2){
    fprintf(stderr, "USAGE: ./lru <input.txt>\n");
    fprintf(stderr, "ERROR: input file is not provided\n");
    exit(1);
  }

  const char *input_file_path = argv[0];
  (void) input_file_path;
  system("./segundoArchivo.exe");

  fprintf(stdout, "\nArchivo principal\n");

  char user_data[88];
  fprintf(stdout, "\n\t\t(Archivo Principal) Ingrese el usuario: ");
  fgets(user_data, 88, stdin); strtok(user_data, "\n");

  fprintf(stdout, "\n\t\t <3 <3 <3 <3 %s <3 <3 <3 <3 \n", user_data);
  
  return 0;
}
