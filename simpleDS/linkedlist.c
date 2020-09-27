#include <stdio.h>
#include <stdlib.h>

//노드와 링크가 있는 구조체
typedef struct _NODE{
    char Data;
    struct _NODE *Next;
} NODE;

NODE *head, *end, *temp;
NODE *temp1, *temp2, *temp3, *temp4;

void Initialize(void);
void InsertNode(NODE *);
void DeleteNode(NODE *);

void Initialize(void){
    NODE *ptr;
    head = (NODE *)malloc(sizeof(NODE));
    end = (NODE *)malloc(sizeof(NODE));

    temp1 = (NODE *)malloc(sizeof(NODE));
    temp1->Data = 'A';
    head->Next = temp1;
    temp1->Next = end;
    end->Next = end;
    ptr = temp1;

    temp2 = (NODE *)malloc(sizeof(NODE));
    temp2->Data = 'B';
    ptr->Next = temp2;
    temp2->Next = end;
    ptr = temp2;

    temp3 = (NODE *)malloc(sizeof(NODE));
    temp3->Data = 'D';
    ptr->Next = temp3;
    temp3->Next = end;
    ptr = temp3;

    temp4 = (NODE *)malloc(sizeof(NODE));
    temp4->Data = 'E';
    ptr->Next = temp4;
    temp4->Next = end;
    ptr = temp4;
}
//노드 추가 함수
void InsertNode(NODE *ptr){
    NODE *indexptr;
//head부터 검사하기 시작해서 ptr->data 보다 indexptr->Next->Data가 클 때 삽입
    for(indexptr = head->Next; indexptr != end; indexptr = indexptr->Next){
        if((indexptr->Data < ptr->Data)&&(indexptr->Next->Data > ptr->Data)){
            break;
        }
    }
    ptr->Next = indexptr->Next;
    indexptr->Next = ptr;
}
//노드 삭제 함수
void DeleteNode(NODE *ptr){
    NODE *indexptr;
    NODE *deleteptr;

    for(indexptr = head; indexptr != end; indexptr = indexptr->Next){
        if(indexptr->Next->Data == ptr->Data){
            deleteptr = indexptr->Next;
            break;
        }
    }
    indexptr->Next = indexptr->Next->Next;
    free(deleteptr);
}
void main(){
    NODE *ptr;
    int i = 0;
    Initialize();

    printf("노드 C 삽입 전\n");
    ptr= head->Next;

    for(i=0;i<4;i++){
        printf("%c", ptr->Data);
        ptr=ptr->Next;
    }
//새 노드 생성
    temp = (NODE *)malloc(sizeof(NODE));
    temp->Data='C';
//노드 삽입
    InsertNode(temp);
    printf("\n노드 삽입 후\n");
    ptr=head->Next;

    for(i=0;i<5;i++){
        printf("%c", ptr->Data);
        ptr=ptr->Next;
    }
//노드 삭제
    DeleteNode(temp);
    printf("\n삭제 후\n");
    ptr=head->Next;

    for(i=0;i<4;i++){
        printf("%c", ptr->Data);
        ptr=ptr->Next;
    }
}