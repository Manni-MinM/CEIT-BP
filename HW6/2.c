// BWOTSHEWCHB 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG false

struct Node {
	int val ;
	int carry ;
	struct Node* next ;
} ;
typedef struct Node node ;

node** head1 ;
node** head2 ;
node** head_ans ;

void init() {
	head1 = (node**)malloc(sizeof(node*)) ;
	head2 = (node**)malloc(sizeof(node*)) ;
	head_ans = (node**)malloc(sizeof(node*)) ;
	return ;
}

void append(int val , int list) {
	node* new = (node*)malloc(sizeof(node)) ;
	new->val = val ;
	if ( list == 1 ) {
		new->next = *head1 ;
		*head1 = new ;
	}
	else if ( list == 2 ) {
		new->next = *head2 ;
		*head2 = new ;
	}
	else {
		new->next = *head_ans ;
		*head_ans = new ;
	}
	return ;
}
void add() {
	node* cur1 = *head1 ;
	node* cur2 = *head2 ;
	while ( cur1 != NULL || cur2 != NULL ) {
		if ( cur1 == NULL ) {
			if ( cur2->val + cur2->carry >= 10 )
				if ( cur2->next != NULL )
					cur2->next->carry ++ ;
			append((cur2->val + cur2->carry) % 10 , 3) ;
			cur2->carry = 0 ;
			cur2 = cur2->next ;
		}
		else if ( cur2 == NULL ) {
			if ( cur1->val + cur1->carry >= 10 )
				if ( cur1->next != NULL )
					cur1->next->carry ++ ;
			append((cur1->val + cur1->carry) % 10 , 3) ;
			cur1->carry = 0 ;
			cur1 = cur1->next ;
		}
		else {
			if ( cur1->val + cur2->val + cur2->carry >= 10 ) {
				if ( cur1->next != NULL )
					cur1->next->carry ++ ;
				if ( cur2->next != NULL )
					cur2->next->carry ++ ;
			}
			append((cur1->val + cur2->val + cur2->carry) % 10 , 3) ;
			cur1->carry = 0 , cur2->carry = 0 ;
			cur1 = cur1->next ;
			cur2 = cur2->next ;
		}
	}
	return ;
}

void traverse() {
	if ( (*head_ans)->val != 0 )
		printf("%d " , (*head_ans)->val) ;
	node* cur = (*head_ans)->next ;
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
	append(0 , 1) ;
	while ( true ) {
		scanf("%d" , &n) ;
		if ( n == -1 )
			break ;
		append(n , 1) ;
	}
	append(0 , 2) ;
	while ( true ) {
		scanf("%d" , &n) ;
		if ( n == -1 )
			break ;
		append(n , 2) ;
	}
	add() ;
	traverse() ;
	return 0 ;
}
