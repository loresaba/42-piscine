/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:33:08 by losabati          #+#    #+#             */
/*   Updated: 2026/10/25 14:11:55 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_puterr_msg(char *errstr, int errtype)
{
	if (errtype == ERR_NONE)
		ft_putstr(STDERR, errstr);
	else if (errtype == ERR_READ)
	{
		ft_putstr(STDERR, "cannot open '");
		ft_putstr(STDERR, errstr);
		ft_putstr(STDERR, "' for reading");
	}
	else if (errtype == ERR_HELP)
	{
		ft_putstr(STDERR, "Try '");
		ft_putstr(STDERR, errstr);
		ft_putstr(STDERR, " --help' for more information.");
	}
	else if (errtype == ERR_C_OPT_INVALID || errtype == ERR_C_OPT_OVERFLOW)
	{
		ft_putstr(STDERR, "invalid number of bytes: ‘");
		ft_putstr(STDERR, errstr);
		ft_putstr(STDERR, "’");
		if (errtype == ERR_C_OPT_OVERFLOW)
			ft_putstr(STDERR, ": Value too large for defined data type");
	}
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
