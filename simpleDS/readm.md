


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
  indexptr->Next가 deleteptr과 같다면 삭제
  1. indexptr->Next를 indexptr->Next->Next로 연결
  2. free(deleteptr) 실제 메모리에서 삭제
     