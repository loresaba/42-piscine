/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:42:53 by losabati          #+#    #+#             */
/*   Updated: 2026/10/21 11:50:48 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*res;
	int	i;

	res = malloc(sizeof(int) * length);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}

/*
int is_even(int n)
{
	return (n % 2 == 0);
}

#include <stdio.h>
void print_array(int *arr, int length) {
	int i;

	printf("[");
	i = 0;
	while (i < length)
	{
		printf("%d", arr[i]);
		if (i < length - 1)
			printf(", ");
		i++;
	}
	printf("]\n");
}

int main(void) {
	int arr[] = {1, 2, 3, 4, 5, 6};
	int *res;

	int length = sizeof(arr)/sizeof(arr[0]);
	print_array(arr, length);
	res = ft_map(arr, length, &is_even);
	if (res != NULL)
		print_array(res, length);
	else
		printf("(null)\n");
}
*/
