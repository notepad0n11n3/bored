#include <stdio.h>

int main(void){

  int altura;

  fprintf(stdout, "\nIngrese la altura para la piramide: ");
  scanf("%d", &altura); getchar();

  for(int i=1; i<=altura; i++){

    for(int espacios=1; espacios<=altura - i; espacios++){
      printf(" ");
    }

    for(int asteriscos=1; asteriscos<=2*i-1; asteriscos++){
      printf("*");
    }
    printf("\n");
  }


  return 0;
}


