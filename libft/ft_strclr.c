void	ft_strclr(char *s)
{
	if (s != 0)
	{
		while (*s)
		{
			*s = '\0';
			s++;
		}
	}
}
