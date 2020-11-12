#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*i;

	if (!(i = malloc(size)))
		return (NULL);
	ft_bzero(i, size);
	return (i);
}
