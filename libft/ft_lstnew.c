#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*contcopy;

	list = (t_list*)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->next = NULL;
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		contcopy = (void*)malloc(content_size);
		list->content = ft_memcpy(contcopy, (void*)content, content_size);
		list->content_size = content_size;
	}
	free(list->next);
	return (list);
}
