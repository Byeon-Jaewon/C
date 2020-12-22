# <string.h>
C 형식 문자열(널 종료 문자열을 다룰 수 있는 함수들을 포함한다.)
   
size_t 타입
> C에서 임의의 객체가 가질 수 있는 최대크기를 나타냄. 크기를 표현하므로 부호없는 정수 이용.   
> size_t타입을 쓰는 이유는 시스템에서 주소지정이 가능한 메모리영역과 일치하는 크기를 선언하는 이식 가능한 방법을 제공하기 위해.

**********************
## 문자열 복사
- strcpy
<pre>char strcpy(char *dest, char *src)</pre>
> src가 가리키는 문자열을 dest가 가리키는 곳에 복사한다.   
> 오버플로우를 방지하기 위해 dest가 가리키는 배열의 크기는 반드시 src문자열의 크기와 같거나 이보다 커야하며 복사 영역이 src와 겹치면 안된다.   
> dest가 리턴된다.
- strncpy
<pre>char strncpy(char *dest, char *src, unsigned int n)</pre>
> src에서 dest로 src의 처음 n개의 문자들만 복사.   
> n보다 src의 문자수가 적다면 모자란 부분은 \0으로 취급되어 dest에 복사된다.   
> dest를 리턴.   
- strlcpy
<pre>unsinged int strlcpy(char *dest, char *src, unsigned int size)</pre>
> dst의 크기가 0이 아닌 경우, (size-1)만큼의 문자를 src에서 dst로 복사 후 null 종료한다.   
> size가 0 또는 dest문자열보다 큰 경우 종료   
> dst[size]에 \0을 붙혀준다.   
> src의 크기를 리턴한다.

## 문자열 합치기
- strcat
<pre>char *strcat(char *dest, char *src)</pre>
> dest의 끝에 src를 더하게 된다.   
> 이때 dest의 마지막 널 문자는 src의 첫문자가 덮어 씌우게 되고   
> src의 마지막 널문자가 dest의 끝에 붙어 새로운 문자열이 된다.   
> dest가 리턴된다.
- strncat
<pre>char *strcat(char *dest, char *src, unsigned int nb)</pre>
> src의 처음 nb개 문자들을 dest끝에 덧붙히고, dest끝에는 자동으로 NULL문자까지 붙여진다.   
> 만일 src의 문자열 길이가 nb보다 작다면, src의 NULL문자까지만 붙여진다.   
> dest가 리턴된다.
- strlcat
<pre>unsigned int strlcat(char *dest, char *src, unsigned int size)</pre>
> size가 dest길이+null문자 보다 클때부터 src가 들어간다.   
> dest의 마지막 위치에 src를 size-(dest의 길이)-1 만큼 복사하고 끝에 널문자를 삽입한다.   
> 결합되는 문자열의 총 길이를 반환한다.

## 문자열 비교
- strcmp
<pre> int strcmp(char *s1, char *s2) </pre>
> 문자열 s1과 s2를 비교한다.   
> 첫문자부터 비교를 시작하고, 만일 같다면 두 문자가 다를때까지나 null에 도달할 때 까지 계속 비교를 수행한다.   
> 문자열이 일치한다면 0,   
> 일치하지 않는 첫 문자를 비교해 s1 - s2를 리턴한다.
- strncmp
<pre>int strncmp(char *s1, char *s2, unsigned int n)</pre>
> s1의 처음 n개 문자를 s2의 처음 n개 문자와 비교한다.   
> 두 문자가 다르거나, Null에 도달하거나, n개의 문자들을 비교할 때까지 수행한다.   
> n개의 문자가 모두 일치한다면 0을 리턴    
> 비교한 n개의 문자 중 최초로 일치하지 않는 문자에서, s1 - s2를 리턴한다.

## 문자열 검색 
- strstr
<pre>char *strstr(char *str, char *to_find)</pre>
> str에서 to_find를 검색하여 가장 먼저 나타나는 곳의 위치를 리턴한다.   
> 일치하는 문자열이 없다면, 널포인터를 리턴하게 된다.   
> 검색에서 마지막 널문자는 포함하지 않는다.

## 메모리
- memset
<pre>void* memset(void* ptr, int value, size_t num);</pre>
> ptr로 시작하는 메모리 주소부터 num개의 바이트를 value값으로 채운다.   
> 이 때 value는 unsigned char로 형변환 된다.
> ptr이 리턴된다.
- memcpy
<pre>void* memcpy(void* dest, const void* src, size_t num);</pre>
> src가 가리키는 곳 부터 num 바이트 만큼을 dest가 가리키는 곳에 복사한다.   
> dest와 src의 타입은 무관. src의 널문자를 검사하지 않고 정확히 num바이트 만큼을 복사.   
> 오버플로우를 방지하기 위해 dest와 src가 가리키는 배열의 크기는 num바이트 이상이여야 하며, 서로 겹치면 안된다.
> dest가 리턴된다.
- memmove
<pre>void* memmove(void* dest, const void* src, size_t num);</pre>
> src가 가리키는 곳부터 num바이트 만큼을 dest가 가리키는 곳으로 옮긴다.   
> 메모리 복사 수행 시, 중간에 버퍼를 이용하게 되므로 범위가 겹쳐져도 문제 없다.   
>  dest와 src의 타입은 무관. src의 널문자를 검사하지 않고 정확히 num바이트 만큼을 복사.   
> 오버플로우를 방지하기 위해 dest와 src가 가리키는 배열의 크기는 num바이트 이상이여야 하며, 서로 겹치면 안된다.
> dest가 리턴된다.
- memchr
<pre>void *memchr(const void *ptr, int value, size_t n); </pre>
> ptr이 가리키는 메모리의 처음 n바이트 중에서 처음으로 value와 일치하는 값의 주소를 리턴.   
> value는 찾을 값으로 int 로 전달되지만 함수 내부적으로는 한바이트씩 비교하기 때문에 이 값은 unsigned char 로 변환되어 사용됨.   
> 메모리블록에서 value와 일치하는 값이 있다면 그 곳의 주소를 리턴하고 값을 찾지 못한다면 NULL을 리턴.
- memcmp
<pre>int memcmp(const void* ptr1, const void* ptr2, size_t num);</pre>
> 두개의 메모리 블록 비교   
> ptr1이 가리키는 처음 num바이트의 데이터와 ptr2가 가리키는 처음 num바이트의 데이터를 비교하여 이들이 같다면 0을 리턴하고 다르다면 0이 아닌 값을 리턴.   
> ptr1 - ptr2 를 리턴..