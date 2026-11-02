/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 16:52:10 by losabati          #+#    #+#             */
/*   Updated: 2026/10/27 08:33:17 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_print_rept(t_hexdump *h, unsigned char *ptr, unsigned int i,
	unsigned int line_size)
{
	if (i >= 16 && line_size == 16 && ft_is_same_line(ptr + i - 16, ptr + i))
	{
		if (!h->in_rept)
		{
			h->in_rept = 1;
			ft_putstr(STDOUT, "*\n");
		}
		return (1);
	}
	return (0);
}

void	ft_print_memory_line(t_hexdump *h, unsigned char *ptr, unsigned int i,
	unsigned int line_size)
{
	if (!ft_print_rept(h, ptr, i, line_size))
	{
		ft_putaddr(h, (unsigned long)i);
		ft_putstr(STDOUT, " ");
		if (h->is_canonical)
		{
			ft_putstr(STDOUT, " ");
			ft_puthex_can(ptr + i, line_size);
		}
		else
			ft_puthex(ptr + i, line_size);
		if (h->is_canonical)
		{
			ft_putstr(STDOUT, "  ");
			ft_puttext(ptr + i, line_size);
		}
		ft_putstr(STDOUT, "\n");
		h->in_rept = 0;
	}
}

void	ft_print_memory(t_hexdump *h, void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	line_size;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		line_size = size - i;
		if (line_size > 16)
			line_size = 16;
		ft_print_memory_line(h, ptr, i, line_size);
		i += line_size;
	}
}

void	ft_print_end(t_hexdump *h, unsigned long addr)
{
	ft_putaddr(h, addr);
	ft_putstr(STDOUT, "\n");
}
