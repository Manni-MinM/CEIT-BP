// BWOTSHEWCHB

#include <stdio.h>
#include <string.h>

#define MAXN 169

char str[MAXN] ;

int main() {
	scanf("%s" , str) ;
	for ( int i = 0 ; i < strlen(str) ; i ++ ) {
		printf("%c: " , str[i]) ;
		for ( int j = 0 ; j < (int)(str[i] - '0') ; j ++ )
			printf("%c" , str[i]) ;
		printf("\n\n") ;
	}
	return 0 ;
}
