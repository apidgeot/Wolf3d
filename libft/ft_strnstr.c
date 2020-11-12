#include "libft.h"

char	*ft_strnstr(const char *h, const char *need, size_t len)
{
	size_t b;
	size_t n;

	b = ft_strlen((char*)h);
	n = ft_strlen((char*)need);
	if (n == 0)
		return ((char*)h);
	if (n > len)
		return (NULL);
	if ((ft_memcmp(h++, need, n) == 0) && (len >= 1))
		return ((char*)h - 1);
	while ((*h != '\0') && (len > 0))
	{
		if ((ft_memcmp(h, need, n) == 0) && ((len - 1) >= n))
			return ((char*)h);
		h++;
		len--;
	}
	return (NULL);
}
