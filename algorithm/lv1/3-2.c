#include <stdio.h>

void main(){
    int data1, data2;
    int i, num, max;

    printf("공약수를 구할 두 정수값\n");
    
    printf("입력 1 : ");
    scanf("%d", &data1);

    printf("입력 2 : ");
    scanf("%d", &data2);

    if(data1 > data2)
        num = data1;
    else 
        num = data2;

    for(i=1 ; i<=num ; i++){
        if(((data1 % i) == 0)&& ((data2 % i)==0)){
            max = i;
            printf("%4d", i);
        }

        if((i==data1)||(i==data2)){
            printf("\n");
            break;
        }
    }
    printf("최대공약수는 : %d\n", max);
}