#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct QueueNode;
typedef struct QueueNode *PtrNode;

struct QueueNode
{
	int element;
	PtrNode next;
};

typedef struct
{
	PtrNode rear;
	PtrNode front;
}LinkedQueue,*Queue;

Queue InitQueue(Queue Q){
	PtrNode init_node = malloc(sizeof(struct QueueNode));
	init_node->next = NULL;
	Q->rear = Q->front = init_node;
	return Q;
}

void EnQueue(int X,Queue Q){
	PtrNode new_node = malloc(sizeof(struct QueueNode));
	if(!new_node)exit(0);
	new_node->element = X;
	new_node->next = NULL;
	Q->rear->next = new_node;
	Q->rear = new_node;
}

void DeQueue(Queue Q){
    if(Q->rear==Q->front)
        exit(0);
	PtrNode tmp_cell = Q->front->next;
	Q->front->next = tmp_cell->next;
	if(Q->rear==tmp_cell){
        Q->rear = Q->front;
        printf("rear = front= %d",Q->front->next);
	}
	free(tmp_cell);
}

void Printer(Queue Q){
	PtrNode tmp_cell = Q->front;
	while(tmp_cell->next){
		tmp_cell = tmp_cell->next;
		printf("%d\n", tmp_cell->element);
	}
}


int main(){
	Queue Q = malloc(sizeof(LinkedQueue));
	Q = InitQueue(Q);
	int i;
	for(i=0;i<3;i++)
        EnQueue(i+1,Q);
    Printer(Q);
    printf("=========\n");
    DeQueue(Q);
    Printer(Q);
    printf("=========\n");
    DeQueue(Q);
    //EnQueue(15,Q);
    Printer(Q);
    printf("=========\n");
    DeQueue(Q);
    Printer(Q);
	//Printer(Q);

}

