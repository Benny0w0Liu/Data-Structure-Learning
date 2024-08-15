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
void Insert(struct Node** pointerToHead,int pos,int x){
	struct Node* new_node = GetNewNode(x);
	if(pos==0){
		if(*pointerToHead == NULL){		
			*pointerToHead = new_node;
			return;
		}
		(*pointerToHead)->prev = new_node;
		new_node->next = (*pointerToHead);
		(*pointerToHead) = new_node;
		return;
	}
	struct Node* temp1 = *pointerToHead;
	int i;
	for(i=0;i<pos-1;i++){
		if(temp1->next->next==NULL){//if position is bigger than the size
			temp1->next->next=new_node;
			new_node->prev = temp1->next;
			return; 
		}
		temp1=temp1->next; 
	}
	struct Node* temp2=temp1->next;
	temp1->next=new_node;
	new_node->prev = temp1;
	new_node->next = temp2;
	temp2->prev=new_node;
}
void Delete(struct Node** pointerToHead, int pos){
	if(*pointerToHead==NULL) return;// empty
	struct Node* temp1= *pointerToHead;
	if(pos==0){//Delete head
		*pointerToHead = temp1->next;
		(*pointerToHead)->prev=NULL;
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
	temp2->next->prev=temp1;
	//Free the memory
	free(temp2);
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
	Insert(&head, 0, 1);
	Insert(&head, 0, 2);
	Insert(&head, 0, 3);
	Insert(&head, 2, 4);
	Delete(&head, 1);
	Print(head);
	PrintReverse(head);
	return 0;
} 
