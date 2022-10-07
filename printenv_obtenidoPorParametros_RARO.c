#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  // Es extra~o, el primer parametro es NULL, d[esde el segundo parametro empezamos a obtener linea por linea el output de ::: printenv   (variablesDeEntorno)  see... RARO...!!!

int main(int argc, char *argv[]){

  if( argc != 2 ){
    fprintf(stdout, "\n\tError... error...\n\n");
  }

  printf("\n\t argv[0]= %s  \nargv[1]= %s\n argv[2]= %s\n argv[3]= %s\n argv[4]= %s\n argv[5]= %s\n argv[6]= %s\n argv[7]= %s\n, argv[8]= %s\nargv[9]= %s\n argv[10]= %s\n argv[11]= %s\n argv[12]= %s\n, argv[13]= %s\nargv[14]= %s\n argv[15]= %s\n argv[16]= %s\n argv[17]= %s\n, argv[18]= %s\n argv[19]= %s\n, argv[20]= %s\nargv[21]= %s\n argv[22]= %s\n argv[23]= %s\n argv[24]= %s\n, argv[25]= %s\nargv[26]= %s\n argv[27]= %s\n argv[28]= %s\n argv[29]= %s\n", argv[0], argv[1], argv[2], argv[3], argv[4], argv[5],argv[6], argv[7], argv[8], argv[9], argv[10], argv[11],argv[12], argv[13], argv[14], argv[15], argv[16], argv[17],argv[18], argv[19], argv[20], argv[21], argv[22], argv[23],argv[24], argv[25], argv[26], argv[27], argv[28], argv[29]);

  if( strcmp(argv[3], "COLORTERM=truecolor")==0 ){
    fprintf(stdout, "\n\t\t COLORTERM=truecolor READYY  strcmp()==0 ..... argv[3]\n");
    fprintf(stderr, "\n\t\t ESTO ES UNA LOCURA, QUE TA PASANDO DOCTOR GARCIA?!\n");
  }else {
    fprintf(stdout, "\n direfente a 0     =! 0\n");
  }

  return 0;
}
