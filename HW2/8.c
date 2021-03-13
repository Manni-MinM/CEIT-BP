// BWOTSHECHB

#include <stdio.h>
#include <math.h>

int check_prime(int x) {
	if ( x == 1 )
		return 0 ;
	for ( int i = 2 ; i <= sqrt(x) ; i ++ )
		if ( x % i == 0 )
			return 0 ;
	return 1 ;
}
int main() {
	int n , val = 1 ;
	scanf("%d" , &n) ;
	while ( val <= n ) {
		if ( check_prime(val) )
			printf("%d " , val) ;
		val = (val << 1) + 1 ;
	}	
	printf("\n") ;
}
