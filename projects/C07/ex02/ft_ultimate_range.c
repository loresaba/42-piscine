/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:08:02 by losabati          #+#    #+#             */
/*   Updated: 2026/10/14 10:13:33 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (min + i < max)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}

/*
#include <stdio.h>
int main(void) {
	int *arr = NULL;
	int i = 0;
	int count = ft_ultimate_range(&arr, -42, 43);
	printf("[ ");
	while (i < count)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	printf(" ]");
}
*/
