/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crselaru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 14:26:19 by crselaru          #+#    #+#             */
/*   Updated: 2026/10/11 16:14:00 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_row(char start, char middle, int ncols, char end)
{
	int	count;

	count = 0;
	ft_putchar(start);
	if (ncols > 2)
	{
		while (count < ncols -2)
		{
			ft_putchar(middle);
			count++;
		}
	}
	if (ncols > 1)
		ft_putchar(end);
	ft_putchar('\n');
}

void	rush(int ncols, int nrows)
{
	int	count;

	count = 0;
	if (ncols <= 0 || nrows <= 0)
	{
		write(1, "Error: You passed an invalid value\n", 35);
		return ;
	}
	print_row('A', 'B', ncols, 'C');
	if (nrows > 2)
	{
		while (count < nrows -2)
		{
			print_row('B', ' ', ncols, 'B');
			count++;
		}
	}
	if (nrows > 1)
		print_row('A', 'B', ncols, 'C');
}
