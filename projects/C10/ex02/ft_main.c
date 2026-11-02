/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:59:24 by losabati          #+#    #+#             */
/*   Updated: 2026/10/25 13:54:04 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	t_tail	t;
	int		tail_res;

	if (!ft_tail_parse_args(argc, argv, &t))
		return (1);
	if (t.nbytes == 0)
		return (0);
	if (t.nfiles == 0)
	{
		if (!ft_tail_input(&t, t.nbytes))
			return (1);
		return (0);
	}
	tail_res = ft_tail_files(&t);
	if (t.fnames != NULL)
		free(t.fnames);
	return (!tail_res);
}
