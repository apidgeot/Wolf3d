#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*curr;
	t_list	*next;

	curr = *alst;
	while (curr)
	{
		next = curr->next;
		del(curr->content, curr->content_size);
		free(curr);
		curr = next;
	}
	*alst = NULL;
}
