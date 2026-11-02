/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 09:58:02 by losabati          #+#    #+#             */
/*   Updated: 2026/10/22 10:11:22 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	nelems;

	nelems = 0;
	while (begin_list != 0)
	{
		begin_list = begin_list->next;
		nelems++;
	}
	return (nelems);
}
