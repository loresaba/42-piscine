/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:07:31 by losabati          #+#    #+#             */
/*   Updated: 2026/10/08 11:55:55 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

int	my_pow(int base, int exp)
{
	int	num;

	num = 1;
	while (exp > 0)
	{
		num *= base;
		exp--;
	}
	return (num);
}

int	count_digits(int n)
{
	int	count;

	count = 1;
	while ((n / 10) != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

void	print_num(int n, int size)
{
	char	c;
	int		div;

	while (size > 0)
	{
		div = (my_pow(10, (size - 1)));
		c = (n / div) + '0';
		write(1, &c, 1);
		n %= div;
		size--;
	}
}

void	ft_putnbr(int nb)
{
	char	c;
	int		digits;

	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		c = '-';
		write(1, &c, 1);
		nb = -nb;
	}
	digits = count_digits(nb);
	print_num(nb, digits);
}
