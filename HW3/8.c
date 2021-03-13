// BWOTSHECHB

#include <stdio.h>

int main() {
	int h1 , m1 , s1 , h2 , m2 , s2 , h_ans , m_ans , s_ans ;
	scanf("%d:%d:%d" , &h1 , &m1 , &s1) ;
	scanf("%d:%d:%d" , &h2 , &m2 , &s2) ;
	int val1 = h1 * 3600 + m1 * 60 + s1 , val2 = h2 * 3600 + m2 * 60 + s2 , ans ;
	if ( val2 > val1 )
		ans = (24 * 3600 - val2) + val1 ;
	else
		ans = val1 - val2 ;
	h_ans = ans / 3600 , ans %= 3600 ;
	m_ans = ans / 60 , ans %= 60 ;
	s_ans = ans ;
	printf("%.2d:%.2d:%.2d\n" , h_ans , m_ans , s_ans) ;
	return 0 ;
}
