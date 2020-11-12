#include "libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	int n;

	n = 0;
	while (s1[n] && s2[n] && s1[n] == s2[n])
		n++;
	return ((unsigned char)s1[n] - (unsigned char)s2[n]);
}
