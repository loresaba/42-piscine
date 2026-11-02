/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:04:47 by losabati          #+#    #+#             */
/*   Updated: 2026/10/14 10:06:28 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (0);
	arr = malloc(sizeof(int) * (max - min));
	if (arr == NULL)
		return (0);
	i = 0;
	while (min + i < max)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

/*
#include <stdio.h>
int main(void) {
	int *arr = ft_range(-42, 43);
	int i = 0;
	printf("[ ");
	while (i < 42+43)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	printf(" ]");
}
*/
