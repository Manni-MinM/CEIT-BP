// BWOTSHEWCHB

#include <stdio.h>

void foo(int n) {
	if ( n != 0 ) {
		int m = n % 10 ;
		printf("%d" , m) ;
		foo(n / 10) ;
	}
	return ;
}
int main() {
	int n ;
	scanf("%d" , &n) ;
	foo(n) ;
	printf("\n") ;
}
