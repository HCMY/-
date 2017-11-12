#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#define OVERFLOW -1
#define ERROR 0

#define INIT_LIST_SIZE 100
#define LIST_INCREMENT 10


typedef struct
{
	char identifier[20];
	char name[10];
	int class_no;
}Node;

typedef struct
{
    Node *elem;
	int length;
	int list_size;
}SqList;

void InitList(SqList *L){
	L->elem = (Node *)malloc(INIT_LIST_SIZE*sizeof(Node));
	 printf("------\n");
	if(!L->elem) exit(OVERFLOW);
	L->length = 0;
	L->list_size = INIT_LIST_SIZE;
}

void Insert(SqList *L,int index,Node *node){
	if(index<1 || index>L->length+1)exit(ERROR);
	if(L->length>=L->list_size){
		SqList *new_base = (Node *)realloc(L->elem,(L->list_size+LIST_INCREMENT)*sizeof(Node));
		if(!new_base)exit(OVERFLOW);
		L->elem = new_base;
		L->list_size += LIST_INCREMENT;
	}
	Node *q = &(L->elem[index-1]);
	Node *p;
	for(p=&(L->elem[L->length-1]);p>=q;--p)
		*(p+1) = *p;
	*q = *node;
	++L->length;
}

void Delete(SqList *L,int index){
    if(index<1 || index>L->length+1)
        exit(ERROR);
    Node *target_node_index = &(L->elem[index]);
    Node *end_node_index = L->elem+L->length-1;
    for(target_node_index;target_node_index<end_node_index;++target_node_index)
        *(target_node_index-1) = *target_node_index;
    --L->length;
}

void Printer(SqList *L){
	int i;
	printf("-----name-----student number-----score\n");
	for(i = 0;i<=L->length-1;++i){
		Node *tmp_cell = &(L->elem[i]);
		printf("     %s           %s           %d\n", tmp_cell->name,tmp_cell->identifier,tmp_cell->class_no);
    }
}

Node *NodeCreater(){
    Node *new_node = (Node *)malloc(sizeof(Node));

    printf("input name:");
	scanf("%s",new_node->name);

	printf("input number:");
	scanf("%s",&(new_node->identifier));

	printf("input score:");
	scanf("%d",&(new_node->class_no));

	printf("\n");
	return new_node;
}


int GetListLength(SqList *L){
	return L->length;
}

int IsEmpty(SqList *L){
	return L->length==0;
}


void DestroyList(SqList *L){
	Node *fist = &(L->elem[0]);
	Node *last = L->elem+L->length-1;
	for(fist;fist<=last;fist++)
		free(fist);
	L->length = 0;

}


void Menue(){
	printf("******************** input option***********************\n");
	printf("1---get list length   2---judge empty   3---print list\n");
	printf("4---insert element by index\n");
	printf("5---delete element by index\n");
	printf("6---destroy list   7---break out\n");
}



int main(int argc, char const *argv[])
{
	SqList L;
	InitList(&L);

	int option;
	while(1){
		Menue();
		scanf("%d",&option);

		switch(option){
			case 1:printf("list length= %d\n",GetListLength(&L));break;
			case 2:printf("list empty= %d\n",IsEmpty(&L));break;
			case 3:Printer(&L);break;
			case 4:{
				Node *insert_node = NodeCreater();

				int insert_index;
				printf("input insert index:\n");
				scanf("%d",&insert_index);
				Insert(&L,insert_index,insert_node);
			}break;
			case 5:{
				int delete_index;
				printf("input delete index:\n");
				scanf("%d",&delete_index);
				Delete(&L,delete_index);
			}break;
			case 6:DestroyList(&L);break;
			case 7:return 0;
		}
	}

	return 0;
}


