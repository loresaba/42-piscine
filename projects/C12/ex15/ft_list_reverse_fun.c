/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:23:17 by losabati          #+#    #+#             */
/*   Updated: 2026/10/28 13:44:29 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_size(t_list *l)
{
	int	size;

	size = 0;
	while (l != 0)
	{
		size++;
		l = l->next;
	}
	return (size);
}

t_list	*ft_get_nth(t_list *l, int n)
{
	while (n > 0 && l != 0)
	{
		l = l->next;
		n--;
	}
	return (l);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*left;
	t_list	*right;
	void	*tmp;
	int		size;
	int		i;

	size = ft_size(begin_list);
	left = begin_list;
	i = 0;
	while (i < size / 2)
	{
		right = ft_get_nth(begin_list, size - 1 - i);
		tmp = left->data;
		left->data = right->data;
		right->data = tmp;
		left = left->next;
		i++;
	}
}
