## <string.h>
C 형식 문자열(널 종료 문자열을 다룰 수 있는 함수들을 포함한다.)
**********************
#### 문자열 복사
- memcpy
- memmove
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

#### 문자열 합치기
- strcat
- strncat

#### 문자열 비교
- memcmp
- strcmp
- strcoll
- 