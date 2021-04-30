/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 01:26:52 by bcherie           #+#    #+#             */
/*   Updated: 2021/04/29 01:27:02 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
