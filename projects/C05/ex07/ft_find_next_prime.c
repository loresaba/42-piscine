/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:39:34 by losabati          #+#    #+#             */
/*   Updated: 2026/10/13 11:49:45 by losabati         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb += 1;
	}
	return (0);
}

/*
#include <stdio.h>
int main(void) {
	printf("%d %d\n", 0, ft_find_next_prime(0));
	printf("%d %d\n", 1, ft_find_next_prime(1));
	printf("%d %d\n", 2, ft_find_next_prime(2));
	printf("%d %d\n", 7, ft_find_next_prime(7));
	printf("%d %d\n", 11, ft_find_next_prime(11));
	printf("%d %d\n", 13, ft_find_next_prime(13));
	printf("%d %d\n", 17, ft_find_next_prime(17));
	printf("%d %d\n", 19, ft_find_next_prime(19));
	printf("%d %d\n", 23, ft_find_next_prime(23));
	printf("%d %d\n", 27, ft_find_next_prime(27));
	printf("%d %d\n", 42, ft_find_next_prime(42));
}
*/
