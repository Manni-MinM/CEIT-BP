// BWOTSHEWCHB

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 13

int mat[MAXN][MAXN] ;

long int det(int mat[MAXN][MAXN] , int n) {
	long int ans = 0 ;
	if ( n == 1 )
		return (long int)mat[0][0] ;
	for ( int iter = 0 ; iter < n ; iter ++ ) {
		int it = 0 , cur[MAXN][MAXN] ;
		for ( int i = 1 ; i < n ; i ++ ) {
			int jt = 0 ;
			for ( int j = 0 ; j < n ; j ++ )
				if ( j != iter )
					cur[it][jt ++] = mat[i][j] ;
			it ++ ;
		}
		ans += (long int)pow(-1 , (iter & 1)) * (long int)mat[0][iter] * det(cur , n - 1) ;
	}
	return ans ;
}

int main() {
	int n ;
	scanf("%d" , &n) ;
	for ( int i = 0 ; i < n ; i ++ )
		for ( int j = 0 ; j < n ; j ++ )
			scanf("%d" , &mat[i][j]) ;
	printf("%ld\n" , det(mat , n)) ;
	return 0 ;
}
