/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 16:39:51 by losabati          #+#    #+#             */
/*   Updated: 2026/10/17 17:31:02 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	inv_nums(int *nums);
int		is_rept(int *arr, int n);
int		is_valid_matrix(int **mat, int *seq, int row, int col);

void	put_matrix(int **mat)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = mat[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int	count_visible_buildings(int *nums)
{
	int	higher;
	int	i;
	int	count;

	i = 0;
	count = 0;
	higher = 0;
	while (i < 4)
	{
		if (higher < nums[i])
		{
			higher = nums[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	is_base_case(int **mat, int row)
{
	if (row == 4)
	{
		put_matrix(mat);
		return (1);
	}
	return (0);
}

int	setnbr_matrix_rec(int **mat, int *seq, int row, int col)
{
	int	n;

	if (is_base_case(mat, row))
		return (1);
	n = 1;
	while (n <= 4)
	{
		mat[row][col] = n;
		if (is_valid_matrix(mat, seq, row, col))
		{
			if (col == 3)
			{
				if (setnbr_matrix_rec(mat, seq, row + 1, 0))
					return (1);
			}
			else
			{
				if (setnbr_matrix_rec(mat, seq, row, col + 1))
					return (1);
			}
		}
		n++;
	}
	return (0);
}
