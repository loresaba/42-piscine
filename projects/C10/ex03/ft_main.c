/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:59:24 by losabati          #+#    #+#             */
/*   Updated: 2026/10/27 08:44:43 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

// TODO check position on error messages
int	main(int argc, char **argv)
{
	t_hexdump	h;
	int			hexdump_res;

	if (!ft_hexdump_parse_args(argc, argv, &h))
		return (1);
	if (h.nfiles == 0)
		hexdump_res = ft_hexdump_input(&h);
	else
		hexdump_res = ft_hexdump_files(&h);
	if (h.fnames != NULL)
		free(h.fnames);
	return (!hexdump_res);
}
