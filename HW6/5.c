// BWOTSHEWCHB

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	int n ;
	int* arr = (int*)malloc(sizeof(int)) ;
	int* subarr = (int*)malloc(sizeof(int)) ;
	int* newarr = (int*)malloc(sizeof(int)) ;
	int it_arr = 0 ;
	while ( true ) {
		scanf("%d" , &n) ;
		if ( n == -1 )
			break ;
		arr[it_arr ++] = n ;
		arr = realloc(arr , sizeof(int) * (it_arr + 1)) ;
	}
	int it_subarr = 0 ;
	while ( true ) {
		scanf("%d" , &n) ;
		if ( n == -1 )
			break ;
		subarr[it_subarr ++] = n ;
		subarr = (int*)realloc(subarr , sizeof(int) * (it_subarr + 1)) ;
	}
	int it_newarr = 0 ;
	while ( true ) {
		scanf("%d" , &n) ;
		if ( n == -1 )
			break ; 
		newarr[it_newarr ++] = n ;
		newarr = (int*)realloc(newarr , sizeof(int) * (it_newarr + 1)) ;
	}
	int L , R ;
	for ( int i = 0 ; i < it_arr ; i ++ ) {
		int flag = 1 ; 
		L = i , R = i + it_subarr - 1 ;
		for ( int j = 0 ; j < it_subarr ; j ++ ) {
			if ( arr[i + j] != subarr[j] )
				flag = 0 ;
		}
		if ( flag )
			break ;
	}
	int it_ans = it_arr - it_subarr + it_newarr ;
	int* ans = (int*)malloc(sizeof(int) * (it_ans)) ;
	for ( int i = 0 ; i < L ; i ++ )
		ans[i] = arr[i] ;
	for ( int i = L ; i < L + it_newarr ; i ++ )
		ans[i] = newarr[i - L] ;
	for ( int i = L + it_newarr , j = R + 1 ; i < it_ans ; i ++ , j ++ )
		ans[i] = arr[j] ;
	for ( int i = 0 ; i < it_ans ; i ++ )
		printf("%d " , ans[i]) ;
	printf("\n") ;
	return 0 ;
}
