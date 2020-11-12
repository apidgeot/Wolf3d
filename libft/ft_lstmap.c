#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!lst || !(new = malloc(sizeof(lst))))
		return (NULL);
	new = (f(lst));
	new->next = ft_lstmap(lst->next, f);
	return (new);
}
