#include <stdio.h>

void main(){
    int MaxLine = 5;
    int data;
    int MInteger;
    int LineNum;

    printf("지그재크 숫자출력\n");

    for(LineNum = 1 ; LineNum <= MaxLine ; LineNum++){
        if((LineNum%2)==0){
            for(data=LineNum*5 ; data>=(LineNum*5)-4 ; data--){
                printf("%d\t",data);
            }
            printf("\n");
        }
        else{
            for(data=(5*(LineNum-1))+1 ; data<=(5*(LineNum-1))+5 ; data++){
                printf("%d\t", data);
            }
            printf("\n");
        }
    }

}