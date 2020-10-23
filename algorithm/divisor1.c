#include <stdio.h>

void main(){
    int data, i;
    printf("약수를 구할 정수값 입력\n");
    printf("입력 : ");
    scanf("%d", &data);

    for(i=1 ; i<=data ; i++){
        if((data % i)==0){
            printf("%4d", i);
        }
    }
}