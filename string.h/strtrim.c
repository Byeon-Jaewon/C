char	*my_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] != '\0' && my_strchr(set, s1[start]) != 0)
		start++;
	end = my_strlen(s1);
	while (end > start && my_strchr(set, s1[end]) != 0)
		end--;
	end++;
	if (!(p = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	my_strlcpy(p, s1 + start, end - start + 1);
	return (p);
}
