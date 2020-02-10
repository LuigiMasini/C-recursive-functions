#include <stdio.h>

int mcd(int *a, int *b){
	int c;
	if(*b > *a){ //swap w/out aux
		*b+=*a;
		*a=*b-*a;
		*b-=*a;
	}
	c= *a % *b;
	if(c)
		return mcd(b, &c);
	else
		return *b;
}


void main(){
	int a=12, b=36;
	printf("l'mcd di %d e %d e' %d\n", a, b, mcd(&a, &b));
}