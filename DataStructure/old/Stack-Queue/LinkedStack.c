#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#define OVERFLOW -1


struct Node;
typedef struct Node *PtrNode;
typedef PtrNode Stack;
typedef PtrNode Position;

typedef int ElementType;


struct Node
{
	ElementType data;
	PtrNode next;
};

int IsEmpty(Stack S){
	return S->next == NULL;
}

void FatalError(char *error_content){
	printf("%s\n", error_content);
	exit(OVERFLOW);
}

void Alter(char *error_content){
	printf("%s\n", error_content);
}


void Push(Stack S,ElementType X){
	PtrNode new_node = malloc(sizeof(struct Node));
	if(!new_node)FatalError("create node fail");

	new_node->data = X;
	PtrNode top_cell = S->next;
	new_node->next = top_cell;
	S->next = new_node;
}


void Pop(Stack S){
	if(IsEmpty(S))FatalError("stack is empty,can't pop");
	PtrNode top_cell = S->next;
	S->next = top_cell->next;
	free(top_cell);
}

ElementType Top(Stack S){
	return S->next->data;
}

void MakeEmpty(Stack S){
	if(!S)FatalError("must init stack first");
	while(!IsEmpty(S))
		Pop(S);
}

Stack CreateStack(void){
	Stack S;
	S = malloc(sizeof(struct Node));
	if(!S)FatalError("init stack error");
	S->next = NULL;
	MakeEmpty(S);

	return S;
}

void DestroyStack(Stack S){
	PtrNode tmp_cell;
	PtrNode top_cell;
	top_cell = S->next;
	S->next = NULL;

	while(!IsEmpty(S)){
		tmp_cell = top_cell->next;
		free(top_cell);
		top_cell = tmp_cell;
	}
}


void Printer(Stack S){
	PtrNode top_cell = S->next;

	while(top_cell){
		printf("%d\n", top_cell->data);
		top_cell = top_cell->next;
	}
}



int main(){
	Stack S;
	S = CreateStack();

	int i;
	for (i = 1; i < 10; ++i)
	{
		Push(S,i);
	}
    Pop(S);
    //DestroyStack(S);
	Printer(S);
	printf("top element is: %d\n",Top(S));
	MakeEmpty(S);
	Printer(S);

}
