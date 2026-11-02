/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:44:12 by losabati          #+#    #+#             */
/*   Updated: 2026/10/21 15:38:22 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_add(int a, int b, int *res)
{
	*res = a + b;
	return (1);
}

int	ft_sub(int a, int b, int *res)
{
	*res = a - b;
	return (1);
}

int	ft_div(int a, int b, int *res)
{
	if (b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	*res = a / b;
	return (1);
}

int	ft_mul(int a, int b, int *res)
{
	*res = a * b;
	return (1);
}

int	ft_mod(int a, int b, int *res)
{
	if (b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	*res = a % b;
	return (1);
}
