/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 16:25:23 by losabati          #+#    #+#             */
/*   Updated: 2026/10/07 17:04:28 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int n)
{
	char	c;

	c = (n / 10) + '0';
	write(1, &c, 1);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	print_num_pair(int n1, int n2)
{
	char	c;

	print_num(n1);
	c = ' ';
	write(1, &c, 1);
	print_num(n2);
}

void	ft_print_comb2(void)
{
	int		first;
	int		second;
	char	c;

	first = 0;
	while (first <= 99)
	{
		second = first + 1;
		while (second <= 99)
		{
			print_num_pair(first, second);
			if (!(first == 98 && second == 99))
			{
				c = ',';
				write(1, &c, 1);
				c = ' ';
				write(1, &c, 1);
			}
			second++;
		}
		first++;
	}
}
