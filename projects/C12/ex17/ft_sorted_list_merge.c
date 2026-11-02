/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:57:19 by losabati          #+#    #+#             */
/*   Updated: 2026/10/28 12:39:55 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include "ft_list.h"

void	merge_loop(t_list ***tail, t_list **cur1, t_list **cur2,
		int (*cmp)())
{
	while (*cur1 != 0 && *cur2 != 0)
	{
		if (cmp((*cur1)->data, (*cur2)->data) <= 0)
		{
			**tail = *cur1;
			*cur1 = (*cur1)->next;
		}
		else
		{
			**tail = *cur2;
			*cur2 = (*cur2)->next;
		}
		*tail = &(**tail)->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*cur1;
	t_list	*merg;
	t_list	**tail;

	if (begin_list1 == 0 || begin_list2 == 0 || cmp == 0)
		return ;
	cur1 = *begin_list1;
	merg = 0;
	tail = &merg;
	merge_loop(&tail, &cur1, &begin_list2, cmp);
	if (cur1 != 0)
		*tail = cur1;
	else
		*tail = begin_list2;
	*begin_list1 = merg;
}
