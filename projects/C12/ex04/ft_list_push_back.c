/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:02:16 by losabati          #+#    #+#             */
/*   Updated: 2026/10/29 11:32:08 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*curr;

	if (begin_list == NULL)
		return ;
	new = ft_create_elem(data);
	if (new == NULL)
		return ;
	if (*begin_list == NULL)
	{
		*begin_list = new;
		return ;
	}
	curr = *begin_list;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}
