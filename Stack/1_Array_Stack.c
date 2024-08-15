#include<stdio.h>
void push(int stack[],int* top,int size,int n) {
	if(*top==size-1) return;
	stack[++(*top)]=n;
}
void pop(int* stack,int* top){
	if(*top==-1) return;
	(*top)--;
}
int main(){
	int stack[10],size=10 ,top=-1,i;
	push(stack, &top, size,3);
	push(stack, &top, size,0);
	push(stack, &top, size,7);
	push(stack, &top, size,5);
	pop(stack, &top);
	for(i=top;i>=0;i--)
		printf("%d : %d\n",i, stack[i]);
	return 0;
} 
