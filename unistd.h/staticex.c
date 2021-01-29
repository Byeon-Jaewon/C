#include <stdio.h>

int test(char *lst)
{
    static int count = 1;

    while(lst[count] != '\0')
    {
        if(lst[count]=='\n')
            return count++;
        count++;
    }
    return count;
}

int main()
{
    static char *lst;

    lst = "asdfas\ndfasdf\nasdfasdfasdf\n";

    printf("%d\n", test(lst));
    printf("%d\n", test(lst));
    printf("%d\n", test(lst));
    printf("%d", test(lst));
}

//static 변수는 프로그램 내에서 한번만 초기화되며 프로그램이 종료하기전까지 데이터를 유지..