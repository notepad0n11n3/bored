#include <stdio.h>

int main(){
	int edad = 20;
	const char *mensaje = (edad >= 18)?"Mayor de edad":"Menor de edad";
	fprintf(stdout, "\xA\x9 %s \xA", mensaje);
	return 0;
}
