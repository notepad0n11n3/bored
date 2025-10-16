#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
                    // ejecuta con  ::: time ./a.out        para testear el tiempo  <3 <3 <3
int hunter();

int main(void){

  time_t begin_time, end_time;
  begin_time = time(NULL);
  int mango=-1; printf("\n\t\t\t Valor de mango=> %d", mango);

  mango = hunter(); printf("\n\t\t\tMango valor => %d", mango);

  // Solo para hacer tiempo, necesito testear el time.h 
  char user_extra[88]; printf("\nIngrese un string: "); fgets(user_extra, 88, stdin); strtok(user_extra, "\n");

  if( mango == 0 ){
    printf("\n\t\t Salvados por la campana <3 <3 <3 \n");
    end_time = time(NULL);
    printf("\n\t rm *.txt  -> execution time %.2f", difftime(end_time, begin_time) );
    return 0;
  }

  end_time = time(NULL);
  system("rm *.txt"); // quiero evitar esto con returnFunciton0 <=!
  printf("\n\t rm *.txt  -> execution time %.2f", difftime(end_time, begin_time) );
  return 0;
}

int hunter(){

  printf("\n\t\t I'm the last remaning light... <3 \n");
  return 0;
}
