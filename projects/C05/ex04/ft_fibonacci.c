/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:28:34 by losabati          #+#    #+#             */
/*   Updated: 2026/10/12 17:33:50 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

/*
#include <stdio.h>
int main(void) {
	printf("%d\n", ft_fibonacci(0));
	printf("%d\n", ft_fibonacci(2));
	printf("%d\n", ft_fibonacci(5));
	printf("%d\n", ft_fibonacci(10));
	printf("%d\n", ft_fibonacci(42));
	printf("%d\n", ft_fibonacci(-42));
}
*/
