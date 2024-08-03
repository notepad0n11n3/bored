#include <regex.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

regex_t regex;
int reti;
char msgbuf[100];


int main(int argc, char const *argv[]){

    fgets( msgbuf, 100, stdin); strtok(msgbuf, "\n");
    reti = regcomp(&regex, "^[0-9]+/open", REG_EXTENDED);

    if (reti){
      fprintf(stderr, "Could not compile regex\n");
      exit(1);
    }

    printf("\n\t->%s\n", msgbuf);
    reti = regexec(&regex, msgbuf, 0, NULL, 0);

    if(!reti){
      puts("\t\tMatch");
      printf("\n\t=>%s\n", msgbuf);
    }else if(reti == REG_NOMATCH){
      puts("No match");
    }else {
      regerror(reti, &regex, msgbuf, sizeof(msgbuf) );
      fprintf(stderr, "Regex match failed: %s\n", msgbuf);
      exit(1);
    }

    regfree(&regex);


  return 0;
}
