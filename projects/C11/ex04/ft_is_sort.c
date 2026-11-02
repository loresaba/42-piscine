/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:25:53 by losabati          #+#    #+#             */
/*   Updated: 2026/10/22 09:38:00 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	desc;

	i = 0;
	asc = 1;
	desc = 1;
	while (i < (length - 1))
	{
		if (f(tab[i], tab[i + 1]) > 0)
			asc = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			desc = 0;
		i++;
	}
	return (asc || desc);
}

/*
int ft_numcmp(int n1, int n2)
{
	return (n1 - n2);
}

#include <stdio.h>
int main(void) {
	int arr[] = {1, 2, 3, 4, 5, 6};
	//int arr[] = {1, 2, 3, 8, 5, 6};
	//int arr[] = {6, 5, 5, 4, 2, 1};

	printf("%d\n", ft_is_sort(arr, sizeof(arr)/sizeof(arr[0]), &ft_numcmp));
}
*/
