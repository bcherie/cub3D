/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:08:13 by bcherie           #+#    #+#             */
/*   Updated: 2020/11/21 18:02:21 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s)
{
	int		x;
	char	c;

	x = 0;
	if (!s)
		return ;
	while (s[x] != '\0')
	{
		c = s[x];
		write(1, &c, 1);
		x++;
	}
}
