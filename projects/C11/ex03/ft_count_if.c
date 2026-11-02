/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 12:12:47 by losabati          #+#    #+#             */
/*   Updated: 2026/10/21 12:19:53 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}

/*
int is_alpha_str(char *str) {
	while (*str != '\0')
	{
		if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
			return (0);
		str++;
	}
	return (1);
}

#include <stdio.h>
int main(void) {
	char *arr[] = {"hello", "how", "are", "you", "?"};
	//char *arr[] = {"12394", "398", "482", "!@)", "?"};

	printf("%d\n", ft_count_if(arr, sizeof(arr)/sizeof(arr[0]), &is_alpha_str));
}
*/
