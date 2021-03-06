void	*my_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest_ptr;
	unsigned char		*src_ptr;
	size_t				i;

	dest_ptr = (unsigned char*)dest;
	src_ptr = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		if (dest_ptr[i] == (unsigned char)c)
			return ((void*)(dest + i + 1));
		i++;
	}
	return (NULL);
}