/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:08:18 by losabati          #+#    #+#             */
/*   Updated: 2026/10/24 17:41:23 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_tail_c_opt_get_nbytes(t_tail *t, int argc, char **argv,
		unsigned long long *nbytes)
{
	int	i;
	int	moreargs;

	i = 0;
	while (i < argc)
	{
		moreargs = (i < (argc - 1));
		if (ft_strcmp(argv[i], "-c") == 0)
		{
			if (!moreargs)
			{
				ft_puterr(t->prgname, "option requires an argument -- 'c'", -1,
					ERR_NONE);
				ft_puterr_msg(t->prgname, ERR_HELP);
				ft_putstr(STDERR, "\n");
				return (0);
			}
			if (!ft_tail_parse_num(t, argv[i + 1], nbytes))
				return (0);
			i++;
		}
		i++;
	}
	return (1);
}

int	ft_tail_get_n_files(int argc, char **argv)
{
	int	i;
	int	nfiles;

	i = 1;
	nfiles = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-c") == 0)
			i++;
		else
			nfiles++;
		i++;
	}
	return (nfiles);
}

void	ft_tail_parse_file_args(int argc, char **argv, char **fnames)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-c") == 0)
			i++;
		else
			fnames[j++] = argv[i];
		i++;
	}
}

int	ft_tail_parse_args(int argc, char **argv, t_tail *t)
{
	t->prgname = argv[0];
	t->curr_file_idx = 0;
	t->in_inval_streak = 1;
	t->fnames = NULL;
	t->nfiles = ft_tail_get_n_files(argc, argv);
	if (!ft_tail_c_opt_get_nbytes(t, argc, argv, &t->nbytes))
		return (0);
	if (t->nfiles > 0)
	{
		t->fnames = malloc(sizeof(char *) * t->nfiles);
		if (t->fnames == NULL)
			return (0);
		ft_tail_parse_file_args(argc, argv, t->fnames);
	}
	return (1);
}
