// BWOTSHECHB

#include <stdio.h>

int main() {
	int n ;
	scanf("%d" , &n) ;
	for ( int i = 1 ; i <= n ; i ++ )
		for ( int j = 1 ; j <= i ; j ++ ) {
			int k = n - (i + j) ;
			if ( k <= j && (i + j) > k && (i + k) > j && (j + k) > i )
				printf("(%d,%d,%d)\n" , k , j , i) ;
		}
}
