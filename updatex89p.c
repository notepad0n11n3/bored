#include <stdio.h>
#include <stdlib.h>


int main(){
  system("echo 'passwordHere' | sudo -S apt update && sudo apt-get full-upgrade -y && sudo updatedb");
}
