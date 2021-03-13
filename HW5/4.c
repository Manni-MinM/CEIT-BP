// BWOTSHEWCHB

#include <stdio.h>
#include <string.h>

#define MAXN 300069

char str[MAXN] , ans[MAXN] ;

int MOD(int val , int mod) {
	if ( val < 0 )
		val += mod ;
	else
		val %= mod ;
	return val ;
}

char* decode(char* msg , int key) {
	char* it = ans ;
	for ( int i = 0 ; i < strlen(str) ; i ++ ) {
		if ( msg[i] >= 'a' && msg[i] <= 'z' )
			*it = MOD(msg[i] - 'a' + key , 26) + 'a' ;
		else if ( msg[i] >= 'A' && msg[i] <= 'Z' ) 
			*it = MOD(msg[i] - 'A' + key , 26) + 'A' ;
		else
			*it = msg[i] ;
		it ++ ;
	}
	return ans ;
}

int main() {
	gets(str) ;
	int diff = 'S' - str[0] ;
	puts(decode(str , diff)) ;
	return 0 ;
}
