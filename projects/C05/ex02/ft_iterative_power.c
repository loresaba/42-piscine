/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:52:01 by losabati          #+#    #+#             */
/*   Updated: 2026/10/12 16:57:19 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}

/*
#include <stdio.h>
int main(void) {
	printf("%d\n", ft_iterative_power(0, 0));
	printf("%d\n", ft_iterative_power(2, 2));
	printf("%d\n", ft_iterative_power(5, 3));
	printf("%d\n", ft_iterative_power(10, 5));
	printf("%d\n", ft_iterative_power(-42, 2));
	printf("%d\n", ft_iterative_power(42, -3));
}
*/
