# stdlib.h
stdlib.h는 C언어의 표준 라이브러리로, 문자열 변환, 난수 생성, 동적메모리 관리 등의 함수를 포함한다.
***
## 문자열 변환
- atoi
- atol
- atof
- strol
- strtoul
- strtod
## 난수 생성
- rand
- srand
## 동적 메모리 관리
- malloc
<pre> void *malloc(size_t size)</pre>

> 인자로 전달된 크기만큼의 메모리를 할당 후에 그 메모리의 시작 주소값을 리턴한다.   
> 메모리 할당에 실패한다면, 널포인터를 리턴한다.   
> 할당한 메모리는 반드시 free로 해제해야한다.
- calloc
<pre>void *calloc(size_t nmemb, size_t size) </pre>

> size크기의 변수를 nmemb개 만큼 저장할 수 있는 메모리 공간을 할당.   
> 할당된 공간의 값을 모두 0으로 초기화한다.   
- realloc
- free