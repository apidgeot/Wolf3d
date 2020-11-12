#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t n;

	n = ft_strlen((char*)needle);
	if (ft_memcmp(haystack++, needle, n) == 0)
		return ((char*)haystack - 1);
	while (*haystack != '\0')
	{
		if (ft_memcmp(haystack++, needle, n) == 0)
			return ((char*)haystack - 1);
	}
	return (NULL);
}
