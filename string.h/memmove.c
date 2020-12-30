void	*my_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_ptr;
	unsigned char		*src_ptr;

	dest_ptr = (unsigned char*)dest;
	src_ptr = (unsigned char*)src;
	i = 1;
	if (src_ptr < dest_ptr)
	{
		while (i <= n)
		{
			dest_ptr[n - i] = src_ptr[n - i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			*dest_ptr = *src_ptr;
			dest_ptr++;
			src_ptr++;
		}
	}
	return (dest);
}
