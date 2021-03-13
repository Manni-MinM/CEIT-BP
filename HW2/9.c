// BWOTSHECHB

#include <stdio.h>

#define MAXN (int)1e6

int arr[MAXN] ;

int main() {
	int n ;
	scanf("%d" , &n) ;
	// get array consisting of 0s and 1s , 0 for correct files and 1 for broken files
	for ( int i = 1 ; i <= n ; i ++ )
		scanf("%d" , &arr[i]) ;
	int l = 1 , r = n , mid ;
	while ( l < r ) {
		mid = (l + r) / 2 ;
		if ( arr[mid] )
			r = mid ;
		else
			l = mid + 1 ;
	}
	printf("index of first broken file is %d\n" , l) ;

}
