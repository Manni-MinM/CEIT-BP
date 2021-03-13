// BWOTSHEWCHB

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG false

struct node {
	int val ;
	struct node* prev ;
	struct node* next ;
} ;
typedef struct node NODE ;

NODE** head ;

void init() {
	head = (NODE**)malloc(sizeof(NODE*)) ;
	return ;
}

NODE* search(int val) {
	NODE* cur = *head ;
	while ( cur != NULL ) {
		if ( cur->val == val )
			return cur ;
		cur = cur->next ;
	}
	return NULL ;
}

void append(int val) {
	if ( search(val) != NULL )
		return ;
	NODE* new = (NODE*)malloc(sizeof(NODE)) ;
	new->val = val ;
	if ( *head != NULL ) {
		new->next = *head ;
		(*head)->prev = new ;
	}
	*head = new ;
	return ;
}

void delete(int val) {
	NODE* cur = search(val) ;
	if ( cur == *head )
		*head = cur->next ;
	if ( cur->prev != NULL )
		(cur->prev)->next = cur->next ;
	if ( cur->next != NULL )
		(cur->next)->prev = cur->prev ;
        free(cur) ;
	return ;
}

void traverse() {
	NODE* cur = *head ;
	while ( cur != NULL ) {
		printf("address : %x / val : %d / next %x / prev %x\n" , cur , cur->val , cur->next , cur->prev) ;
		cur = cur->next ;
	}
	printf("\n") ;
	return ;
}

int main() {
	init() ;
	return 0 ;
}
