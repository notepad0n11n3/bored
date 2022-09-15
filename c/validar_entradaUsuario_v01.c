#include <stdio.h>

int main(int argc, char **argv){

  fprintf(stdout, "\n\t\t Filtrar que el input del usuario sea un numero\n");

  int user_data, retorno = -1;

  do{
    printf("\n\n\n Ingrese un entero: ");
    retorno = scanf("%d", &user_data);  // si consige un numero retorna 1, else retorna 0(0)
                                        //
    getchar();    // sin getchar(); por '\n' entramos en un blucle :u
               // SI INTRODUCIMOS UN STRING, VAMOS A RECOREER EL DO/WHILE POR CADA CARACTER HASTA LLEGA AL '\n'
               //       solucion  en la version 2 <3

  }while(retorno == 0);

  return 0;
}
