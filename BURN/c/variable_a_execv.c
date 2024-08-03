#include <stdio.h>
#include <unistd.h> // execv


int main(void){

  //char *argumentos[]={"/bin/ls", "-l" , NULL};

  char *mango[]={
    "/bin/ls",
    "-lah",
    NULL
  };
  execv("/bin/ls", mango);

  printf("\n TERMINO...!!!\n");


  return 0;
}
