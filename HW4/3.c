// BWOTSHEWCHB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 300069

char str[11][MAXN] ;

void normalize(char str[]) {
	for ( int i = 0 ; i < strlen(str) ; i ++ )
		if ( str[i] >= 'A' && str[i] <= 'Z' )
			str[i] += 32 ;
	return ;
}
void solve(char str[]) {
	int len = strlen(str) ;
	for ( int i = 0 ; i < len ; i ++ ) {
		if ( str[i] >= 'a' && str[i] <= 'z' )
			if ( i == 0 )
				str[i] -= 32 ;
			else if ( str[i - 1] == ' ' )
				str[i] -= 32 ;
	}
	return ;
}

int main() {
	int n ;
	scanf("%d\n" , &n) ;
	for ( int i = 1 ; i <= n ; i ++ )
		gets(str[i]) , normalize(str[i]) , solve(str[i]) ;
	for ( int i = 1 ; i <= n ; i ++ )
		printf("%s\n" , str[i]) ;
	return 0 ;
}
