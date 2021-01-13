# unistd.h

POSIX 운영 체제 API에 대한 액세스를 제공하는 헤더파일.
***
- read
<pre>ssize_t read(int fd, void *buf, size_t n);</pre>

> - fd : 데이터를 전송해주는 대상을 가리키는 파일디스크립터.   
> - buf : 수신한 데이터를 저장할 버퍼를 가리키는 포인터.   
> - n : 수신할 최대 바이트 수. 
>   
읽어들인 데이터의 길이를 반환.   
무조건 n이 리턴되는 것이 아니라 중간에 EOF를 만난다면 거기까지 읽은 결과만을 리턴.

- write
<pre>ssize_t write(int fd, const void *buf, size_t n)</pre>

> - fd : 데이터를 전송영역을 가리키는 파일디스크립터.   
> - buf : 전송할 데이터를 가지고 있는 버퍼를 가리키는 포인터.   
> - n : 전송할 최대 바이트 수. 
성공할 시, 전달한 바이트의 수를 반환하고, 실패할 시, -1을 반환.   

- close
<pre>int close(int fd)</pre>

> - fd : 파일디스크립터
파일이 성공적으로 닫히면 지정한 파일디스크립터를 사용해 파일을 읽거나 쓸 수 없다.   
fd가 소켓을 지정한다면, 지정한 소켓을 제거한다.   
성공 시 0 반환, 실패 시 -1을 반환하고 errno에 오류값을 설정.
- lseek
- truncate