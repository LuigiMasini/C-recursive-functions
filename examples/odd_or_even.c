#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool pari(int);
bool dispari(int);

void main(){
	printf("5 %s e' pari, 4 %s e' pari\n", pari(5)? "" : "non", pari(4)? "" : "non");
}

bool pari( int n ){
	if( n == 0 )
		return true;
	else
		return dispari(abs(n)-1);
}
bool dispari( int n ){
	if( n == 0 )
		return false;
	else
		return pari(abs(n)-1);
}