// BWOTSHECHB

#include <stdio.h>

int main() {
	double val , ans = 0 ;
	int len ;
	scanf("%d%lf" , &len , &val) ;
	ans = (len * 0.94 * val) + (len / 12) * (12 * (val / 6.0)) - (len / 6) * (val / 5.0) ;
	printf("%.2lf\n" , ans) ;
	return 0 ;
}
