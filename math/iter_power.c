int		inter_power(int nb, int power)
{
	int		result;

	if (power < 0 || (nb == 0) && power != 0)
		return (0);
	if (power == 0)
		return (1);
	result = 1;
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}
