


## 자료구조
***
- 단방향 링크드리스트
  - 삽입 알고리즘
  <pre>
  ptr=C  (새로 추가될 노드)
  indexptr->NEXT 가 D가 되면 ptr을 노드에 추가(노드 삽입 위치 탐색)
  1. ptr->Next를 indexptr->Next로 연결
  2. indexptr->Next를 ptr로 연결</pre>
  - 삭제 알고리즘
  <pre>
  deleteptr=C=ptr(삭제될 노드)
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
- 스택
    - Initialize
    <pre>
    head와 end에 메모리 할당
    head->end 로 스택 초기화</pre>
    - Push
    <pre>
    1. num을 받은 후 새로운 노드 생성
    2. 새로운 노드에 num값 추가
    3. ptrNode->Next 를 head->Next로 연결
    4. head-> Next를 ptrNode로 
    head -> num -> end (새로이 추가 시 head쪽으로 데이터가 push됨)</pre>
    - Pop
    <pre>
    매개변수가 없는 대신 리턴 값. 
    1. ptrNode = head->Next (가장 최근에 push된 데이터를 ptrNode로)
    2. head->Next 를 head->Next->Next로 연결
    3. free(ptrNode) ptrNode에 할당 된 메모리 회수