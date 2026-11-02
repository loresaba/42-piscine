/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:00:32 by losabati          #+#    #+#             */
/*   Updated: 2026/10/27 09:44:03 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define ERR_NONE 0

# define MAX_BUF 4096

typedef struct s_hexdump
{
	char	*prgname;
	char	**fnames;
	int		nfiles;
	int		curr_file_idx;
	int		nfailed_files;
	int		is_canonical;
	char	*buf;
	size_t	buf_size;
	size_t	buf_input_off;
	int		in_rept;
}	t_hexdump;

int		ft_strlen(char *str);
int		ft_is_same_line(unsigned char *a, unsigned char *b);
void	ft_putstr(int fd, char *str);
void	ft_puterr_msg(char *errstr, int errtype);
void	ft_puterr(char *prgname, char *errmsg, int errnum, int errtype);
void	ft_strncpy(char *dst, char *src, size_t n);
int		ft_strcmp(char *s1, char *s2);
void	*ft_realloc(t_hexdump *h, void *ptr, size_t old_size, size_t new_size);
int		ft_open_file(t_hexdump *h, char *fname, int *fd);
int		ft_close_file(t_hexdump *h, int fd);
int		ft_read_entire_file(t_hexdump *h, int fd, char **buf, size_t *size);
void	ft_putaddr(t_hexdump *h, unsigned long addr);
void	ft_puthex(unsigned char *addr, unsigned int size);
void	ft_puthex_can(unsigned char *addr, unsigned int size);
void	ft_puttext(unsigned char *str, unsigned int len);
void	ft_print_memory_line(t_hexdump *h, unsigned char *ptr, unsigned int i,
			unsigned int line_size);
void	ft_print_memory(t_hexdump *h, void *addr, unsigned int size);
void	ft_print_end(t_hexdump *h, unsigned long addr);
void	ft_hexdump_for_input(t_hexdump *h, int fd);
int		ft_hexdump_input(t_hexdump *h);
int		ft_hexdump_files(t_hexdump *h);
int		ft_hexdump_parse_args(int argc, char **argv, t_hexdump *h);

#endif
