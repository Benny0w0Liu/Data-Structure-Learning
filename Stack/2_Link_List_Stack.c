#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
void push(struct Node** pointerToTop ,int x){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
	temp->data = x;
	temp->next = *pointerToTop;
	*pointerToTop=temp;
}
void pop(struct Node** pointerToTop){
	if (*pointerToTop==NULL) return;
	struct Node* temp = *pointerToTop;
	*pointerToTop = (*pointerToTop)->next;
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
	struct Node* top = NULL;
	printf("push(&top ,0);\n");
	push(&top ,2);
	print(top);
	printf("push(&top ,7);\n");
	push(&top ,7);
	print(top);
	printf("push(&top ,5);\n");
	push(&top ,5);
	print(top);
	printf("pop(&top);\n");
	pop(&top);
	print(top);
	printf("push(&top ,3);\n");
	push(&top ,3);
	print(top);
	printf("pop(&top);\n");
	pop(&top);
	print(top);
	printf("pop(&top);\n");
	pop(&top);
	print(top);
	printf("pop(&top);\n");
	pop(&top);
	print(top);
}
