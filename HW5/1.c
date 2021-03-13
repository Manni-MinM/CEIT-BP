// BWOTSHEWCHB

#include <stdio.h>

#define MAXN 300069

int mapin[MAXN] , mapout[MAXN] ;
char str[MAXN] ;

void add(int hour , int minute , char sign) {
	if ( sign == '+' )
		mapin[hour * 60 + minute] ++ ;
	else
		mapout[hour * 60 + minute] ++ ;
	return ;
}

int main() {
	int n ;
	scanf("%d" , &n) ;
	for ( int i = 0 ; i < 2 * n ; i ++ ) {
		char sign ;
		int hour , minute ;
		scanf("%s %d:%d %c" , str , &hour , &minute , &sign) ;
		add(hour , minute , sign) ;
	}
	int cur = 0 , ans = 0 , index = 0 ;
	for ( int i = 0 ; i < MAXN ; i ++ ) {
		cur += mapin[i] ;
		if ( cur > ans )
			index = i , ans = cur ;
		cur -= mapout[i] ;
	}
	printf("%.2d:%.2d\n" , index / 60 , index % 60) ;
	return 0 ;
}
