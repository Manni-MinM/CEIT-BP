// BWOTSHECHB

#include <stdio.h>
#include <math.h>

const double PI = 3.141592 ;

int main() {
	double l1 , l2 , theta , theta_max ;
	scanf("%lf%lf%lf%lf" , &l1 , &l2 , &theta , &theta_max) ;
	if ( theta > theta_max )
		printf("Theta is bigger than theta max!\n") ;
	else {
		double ans = (l1 * l1) + (l2 * l2) - 2.0 * (l1 * l2) * cos(theta) ;
		ans = sqrt(ans) ;
		printf("%.2lf\n" , ans) ;
	}
	return 0 ;
}
