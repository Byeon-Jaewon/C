#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

void MakeRandomNum(void);
void MergeSort(int [], int, int);
void DisplayBuffer(void);
int IsNumExit(int, int);
int Buf[MAX];
int temp[MAX];

void MakeRandomNum(void){
    int i, Num;
    i = 1;
    srand((unsigned)time(NULL));
    Buf[0] = 100;
    while(i<MAX){
        Num = rand()%MAX;

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
void MergeSort(int data[], int left, int right){
    int i, j, k, cen;
    if(right > left){
        cen = (left+right)/2;
        MergeSort(data, left, cen);
        MergeSort(data, cen+1, right);

        for(i=cen+1 ; i>left ; i--)
            temp[i-1] = data[i-1];
        for(j=cen ; j<right ; j++)
            temp[right+cen-j] = data[j+1];
        for(k=left ; k<=right ; k++)
            data[k] = (temp[i]<temp[j]) ? temp[i++] : temp[j--];
    }

}
void main(){
    printf("정렬데이터 초기화\n");
    MakeRandomNum();
    DisplayBuffer();

    printf("정렬 후\n");
    MergeSort(Buf, 0, MAX-1);
    DisplayBuffer();
    printf("\n");
}