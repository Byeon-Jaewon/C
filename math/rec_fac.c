int		recursive_fac(int nb)
{
	if (nb == 1)
		return (1);
	else if (nb <= 0)
		return (0);
	return (nb * recursive_fac(nb - 1));
}
