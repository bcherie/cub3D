#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;
	t_list *next;

	last = ft_lstlast(*lst);
	if (!new)
		return ;
	else if (!*lst)
	{
		*lst = new;
		return ;
	}
	last->next = new;
}
