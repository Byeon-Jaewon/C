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
    1. num을 받은 후 새로운 노드(ptrNode) 생성
    2. 새로운 노드에 num값 추가
    3. ptrNode->Next 를 head->Next로 연결
    4. head-> Next를 ptrNode로 
    head -> num -> end (새로이 추가 시 head쪽으로 데이터가 push됨)</pre>
    - Pop
    <pre>
    매개변수가 없는 대신 리턴 값. 
    1. ptrNode = head->Next (가장 최근에 push된 데이터를 ptrNode로)
    2. head->Next 를 head->Next->Next로 연결
    3. free(ptrNode) ptrNode에 할당 된 메모리 회수</pre>

- 큐(배열)
  - Initialize
  <pre>
  front와 rear를 0으로 초기화해줌으로써 큐를 비움
  </pre>
  - Put과 Get
  <pre>
  put : num을 받고 큐에 추가한 다음 Rear를 1 증가
        Rear이 Max를 넘으면 다시 0으로 초기화
  get : ret변수에 큐의 첫번째 값을 넘기고 front를 1 증가
        Front가 Max를 넘기면 다시 0으로
  </pre>
- 큐(연결 리스트)
  - front와 rear의 Next를 둘 다 rear로 초기화
  - Put
  <pre>
  큐가 비어있다면, 1. front의 next를 새 노드에
  2. 새 노드의 next를 rear에
  3. rear의 next를 새 노드로 연결
  큐가 비어있지 않다면, 1. rear->next->next를 새 노드에 연결
  2. 새 노드의 next를 rear에 연결
  3. rear->next를 새 노드에 연결
  </pre>
  - Get
  <pre>
  큐가 비어있다면 메세지 출력
  큐가 비어있지 않다면, 1. deleteNode에 front->next를 연결
  2. front->next를 deleteNode->Next로 연결
  3. deleteNode->Data 출력 후 메모리 회수