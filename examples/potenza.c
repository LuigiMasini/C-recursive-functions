#include <stdio.h>

int pot(int base, int esp){
	if (esp == 0)
		return 1;
	else
		return base * pot(base, esp-1);
}

void main(){
	printf("la potenza di 5^3 e' %d", pot(5,3));
}