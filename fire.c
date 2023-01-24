#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

  fprintf(stdout, "\n\t\t FIRE loading...\n");

  char *mango[]={"./fox.exe", NULL};
  execvp(mango[0],mango);

  fprintf(stderr, "\v\t\t fire ERROR... fire ERROR...\n");

  return 0;
}
