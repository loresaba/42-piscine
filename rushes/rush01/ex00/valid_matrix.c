/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:28:50 by losabati          #+#    #+#             */
/*   Updated: 2026/10/17 17:30:13 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_rept(int *arr, int n);
int		count_visible_buildings(int *nums);
void	inv_nums(int *nums);

// check columns
// *	check repetition on columns
// *	check visibile buildings on columns in both directions (pov)
int	check_cols(int **mat, int *seq, int row, int col)
{
	int	i;
	int	nums[4];
	int	vis_count;

	i = 0;
	while (i <= row)
	{
		nums[i] = mat[i][col];
		i++;
	}
	if (is_rept(nums, i))
		return (0);
	if (row == 3)
	{
		vis_count = count_visible_buildings(nums);
		if (seq[col] != vis_count)
			return (0);
		inv_nums(nums);
		vis_count = count_visible_buildings(nums);
		if (seq[4 + col] != vis_count)
			return (0);
	}
	return (1);
}

// check rows
// *	check repetition on rows
// *	check visibile buildings on rows in both directions (pov)
int	check_rows(int **mat, int *seq, int row, int col)
{
	int	i;
	int	nums[4];
	int	vis_count;

	i = 0;
	while (i <= col)
	{
		nums[i] = mat[row][i];
		i++;
	}
	if (is_rept(nums, i))
		return (0);
	if (col == 3)
	{
		vis_count = count_visible_buildings(nums);
		if (seq[8 + row] != vis_count)
			return (0);
		inv_nums(nums);
		vis_count = count_visible_buildings(nums);
		if (seq[12 + row] != vis_count)
			return (0);
	}
	return (1);
}

int	is_valid_matrix(int **mat, int *seq, int row, int col)
{
	if (!check_cols(mat, seq, row, col))
		return (0);
	if (!check_rows(mat, seq, row, col))
		return (0);
	return (1);
}
