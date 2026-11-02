/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 09:54:13 by losabati          #+#    #+#             */
/*   Updated: 2026/10/29 11:29:01 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	if (begin_list == NULL)
		return ;
	new = ft_create_elem(data);
	if (new == NULL)
		return ;
	new->next = *begin_list;
	*begin_list = new;
}
