/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:41:47 by losabati          #+#    #+#             */
/*   Updated: 2026/10/28 13:42:57 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	if (begin_list == NULL || cmp == NULL)
		return ;
	prev = NULL;
	curr = *begin_list;
	while (curr != NULL)
	{
		next = curr->next;
		if (cmp(curr->data, data_ref) == 0)
		{
			if (prev == NULL)
				*begin_list = next;
			else
				prev->next = next;
			if (free_fct != NULL)
				free_fct(curr->data);
			free(curr);
		}
		else
			prev = curr;
		curr = next;
	}
}
