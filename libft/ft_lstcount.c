#include "libft.h"

size_t	ft_lstcount(t_list *list)
{
	size_t	i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}
