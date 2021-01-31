int		strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (ptr[i] != c)
	{
		if (ptr[i] == '\0')
			return (NULL);
		i++;
	}
	return (i);
}
