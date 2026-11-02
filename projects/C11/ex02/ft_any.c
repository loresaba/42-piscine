/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:55:10 by losabati          #+#    #+#             */
/*   Updated: 2026/10/21 12:12:09 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
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
	//char *arr[] = {"hello", "how", "are", "you", "?", NULL};
	char *arr[] = {"12394", "398", "482", "!@)", "?", NULL};

	printf("%d\n", ft_any(arr, &is_alpha_str)); 
}
*/
