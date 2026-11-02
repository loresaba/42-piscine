/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 16:52:10 by losabati          #+#    #+#             */
/*   Updated: 2026/10/11 17:36:04 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_hex_to_char(int n)
{
	if (n >= 10 && n <= 15)
		return (n - 10 + 'a');
	return (n + '0');
}

void	ft_putaddr(unsigned long long addr)
{
	int		i;
	char	c;

	i = sizeof(addr) * 8 - 4;
	while (i >= 0)
	{
		c = ft_hex_to_char((addr >> i) & 0x0F);
		write(1, &c, 1);
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
			c = ft_hex_to_char(addr[i] / 16);
			write(1, &c, 1);
			c = ft_hex_to_char(addr[i] % 16);
			write(1, &c, 1);
		}
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	ft_puttext(unsigned char *str, unsigned int len)
{
	unsigned int	i;
	char			c;

	i = 0;
	while (i < len)
	{
		c = str[i];
		if (!(c >= 32 && c <= 126))
			c = '.';
		write(1, &c, 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
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
		ft_putaddr((unsigned long long)(ptr + i));
		write(1, ": ", 2);
		ft_puthex(ptr + i, line_size);
		ft_puttext(ptr + i, line_size);
		write(1, "\n", 1);
		i += line_size;
	}
	return (addr);
}
