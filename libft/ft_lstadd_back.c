/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 01:25:53 by bcherie           #+#    #+#             */
/*   Updated: 2021/04/29 01:26:00 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
