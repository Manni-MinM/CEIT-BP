// BWOTSHEWCHB

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double PI = 3.14159265 ;

int main() {
	double a , b , c , temp , ans;
	a = -5.0 , b = PI/6 , c = PI/5 ;
	ans = exp((double)log2(abs(a)) + sin(b) + tan(c)) ;
	printf("%.2lf\n" , ans) ;

	a = 3.5 , b = 2.0 , c = 9.0 ;
	ans = a * (b + a) * b * log(c) ;
	printf("%.2lf\n" , ans) ;
	
	a = 5.0 , b = 6.0 ;
	ans = pow(pow(a , -0.3) + 2.0 * pow(b , -2.3) , 4.5) ;
	printf("%.2lf\n" , ans) ;
}
