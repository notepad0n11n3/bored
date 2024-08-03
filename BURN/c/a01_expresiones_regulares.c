#include <stdio.h>
#include <regex.h>

int main(void){

  regex_t regex;
  int return_value;
  return_value = regcomp(&regex,"[:lower:]",0);
  
  if( return_value == 0 ){
    printf("\nRegular expresion compiled successfully\n");
  }else {
    printf("\nCompilation error.\n");
  }

  return 0;
}
