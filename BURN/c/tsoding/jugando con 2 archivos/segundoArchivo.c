#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

  const char *little_array[]={
    "jugando",
    "un",
    "rato",
    "con",
    "arrays",
    " <3 <3 <3"
  };
  fprintf(stdout, "\nJugando con CMD desde otro archivo UmU <3 <3 <3\n");

  for(int i=0; i<6; i++){
    fprintf(stdout, "Posici[on del array %d => %s\n", i, little_array[i]);
  }; printf("\n");

  system("ls -lah");

  char user_data[88];
  printf("\n\t\t(segundoArchivo) Ingrese el Usuario: ");
  fgets(user_data, 88, stdin); strtok(user_data, "\n");

  fprintf(stdout, "\n\n\t\t <3 <3 <3 %s <3 <3 <3 \n", user_data);
  return 0;
}
