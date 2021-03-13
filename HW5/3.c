//BWOTSHEWCHB

#include <stdio.h>
#include <string.h>

#define MAXN 3069

char key[MAXN] , str[MAXN] ;

int main() {
	int n , ans = 0 ;
	scanf("%s" , key) ;
	scanf("%d" , &n) ;
	for ( int i = 0 ; i < n ; i ++ ) {
		scanf("%s" , str) ;
		char* it = key ;
		for ( int j = 0 ; j < strlen(str) ; j ++ )
			if ( str[j] == *it )
				it ++ ;
		if ( *it == '\0' )
			ans ++ ;
	}
	printf("%d\n" , ans) ;
	return 0 ;
}
