#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OVERFLOW -1
#define INIT_SIZE 10

struct QueueRecord;
typedef struct QueueRecord *Queue;

typedef int ElementType;
typedef int Status;

struct QueueRecord
{
	ElementType *base;
	int front;
	int rear;
	int capacity;
	int size;
};

void FatalError(char *error_content){
	printf("%s\n",error_content);
	exit(OVERFLOW);
}

void Alter(char *error_content){
	printf("%s\n",error_content );
}


Queue InitQueue(Queue Q){
    Q = malloc(sizeof(struct QueueRecord));
    if(!Q)FatalError("init QueueRecord error");
	Q->base = (ElementType *)malloc(INIT_SIZE*sizeof(ElementType));
	if(!Q->base)FatalError("init queue fail");

	Q->front = Q->rear = 0;
	Q->size = 0;
	Q->capacity = INIT_SIZE;

	return Q;
}

int IsEmpty(Queue Q){
	return Q->front == Q->rear;
}

int IsFull(Queue Q){
	return Q->size == Q->capacity;
}


void EnQueue(Queue Q,ElementType x){
	if (IsFull(Q))FatalError("queue is full");
	Q->base[Q->rear] = x;
	Q->size++;
	Q->rear = (Q->rear+1)%INIT_SIZE;
}

void DeQueue(Queue Q){
	if(IsEmpty(Q))FatalError("queue is full");
	Q->front = (Q->front+1)%INIT_SIZE;
	Q->size--;
}


void Printer(Queue Q){
	int front_cell_loc = Q->front;
	int last_cell_loc = Q->rear;


	while(front_cell_loc!=last_cell_loc)
		printf("%d\n", Q->base[front_cell_loc++]);
}

int main(){
	Queue Q;
	Q = InitQueue(Q);

	int i;
	for (i = 1; i < 8; ++i)
		EnQueue(Q,i);
	Printer(Q);
	DeQueue(Q);
	printf("=======\n");
    Printer(Q);
}




