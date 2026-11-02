/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 13:55:39 by losabati          #+#    #+#             */
/*   Updated: 2026/10/26 14:02:20 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	ft_hex_to_char(int n)
{
	if (n >= 10 && n <= 15)
		return (n - 10 + 'a');
	return (n + '0');
}

void	ft_putaddr(t_hexdump *h, unsigned long addr)
{
	int		i;
	char	c;

	i = (28 + (h->is_canonical * 4)) - 4;
	while (i >= 0)
	{
		c = ft_hex_to_char((addr >> i) & 0x0F);
		write(STDOUT, &c, 1);
		i -= 4;
	}
}

void	ft_puthex(unsigned char *addr, unsigned int size)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			c = ft_hex_to_char(addr[i + 1] / 16);
			write(STDOUT, &c, 1);
			c = ft_hex_to_char(addr[i + 1] % 16);
			write(STDOUT, &c, 1);
			c = ft_hex_to_char(addr[i] / 16);
			write(STDOUT, &c, 1);
			c = ft_hex_to_char(addr[i] % 16);
			write(STDOUT, &c, 1);
		}
		else
			ft_putstr(STDOUT, "    ");
		if (i < (16 - 2))
			ft_putstr(STDOUT, " ");
		i += 2;
	}
}

void	ft_puthex_can(unsigned char *addr, unsigned int size)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			c = ft_hex_to_char(addr[i] / 16);
			write(STDOUT, &c, 1);
			c = ft_hex_to_char(addr[i] % 16);
			write(STDOUT, &c, 1);
		}
		else
			ft_putstr(STDOUT, "  ");
		if (i < (16 - 1))
			ft_putstr(STDOUT, " ");
		if (i == 7)
			ft_putstr(STDOUT, " ");
		i += 1;
	}
}

void	ft_puttext(unsigned char *str, unsigned int len)
{
	unsigned int	i;
	char			c;

	i = 0;
	ft_putstr(STDOUT, "|");
	while (i < len)
	{
		c = str[i];
		if (!(c >= 32 && c <= 126))
			c = '.';
		write(STDOUT, &c, 1);
		i++;
	}
	ft_putstr(STDOUT, "|");
}
