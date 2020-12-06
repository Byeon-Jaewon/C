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

#### 문자열 비교
- memcmp
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

#### 문자열 검색 
- strstr
<pre>char *strstr(char *str, char *to_find)</pre>
> str에서 to_find를 검색하여 가장 먼저 나타나는 곳의 위치를 리턴한다.   
> 일치하는 문자열이 없다면, 널포인터를 리턴하게 된다.   
> 검색에서 마지막 널문자는 포함하지 않는다.