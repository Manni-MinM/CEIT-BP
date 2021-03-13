// BWOTSHEWCHB

#include <stdio.h>
#include <stdlib.h>

#define MAXN 3069
#define INF (int)1e9

int arr[MAXN] , brr[MAXN] ;

int* intersection(int* a , int size_a , int* b , int size_b , int* size_result) {
	for ( int i = 0 ; i < size_a ; i ++ )
		for ( int j = 0 ; j < size_b ; j ++ )
			if ( a[i] == b[j] )
				*size_result += 1 ;
	int it = 0 , arr_res[*size_result] ;
	int* res = arr_res ;
	for ( int i = 0 ; i < size_a ; i ++ ) {
		int flag = 0 ;
		for ( int j = 0 ; j < size_b ; j ++ )
			if ( a[i] == b[j] )
				flag = 1 ;
		int* ptr = (res + it) ;
		if ( flag )
			*ptr = a[i] , it ++ ;
	}
	return res ;
}

int main() {
	int n , m ;
	scanf("%d" , &n) ;
	scanf("%d" , &m) ;
	for ( int i = 0 ; i < n ; i ++ )
		scanf("%d" , &arr[i]) ;
	for ( int i = 0 ; i < m ; i ++ )
		scanf("%d" , &brr[i]) ;
	int size_res = 0 ;
	int* intersect = intersection(arr , n , brr , m , &size_res) ;
	int it = 0 , cur[m - size_res] ;
	for ( int i = 0 ; i < m ; i ++ ) {
		int flag = 0 ;
		for ( int j = 0 ; j < size_res ; j ++ )
			if ( brr[i] == *(intersect + j) )
				flag = 1 ;
		if ( !flag )
			cur[it] = brr[i] , it ++ ;
	}
	for ( int i = 0 ; i < n ; i ++ )
		printf("%d " , arr[i]) ;
	for ( int i = 0 ; i < m - size_res ; i ++ )
		printf("%d " , cur[i]) ;
	printf("\n") ;
	return 0 ;
}
