// BWOTSHEWCHB

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXN 300069

char str[MAXN] , key[MAXN] ;

int main() {
	int n ;
	scanf("%d\n" , &n) ;
	int cnt_str = 0 , cnt_key = 0 ;
	gets(str) , gets(key) ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cnt_str += (str[i] == '1' ? 1 : 0) ;
		cnt_key += (key[i] == '1' ? 1 : 0) ;
	}
	for ( int i = 0 ; i < n ; i ++ )
		if ( key[i] == '1' && str[i] == '1' )
			key[i] = '0' , str[i] = '0' ;
//	printf("%s %s\n" , str , key) ;
//	printf("%d %d\n" , cnt_str , cnt_key) ;
	int ans = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( key[i] == '1' ) {
			if ( i - 1 >= 0 && str[i - 1] == '1' )
				str[i - 1] = '0' , key[i] = '0' , ans ++ ;
			else if ( i + 1 <= n - 1 && str[i + 1] == '1' )
				str[i + 1] = '0' , key[i] = '0' , ans ++ ;
		}
	}
	cnt_str = 0 , cnt_key = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cnt_str += (str[i] == '1' ? 1 : 0) ;
		cnt_key += (key[i] == '1' ? 1 : 0) ;
	}
//	printf("%s %s\n" , str , key) ;
//	printf("%d %d\n" , cnt_str , cnt_key) ;
	if ( cnt_str > cnt_key )
		ans += cnt_str - cnt_key , ans += 2 * cnt_key ;
	else
		ans += cnt_key - cnt_str , ans += 2 * cnt_str ;
	printf("%d\n" , ans) ;
	return 0 ;
}
