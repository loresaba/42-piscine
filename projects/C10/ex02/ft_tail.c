/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:02:45 by losabati          #+#    #+#             */
/*   Updated: 2026/10/26 08:19:06 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_tail_input(t_tail *t, unsigned long long nbytes)
{
	char	*buf;
	size_t	buf_size;

	if (t->curr_file_idx > 0 && !t->in_inval_streak)
		ft_putstr(STDOUT, "\n");
	if (t->nfiles > 1)
		ft_putheader("standard input");
	buf = NULL;
	buf_size = 0;
	if (!ft_read_entire_file(t, STDIN, &buf, &buf_size))
	{
		free(buf);
		return (0);
	}
	if (nbytes > (unsigned long long)buf_size)
		nbytes = buf_size;
	if (buf != NULL)
		write(STDOUT, (buf + buf_size) - nbytes, nbytes);
	free(buf);
	return (1);
}

int	ft_tail_file(t_tail *t, char *fname, unsigned long long nbytes)
{
	char	*buf;
	size_t	buf_size;
	int		fd;

	buf = NULL;
	buf_size = 0;
	if (!ft_open_file(t, fname, &fd))
		return (0);
	if (!ft_read_entire_file(t, fd, &buf, &buf_size))
	{
		free(buf);
		ft_close_file(t, fd);
		return (0);
	}
	if (nbytes > (unsigned long long)buf_size)
		nbytes = buf_size;
	if (t->curr_file_idx > 0 && !t->in_inval_streak)
		ft_putstr(STDOUT, "\n");
	if (t->nfiles > 1)
		ft_putheader(fname);
	if (buf != NULL)
		write(STDOUT, (buf + buf_size) - nbytes, nbytes);
	free(buf);
	return (ft_close_file(t, fd));
}

int	ft_tail_files(t_tail *t)
{
	int	i;
	int	tail_res;
	int	res;

	i = 0;
	res = 1;
	while (i < t->nfiles)
	{
		t->curr_file_idx = i;
		if (ft_strcmp(t->fnames[i], "-") == 0)
			tail_res = ft_tail_input(t, t->nbytes);
		else
			tail_res = ft_tail_file(t, t->fnames[i], t->nbytes);
		t->in_inval_streak = t->in_inval_streak && !tail_res;
		res = res && tail_res;
		i++;
	}
	return (res);
}
