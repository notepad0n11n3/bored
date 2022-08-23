#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
  
  printf("\nID de proceso: %ld \n", (long)getpid() );
  printf("\nID de proceso padre: %ld \n", (long)getppid() );
  printf("\nID de usuario propietario: %ld \n", (long)getuid() );

  return 0;
}
