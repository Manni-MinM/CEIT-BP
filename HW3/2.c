// BWOTSHECHB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int x , point_BAV , point_BOX ;
	scanf("%d" , &x) ;
	srand(time(0)) ;
	int prob = rand() % 100 ;
	if ( prob < x )
		point_BAV = rand() % 39 + 1 , point_BOX = rand() % point_BAV ;
	else	
		point_BOX = rand() % 39 + 1 , point_BAV = rand() % point_BOX ;
	printf("Barvard%d - Boxford%d\n" , point_BAV , point_BOX) ;
	return 0 ;
}
