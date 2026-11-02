/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:30:34 by losabati          #+#    #+#             */
/*   Updated: 2026/10/21 15:39:42 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

typedef int	(*t_math_fn)(int, int, int *);

int			ft_add(int a, int b, int *res);
int			ft_sub(int a, int b, int *res);
int			ft_div(int a, int b, int *res);
int			ft_mul(int a, int b, int *res);
int			ft_mod(int a, int b, int *res);
t_math_fn	ft_get_math_func(char *opstr);
int			ft_doop(int n1, t_math_fn mf, int n2, int *res);
int			ft_atoi(char *str);
void		ft_putnbr(int nbr);

#endif
