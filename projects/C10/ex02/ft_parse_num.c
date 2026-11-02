/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:10:37 by losabati          #+#    #+#             */
/*   Updated: 2026/10/25 15:07:48 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_num_suffixes.h"

int	ft_atoi_advance(char **str, unsigned long long *n)
{
	int					i;
	unsigned long long	digit;
	int					overflow;

	i = 0;
	*n = 1;
	overflow = 0;
	if ((*str)[i] != '\0' && ((*str)[i] >= '0' && (*str)[i] <= '9'))
	{
		*n = (*str)[i] - '0';
		i++;
	}
	while ((*str)[i] != '\0' && ((*str)[i] >= '0' && (*str)[i] <= '9'))
	{
		digit = (*str)[i] - '0';
		if ((*n) > (~0ULL - digit) / 10ULL)
			overflow = 1;
		else
			*n = ((*n) * 10ULL) + digit;
		i++;
	}
	*str += i;
	return (!overflow);
}

int	ft_will_mult_overflow(unsigned long long a, unsigned long long b)
{
	if (a == 0 || b == 0)
		return (0);
	return (b > (~0ULL / a));
}

/* NUM may have a multiplier suffix: b 512, kB 1000, K 1024, MB 1000*1000,
 * M 1024*1024, GB 1000*1000*1000, G 1024*1024*1024, and so on for  T,  P,
 * E, Z, Y.  Binary prefixes can be used, too: KiB=K, MiB=M, and so on. */
int	ft_parse_num_suffix_advance(char **str, unsigned long long *suf)
{
	int	suf_len;
	int	i;

	suf_len = sizeof(g_tail_num_suffixes) / sizeof(g_tail_num_suffixes[0]);
	i = 0;
	while (i < suf_len)
	{
		if (ft_strcmp(*str, g_tail_num_suffixes[i]) == 0)
		{
			*suf = g_tail_num_values[i];
			*str = *str + ft_strlen(g_tail_num_suffixes[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_tail_try_parse_num(char **str, unsigned long long *num)
{
	int					ok;
	unsigned long long	suf;

	ok = ft_atoi_advance(str, num);
	if (!ok)
		return (0);
	if (*num != 0 && (ft_strcmp(*str, "ZB") == 0 || ft_strcmp(*str, "Z") == 0
			|| ft_strcmp(*str, "YB") == 0 || ft_strcmp(*str, "Y") == 0))
		ok = 0;
	if (ft_parse_num_suffix_advance(str, &suf) && ok)
	{
		ok = !ft_will_mult_overflow(*num, suf);
		(*num) *= suf;
	}
	return (ok);
}

int	ft_tail_parse_num(t_tail *t, char *str, unsigned long long *num)
{
	char	*numstr;
	int		overflow;

	numstr = str;
	overflow = !ft_tail_try_parse_num(&numstr, num);
	if (numstr[0] != '\0')
	{
		ft_puterr(t->prgname, str, -1, ERR_C_OPT_INVALID);
		return (0);
	}
	if (overflow)
	{
		ft_puterr(t->prgname, str, -1, ERR_C_OPT_OVERFLOW);
		return (0);
	}
	return (1);
}
