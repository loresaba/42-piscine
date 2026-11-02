/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:58:48 by losabati          #+#    #+#             */
/*   Updated: 2026/10/12 17:23:14 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

/*
#include <stdio.h>
int main(void) {
	printf("%d\n", ft_recursive_power(0, 0));
	printf("%d\n", ft_recursive_power(2, 2));
	printf("%d\n", ft_recursive_power(5, 3));
	printf("%d\n", ft_recursive_power(10, 5));
	printf("%d\n", ft_recursive_power(-42, 2));
	printf("%d\n", ft_recursive_power(42, -3));
}
*/
