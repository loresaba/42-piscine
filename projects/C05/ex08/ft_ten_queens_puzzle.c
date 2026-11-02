/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:10:08 by losabati          #+#    #+#             */
/*   Updated: 2026/10/13 14:53:38 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

int	ft_is_valid_queen_pos(int *cols, int qrow, int qcol)
{
	int	col;
	int	row;

	col = 0;
	while (col < qcol)
	{
		row = cols[col];
		if (col == qcol || row == qrow
			|| ft_abs(col - qcol) == ft_abs(row - qrow))
			return (0);
		col++;
	}
	return (1);
}

void	ft_print_queens(int *queens)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = queens[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_place_queen_rec(int queen, int *pos)
{
	int		row;
	int		count;

	if (queen == 10)
	{
		ft_print_queens(pos);
		return (1);
	}
	count = 0;
	row = 0;
	while (row < 10)
	{
		if (ft_is_valid_queen_pos(pos, row, queen))
		{
			pos[queen] = row;
			count += ft_place_queen_rec(queen + 1, pos);
		}
		row++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	positions[10];

	return (ft_place_queen_rec(0, positions));
}

/*
#include <stdio.h>
int main(void) {
	printf("%d\n", ft_ten_queens_puzzle());
}
*/
