/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:26:23 by losabati          #+#    #+#             */
/*   Updated: 2026/10/28 10:42:51 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;

	while (begin_list != NULL)
	{
		tmp = begin_list;
		begin_list = begin_list->next;
		if (free_fct != NULL)
			free_fct(tmp->data);
		free(tmp);
	}
}
