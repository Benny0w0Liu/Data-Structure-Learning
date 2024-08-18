#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
void enqueue(struct Node** pointerToFront, struct Node** pointerToRear ,int x){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
	temp->data = x;
	temp->next = NULL;
	if(*pointerToRear==NULL){//if queue is empty
		*pointerToFront=temp;
		*pointerToRear=temp;
		return;
	}
	(*pointerToRear)->next = temp;
	*pointerToRear=temp;
}
void dequeue(struct Node** pointerToFront, struct Node** pointerToRear ){
	struct Node* temp = *pointerToFront;
	if (*pointerToFront==NULL) return;//if queue is empty
	else if (*pointerToFront==*pointerToRear){//if left only one element
		*pointerToFront=NULL;
		*pointerToRear=NULL;
	}else{
		*pointerToFront = (*pointerToFront)->next;
	}
	free(temp);
}
void print(struct Node* head){
	while(head!=NULL){
		printf("%d ", head->data);
		head=head->next;
	}
	printf("\n");
}
int main(){
	struct Node* front = NULL;
	struct Node* rear = NULL;
	
	printf("enqueue(&rear ,0);\n");
	enqueue(&front, &rear ,0);
	print(front);
	
	printf("enqueue(&rear ,4);\n");
	enqueue(&front, &rear ,4);
	print(front);
	
	printf("enqueue(&rear ,7);\n");
	enqueue(&front, &rear ,7);
	print(front);
	
	printf("dequeue(&front);\n");
	dequeue(&front, &rear);
	print(front);
	
	printf("enqueue(&rear ,2);\n");
	enqueue(&front, &rear ,2);
	print(front);
	
	printf("enqueue(&rear ,8);\n");
	enqueue(&front, &rear ,8);
	print(front);
	
	printf("dequeue(&front);\n");
	dequeue(&front, &rear);
	print(front);
	
	printf("dequeue(&front);\n");
	dequeue(&front, &rear);
	print(front);
	
	printf("dequeue(&front);\n");
	dequeue(&front, &rear);
	print(front);
	
	printf("dequeue(&front);\n");
	dequeue(&front, &rear);
	print(front);
	return 0;
} 
