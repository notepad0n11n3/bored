#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	char command[256];
	char url[256]="https://www.0xword.com";
	char url2[256]="https://www.hackthebox.com";

	snprintf(command, sizeof(command), "firefox %s %s &", url ,url2);
	
	system(command);

	return 0;
}
