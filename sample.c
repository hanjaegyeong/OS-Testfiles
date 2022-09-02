#include <stdio.h>
int factorial(int n){
	return (n <= 1 ? 1 : n * factorial(n-1));
}
int main(void){
	int n = 0;
	scanf("%d", &n);
	printf("factorial(%d) = %d\n", n, factorial(n));
	return 0;
}
