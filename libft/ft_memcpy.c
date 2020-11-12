#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dp;
	const char	*sp;

	dp = (char*)dest;
	sp = (const char*)src;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n > 0)
	{
		n--;
		*dp++ = *sp++;
	}
	return (dest);
}
