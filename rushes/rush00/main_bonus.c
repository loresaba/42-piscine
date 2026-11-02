/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 16:15:29 by losabati          #+#    #+#             */
/*   Updated: 2026/10/11 16:28:07 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	rush(int ncols, int nrows);

int	main(int argc, char **argv)
{
	int	ncols;
	int	nrows;

	if (argc != 3)
	{
		write(1, "Error: Invalid number of arguments\n", 35);
		return (1);
	}
	ncols = atoi(argv[1]);
	nrows = atoi(argv[2]);
	rush(ncols, nrows);
	return (0);
}
