#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	char	*p;
	int		len;

	len = 0;
	while (src[len])
		len++;
	if (!(str = malloc(len + 1)))
		return (0);
	p = str;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (str);
}
