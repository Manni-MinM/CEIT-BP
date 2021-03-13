// BWOTSHEWCHB

#include <stdio.h>

int votes[201] , results[201] ;

int main() {
	int n ;
	scanf("%d" , &n) ;
	for ( int i = 1 ; i <= n ; i ++ )
		scanf("%d" , &votes[i]) ;
	for ( int i = 1 ; i <= n ; i ++ )
		results[votes[i]] ++ ;
	for ( int i = 1 ; i <= 200 ; i ++ )
		printf("%d " , results[i]) ;
	printf("\n") ;
}
