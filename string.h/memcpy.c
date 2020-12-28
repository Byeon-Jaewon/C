void	*my_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*tmp;
	unsigned char			*s;

	tmp = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (n != 0)
	{
		*tmp = *s;
		tmp++;
		s++;
		n--;
	}
	return (dest);
}