/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:40:39 by losabati          #+#    #+#             */
/*   Updated: 2026/10/29 11:34:52 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*cur;
	t_list	*ele;

	if (begin_list == NULL || cmp == NULL)
		return ;
	ele = ft_create_elem(data);
	if (ele == NULL)
		return ;
	if (*begin_list == NULL || cmp(data, (*begin_list)->data) < 0)
	{
		ele->next = *begin_list;
		*begin_list = ele;
		return ;
	}
	cur = *begin_list;
	while (cur->next != NULL && cmp(cur->next->data, data) <= 0)
		cur = cur->next;
	ele->next = cur->next;
	cur->next = ele;
}
