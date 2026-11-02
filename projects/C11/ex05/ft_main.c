/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:23:20 by losabati          #+#    #+#             */
/*   Updated: 2026/10/21 15:36:25 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int			res;
	t_math_fn	mf;

	if (argc == 4)
	{
		mf = ft_get_math_func(argv[2]);
		if (mf == NULL)
		{
			write(1, "0\n", 2);
			return (0);
		}
		if (ft_doop(ft_atoi(argv[1]), mf, ft_atoi(argv[3]), &res))
		{
			ft_putnbr(res);
			write(1, "\n", 1);
		}
	}
	return (0);
}
