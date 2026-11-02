/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:16:07 by losabati          #+#    #+#             */
/*   Updated: 2026/10/21 16:20:53 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tab[i] != 0)
	{
		j = i;
		while (j > 0 && cmp(tab[j], tab[j - 1]) < 0)
		{
			tmp = tab[j];
			tab[j] = tab[j - 1];
			tab[j - 1] = tmp;
			j--;
		}
		i++;
	}
}

/*
#include <stdio.h>
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	else if (*s1 == '\0')
		return (-1);
	else
		return (1);
}

void ft_print_strings(char **strs) {
	int	i;

	i = 0;
	while (strs[i] != 0)
	{
		printf("%s\n", strs[i]);
		i++;
	}
	printf("\n");
}

int main(void) {
	char *arr[] = {"hello", "how", "are", "you", "1234", NULL };

	ft_print_strings(arr);
	ft_advanced_sort_string_tab(arr, &ft_strcmp);
	ft_print_strings(arr);
}
*/
