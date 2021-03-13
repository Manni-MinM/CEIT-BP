// BWOTSHECHB

#include <stdio.h>
#include <math.h>

int get(int l1 , int r1 , int l2 , int r2) {
	if ( r1 <= l2 )
		return 0 ;
	return fmin(r1 , r2) - fmax(l1 , l2) ;
}

int main() {
	int x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 ;
	scanf("%d%d%d%d%d%d%d%d" , &x1 , &y1 , &x2 , &y2 , &x3 , &y3 , &x4 , &y4) ;
	printf("%d\n" , get(x1 , x2 , x3 , x4) * get(y1 , y2 , y3 , y4)) ;
	return 0 ;
}
