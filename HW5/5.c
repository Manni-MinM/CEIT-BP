// BWOTSHEWCHB

#include <stdio.h>

#define MAXN 3069

int len , carry , arr[MAXN] , temp[MAXN] ;

void build() {
	int it = 0 ;
	for ( int i = 0 ; i < len ; i ++ )
		if ( arr[i] != -1 )
			temp[it ++] = arr[i] ;
	len = it ;
	for ( int i = 0 ; i < len ; i ++ )
		arr[i] = temp[i] ;
	return ;
}
void kill(int k) {
	for ( int i = 0 ; i < len ; i ++ )
		if ( (i + carry) % (k + 1) == 0 )
			arr[i] = -1 ;
	carry += len % (k + 1) ;
	return ;
}

int main() {
	int n , k ;
	scanf("%d%d" , &n , &k) ;
	len = n ;
	for ( int i = 0 ; i < n ; i ++ )
		arr[i] = i ;
	while ( len > 1 )
		kill(k) , build() ;
	printf("%d\n" , arr[0]) ;
	return 0 ;
}
