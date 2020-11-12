#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	register char		*dp;
	register char const	*sp;

	dp = dst;
	sp = src;
	if (!dst && !src)
		return (NULL);
	if (dp < sp)
	{
		while (len-- > 0)
			*dp++ = *sp++;
	}
	else
	{
		dp += len;
		sp += len;
		while (len-- > 0)
			*--dp = *--sp;
	}
	return (dst);
}
