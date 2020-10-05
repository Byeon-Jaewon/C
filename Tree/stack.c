#include "node.h"

#define MAX 100

NODE *Stack[MAX];
int Top;

void InitStack(void);
void Push(NODE *);
NODE *Pop(void);
int IsStackEmpty(void);

void InitStack(void){
    Top = 0;
}
void Push(NODE *ptrNode){
    Stack[Top] = ptrNode;
    Top = (Top++) % MAX;
}
NODE *Pop(void){
    NODE *ptrNode;

    if(!IsStackEmpty()){
        ptrNode = Stack[--Top];
        return ptrNode;
    }
    else 
        printf("스택이 비었습니다.");
    return NULL;
}
int IsStackEmpty(void){
    if(Top == 0)
        return TRUE;
    else
        return FALSE;
}