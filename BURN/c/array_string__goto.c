//   falta filtrar la entrada, si le introduces una cadena sumara a iterador_Goto, quiero filtrar </3
#include <stdio.h>
#include <stdlib.h>

int main(void){
  printf("jugando con goto <3\n");
  int iterador_Goto=0;

//const char *arreglo_strings[] = {"primero", "segundo", "tercero"};
//for(int i=0; i<3; i++){
//  fprintf(stderr, "\nPosicion del array %d: => %s", i, arreglo_strings[i]);
//}
//
  char *arreglo_strings[] = {"PREGOTO", "POSTGOTO"};
mango:
  if( iterador_Goto == 0){
    fprintf(stdout, "\n\tValor de iterador %s Goto: %d  <<===\n", arreglo_strings[0], iterador_Goto);
  }else{
    fprintf(stdout, "\n\tValor de iterador %s Goto: %d  <<===\n", arreglo_strings[1], iterador_Goto);
  }

  int user_numer;
  printf("\nIngrese 1 para usar el goto: => ");
  scanf("%d", &user_numer); getchar();

  if( user_numer == 1 ){
    fprintf(stdout, "\n\t Jugando con goto:\t goto mango;\n");
    iterador_Goto++;
    goto mango;
  }else {
    system("clear");
    fprintf(stdout, "\n\n\t\tSaliendo...!!!\n");
  }

  return 0;
}
