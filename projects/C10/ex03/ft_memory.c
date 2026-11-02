/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:10:37 by losabati          #+#    #+#             */
/*   Updated: 2026/10/25 17:14:11 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_memncpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

void	*ft_realloc(t_hexdump *h, void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = NULL;
	if (new_size <= old_size)
		return (ptr);
	if (new_size != 0)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
		{
			ft_puterr(h->prgname, NULL, errno, ERR_NONE);
			return (NULL);
		}
	}
	if (ptr != NULL)
	{
		ft_memncpy(new_ptr, ptr, old_size);
		free(ptr);
	}
	return (new_ptr);
}
