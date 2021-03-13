// BWOTSHEWCHB

#include <stdio.h>
#include <stdlib.h>

#define MAXN 3069
#define INF (int)1e9

int arr[MAXN] ;

int main() {
	int n ;
	scanf("%d" , &n) ;
	for ( int i = 1 ; i <= n ; i ++ )
		scanf("%d" , &arr[i]) ;
	int indx = 0 , ans = INF ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		int cur = 0 ;
		for ( int j = 1 ; j <= n ; j ++ )
			cur += abs(i - j) * arr[j] ;
		if ( cur < ans )
			indx = i , ans = cur ;
	}
	printf("%d\n" , indx) ;
	return 0 ;
}
