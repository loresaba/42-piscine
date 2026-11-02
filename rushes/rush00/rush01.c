/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 16:09:24 by losabati          #+#    #+#             */
/*   Updated: 2026/10/11 16:11:45 by losabati         ###   ########.fr       */
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
	print_row('/', '*', ncols, '\\');
	if (nrows > 2)
	{
		while (count < nrows -2)
		{
			print_row('*', ' ', ncols, '*');
			count++;
		}
	}
	if (nrows > 1)
		print_row('\\', '*', ncols, '/');
}
