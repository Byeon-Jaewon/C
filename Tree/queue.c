#include "node.h"
#define MAX 100

NODE *Queue[MAX];
int Front, Rear;

void InitQ(void);
void Put(NODE *);
NODE *Get(void);
int IsQEmpty(void);

void InitQ(void){
    Front = Rear = 0;
}
void Put(NODE *ptrNode){
    Queue[Rear] = ptrNode;
    Rear = (Rear++)%MAX;
}
NODE *Get(void){
    NODE *ptrNode;
    if(!IsQEmpty()){
        ptrNode = Queue[Front];
        Front = (Front++) % MAX;
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

