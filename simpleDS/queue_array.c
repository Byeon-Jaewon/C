#include <stdio.h>

#define MAX 100

int Queue[MAX];
int Front, Rear;

void Initialize(void);
void Put(int);
int Get(void);
void PrintQ(void);

void Initialize(void){
    Front = Rear = 0;
}

void Put(int num){
    Queue[Rear++] = num;

    if(Rear >= MAX)
        Rear = 0;
}
int Get(void){
    int ret;
    ret = Queue[Front++];

    if(Front >= MAX)
        Front = 0;

    return ret;
}
void PrintQ(void){
    int i;
    printf("Front -> ");

    for(i=Front ; i<Rear ; i++)
        printf("%d -> ", Queue[i]);

    printf("Rear\n");
}

void main(){
    int ret;
    Initialize();

    Put(1);
    Put(3);
    Put(5);
    Put(10);
    Put(15);

    printf("5번 put 결과\n");
    PrintQ();

    ret = Get();
    ret = Get();
    ret = Get();

    printf("3번 get 결과\n");
    PrintQ();

    ret=Get();
    ret=Get();

    printf("2번 get결과\n");
    PrintQ();
}