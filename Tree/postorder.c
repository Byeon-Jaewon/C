#include "node.h"

extern void InitStack(void);
extern void Push(NODE *);
extern NODE *Pop(void);
extern int IsStackEmpty(void);


void InitTree(void);
void MakeTree(void);
void rec_Traverse(NODE *);
void Stack_Traverse(NODE *);
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
void Visit(NODE *ptrNode){
    printf("%2c ->", ptrNode->Data);
}
void rec_Traverse(NODE *ptrNode){
    //ptrnode가 단말노드가 될때까지 재귀
    if(ptrNode != EndNode){
        rec_Traverse(ptrNode->Left);
        rec_Traverse(ptrNode->Right);
        Visit(ptrNode);
    }
}
void Stack_Traverse(NODE *ptrNode){
    int Finish = 0;
    NODE *ptrVisited = EndNode;
    NODE *ptrPushed = EndNode;

    do{
        while(ptrNode != EndNode && ptrNode != ptrVisited){
            //현재노드-오른노드-왼노드 순으로 스택
            if (ptrNode != ptrPushed)
                Push(ptrNode);
            if(ptrNode->Right != EndNode)
                Push(ptrNode->Right);
            if(ptrNode->Left != EndNode)
                Push(ptrNode->Left);
            ptrPushed = ptrNode->Left;
            ptrNode = ptrNode->Left;
        }
        if(!IsStackEmpty()){
            ptrNode = Pop();

            if(ptrNode->Left != EndNode && ptrNode->Right == EndNode && ptrNode->Left != ptrVisited){
                Push(ptrNode);
                ptrNode = ptrNode->Left;
            }
            if(ptrNode->Right == EndNode || ptrNode->Right == ptrVisited){
                Visit(ptrNode);
                ptrVisited = ptrNode;
            }
        }
        else
            Finish = 1;
    } while(!Finish);
}
void main(){
    InitStack();
    InitTree();
    MakeTree();

    printf("재귀호출 순회 : ");
    rec_Traverse(HeadNode->Left);
    printf("\n스택 순회 : ");
    Stack_Traverse(HeadNode->Left);
}