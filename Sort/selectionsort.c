#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

void MakeRandomNum(void);
void SelectionSort(void);
void DisplayBuffer(void);
int IsNumExit(int, int);
int Buf[MAX];

void MakeRandomNum(void){
    int i, Num;
    i = 1;
    Buf[0] = 100;
    while(i<MAX){
        Num = rand() % MAX;

        if(!IsNumExit(Num, i)){
            Buf[i]=Num;
            i++;
        }
    }
}
void SelectionSort(void){
    int i, j, min, dummy;

    for(i=0; i<MAX; i++){
        min = i;
        for(j = i+1 ; j < MAX ; j++){
            if(Buf[j]<Buf[min]){
                min = j;
            }
        }
        dummy = Buf[min];
        Buf[min] = Buf[i];
        Buf[i] = dummy;
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

void main(){
    printf("정렬할 데이터 초기화\n");
    MakeRandomNum();
    DisplayBuffer();

    printf("정렬 후 데이터\n");
    SelectionSort();
    DisplayBuffer();
    printf("\n");
}