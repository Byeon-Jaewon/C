#include <unistd.h>

void    putstr(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int     mystrcmp(char *s1, char *s2)
{
    int     i;

    i = 0;
    while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0'))
        i++;
    return (s1[i] - s2[i]);
}

int     main(int argc, char *argv[])
{
    char    *tmp;
    int     i;
    int     j;

    i = 1;
    while (i < argc - 1)
    {
        j = i + 1;
        while (j < argc)
        {
            if (mystrcmp(argv[i], argv[j]) > 0)
            {
                tmp = argv[i];
                argv[i] = argv[j];
                argv[j] = tmp;
            }
            j++;
        }
        i++;
    }
    i = 1;
    while (i < argc)
    {
        putstr(argv[i]);
        write(1, "\n", 1);
        i++;
    }
}