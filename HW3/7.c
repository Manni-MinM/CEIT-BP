// BWOTSHECHB

#include <stdio.h>
#include <math.h>

int main() {
	int n , m , a ;
	scanf("%d%d%d" , &n , &m , &a) ;
	int ans = (int)ceil(1.0 * n / a) * (int)ceil(1.0 * m / a) ;
	printf("%d\n" , ans) ;
	return 0 ;
}
