#include <stdio.h>
int fat(int n){
	if (n == 0) //condizione di terminazione
		return 1;
	else
		return n*fat(n-1); //chiamata ricorsiva
}
void main(){
	printf("fattoriale di 5 e' %d",fat(5));
}