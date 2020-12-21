unsigned int    my_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int    i;
    unsigned int    j;

    i = 0;
    while (src[i] != '\0')
        i++;
    if (dest == 0 || src == 0)
        return (0);
    if (size != 0)
    {
        j = 0;
        while (src[j] != '\0' && j < size - 1)
        {
            dest[j] = src[j];
            j++;
        }
        dest[j] = '\0';
    }
    return (i);
}