// BWOTSHEWCHB

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 300
#define DEBUG false

typedef struct {
	int ID ;
	char Phone[MAXN] ;
} Student ;

struct node {
	Student student ;
	struct node* prev ;
	struct node* next ;
} ;
typedef struct node NODE ;

NODE** head ;
NODE** tail ;

void init() {
	head = (NODE**)malloc(sizeof(NODE*)) ;
	tail = (NODE**)malloc(sizeof(NODE*)) ;
	return ;
}

NODE* search(int ID) {
	NODE* cur = *head ;
	while ( cur != NULL ) {
		if ( cur->student.ID == ID )
			return cur ;
		cur = cur->next ;
	}
	return NULL ;
}

void append(Student User) {
	if ( search(User.ID) != NULL )
		return ;
	NODE* new = (NODE*)malloc(sizeof(NODE)) ;
	new->student = User ;
	if ( *head == NULL )
		*tail = new ;	
	if ( *head != NULL ) {
		new->next = *head ;
		(*head)->prev = new ;
	}
	*head = new ;
	return ;
}

void delete(int ID) {
	NODE* cur = search(ID) ;
	if ( cur == NULL ) {
		printf("%d does not exist\n" , ID) ;
		return ;
	}
	if ( cur == *head )
		*head = cur->next ;
	if ( cur == *tail )
		*tail = cur->prev ;
	if ( cur->prev != NULL )
		(cur->prev)->next = cur->next ;
	if ( cur->next != NULL )
		(cur->next)->prev = cur->prev ;
	free(cur) ;
	printf("%d has been removed\n" , ID) ;
	return ;
}

void print(NODE* Entity) {
	if ( Entity != NULL )
		printf("No: %d\nPhone: %s\n" , Entity->student.ID , Entity->student.Phone) ;
	return ;
}

void traverse() {
	int it = 1 ;
	NODE* cur = *tail ;
	#if DEBUG
		printf("head points to : %x / tail points to : %x\n" , *head , *tail) ;
	#endif
	if ( *head == NULL && *tail == NULL )
		return ;
	while ( true ) {
		printf("%d)\n" , it ++) ;
		print(cur) ;
		if ( cur == *head )
			break ;
		cur = cur->prev ;
	}
	return ;
}

int main() {
	init() ;
	while ( true ) {
		int condition ;
		printf("1) Add\n2) Remove\n3) List\n4) Quit\n") ;
		scanf("%d" , &condition) , getchar() ;
		if ( condition == 1 ) {
			Student New_User ;
			printf("No: ") ;
			scanf("%d" , &New_User.ID) ;
			printf("Phone: ") ;
			scanf("%s" , New_User.Phone) ;
			append(New_User) ;
		}	
		else if ( condition == 2 ) {
			int ID ;
			printf("No: ") ;
			scanf("%d" , &ID) ;
			delete(ID) ;
		}
		else if ( condition == 3 )
			traverse() ;
		else
			break ;
	}
	return 0 ;
}
