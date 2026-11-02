/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:35:06 by losabati          #+#    #+#             */
/*   Updated: 2026/10/28 11:53:38 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cur;

	if (begin_list1 == 0 || begin_list2 == 0)
		return ;
	if ((*begin_list1) == 0)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	cur = *begin_list1;
	while (cur->next != 0)
		cur = cur->next;
	cur->next = begin_list2;
}
