#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElementType;
typedef int Status;

typedef struct Node
{
	ElementType data;
	struct Node *next;
}Node,*List;


Status Insert(List *L){
	int x;
	scanf("%d",&x);

	if(x==-1)
		*L = NULL;
	else{
		*L = (List)malloc(sizeof(Node));
		(*L)->data = x;
		Insert(&((*L)->next));
	}

}

Node *FindPrevious(List *L,ElementType target){
    Node *tmp_cell = *L;//malloc(sizeof(Node));
    while(tmp_cell){
        if(tmp_cell->next->data == target){
            return tmp_cell;
        }
        tmp_cell = tmp_cell->next;
    }
    return tmp_cell;
}


void Delete(List *L,ElementType target){
    Node *previous_node = FindPrevious(L,target);
    Node *this_node = previous_node->next;
    previous_node->next = this_node->next;
    free(this_node);

}


Status FuckDelete(List *L,ElementType target){
    Node *target_cell = *L;
    Node *tmp_cell;

    if(target_cell->data==target){
        printf("get\n");
        tmp_cell = target_cell;
        target_cell = target_cell->next;
         *L = target_cell;
        free(tmp_cell);
        return 0;
    }else
    FuckDelete(&((*L)->next),target);
}

Status Printer(List *L){
    List head = *L;
	while(head){
		printf("%d\n", head->data);
		head = head->next;
	}
}


int main(){
	List L;
	Insert(&L);
	//Printer(&L);
	printf("==============\n");
	//Printer(&L);
    FuckDelete(&L,1);
    printf("====delete 1:\n");
    Printer(&L);
	//FindPrevious(&L,2);
	//printf("ggg");
	//printf("x is %d",tmp->data);
}
