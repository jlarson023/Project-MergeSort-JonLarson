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


int main(){

	struct node *head1 = malloc(sizeof(struct node));
	struct node *second1 = malloc(sizeof(struct node));
	struct node *third1 = malloc(sizeof(struct node));

	struct node *head2 = malloc(sizeof(struct node));
	struct node *second2 = malloc(sizeof(struct node));
	struct node *third2 = malloc(sizeof(struct node));

	// initialize head1 list values
	head1->data = 3;
	second1->data = 5;
	third1->data = 9;
	
	//link head1 list
	head1->next = second1;
	second1->next = third1;
	third1->next = NULL;

	// initialize head2 list values
	head2->data = 1;
	second2->data = 6;
	third2->data = 7;
	
	//link head2 list
	head2->next = second2;
	second2->next = third2;
	third2->next = NULL;

	printlist(head1);
	printlist(head2);
	int size = getlistlength(head1);
	printf("\nSize: %d\n", size);

	struct node * newlist = merge(head1, head2);
	printlist(newlist);
	
	free(head1);
	free(second1);
	free(third1);

	free(head2);
	free(second2);
	free(third2);
	
	return 0;
}
