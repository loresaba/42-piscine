/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 09:07:38 by losabati          #+#    #+#             */
/*   Updated: 2026/10/15 09:36:39 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dup == NULL)
		return (0);
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*res;
	int					i;

	if (ac < 0 || (av == NULL && ac > 0))
		return (NULL);
	res = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		res[i].size = ft_strlen(av[i]);
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
		if (res[i].copy == NULL)
		{
			while (i > 0)
				free(res[--i].copy);
			free(res);
			return (NULL);
		}
		i++;
	}
	res[ac].str = NULL;
	return (res);
}

/*

#include <stdio.h>
void	print_tab(t_stock_str *tab)
{
	int	i;

	if (!tab)
	{
		printf("Returned NULL\n");
		return ;
	}
	i = 0;
	while (tab[i].str != NULL)
	{
		printf("String: \"%s\"\n", tab[i].str);
		printf("Copy:   \"%s\"\n", tab[i].copy);
		printf("Size:   %d\n\n", tab[i].size);
		i++;
	}
}

void	free_tab(t_stock_str *tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i].str != NULL)
	{
		free(tab[i].copy);
		i++;
	}
	free(tab);
}

int	main(void)
{
	char	*test1[] = {"Hello", "World", "42"};
	char	*test2[] = {"", "abc", "", "Piscine"};
	char	*test3[] = {"Only one string"};
	char	**test4 = NULL;
	t_stock_str	*result;

	printf("=== Test 1: Multiple strings ===\n");
	result = ft_strs_to_tab(3, test1);
	print_tab(result);
	free_tab(result);

	printf("=== Test 2: Empty strings ===\n");
	result = ft_strs_to_tab(4, test2);
	print_tab(result);
	free_tab(result);

	printf("=== Test 3: One string ===\n");
	result = ft_strs_to_tab(1, test3);
	print_tab(result);
	free_tab(result);

	printf("=== Test 4: Empty array ===\n");
	result = ft_strs_to_tab(0, test4);
	print_tab(result);
	free_tab(result);

	printf("=== Test 5: Invalid arguments ===\n");
	result = ft_strs_to_tab(-1, test1);
	print_tab(result);
	free_tab(result);

	result = ft_strs_to_tab(2, NULL);
	print_tab(result);
	free_tab(result);

	return (0);
}
*/
