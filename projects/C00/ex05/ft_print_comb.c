/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:27:17 by losabati          #+#    #+#             */
/*   Updated: 2026/10/07 16:07:33 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(char i, char j, char k)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
}

void	print_sep(void)
{
	char	comma;
	char	space;

	comma = ',';
	space = ' ';
	write(1, &comma, 1);
	write(1, &space, 1);
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '9')
	{
		j = i + 1;
		while (j <= '9')
		{
			k = j + 1;
			while (k <= '9')
			{
				print_num(i, j, k);
				if (!(i == '7' && j == '8' && k == '9'))
				{
					print_sep();
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
