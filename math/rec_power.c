int		rec_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (nb * power(nb, rec_power - 1));
}
