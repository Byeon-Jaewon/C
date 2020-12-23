# ctype.h

ctype.h는 C언어의 표준 라이브러리로, 문자들을 조건에 맞는지 검사하고 변환하는 함수들을 포함한다.
*******
|  함수원형 |설명|
|:---:|:---:|
|int isalnum(int c)|c가 알파벳이나 숫자면 0이 아닌 값을 반환.|
|int isalpha(int c)|c가 알파벳이면 0이 아닌 값을 반환.|
|int iscntrl(int c)|c가 제어문자면 0이 아닌 값을 반환.|
|int isdigit(int c)|c가 숫자라면 0이 아닌 값을 반환.|
|int isgraph(int c)|c가 그래픽문자라면 0이 아닌 값을 반환.|
|int islower(int c)|c가 알파벳 소문자라면 0이 아닌 값을 반환.|
|int isprint(int c)|c가 출력가능한 문자라면 0이 아닌 값 반환.|
|int ispunct(int c)|c가 구두점 문자라면 0이 아닌 값을 반환.|
|int isspace(int c)|c가 공백문자라면 0이 아닌 값을 반환.|
|int isupper(int c)|c가 알파벳 대문자라면 0이 아닌 값을 반환.|
|int isxdigit(int c)|c가 16진수라면 0이 아닌 값을 반환.|
|int tolower(int c)|알파벳 대문자 c를 소문자로 변환.|
|int toupper(int c)|알파벳 소문자 c를 대문자로 변환.|
|int toascii(int c)|정수 값을 7비트 ASCII문자로 변환.|
