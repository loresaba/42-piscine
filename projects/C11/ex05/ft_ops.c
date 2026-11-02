/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:39:09 by losabati          #+#    #+#             */
/*   Updated: 2026/10/21 15:37:55 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	else if (*s1 == '\0')
		return (-1);
	else
		return (1);
}

t_math_fn	ft_get_math_func(char *opstr)
{
	if (ft_strcmp(opstr, "+") == 0)
		return (&ft_add);
	if (ft_strcmp(opstr, "-") == 0)
		return (&ft_sub);
	if (ft_strcmp(opstr, "*") == 0)
		return (&ft_mul);
	if (ft_strcmp(opstr, "/") == 0)
		return (&ft_div);
	if (ft_strcmp(opstr, "%") == 0)
		return (&ft_mod);
	return (0);
}

int	ft_doop(int n1, t_math_fn mf, int n2, int *res)
{
	return (mf(n1, n2, res));
}
