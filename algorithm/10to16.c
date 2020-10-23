#include <stdio.h>

void main(){
    char key;
    int data;

    printf("10진수->16진수 변환\n");
    printf("10->16 : [A]\n");
    printf("16->10 : [B]\n");
    printf("a나 b를 누르세용");

    scanf("%c", &key);
    printf("변환할 숫자 입력 : ");

    if(key=='a'){
        scanf("%d",&data);
        printf("10진수 값 : %d --> 16진수 값 : %x\n",data, data);
    }
    else if(key =='b'){
        scanf("%x", &data);
        printf("16진수값 : %x --> 10진수 값 : %d\n", data, data);
    }
    else
        printf("a와b만 사용하세용");
}