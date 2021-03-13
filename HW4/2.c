// BWOTSHEWCHB

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXN 300069
#define MAXK 69

int n , len , flag , rand_seed ;
char number[MAXK] , arr[MAXN][MAXK] ;

void build_number(int seed) {
	for ( int i = 0 ; i < MAXK ; i ++ )
		number[i] = '\0' ;
	srand(seed) ;
	for ( int i = 0 ; i < len ; i ++ ) {
		int rand_number = rand() ;
		number[i] = (rand_number % 10) + '0' ;
	}
	rand_seed = rand() ;
	return ;
}

void end() {
	printf("1)Continue\n2)Increase numbers\n3)Increase digits\n4)End\n") ;
	int input ;
	scanf("%d" , &input) ;
	if ( input == 2 )
		n ++ ;
	else if ( input == 3 )
		len ++ ;
	else if ( input == 4 )
		flag = 1 ;
	return ;
}

void run() {
	srand(time(0)) ;
	rand_seed = rand() ;
	for ( int i = 0 ; i < n ; i ++ )
		build_number(rand_seed) , strcpy(arr[i] , number) ;
	for ( int i = 0 ; i < n ; i ++ )
		printf("%s " , arr[i]) ;
	printf("\n") ;
	int score = 0 ;
	char input[n] ;
	for ( int i = 0 ; i < n ; i ++ ) {
		scanf("%s" , input) ;
		if ( !strcmp(input , arr[i]) )
			printf("Correct :) :D\n") , score ++ ;
		else
			printf("Incorrect :( :P\n") ;
	}
	printf("%lf\n" , (double)score / (double)n) ;
	return ;
}

int main() {
	scanf("%d%d" , &n , &len) ;
	while ( true ) {
		flag = 0 ;
		for ( int i = 0 ; i < 5 ; i ++ )
			run() ;
		end() ;
		if ( flag )
			break ;
	}
	return 0 ;
}
