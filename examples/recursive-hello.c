#include <stdio.h>

void hello(int n)
{
	if (n == 0) return;
	
	printf("\n");
	hello(n - 1);
}

void main()
{
	hello(1000000);
}