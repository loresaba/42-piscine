/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:29:46 by losabati          #+#    #+#             */
/*   Updated: 2026/10/13 10:58:37 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 46341 is the last square root for int */
int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i < nb)
		i++;
	return (i);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	sqrt = ft_sqrt(nb);
	while (i <= sqrt)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

/*
#include <stdio.h>
int main(void) {
	printf("%d is prime: %s\n", 0, ft_is_prime(0) ? "true" : "false");
	printf("%d is prime: %s\n", 1, ft_is_prime(1) ? "true" : "false");
	printf("%d is prime: %s\n", 2, ft_is_prime(2) ? "true" : "false");
	printf("%d is prime: %s\n", 7, ft_is_prime(7) ? "true" : "false");
	printf("%d is prime: %s\n", 11, ft_is_prime(11) ? "true" : "false");
	printf("%d is prime: %s\n", 13, ft_is_prime(13) ? "true" : "false");
	printf("%d is prime: %s\n", 17, ft_is_prime(17) ? "true" : "false");
	printf("%d is prime: %s\n", 19, ft_is_prime(19) ? "true" : "false");
	printf("%d is prime: %s\n", 23, ft_is_prime(23) ? "true" : "false");
	printf("%d is prime: %s\n", 27, ft_is_prime(27) ? "true" : "false");
	printf("%d is prime: %s\n", 42, ft_is_prime(42) ? "true" : "false");
}
*/
