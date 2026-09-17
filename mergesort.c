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

int getlistlength(struct node *head){
	int count = 0;

	struct node *curr = head;
	while (curr != NULL){
		count++;
		curr = curr->next;
	}
	printf("List Length: %d", count);

	return count;
}

struct node* merge(struct node * head1, struct node * head2){
	struct node *newhead = NULL;
	struct node *tail = NULL;
	
	while(head1 != NULL && head2 != NULL){
		struct node *curr;
		if(head1->data <= head2->data){
			curr = head1;
			head1 = head1->next; //update head1's list
		}else{
			curr = head2;
			head2 = head2->next; //update head2's list
		}

		//update newhead with current node to merge
		if(newhead == NULL){
			newhead = curr;
			tail = curr;
		}else{
			tail->next = curr;
			tail = curr;
		}
	}

	//update newhead with remaining nodes
	if(head1 != NULL){
		tail->next = head1;
	}else{
		tail->next = head2;
	}

	return newhead;
}

struct node* merge_sort(struct node* head, int size){
	int firsthalf = size / 2;
	int secondhalf = size - firsthalf;

	struct node *curr = head;

	//set curr to the end of the first half (to split the list in two)
	for(int i = 1; i < firsthalf; i++){
		curr = curr->next;
	}

	//start of the second half of the list
	struct node *secondstart = curr->next;

	//separate the list in two
	curr->next = NULL;

	printf("\nfirst list: ");
	printlist(head);
	printf("\nsecond list: ");
	printlist(secondstart);

	return head;
}

int main(){

	struct node *head = malloc(sizeof(struct node));
	struct node *second = malloc(sizeof(struct node));
	struct node *third = malloc(sizeof(struct node));
	struct node *fourth = malloc(sizeof(struct node));
	struct node *fifth = malloc(sizeof(struct node));
	struct node *sixth = malloc(sizeof(struct node));

	//initialize list values
	head->data = 5;
	second->data = 9;
	third->data = 3;
	fourth->data = 6;
	fifth->data = 7;
	sixth->data = 1;
	
	//link the list
	head->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = fifth;
	fifth->next = sixth;
	sixth->next = NULL;

	printf("OG List: ");
	printlist(head);
	int size = getlistlength(head);
	//printf("\nSize: %d\n", size);

	struct node * newlist = merge_sort(head, size);
	printf("\nList After Mergesort: ");
	printlist(newlist);
	
	free(head);
	free(second);
	free(third);
	free(fourth);
	free(fifth);
	free(sixth);
	
	return 0;
}
