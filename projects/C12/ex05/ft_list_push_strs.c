/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:14:40 by losabati          #+#    #+#             */
/*   Updated: 2026/10/29 11:32:59 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	t_list	*ele;
	int		i;

	if (size <= 0 || strs == NULL)
		return (NULL);
	list = NULL;
	i = 0;
	while (i < size)
	{
		ele = ft_create_elem(strs[i]);
		if (ele == NULL)
			return (list);
		ele->next = list;
		list = ele;
		i++;
	}
	return (list);
}
