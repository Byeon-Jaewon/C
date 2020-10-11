#include "node.h"
#define MAX 100

void InitQ(void);
void Put(NODE *);
NODE *Get(void);
int IsQEmpty(void);
void InitTree(void);
void MakeTree(void);
void levTraverse(NODE *);
void Visit(NODE *);

NODE *Queue[MAX];
int Front, Rear;

NODE *Parent, *Leftchild, *Rightchild;
NODE *HeadNode, *EndNode;

void InitQ(void){
    Front = Rear = 0;
}
void Put(NODE *ptrNode){
    Queue[Rear] = ptrNode;
    Rear = (Rear+1)%MAX;
}
NODE *Get(void){
    NODE *ptrNode;
    if(!IsQEmpty()){
        ptrNode = Queue[Front];
        Front = (Front+1) % MAX;
        return ptrNode;
    }
    else 
        printf("큐가 비었음\n");
    return NULL;
}
int IsQEmpty(void){
    if(Rear == Front){
        return TRUE;
    }
    else{   
        return FALSE;
    }
}

void InitTree(void){
    HeadNode = (NODE *)malloc(sizeof(NODE));
    EndNode = (NODE *)malloc(sizeof(NODE));

    HeadNode->Left = EndNode;
    HeadNode->Right = EndNode;

    EndNode->Left = EndNode;
    EndNode->Right = EndNode;
}
void MakeTree(void){
    Parent = (NODE *)malloc(sizeof(NODE));
    Parent->Data = 'A';

    Leftchild = (NODE *)malloc(sizeof(NODE));
    Leftchild->Data = 'B';

    Rightchild = (NODE *)malloc(sizeof(NODE));
    Rightchild->Data = 'C';

    Parent->Left = Leftchild;
    Parent->Right = Rightchild;

    HeadNode->Left = Parent;
    HeadNode->Right = Parent;

    Parent = Parent->Left;

    Leftchild = (NODE *)malloc(sizeof(NODE));
    Leftchild->Data = 'D';
    Leftchild->Left = EndNode;
    Leftchild->Right = EndNode;

    Rightchild = (NODE *)malloc(sizeof(NODE));
    Rightchild->Data = 'E';
    Rightchild->Left = EndNode;
    Rightchild->Right = EndNode;

    Parent->Left = Leftchild;
    Parent->Right = Rightchild;
    Parent = HeadNode->Right->Right;

    Leftchild = (NODE *)malloc(sizeof(NODE));
    Leftchild->Data = 'F';
    Leftchild->Left = EndNode;
    Leftchild->Right = EndNode;

    Rightchild = (NODE *)malloc(sizeof(NODE));
    Rightchild->Data = 'G';
    Rightchild->Left = EndNode;
    Rightchild->Right = EndNode;

    Parent->Left = Leftchild;
    Parent->Right = Rightchild;
}
void Visit(NODE *ptrNode){
    printf("%2c ->", ptrNode->Data);
}
void levTraverse(NODE *ptrNode){
    Put(ptrNode);
    while(!IsQEmpty()){
        ptrNode = Get();
        Visit(ptrNode);

        if(ptrNode->Left != EndNode)
            Put(ptrNode->Left);
        if(ptrNode->Right != EndNode)
            Put(ptrNode->Right);
    }
}
void main(){
    InitQ();
    InitTree();
    MakeTree();
    printf("큐를 사용한 레벨순회 : ");

    levTraverse(HeadNode->Left);
}