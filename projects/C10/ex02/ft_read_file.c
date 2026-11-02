/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:19:30 by losabati          #+#    #+#             */
/*   Updated: 2026/10/25 13:18:28 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_open_file(t_tail *t, char *fname, int *fd)
{
	*fd = open(fname, O_RDONLY);
	if (*fd == -1)
	{
		ft_puterr(t->prgname, t->fnames[t->curr_file_idx], errno, ERR_READ);
		return (0);
	}
	return (1);
}

int	ft_close_file(t_tail *t, int fd)
{
	if (close(fd) == -1)
	{
		ft_puterr(t->prgname, t->fnames[t->curr_file_idx], errno, ERR_READ);
		return (0);
	}
	return (1);
}

char	*ft_get_curr_fname(t_tail *t)
{
	if (t->fnames && t->curr_file_idx >= 0 && t->curr_file_idx < t->nfiles
		&& ft_strcmp(t->fnames[t->curr_file_idx], "-") != 0)
		return (t->fnames[t->curr_file_idx]);
	return ("standard input");
}

int	ft_read_entire_file(t_tail *t, int fd, char **buf, size_t *size)
{
	char	rbuf[MAX_BUF];
	ssize_t	read_bytes;
	char	*new_buf;
	char	*fname;

	fname = ft_get_curr_fname(t);
	while (1)
	{
		read_bytes = read(fd, rbuf, MAX_BUF);
		if (read_bytes == -1)
		{
			ft_puterr(t->prgname, fname, errno, ERR_READ);
			return (0);
		}
		if (read_bytes == 0)
			break ;
		new_buf = ft_realloc(t, (*buf), (*size), (*size) + read_bytes + 1);
		if (new_buf == NULL)
			return (0);
		*buf = new_buf;
		ft_strncpy((*buf) + (*size), rbuf, read_bytes);
		*size += read_bytes;
		(*buf)[*size] = '\0';
	}
	return (1);
}
