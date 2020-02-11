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

int mcd2(int t, int k){
	if(k==0)
		return t;
	if(k>t)
		return mcd2(k, t);
	return mcd2(k, t%k);
}

void main(){
	int a=12, b=34;
	printf("l'mcd di %d e %d e' %d\n", a, b, mcd2(a, b));
}