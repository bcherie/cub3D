#include "libft.h"

void	ft_lstclear(t_list **list, void (*del)(void*))
{
	t_list	*tmp;

	if (!list)
		return ;
	while (*list != NULL)
	{
		tmp = (*list)->next;
		del((*list)->content);
		free(*list);
		*list = tmp;
	}
}
