// BWOTSHEWCHB

#include <stdio.h>

#define MAXN 300069

long int fact[MAXN] ;

int main() {
	long int n , mod ;
	scanf("%ld%ld" , &n , &mod) ;
	fact[0] = 1 ;
	for ( int i = 1 ; i <= n + 1 ; i ++ )
		fact[i] = (fact[i - 1] * i) % mod ;
	printf("%ld\n" , fact[n + 1]) ;
	return 0 ;
}
