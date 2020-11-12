#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;

	if (s == NULL || !(substr = ft_memalloc((len) + 1)))
		return (NULL);
	return (ft_strncpy(substr, (char*)s + start, len));
}
