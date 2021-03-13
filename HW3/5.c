// BWOTSHEWCHB

#include <stdio.h>
#include <math.h>

int main() {
	int x1 , y1 , x2 , y2 , x3 , y3 ; 
	double midX , midY ;
	scanf("%d%d%d%d%d%d" , &x1 , &y1 , &x2 , &y2 , &x3 , &y3) ;
	midX = (x1 + x3) / 2.0 , midY = (y1 + y3) / 2.0 ;
	double dx1 = fabs(midX - x1) , dx2 = fabs(midX - x2) , dy1 = fabs(midY - y1) , dy2 = fabs(midY - y2) ;
//	printf("%lf %lf // %lf %lf\n" , fabs(midX - x1) , fabs(midX - x2) , fabs(midY - y1) , fabs(midY - y2)) ;
	if ( dx1 * dx1 + dy1 * dy1 == dx2 * dx2 + dy2 * dy2 )
		printf("%d %d\n" , x1 + x3 - x2 , y1 + y3 - y2) ;
	else
		printf("Not Possible\n") ;
}
