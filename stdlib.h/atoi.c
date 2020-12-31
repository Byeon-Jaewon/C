int		my_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	result = 0;
	while (ft_isdigit(nptr[i]) != 0)
	{
		result = 10 * result + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}
