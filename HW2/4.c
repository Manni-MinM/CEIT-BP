// BWOTSHEWCHB

#include <stdio.h>
#include <math.h>

int main() {
	int n , ans = 0 ;
	scanf("%d" , &n) ;
	for ( int i = 2 ; i <= n ; i ++ ) {
		int flag = 0 ;
		for ( int j = 2 ; j <= sqrt(i) ; j ++ )
			if ( i % j == 0 )
				flag = 1 ;
		if ( !flag )
			ans ++ ;
	}
	printf("%d\n" , ans) ;
}
