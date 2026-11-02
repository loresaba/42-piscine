/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:47:42 by losabati          #+#    #+#             */
/*   Updated: 2026/10/17 17:34:31 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	get_nbrs(char *str, int *seq);
int	setnbr_matrix_rec(int **mat, int *seq, int row, int col);

int	**create_matrix(void)
{
	int	i;
	int	**mat;

	i = 0;
	mat = malloc(sizeof(int *) * 4);
	if (mat == NULL)
		return (NULL);
	while (i < 4)
	{
		mat[i] = malloc(sizeof(int) * 4);
		if (mat[i] == NULL)
		{
			while (--i >= 0)
				free(mat[i]);
			free(mat);
			return (NULL);
		}
		i++;
	}
	return (mat);
}

int	run_matrix(int **mat, int *seq)
{
	int	i;

	if (!setnbr_matrix_rec(mat, seq, 0, 0))
		return (0);
	i = 0;
	while (i < 4)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	return (1);
}

int	main(int argc, char **argv)
{
	int	**mat;
	int	seq[4 * 4];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (get_nbrs(argv[1], seq) != 16)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	mat = create_matrix();
	if (mat == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!run_matrix(mat, seq))
		write(1, "Error\n", 6);
	return (0);
}
