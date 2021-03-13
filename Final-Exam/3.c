// BWOTSHEWCHB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 3069
#define INF (int)1e9

struct count{
	char word[20] ;
	int cnt ;
} output[MAXN] ;

int frequency(int rows , int len , char strings[rows][len] , struct count result[]) {
	int size_result = 0 ;
	for ( int i = 0 ; i < rows ; i ++ ) {
		char* token = strtok(strings[i] , " ") ;
		while ( token != NULL ) {
			int indx = -1 ;
			for ( int j = 0 ; j < size_result ; j ++ )
				if ( !strcmp(token , result[j].word) )
					indx = j ;
			if ( indx == -1 ) {
				strcpy(result[size_result].word , token) , result[size_result].cnt = 1 ;
				size_result ++ ;
			}
			else
				result[indx].cnt ++ ;
			token = strtok(NULL , " ") ;
		}
	}
	return size_result ;
}

int main() {
	int rows , len ;
	scanf("%d%d" , &rows , &len) , getchar() ;
	char input[rows][len] ;
	for ( int i = 0 ; i < rows ; i ++ )
		gets(input[i]) ;
	int n = frequency(rows , len , input , output) ;
	for ( int i = 0 ; i < n ; i ++ )
		printf("%s %d\n" , output[i].word , output[i].cnt) ;
	return 0 ;
}
