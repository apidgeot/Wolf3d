int		ft_intlen(int n)
{
	int				i;
	unsigned int	k;

	i = 0;
	if (n < 0)
	{
		k = -n;
		i++;
	}
	else
		k = n;
	while (k > 9)
	{
		k /= 10;
		i++;
	}
	i++;
	return (i);
}
