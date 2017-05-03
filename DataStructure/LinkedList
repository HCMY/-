#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MALLOCERROR -1
#define ERROR 0

typedef struct Node;
typedef struct Node *PtrNode;
typedef PtrNode LinkedList;
typedef PtrNode Position;//last element

struct Node
{
	char name[20];
	int number;
	int score;
	Position next;
}Node;

void Menue();
Position InitList(LinkedList L);
int IsEmpty(LinkedList L);
int GetListLength(LinkedList L);
void InsertElement(LinkedList L,int insert_stunumber,Position p);
void DeleteElement(LinkedList L,int delete_stunumber);
void DestroyList(LinkedList L);
void Printer(LinkedList L);
Position FindPreviousNode(LinkedList L,int stu_number);
Position CreateNode();

void Menue(){
	printf("******************** input option***********************\n");
	printf("1---get list length   2---judge empty   3---print list\n");
	printf("4---insert element by stu_number\n");
	printf("5---delete element by stu_number\n");
	printf("6---destroy list   7---break out\n");
}

int IsEmpty(LinkedList L){
	if(L->next == NULL)
		return 1;
	return 0;
}

int GetListLength(LinkedList L){
	int length = 0;
	Position tmp_node = L;
	while(tmp_node->next != NULL){
		length++;
		tmp_node = tmp_node->next;
	}
	return length;
}


void DestroyList(LinkedList L){
	Position p,tmp;

	p = L->next;
	L->next = NULL;
	while(p!=NULL){
		tmp = p->next;
		free(p);
		p = tmp;
	}
}


Position FindPreviousNode(LinkedList L,int stu_number){
	Position p = L;
	while(p->next!=NULL && p->next->number != stu_number ){
		p = p->next;
	}
	return p;
}

Position FindNode(LinkedList L,int delete_stunumber){
	Position p = L;
	while(p->next!=NULL && p->number != delete_stunumber ){
		p = p->next;
	}
	return p;
}
///insert behind your target
///if method didn't find target,it will insert behind last element
void InsertElement(LinkedList L,int insert_stunumber,Position p){
	Position previous_node = FindNode(L,insert_stunumber);
	Position tmp_node = previous_node->next;
	previous_node->next = p;
	p->next = tmp_node;
}

///delete your target element
///if not find,paograme will quite
void DeleteElement(LinkedList L,int delete_stunumber){
	Position previous_node = FindPreviousNode(L,delete_stunumber);
	if(previous_node->next==NULL) exit(ERROR);
	Position next_node = previous_node->next;
	previous_node->next = next_node->next;
	free(next_node);
}

Position CreateNode(){
	Position new_node = malloc(sizeof(Node));
	new_node->next = NULL;

	printf("input name:");
	scanf("%s",new_node->name);

	printf("input number:");
	scanf("%d",&(new_node->number));

	printf("input score:");
	scanf("%d",&(new_node->score));

	printf("\n");
	return new_node;
}

Position InitList(LinkedList L){
	Position node = malloc(sizeof(Node));
	node->next = NULL;
	L = node;
	return L;
}

void Printer(LinkedList L){
	Position p = L;
	printf("-----name-----student number-----score\n");
	while(p->next!=NULL){
        p = p->next;
		printf("     %s           %d           %d\n", p->name,p->number,p->score);
	}
}


int main(){
	LinkedList L;
	L=InitList(L);

	int option;
	while(1){
		Menue();
		scanf("%d",&option);

		switch(option){
			case 1:printf("list length= %d\n",GetListLength(L));break;
			case 2:printf("list empty= %d\n",IsEmpty(L));break;
			case 3:Printer(L);break;
			case 4:{
				Position insert_node = CreateNode();

				int stu_number;
				printf("input insert stu_number:\n");
				scanf("%s",&stu_number);
				InsertElement(L,stu_number,insert_node);
			}break;
			case 5:{
				int delete_stunumber;
				printf("input delete stu_number:\n");
				scanf("%d",&delete_stunumber);
				DeleteElement(L,delete_stunumber);
			}break;
			case 6:DestroyList(L);break;
			case 7:return 0;
		}
	}

	return 0;
}





