// BWOTSHECHB

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std ;

int main() {
	int x , point_BAV , point_BOX ;
	int cnt_BAV = 0 , cnt_BOX = 0 ;
	cin >> x ;
	for ( int i = 1 ; i <= 100 ; i ++ ) {
		srand(time(0)) ;
		int prob = rand() % 100 ;
		if ( prob < x )
			point_BAV = rand() % 39 + 1 , point_BOX = rand() % point_BAV ;
		else	
			point_BOX = rand() % 39 + 1 , point_BAV = rand() % point_BOX ;
		if ( point_BAV > point_BOX )
			cnt_BAV ++ ;
		else
			cnt_BOX ++ ;
		cout << point_BAV << " " << point_BOX << "\n" ;
		sleep(1) ;
	}
	printf("BAV : %d , BOX : %d\n" , cnt_BAV , cnt_BOX) ;
	return 0 ;
}
