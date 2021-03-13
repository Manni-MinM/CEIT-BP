// BWOTSHEWCHB

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG false

struct Node {
	int val ;
	struct Node* next ;
} ;
typedef struct Node node ;

node** head ;

void init() {
	head = (node**)malloc(sizeof(node*)) ;
	return ;
}

void append(int val) {
	node* new = (node*)malloc(sizeof(node)) ;
	new->val = val ;
	new->next = *head ;
	*head = new ;
	return ;
}
void traverse() {
	node* cur = *head ;
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
		if ( n == 0 )
			break ;
		append(n) ;
	}
	traverse() ;
	return 0 ;
}
