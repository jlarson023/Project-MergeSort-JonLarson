#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node * next;
};

void printlist(struct node *head);
int getlistlength(struct node *head);
struct node* merge_sort(struct node* head, int size);
struct node* merge(struct node * head1, struct node * head2);

void printlist(struct node *head){
	struct node *curr = head;
	while (curr != NULL){
		printf("[%d] -> ", curr->data);
		curr = curr->next;
	}
	printf("NULL\n");
}

/* int getlistlength(struct node *head){

} */



int main(){
	printf("Hello, World!\n");
	struct node *head = malloc(sizeof(struct node));
	struct node *second = malloc(sizeof(struct node));
	struct node *third = malloc(sizeof(struct node));
	struct node *fourth = malloc(sizeof(struct node));

	head->data = 10;
	second->data = 20;
	third->data = 30;
	fourth->data = 40;
	
	head->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = NULL;
	printlist(head);
	
	free(head);
	free(second);
	free(third);
	free(fourth);
	
	
	return 0;
}
