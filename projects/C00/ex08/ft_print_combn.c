/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 09:13:46 by losabati          #+#    #+#             */
/*   Updated: 2026/10/08 09:40:03 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb(int n, int *digits)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = digits[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (digits[0] != 9 - n + 1)
	{
		write(1, ", ", 2);
	}
}

void	gen_combn_rec(int n, int pos, int start, int *digits)
{
	int	i;

	if (pos == n)
	{
		print_comb(n, digits);
		return ;
	}
	i = start;
	while (i <= 9)
	{
		digits[pos] = i;
		gen_combn_rec(n, pos + 1, i + 1, digits);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	digits[10];

	gen_combn_rec(n, 0, 0, digits);
}
