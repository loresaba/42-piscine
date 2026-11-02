/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:33:08 by losabati          #+#    #+#             */
/*   Updated: 2026/10/25 17:25:47 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_puterr_msg(char *errstr, int errtype)
{
	if (errtype == ERR_NONE)
		ft_putstr(STDERR, errstr);
}

void	ft_puterr(char *prgname, char *errmgs, int errnum, int errtype)
{
	ft_putstr(STDERR, prgname);
	ft_putstr(STDERR, ": ");
	if (errmgs != NULL)
		ft_puterr_msg(errmgs, errtype);
	if (errmgs != NULL && errnum >= 0)
		ft_putstr(STDERR, ": ");
	if (errnum >= 0)
		ft_putstr(STDERR, strerror(errnum));
	ft_putstr(STDERR, "\n");
}
