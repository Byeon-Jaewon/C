#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    int num, i, data;
    srand(time(NULL));
    num = rand()%10;
    i=1;
    printf("0부터 9까지 숫자 입력\n");

    while(1){
        printf("[%2d번째 도전] : ", i);
        scanf("%d", &data);

        if(data < num){
            printf("%d보다 큽니다\n",data);
        }
        else if(data >num){
            printf("%d보다 작습니다\n",data);
        }
        else {
            printf("%2d번째 만에 맞춤\n", i);
            break;
        }
        i++;
    }
}