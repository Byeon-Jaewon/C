#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

typedef struct _NODE{
    int Data;
    struct _NODE *Next;
}NODE;

NODE *Front[10];
NODE *Rear[10];
NODE *ptrNode;
int Buf[MAX];


void MakeRandomNum(void);
void RadixSort(void);
void DisplayBuffer(void);
int IsNumExit(int, int);
void InitQ(void);
void Put(int, int);
int Get(int);



void MakeRandomNum(void){
    int i, Num;
    i = 1;
    srand((unsigned)time(NULL));
    Buf[0] = 100;
    while(i<MAX){
        Num = rand()%100;

        if(!IsNumExit(Num, i)){
            Buf[i] = Num;
            i++;
        }
    }
}
void DisplayBuffer(void){
    int i;
    for(i=0 ; i < MAX ; i++){
        if((i%10) == 0){
            printf("\n");
        }
        printf("%4d ", Buf[i]);
    }
    printf("\n");
}
int IsNumExit(int number, int index){
    int i;
    for(i = 0 ; i < index ; i++){
        if(Buf[i] == number){
            return TRUE;
        }
    }
    return FALSE;
}
void InitQ(void){
    int i;

    for(i=0 ; i<MAX ; i++){
        Front[i] = (NODE *)malloc(sizeof(NODE));
        Rear[i] = (NODE *)malloc(sizeof(NODE));

        Front[i]->Next = Rear[i];
        Rear[i]->Next = Rear[i];
    }
}
void Put(int index, int num){
    ptrNode = (NODE *)malloc(sizeof(NODE));
    ptrNode->Data = num;

    if(Front[index]==Rear[index]){
        Front[index]->Next = ptrNode;
        ptrNode->Next = Rear[index];
        Rear[index]->Next = ptrNode;
    }
    else{
        Rear[index]->Next->Next = ptrNode;
        ptrNode->Next = Rear[index];
        Rear[index]->Next = ptrNode;
    }
}
int Get(int index){
    int ret;
    NODE *deleteNode;

    if(Front[index]->Next == Rear[index])
        return -1;
    else {
        deleteNode = Front[index]->Next;
        Front[index]->Next = deleteNode->Next;
        ret = deleteNode ->Data;

        free(deleteNode);
    }
    return ret;
}
///////////////////////////////////////////////////
void RadixSort(void){
    int i, num, digit, j;
    j=0;

    //1의자릿수로 정렬
    for(i=0 ; i<MAX ; i++){
        num = Buf[i];
        digit = num%MAX;
        Put(digit, num);
    }
    printf("\n 1의자릿수로 정렬된 리스트\n");

    for(i=0 ; i<MAX ; i++){
        printf("\n %d : ", i);
        while(1){
            num = Get(i);
            if(num != -1){
                printf("%2d ",num);
                Buf[j++] = num;
            }
            else
                break;
        }
    }
    printf("\n\n1차 정렬 후 Buf 안 데이터들\n");
    DisplayBuffer();

    //10의 자릿수로 정렬
    j=0;
    for(i=0 ; i<MAX ; i++){
        num = Buf[i];
        digit = num/MAX;
        Put(digit, num);
    }
    printf("\n10의자릿수로 정렬된 리스트\n");
    for(i=0 ; i<MAX ; i++){
        printf("\n %d : ",i);
        while(1){
            num = Get(i);

            if(num!=-1){
                printf("%2d ", num);
                Buf[j++] = num;
            }
            else   
                break;
        }
    }
    printf("\n\n 2차 정렬 후 Buf안 데이터\n");
    DisplayBuffer();
}
//////////////////////////////////////////////////////////////////
void main(){
    InitQ();
    printf("정렬할 데이터 초기화\n");
    MakeRandomNum();
    DisplayBuffer();

    RadixSort();
    printf("\n");
}