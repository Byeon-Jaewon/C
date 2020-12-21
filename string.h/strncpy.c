char    *my_strncpy(char *dest, char *src, unsigned int size)
{
    unsigned int    i;

    i = 0;
    while (i < size)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}