#include <stdio.h>
#include <stdlib.h>

//스택의 하위 자료구조용 노드
typedef struct _NODE{
    int Data;
    struct _NODE *Next;
} NODE;

NODE *head, *end;
NODE *ptrNode;

void Initialize(void);
void Push(int);
int Pop(void);
void PrintStack(void);

void Initialize(void){
    head = (NODE *)malloc(sizeof(NODE));
    end = (NODE *)malloc(sizeof(NODE));
    head->Next = end;
    end->Next = end;
}
void Push(int num){
    ptrNode = (NODE *)malloc(sizeof(NODE));
    ptrNode->Data = num;
    ptrNode->Next = head->Next;
    head->Next = ptrNode;
}
int Pop(void){
    int ret;
    ptrNode = head->Next;
    head->Next = head->Next->Next;
    ret = ptrNode->Data;
    free(ptrNode);

    return ret;
}
void PrintStack(void){
    NODE *indexNode;
    printf("head-> ");

    for(indexNode = head->Next ; indexNode != end ; indexNode = indexNode->Next){
        printf("%d -> ", indexNode->Data);
    }
    printf("end \n");
}

void main(){
    int ret;
    Initialize();

    Push(1);
    Push(11);
    Push(111);
    Push(1111);
    Push(11111);

    printf("5번 push\n");
    PrintStack();

    ret = Pop();
    ret = Pop();
    ret = Pop();

    printf("3번 pop\n");
    PrintStack();
}