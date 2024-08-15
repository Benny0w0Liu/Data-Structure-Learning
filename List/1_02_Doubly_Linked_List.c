#include<stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};
struct Node* GetNewNode(int x){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data=x;
	new_node->next=NULL;
	new_node->prev=NULL;
	return new_node;
}
void InsertAtHead(struct Node** pointerToHead,int x){
	struct Node* new_node = GetNewNode(x);
	if(*pointerToHead == NULL){		
		*pointerToHead = new_node;
		return;
	}
	(*pointerToHead)->prev = new_node;
	new_node->next = (*pointerToHead);
	(*pointerToHead) = new_node;
}
void Print(struct Node* head){
	struct Node* temp = head;
	printf("Forward: ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void PrintReverse(struct Node* head){
	struct Node* temp = head;
	printf("Reverse: ");
	if(temp==NULL) return;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}
int main(){
	struct Node* head=NULL;
	InsertAtHead(&head, 1);
	InsertAtHead(&head, 2);
	InsertAtHead(&head, 3);
	Print(head);
	PrintReverse(head);
	return 0;
} 
