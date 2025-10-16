#include <stdio.h>

// El operador ternario evalua de izquierda a derecha... <3 <3 <3 

int main(){
	int nota = 33;
	const char *mensaje = (nota >= 90) ? "Excelente" :
												(nota >= 70) ? "Bien" :
																			"Reprobado";

	fprintf(stdout, "\xA\xA\x9 %s \xA", mensaje);

	return 0;
}
