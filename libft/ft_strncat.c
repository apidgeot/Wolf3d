#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *sone;

	sone = s1;
	while (*s1)
		s1++;
	while (n--)
	{
		if (!(*s1++ = *s2++))
			return (sone);
	}
	*s1 = 0;
	return (sone);
}
