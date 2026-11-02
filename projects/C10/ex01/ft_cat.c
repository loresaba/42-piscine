/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:48:39 by losabati          #+#    #+#             */
/*   Updated: 2026/10/20 18:06:18 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
void	ft_puterr(char *prgname, char *fname, int errnum);

int	ft_write_all(int fd, char *buf, ssize_t len)
{
	ssize_t	written;
	ssize_t	total;

	total = 0;
	while (total < len)
	{
		written = write(fd, buf + total, len - total);
		if (written < 0)
			return (0);
		if (written == 0)
		{
			errno = EIO;
			return (0);
		}
		total += written;
	}
	return (1);
}

int	rw_entire_file(int fd)
{
	char	buf[4096];
	ssize_t	read_bytes;

	while (1)
	{
		read_bytes = read(fd, buf, sizeof(buf));
		if (read_bytes < 0)
			return (0);
		if (read_bytes == 0)
			break ;
		if (!ft_write_all(1, buf, read_bytes))
			return (0);
	}
	return (1);
}

int	open_and_rw_file(char *fname)
{
	int	fd;
	int	saved_errno;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!rw_entire_file(fd))
	{
		saved_errno = errno;
		close(fd);
		errno = saved_errno;
		return (0);
	}
	if (close(fd) == -1)
		return (0);
	return (1);
}

int	ft_cat_run(int argc, char **argv)
{
	int	i;
	int	res;

	res = 1;
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-") == 0)
		{
			if (!rw_entire_file(0))
			{
				ft_puterr(argv[0], "stdin", errno);
				res = 0;
			}
		}
		else if (!open_and_rw_file(argv[i]))
		{
			ft_puterr(argv[0], argv[i], errno);
			res = 0;
		}
		i++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		if (!rw_entire_file(0))
		{
			ft_puterr(argv[0], "stdin", errno);
			return (1);
		}
		return (0);
	}
	if (!ft_cat_run(argc, argv))
		return (1);
	return (0);
}
