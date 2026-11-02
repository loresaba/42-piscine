/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:41:22 by losabati          #+#    #+#             */
/*   Updated: 2026/10/28 11:54:40 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*cur;
	void	*tmp;

	if (cmp == 0 || begin_list == 0 || (*begin_list) == 0)
		return ;
	cur = *begin_list;
	while (cur->next != 0)
	{
		if (cmp(cur->data, cur->next->data) > 0)
		{
			tmp = cur->data;
			cur->data = cur->next->data;
			cur->next->data = tmp;
			cur = *begin_list;
		}
		else
			cur = cur->next;
	}
}
