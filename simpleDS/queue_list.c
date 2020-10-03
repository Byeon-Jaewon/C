#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE{
    int Data;
    struct _NODE *Next;
}NODE;

NODE *Front, *Rear;
NODE *ptrNode;

void Init(void);
void Put(int);
int Get(void);
void PrintQ(void);

void Init(void){
    Front = (NODE *)malloc(sizeof(NODE));
    Rear = (NODE *)malloc(sizeof(NODE));
    Front->Next = Rear;
    Rear->Next = Front;
}
void Put(int num){
    ptrNode = (NODE *)malloc(sizeof(NODE));
    ptrNode -> Data = num;

    if(Front->Next == Rear){
        Front->Next = ptrNode;
        ptrNode->Next = Rear;
        Rear->Next = ptrNode;
    }
    else{
        Rear->Next->Next = ptrNode;
        ptrNode->Next = Rear;
        Rear->Next = ptrNode;
    }
}
int Get(void){
    int ret;
    NODE *deleteNode;
    printf("\n");

    if(Front->Next == Rear)
        printf("큐가 비었음\n");
    else{
        deleteNode = Front->Next;
        Front->Next = deleteNode->Next;
        ret = deleteNode->Data;
        printf("get():%d \n", ret);

        free(deleteNode);
    }
    return ret;
}
void PrintQ(void){
    NODE *ptrTemp;

    if(Front->Next != Rear){
        for(ptrTemp = Front->Next ; ptrTemp->Next != Rear ; ptrTemp = ptrTemp->Next){
            printf("%d -> ", ptrTemp->Data);
        }
        printf("%d\n", ptrTemp->Data);
    }
    else if(Front->Next == Rear)
        printf("큐가 비었음\n");
}

void main(){
    int ret;
    Init();

    Put(1);
    Put(3);
    Put(5);
    Put(10);
    Put(15);

    printf("5번 put 결과\n");
    PrintQ();

    ret = Get();
    ret = Get();
    ret = Get();

    printf("3번 get 결과\n");
    PrintQ();

    ret=Get();
    ret=Get();

    printf("2번 get결과\n");
    PrintQ();
}

