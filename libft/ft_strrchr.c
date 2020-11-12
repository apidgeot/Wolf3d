#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *r;

	r = 0;
	if (*s == (char)c)
		r = (char*)s;
	while (*s++)
	{
		if (*s == (char)c)
			r = (char*)s;
	}
	return (r);
}
