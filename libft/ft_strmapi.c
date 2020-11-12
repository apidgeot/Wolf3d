#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;
	char			*res;

	if (s == NULL || !(res = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
		return (NULL);
	i = 0;
	ptr = res;
	while (s[i])
	{
		*ptr++ = f(i, s[i]);
		i++;
	}
	return (res);
}
