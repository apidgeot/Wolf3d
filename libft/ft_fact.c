int		ft_fact(int nb)
{
	int result;

	result = nb;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	if (nb >= 1)
		return (result * ft_fact(nb - 1));
	return (result);
}
