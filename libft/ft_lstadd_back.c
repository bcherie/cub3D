#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*list);
	if (!new)
		return ;
	else if (!*list)
	{
		*list = new;
		return ;
	}
	last->next = new;
}
