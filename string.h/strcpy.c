char    *my_strcpy(char *dest, char *src)
{
    int     i;

    while(dest[i] != '\0' && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}