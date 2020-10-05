#include "node.h"

extern void InitStack(void);
extern void Push(NODE *);
extern NODE *Pop(void);
extern int IsStackEmpty(void);


void InitTree(void);
void MakeTree(void);
void Traverse(NODE *);
void Visit(NODE *);

NODE *Parent, *Leftchild, *Rightchild;
NODE *HeadNode, *EndNode;

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
void Traverse(NODE *ptrNode){
    Push(ptrNode);
    while(!IsStackEmpty()){
        ptrNode = Pop();
        Visit(ptrNode);

        if(ptrNode->Right != EndNode)
            Push(ptrNode->Right);
        if(ptrNode->Left != EndNode)
            Push(ptrNode->Left);
    }
}
void Visit(NODE *ptrNode){
    printf("%2c ->", ptrNode->Data);
}
void main(){
    InitStack();
    InitTree();
    MakeTree();
    Traverse(HeadNode->Left);
}