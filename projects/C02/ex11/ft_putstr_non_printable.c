/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:04:27 by losabati          #+#    #+#             */
/*   Updated: 2026/10/10 14:00:26 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	my_isprint(unsigned char c)
{
	return (c >= 32 && c <= 126);
}

char	int_to_hexchar(int n)
{
	if (n >= 10 && n <= 15)
		return (n - 10 + 'a');
	return (n + '0');
}

void	ft_puthex(unsigned char c)
{
	char	digit1;
	char	digit2;

	digit1 = int_to_hexchar(c / 16);
	digit2 = int_to_hexchar(c % 16);
	write(1, &digit1, 1);
	write(1, &digit2, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*s;

	s = (unsigned char *)str;
	while (*s != '\0')
	{
		if (my_isprint(*s))
		{
			write(1, s, 1);
		}
		else
		{
			write(1, "\\", 1);
			ft_puthex(*s);
		}
		s++;
	}
}
