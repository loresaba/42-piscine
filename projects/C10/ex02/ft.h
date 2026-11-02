/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:00:32 by losabati          #+#    #+#             */
/*   Updated: 2026/10/25 14:32:36 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define ERR_NONE 0
# define ERR_READ 1
# define ERR_HELP 2
# define ERR_C_OPT_INVALID 3
# define ERR_C_OPT_OVERFLOW 4

# define MAX_BUF 4096

typedef struct s_tail
{
	char				*prgname;
	unsigned long long	nbytes;
	char				**fnames;
	int					nfiles;
	int					curr_file_idx;
	int					in_inval_streak;
}	t_tail;

int		ft_strlen(char *str);
void	ft_putstr(int fd, char *str);
void	ft_putheader(char *name);
void	ft_puterr_msg(char *errstr, int errtype);
void	ft_puterr(char *prgname, char *errmsg, int errnum, int errtype);
void	ft_strncpy(char *dst, char *src, size_t n);
int		ft_strcmp(char *s1, char *s2);
void	*ft_realloc(t_tail *t, void *ptr, size_t old_size, size_t new_size);
int		ft_open_file(t_tail *t, char *fname, int *fd);
int		ft_close_file(t_tail *t, int fd);
int		ft_read_entire_file(t_tail *t, int fd, char **buf, size_t *size);
int		ft_tail_files(t_tail *t);
int		ft_tail_input(t_tail *t, unsigned long long nbytes);
int		ft_tail_parse_args(int argc, char **argv, t_tail *t);
int		ft_tail_parse_num(t_tail *t, char *str, unsigned long long *n);

#endif
