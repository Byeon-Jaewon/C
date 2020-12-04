int		iterative_fac(int nb)
{
	int		result;
	int		i;

	i = 1;
	result = 1;
	if (nb == 1)
		return (1);
	else if (nb <= 0)
		return (0);
	while (i <= nb)
	{
		result = result * i;
		i++;
	}
	return (result);
}
