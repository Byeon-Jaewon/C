//한번의 read호출로 \n기준 한줄씩 받아오려면?
//버퍼에 다 받아놓고...하면 되나...?


#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUF_SIZE    1024

int gnl(int fd, char *line){
    static char     *tmp;
    int             read_size;

    read_size = read(fd, line, BUF_SIZE);
    line[read_size] = '\0';
    printf("%d\n", read_size);
    return (1);
}

int main(void)
{
    char    buf[BUF_SIZE];
    int     fd;
    int     i;

    i = 0;
    if ((fd = open("asdf.txt", O_RDONLY)) > 0)
    {
        read(fd, buf, 5);
        puts(buf);
        read(fd, buf, 5);
        puts(buf);
        read(fd, buf, 5);
        puts(buf);
        close(fd);
    }
    else
        printf("error");
    return 0;
}