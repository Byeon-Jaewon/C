char    *my_strstr(char *str, char *to_find)
{
    char    *cp;
    char    *fp;
    int     i;

    i = 0;
    if (*to_find == '\0')
        return (str);
    while (*str != '\0')
    {
        if (*str == *to_find)
        {
            cp = str + 1;
            fp = to_find + 1;
            while ((*fp != '\0') && (*cp != '\0') && (*cp == *fp))
            {
                cp++;
                fp++;
            }
            if (*fp == '\0')
                return (str);
            if (*cp == '\0')
                break;
        }
        str++;
    }
    return (char *)(0);
}