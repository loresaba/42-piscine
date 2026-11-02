/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:02:45 by losabati          #+#    #+#             */
/*   Updated: 2026/10/27 09:43:46 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_hexdump_for_input(t_hexdump *h, int fd)
{
	size_t	to_write;

	if (fd != STDIN)
		return ;
	to_write = h->buf_size - h->buf_input_off;
	while (to_write >= 16)
	{
		ft_print_memory_line(h, (unsigned char *)(h->buf), h->buf_input_off,
			16);
		h->buf_input_off += 16;
		to_write -= 16;
	}
}

int	ft_hexdump_input(t_hexdump *h)
{
	if (ft_read_entire_file(h, STDIN, &h->buf, &h->buf_size))
	{
		if ((h->buf_size - h->buf_input_off) > 0)
			ft_print_memory_line(h, (unsigned char *)h->buf, h->buf_input_off,
				h->buf_size - h->buf_input_off);
		ft_print_end(h, (unsigned long)h->buf_size);
		return (1);
	}
	return (0);
}

int	ft_hexdump_file(t_hexdump *h, char *fname)
{
	int	fd;
	int	res;

	res = ft_open_file(h, fname, &fd);
	if (!res)
		return (0);
	res = ft_read_entire_file(h, fd, &h->buf, &h->buf_size);
	if (res != 1)
	{
		ft_close_file(h, fd);
		return (res);
	}
	return (ft_close_file(h, fd));
}

int	ft_hexdump_files(t_hexdump *h)
{
	int	i;
	int	res;
	int	hexdump_res;

	i = 0;
	res = 1;
	while (i < h->nfiles)
	{
		h->curr_file_idx = i;
		hexdump_res = ft_hexdump_file(h, h->fnames[i]);
		if (hexdump_res != 1)
			res = 0;
		if (hexdump_res == 0)
			h->nfailed_files++;
		i++;
	}
	if (h->nfailed_files == h->nfiles)
		ft_puterr(h->prgname, "all input file arguments failed", -1, ERR_NONE);
	if (h->buf != NULL)
	{
		ft_print_memory(h, h->buf, h->buf_size);
		ft_print_end(h, (unsigned long)h->buf_size);
	}
	free(h->buf);
	return (res);
}
