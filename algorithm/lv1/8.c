#include <stdio.h>

int gcd(int, int);

int gcd(int x, int y){
    static int ExecNum = 1;
    printf("%d회 실시\n", ExecNum++);

    if(y!=0){
        printf("x: %d, y: %d\n", x, y);
        return gcd(y,x%y);
    }
    else{
        return x;
    }
}
void main(){
    int result;
    int num1, num2;
    printf("최대공약수 구하기\n");
    printf("두개 수 입력\n");
    scanf("%d %d", &num1, &num2);

    result = gcd(num1, num2);
    printf("%d와 %d의 최대공약수는 : %d\n", num1, num2, result);
}