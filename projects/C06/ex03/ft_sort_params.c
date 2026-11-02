/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:46:44 by losabati          #+#    #+#             */
/*   Updated: 2026/10/13 16:06:23 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

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

char	**ft_sort_strings(char **strings, int count)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < count)
	{
		j = i;
		while (j > 0 && ft_strcmp(strings[j], strings[j - 1]) < 0)
		{
			tmp = strings[j];
			strings[j] = strings[j - 1];
			strings[j - 1] = tmp;
			j--;
		}
		i++;
	}
	return (strings);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**strings;

	strings = ft_sort_strings(&argv[1], argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		write(1, strings[i], ft_strlen(strings[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
