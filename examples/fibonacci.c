//src: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

#include <stdio.h>

/* Fibonacci with divide & conquer

Time Complexity: T(n) = T(n-1) + T(n-2) => 2T(n-2) => 2^(n/2) which is exponential (bad).
We can observe that this implementation does a lot of repeated work (see the following recursion tree).
So this is a bad implementation for nth Fibonacci number.

                       fib(5)
                     /                \
               fib(4)                fib(3)   
             /        \              /       \ 
         fib(3)      fib(2)         fib(2)   fib(1)
        /    \       /    \        /      \
  fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
  /     \
fib(1) fib(0)

*/

//avoid repetition by storing values, Time Complexity:O(n)
int fibonacciDC(int n) {
	if(n == 0){
		return 0;
	} else if(n == 1) {
		return 1;
	} else {
		return (fibonacciDC(n-1) + fibonacciDC(n-2));
	}
}

int fibonacciDP(int n) { 
	/* Declare an array to store Fibonacci numbers. */
	int f[n+2];   // 1 extra to handle case, n = 0 
	int i; 
	
	/* 0th and 1st number of the series are 0 and 1*/
	f[0] = 0; 
	f[1] = 1; 
	
	for (i = 2; i <= n; i++) 
	{ 
		/* Add the previous 2 numbers in the series 
		 *       and store it */
		f[i] = f[i-1] + f[i-2]; 
	} 
	
	return f[n]; 
} 

//Optimized, save only last 2 values
int fibonacciOP(int n) {
	int a = 0, b = 1, c, i; 
	if( n == 0) 
		return a; 
	for (i = 2; i <= n; i++) 
	{ 
		c = a + b; 
		a = b; 
		b = c; 
	} 
	return b; 
} 

int main() {
	int n = 5;
	printf("Fibonacci of %d: " , n);
	for(int i=0;i<n;i++) {
		printf("%d ",fibonacciOP(i));
	}
}