#include <stdio.h>
#include <string.h>

int main(){
	const char *mango[]={"test", "test02", "angel", "mochimango"};

	int cantidad_array = sizeof(mango) / sizeof(mango[0]);

	fprintf(stdout, "\xA\x9\x9 La cantidad de elementos en el array es: %d\xA", cantidad_array);

	for(int i=0; i <= cantidad_array; i++){
		int len = strlen(mango[i]);
		fprintf(stdout, "\xA\x90Logitud: %d ::: Palabra>> %s\n", len, mango[i]);
	}
	return 0;
}
