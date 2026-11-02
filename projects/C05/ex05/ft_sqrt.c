/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:48:41 by losabati          #+#    #+#             */
/*   Updated: 2026/10/12 17:57:24 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 46341 is the last square root for int */
int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i < 46341)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main(void) {
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(5));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(36));
	printf("%d\n", ft_sqrt(42));
	printf("%d\n", ft_sqrt(-42));
}
*/
