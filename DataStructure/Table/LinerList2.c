#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK 0
#define OVERFLOW 0
#define ALLOC_SUCCESS 1
#define ALLOC_FAIL 0
#define CHECK_FAIL 0
#define CHECk_SUCCESS 1

#define INIT_LIST_SIZE 2
#define EXTEND_LIST_SIZE 1


typedef int ElemenType;
typedef int Status;

typedef struct
{
	ElemenType *base;
	int length;
	int size;
}SqList;


Status Allocer(SqList *L){
	if(L->length>=L->size){
		ElemenType *new_base = (ElemenType *)realloc(L->base,(EXTEND_LIST_SIZE+L->size)*sizeof(ElemenType));
		if(!L)
			return ALLOC_FAIL;
		L->base = new_base;
		L->size+=EXTEND_LIST_SIZE;
	}
	return ALLOC_SUCCESS;
}


Status Checker(SqList *L,int index){
	if(index>L->length+1||index<1)
		return CHECK_FAIL;
	return CHECk_SUCCESS;
}

Status InitList(SqList *L){
	L->base = (ElemenType *)malloc(INIT_LIST_SIZE*sizeof(ElemenType));
	if(!L->base)exit(OVERFLOW);
	L->length = 1;
	L->size = INIT_LIST_SIZE;
	return OK;
}

Status Insert(SqList *L,ElemenType X,int index){
	if(Allocer(L)==ALLOC_FAIL)exit(OVERFLOW);
	if(Checker(L,index)==CHECK_FAIL)exit(OVERFLOW);

    int i;
	for(i=L->length;i<index;i--)
		L->base[i+1] = L->base[i];
	L->base[index] = X;
	L->length++;

	return OK;
}

Status InsertByAddress(SqList *L,ElemenType X,int index){
	if(Allocer(L)==ALLOC_FAIL)exit(OVERFLOW);
	if(Checker(L,index)==CHECK_FAIL)exit(OVERFLOW);

	ElemenType *inser_add = &(L->base[index]);
	ElemenType *end_add=NULL;

	for(end_add=&(L->base[L->length]);end_add<inser_add;end_add--)
		*(end_add+1) = *end_add;
	*inser_add = X;
	L->length++;

	return OK;
}


Status Delete(SqList *L,int index){
	if(!Allocer(L))exit(OVERFLOW);
	if(!Checker(L,index))exit(OVERFLOW);

	ElemenType *dele_add = &(L->base[index]);
	ElemenType *end_add = &(L->base[L->length]);

	for(dele_add;dele_add<end_add;dele_add++)
		*dele_add = *(dele_add+1);
	L->length--;

	return OK;

}


Status ClearList(SqList *L){
	L->length = 0;
	return 1;
}

Status DestroyList(SqList *L){
	free(L->base);
	L->base = NULL;
	L->length = 0;
	L->size = 0;
	return 1;
}

Status compare(ElemenType x,ElemenType y){
	if (x==y)
		return 1;
	return 0;
}

Status LocElem(SqList *L,ElemenType e,Status(*compare)(ElemenType,ElemenType)){
	int i = 1;
	ElemenType *p = &(L->base[i]);
	while(i<L->length && !(*compare)(*p++,e))
		i++;
	if(i<L->length)
		return i;
	else
		return 0;
}

void Printer(SqList *L){
    ElemenType *start = L->base+1;
    ElemenType *end = L->base+L->length;
	for(start;start<end;start++)
		printf("%d ",*start);
	printf("\n");
}


Status Merge(SqList *L1,SqList *L2,SqList *L){
	ElemenType *p1 = L1->base+1;
	ElemenType *p2 = L2->base+1;

	L->size = L->length = L1->length+L2->length-1;
	if(!Allocer(L))exit(OVERFLOW);

	ElemenType *p1_last = L1->base+L1->length;
	ElemenType *p2_last = L2->base+L2->length;
	ElemenType *p = L->base+1;

	while(p1<=p1_last && p2<=p2_last){
		if(*p1==*p2){
            L->length--;
            printf("ggggg\n");
		}

		if(*p1<*p2)
			*p++ = *p1++;
		else
			*p++ = *p2++;

	}

	while(p1<=p1_last) *p++ = *p1++;
	while(p2<=p2_last) *p++ = *p2++;
	return OK;

}

int main(){
	SqList L;
	SqList L1;
	SqList L2;

	InitList(&L);
    InitList(&L1);
    InitList(&L2);

	int i;
	for(i=1;i<10;i++){
		InsertByAddress(&L1,i,i);
		InsertByAddress(&L2,i*10,i);
	}

    Printer(&L1);
    Printer(&L2);
    Merge(&L1,&L2,&L);
	Printer(&L);
	//printf("length= %d\n",L.length);
	//Delete(&L,5);
	//Printer(&L);
	//ClearList(&L);
	//Printer(&L);
	//DestroyList(&L);
	//printf("length= %d",L.length);
    //Delete(&L,5);
    //Printer(&L);
	//printf("%d\n",LocElem(&L,4,(*compare)));
	return 0;
}

