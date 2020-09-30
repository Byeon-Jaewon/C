


## 자료구조
***
- 단방향 링크드리스트
  - 삽입 알고리즘
  <pre> ptr=C  (새로 추가될 노드)
  indexptr->NEXT 가 D가 되면 ptr을 노드에 추가(노드 삽입 위치 탐색)
  1. ptr->Next를 indexptr->Next로 연결
  2. indexptr->Next를 ptr로 연결</pre>
  - 삭제 알고리즘
  <pre>deleteptr=C=ptr(삭제될 노드)
  indexptr->Next가 ptr과 같다면 deleteptr에 ptr
  1. indexptr->Next를 indexptr->Next->Next로 연결
  2. free(deleteptr) 실제 메모리에서 삭제
- 양방향 링크드리스트
    - 삽입 알고리즘 
    <pre>
    ptr=C(추가될 노드)
    indexptr->Next가 D가 되면 노드 추가
    1. ptr->Next를 indexptr->Next로 연결
    2. indexptr->Next->Prev를 ptr로 연결
    3. indexptr->Next를 ptr로 연결
    4. ptr->Prev를 indexptr로 연결</pre>
    - 삭제 알고리즘
    <pre>
    deleteptr=C=ptr (삭제될 노드)
    indexptr->Next가 ptr과 같다면 delteptr에 indexptr
    1. indexptr->Next를 indexptr->Next->Next로 연결
    2. indexptr->Next->Next->Prev를 indexptr로 연결
    3. free(deleteptr)
     