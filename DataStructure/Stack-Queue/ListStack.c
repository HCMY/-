#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define INIT_SIZE 10
#define EXTEND_SIZE 10
#define OVERFLOW -1
#define EmptyOS -1

struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

struct StackRecord
{
	int capacity;
	int top;
	ElementType *array;
};


void Alter(char *error_content){
	printf("%s\n",error_content);
}

void FatalError(char *error_content){
	printf("%s\n",error_content);
	exit(OVERFLOW);
}

void MakeEmpty(Stack S){
	S->top = EmptyOS;
}

Stack CreateStack(int element_num){
	Stack S;

	if(element_num<=INIT_SIZE)
		FatalError("stack size is too small");
	S = malloc(sizeof(struct StackRecord));
	if(!S)
		FatalError("init struct error");
	S->array = malloc(INIT_SIZE*sizeof(struct StackRecord));
	if(!S->array)
		FatalError("init stack error");
	S->capacity = element_num;
	MakeEmpty(S);

	return S;
}


void DestroyStack(Stack S){
	if(!S){
		free(S->array);
		free(S);
	}
}


int IsEmpty(Stack S){
	return S->top == EmptyOS;
}

int IsFull(Stack S){
	return S->capacity == S->top;
}


void Push(Stack S,ElementType data){
	if (IsFull(S))
		Alter("full stack");
	else
		S->array[++S->top] = data;
}

void Pop(Stack S){
	if (IsEmpty(S))
		Alter("stack is empty");
	else
		S->top--;
}

ElementType Top(Stack S){
	ElementType e;
	if(IsEmpty(S)){
		Alter("stack is empty");
		return 0;
	}
	else{
		e = S->array[S->top];
		return e;
	}

}

void Printer(Stack S){
	int top = S->top;
	while(top!=EmptyOS){
		printf("%d\n",S->array[top]);
		top--;
	}
}

int main(){
	Stack S;
	S = CreateStack(20);

	int i;
	for(i=1;i<8;i++)
		Push(S,i);
	Printer(S);
	printf("top ele is: %d\n",Top(S));

	Pop(S);
	MakeEmpty(S);
	Printer(S);



}




