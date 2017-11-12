#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct Node;
typedef struct Node *PtrNode;
typedef PtrNode List;
typedef PtrNode Position;

typedef int ElementType;

#define OVERFLOW -1


struct Node
{
	ElementType data;
	Position next;
};


Position InitList(List L){
	Position heade_node = malloc(sizeof(struct Node));
	if(!heade_node)exit(OVERFLOW);
	heade_node->next = NULL;
	L = heade_node;
	return L;
}


Position FindPrevious(List L,ElementType X){
	Position tmp_cell = L;
	while(tmp_cell->next!=NULL && tmp_cell->next->data!=X)
		tmp_cell = tmp_cell->next;
	return tmp_cell;
}

void InsertByElement(List L,ElementType X){
	Position new_node = malloc(sizeof(struct Node));
	if(!new_node)exit(OVERFLOW);
	Position previous_node = FindPrevious(L,X);
	new_node->data = X;
	new_node->next = previous_node->next;
	previous_node->next = new_node;

}


void InsertByPos(List L,int index,ElementType X){
	Position tmp_heade = L;
	int j = 0;
	while(tmp_heade&&j<index-1){
		tmp_heade = tmp_heade->next;
		j++;
	}

	if(!tmp_heade || j>index-1)exit(OVERFLOW);
	Position new_node = malloc(sizeof(struct Node));
	if(!new_node)exit(OVERFLOW);
	new_node->data = X;
	new_node->next = tmp_heade->next;
	tmp_heade->next = new_node;

}

void DeleteByEle(List L,ElementType X){
	Position tmp_cell = FindPrevious(L,X);
	Position target_node = tmp_cell->next;
	tmp_cell->next = target_node->next;
	free(target_node);
}

void DeleteByPos(List L,int index){
	Position tmp_heade = L;
	Position target_node;
	int i = 0;
	while(tmp_heade&&i<index-1){
		tmp_heade = tmp_heade->next;
		i++;
	}
	if(!tmp_heade||i>index-1)exit(OVERFLOW);
		target_node = tmp_heade->next;
		tmp_heade->next = target_node->next;
		free(target_node);
}

static int GetLength(List L){
    Position heade = L;
    int length = 0;
    while(heade->next){
        length++;
        heade = heade->next;
    }
    return length;

}

void Printer(List L){
	Position head = L;
	while(head->next){
		head = head->next;
		printf("%d\n",head->data);
	}
}


Position LocalReserveList(List L){
	Position head = L;
	Position previous_node = NULL;
	Position next_node = NULL;
	Position mid_node = NULL;

	
	previous_node = head;
	mid_node = head->next;
	next_node = mid_node->next;

	mid_node->next = NULL;
	previous_node = mid_node;
	mid_node = next_node;

	while(mid_node){
		next_node = mid_node->next;
		mid_node->next = previous_node;
		previous_node = mid_node;
		mid_node = next_node;
	}
	L->next = previous_node;
    return L;
}


Position MergeList(List La,List Lb,List L){
    Position cell_a = La->next;
    Position cell_b = Lb->next;
    Position head = L;
    L = head = La;
    while(cell_a && cell_b){
        if(cell_a->data<=cell_b->data){
            head->next = cell_a;
            head = cell_a;
            cell_a = cell_a->next;
        }else{
            head->next = cell_b;
            head = cell_b;
            cell_b = cell_b->next;
        }
    }

    head->next = cell_a?cell_a:cell_b;
    return L;
}


int main(){
	List L;
	List La;
	List Lb;

    La = InitList(La);
    Lb = InitList(Lb);
    L = InitList(L);
	int count;

	/*************/
	InsertByPos(La,1,1);
	InsertByPos(La,2,2);
	InsertByPos(La,3,3);
	InsertByPos(La,4,4);
	InsertByPos(La,5,1);
	/************/

	InsertByPos(Lb,1,2);
	InsertByPos(Lb,2,1);
	InsertByPos(Lb,3,7);
	InsertByPos(Lb,4,4);
	InsertByPos(Lb,5,2);
	InsertByPos(Lb,6,8);
	//for(count=1;count<10;count++){
		//InsertByElement(La,count);
		//InsertByPos(Lb,count,count);
	//}
    //printf("length= %d\n",GetLength(L));
	//DeleteByEle(L,4);
	//DeleteByPos(L,2);
    //LocalReserveList(L);
    printf("L 1 =%d",L);
	Printer(La);
	printf("**************************\n");
	Lb = LocalReserveList(Lb);
	Printer(Lb);
	printf("**************************\n");
	//L = MergeList(La,Lb,L);
	//Printer(L);
    printf("L 1 =%d",L);
    //printf("length= %d\n",GetLength(L));
	return 0;
}











