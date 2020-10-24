#include <stdio.h>

void main(){
    int i, j, count =1;
    long sum = 0;

    printf("1부터 1000사이의 수 중에서 소수를 구하기\n");
    printf("%d\t",1);

    for(i=1 ; i<=1000 ; i++){
        for(j=2 ; j<i ; j++){
            if((i%j)==0){
                break;
            }
        }
        if(i==j){
            printf("%d\t", i);
            count ++;
            if((count%8)==0){
                printf("\n");
            }
        }
    }
    printf("\n 1부터 1000사이의 소수 %d 개\n", count);
}