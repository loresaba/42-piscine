/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:30:17 by losabati          #+#    #+#             */
/*   Updated: 2026/10/21 15:21:05 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_isspace(char c)
{
	return ((c == ' ') || (c == '\f') || (c == '\n') || (c == '\r')
		|| (c == '\t') || (c == '\v'));
}

int	ft_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	unsigned int	n;
	int				sign;

	n = 0;
	sign = 1;
	while (*str != '\0' && ft_isspace(*str))
		str++;
	while (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (*str != '\0' && ft_isnum(*str))
	{
		n = *str - '0';
		str++;
	}
	while (*str != '\0' && ft_isnum(*str))
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	return (n * sign);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = -nbr;
		}
		if (nbr >= 10)
		{
			ft_putnbr(nbr / 10);
			nbr %= 10;
		}
		if (nbr < 10)
		{
			c = nbr + '0';
			write(1, &c, 1);
		}
	}
}
