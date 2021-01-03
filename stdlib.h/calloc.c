void	*my_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if (!(ptr = malloc(size * nmemb)))
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}