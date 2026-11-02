/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:25:05 by losabati          #+#    #+#             */
/*   Updated: 2026/10/20 17:32:05 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	read_entire_file(char *filename)
{
	int		fd;
	char	buf[4096];
	ssize_t	read_bytes;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		read_bytes = read(fd, buf, sizeof(buf));
		if (read_bytes < 0)
		{
			close(fd);
			return (0);
		}
		if (read_bytes == 0)
			break ;
		write(1, buf, read_bytes);
	}
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	if (!read_entire_file(argv[1]))
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	return (0);
}
