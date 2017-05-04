#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node;
typedef struct Node *PtrNode;
typedef PtrNode Stack;

struct Node{
	int data;
	PtrNode next;
}Node;

void Error(char *str);
int IsEmpty(Stack S);
Stack InitStack();
void MakeEmpty(Stack S);
void Pop(Stack S);
void Push(Stack S,int ele);
int Top(Stack S);
void Menue();



void Error(char *str){
	printf("%s\n",str);
}

int IsEmpty(Stack S){
	return S->next == NULL;
}

Stack InitStack(void){
	Stack S;
	S = malloc(sizeof(Node));
	if(S==NULL)Error("out of space!");
	S->next = NULL;
	MakeEmpty(S);
	return S;
}

void MakeEmpty(Stack S){
	if(S==NULL)Error("must init stack first!");
	while(!IsEmpty(S))
		Pop(S);
}

void Pop(Stack S){
	PtrNode top_cell;
	if(IsEmpty(S))Error("empty stack");
	else{
		top_cell = S->next;
		S->next = top_cell->next;
		free(top_cell);
	}
}


void Push(Stack S,int ele){
	PtrNode tmp_cell;
	tmp_cell = malloc(sizeof(Node));
	tmp_cell->data = ele;
	tmp_cell->next = S->next;
	S->next = tmp_cell;
}

int Top(Stack S){
	if(!IsEmpty(S))
		return S->next->data;
	Error("empty stack");
}

void Menue(){
	printf("******************** input option***********************\n");
	printf("1---judge empty   2---get top element\n");
	printf("3---pop element\n");
	printf("4---push element\n");
	printf("5---break out\n");
}

int Input(){
	printf("input element:");
	int data;
	scanf("%d",&data);
	return data;
}

int main(){
	Stack S = InitStack();
	int option;
	int ele;
	while(1){
        Menue();
		scanf("%d",&option);
		switch(option){
		case 1:printf("empty= %d\n",IsEmpty(S));break;
		case 2:printf("top element= %d\n",Top(S));break;
		case 3:Pop(S);break;
		case 4:ele = Input();Push(S,ele);break;
		case 5:exit(0);
        }
	}
	return 0;
}
