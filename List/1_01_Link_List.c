#include<stdio.h>
struct Node{
	int data;
	struct Node* next;
};

void Insert(struct Node** pointer_to_head,int pos,int x){
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));//new Node
	temp1->data = x;
	temp1->next = NULL;
	if(pos==0){//Insert to the head
		temp1->next = *pointer_to_head;
		*pointer_to_head = temp1;
		return;
	}
	struct Node* temp2 = *pointer_to_head; 
	int i;
	for(i=0;i<pos-1;i++){//Go to the position we want
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

void Delete(struct Node** pointer_to_head, int pos){
	struct Node* temp1= *pointer_to_head;
	if(pos==0){//Delete head
		*pointer_to_head = temp1->next;
		free(temp1);
		return;
	}
	//Fix the Links
	int i;
	for(i=0;i<pos-1;i++){
		temp1 = temp1->next;
	}
	struct Node* temp2 = temp1->next;
	temp1->next = temp2->next;
	//Free the memory
	free(temp2);
}
void Reverse(struct Node** pointer_to_head){
	struct Node* temp = *pointer_to_head, *current = *pointer_to_head, *prev = NULL;
	while(temp != NULL){
		temp = current->next;//store the next node
		current->next = prev;//reverse the link
		prev = current;//move to current node
		current = temp;//move to next node
	}
	*pointer_to_head = prev;
} 
void Print(struct Node* head){
	while(head!=NULL){//Travel the list
		printf("%d ", head->data);
		head=head->next;
	}
	printf("\n");
}
int main(){
	struct Node* head = NULL; // empty list
	Insert(&head,0,2);
	Insert(&head,1,3);
	Insert(&head,2,4);
	Insert(&head,1,5);
	Delete(&head,0);
	//Reverse(&head);
	Print(head);
	return 0;
}
