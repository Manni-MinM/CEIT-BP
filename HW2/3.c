// BWOTSHEWCHB

#include <stdio.h>

int main() {
	int p , d ;
	scanf("%d %d" , &p , &d) ;
	int it = 1 ;
	while ( (it * d) % p > (p / 2) )
		it ++ ;
	printf("%d\n" , it * d) ;
}
