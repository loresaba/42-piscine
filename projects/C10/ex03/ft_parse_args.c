/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:08:18 by losabati          #+#    #+#             */
/*   Updated: 2026/10/27 09:41:40 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_hexdump_is_canonical_opt(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-C") == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_hexdump_get_n_files(int argc, char **argv)
{
	int	i;
	int	nfiles;

	i = 1;
	nfiles = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-C") != 0)
			nfiles++;
		i++;
	}
	return (nfiles);
}

void	ft_hexdump_parse_file_args(int argc, char **argv, char **fnames)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-C") != 0)
			fnames[j++] = argv[i];
		i++;
	}
}

int	ft_hexdump_parse_args(int argc, char **argv, t_hexdump *h)
{
	h->prgname = basename(argv[0]);
	h->curr_file_idx = 0;
	h->nfailed_files = 0;
	h->in_rept = 0;
	h->buf = NULL;
	h->buf_size = 0;
	h->buf_input_off = 0;
	h->is_canonical = ft_hexdump_is_canonical_opt(argc, argv);
	h->fnames = NULL;
	h->nfiles = ft_hexdump_get_n_files(argc, argv);
	if (h->nfiles > 0)
	{
		h->fnames = malloc(sizeof(char *) * h->nfiles);
		if (h->fnames == NULL)
			return (0);
		ft_hexdump_parse_file_args(argc, argv, h->fnames);
	}
	return (1);
}
