// BWOTSHEWCHB

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	int val ;
	struct Node* next ;
} ;
typedef struct Node node ;

node** head[3] ;

void init() {
	for ( int i = 0 ; i < 3 ; i ++ )
		head[i] = (node**)malloc(sizeof(node*)) ;
	return ;
}

void append(int val , int list) {
	node* new = (node*)malloc(sizeof(node)) ;
	new->val = val ;
	new->next = *head[list] ;
	*head[list] = new ;
	return ;
}

void sort(int list1 , int list2) {
	node* cur1 = *head[list1] ;
	node* cur2 = *head[list2] ;
	while ( cur1 != NULL || cur2 != NULL ) {
		if ( cur1 == NULL ) {
			append(cur2->val , 2) ;
			cur2 = cur2->next ;
		}
		else if ( cur2 == NULL ) {
			append(cur1->val , 2) ;
			cur1 = cur1->next ;
		}
		else {
			if ( cur1->val < cur2->val ) {
				append(cur1->val , 2) ;
				cur1 = cur1->next ;
			}
			else {
				append(cur2->val , 2) ;
				cur2 = cur2->next ;
			}
		}
	}
	return ;
}

void traverse() {
	node* cur = *head[2] ;
	while ( cur != NULL ) {
		printf("%d " , cur->val) ;
		cur = cur->next ;
	}
	printf("\n") ;
	return ;
}

int main() {
	int n ;
	init() ;
	while ( true ) {
		scanf("%d" , &n) ;
		if ( n == -1 )
			break ;
		append(n , 0) ;
	}
	while ( true ) {
		scanf("%d" , &n) ;
		if ( n == -1 )
			break ;
		append(n , 1) ;
	}
	sort(0 , 1) ;
	traverse() ;
	return 0 ;
}
