#include<stdio.h>
void enqueue(int* queue, int size,int* front, int* rear, int x){
	if((*rear)%size+1==*front) return;//if full
	else if(*front==-1 && *rear==-1){//if empty
		*front=0;
		*rear=0;
	}else{
		(*rear)=((*rear)+1)%size;//can back to the 0
	}
	queue[*rear]=x;
}
void dequeue(int* queue, int size, int* front, int* rear){
	if(*front==-1 && *rear==-1) return;//if empty
	else if(*front==*rear){//if left only one element
		*front=-1;
		*rear=-1;
	}else{
		(*front)=((*front)+1)%size;//can back to the 0
	}
}
int main(){
	int queue[5], front=-1, rear=-1, size=5,i;
	enqueue(queue, size, &front,&rear,3);
	enqueue(queue, size, &front,&rear,0);
	enqueue(queue, size, &front,&rear,7);
	enqueue(queue, size, &front,&rear,5);
	dequeue(queue, size, &front,&rear);
	dequeue(queue, size, &front,&rear);
	dequeue(queue, size, &front,&rear);
	enqueue(queue, size, &front,&rear,9);
	enqueue(queue, size, &front,&rear,2);
	enqueue(queue, size, &front,&rear,6);
	i=front;
	while(i!=rear){
		printf("%d : %d\n",i,queue[i]);
		i=(i+1)%size;
	}
	printf("%d : %d\n",i,queue[i]);
}
