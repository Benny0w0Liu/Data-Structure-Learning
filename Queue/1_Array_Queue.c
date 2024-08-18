#include<stdio.h>
void enqueue(int* queue, int size,int* front, int* rear, int x){
	if(*rear==size-1) return;//if full
	else if(*front==-1 && *rear==-1){//if empty
		*front=0;
		*rear=0;
	}else{
		(*rear)++;
	}
	queue[*rear]=x;
}
void dequeue(int* queue, int* front, int* rear){
	if(*front==-1 && *rear==-1) return;//if empty
	else if(*front==*rear){//if left only one element
		*front=-1;
		*rear=-1;
	}else{
		(*front)++;
	}
}
int main(){
	int queue[10], front=-1, rear=-1, size=10,i;
	enqueue(queue, size, &front,&rear,3);
	enqueue(queue, size, &front,&rear,0);
	enqueue(queue, size, &front,&rear,7);
	dequeue(queue, &front,&rear);
	enqueue(queue, size, &front,&rear,5);
	enqueue(queue, size, &front,&rear,9);
	dequeue(queue, &front,&rear);
	for(i=front;i<=rear;i++) printf("%d : %d\n",i,queue[i]);
}
