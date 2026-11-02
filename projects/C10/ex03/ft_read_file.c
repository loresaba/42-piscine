/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:19:30 by losabati          #+#    #+#             */
/*   Updated: 2026/10/27 09:47:49 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_open_file(t_hexdump *h, char *fname, int *fd)
{
	*fd = open(fname, O_RDONLY);
	if (*fd == -1)
	{
		ft_puterr(h->prgname, h->fnames[h->curr_file_idx], errno, ERR_NONE);
		return (0);
	}
	return (1);
}

int	ft_close_file(t_hexdump *h, int fd)
{
	if (close(fd) == -1)
	{
		ft_puterr(h->prgname, h->fnames[h->curr_file_idx], errno, ERR_NONE);
		return (0);
	}
	return (1);
}

char	*ft_get_curr_fname(t_hexdump *h, int fd)
{
	if (fd != STDIN)
		return (h->fnames[h->curr_file_idx]);
	return ("standard input");
}

int	ft_handle_read_error(t_hexdump *h, char *fname)
{
	int	res;

	res = 0;
	if (errno == EISDIR)
		res = -1;
	ft_puterr(h->prgname, fname, errno, ERR_NONE);
	return (res);
}

int	ft_read_entire_file(t_hexdump *h, int fd, char **buf, size_t *size)
{
	char	rbuf[MAX_BUF];
	ssize_t	read_bytes;
	char	*new_buf;
	char	*fname;

	fname = ft_get_curr_fname(h, fd);
	while (1)
	{
		read_bytes = read(fd, rbuf, MAX_BUF);
		if (read_bytes == -1)
			return (ft_handle_read_error(h, fname));
		if (read_bytes == 0)
			break ;
		new_buf = ft_realloc(h, (*buf), (*size), (*size) + read_bytes + 1);
		if (new_buf == NULL)
			return (0);
		*buf = new_buf;
		ft_strncpy((*buf) + (*size), rbuf, read_bytes);
		*size += read_bytes;
		(*buf)[*size] = '\0';
		ft_hexdump_for_input(h, fd);
	}
	return (1);
}
