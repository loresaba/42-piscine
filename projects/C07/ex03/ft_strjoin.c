/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 10:14:29 by losabati          #+#    #+#             */
/*   Updated: 2026/10/14 10:40:49 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int	ft_get_strjoin_len(int size, char **strs, char *sep)
{
	int		str_len;
	int		sep_len;
	int		i;

	str_len = 0;
	sep_len = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		str_len += ft_strlen(strs[i]);
		if (i < size - 1)
			str_len += sep_len;
		i++;
	}
	return (str_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		res_len;
	char	*res;
	int		i;
	int		j;

	res_len = ft_get_strjoin_len(size, strs, sep);
	res = malloc(sizeof(char) * (res_len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		j += ft_strcpy(res + j, strs[i]);
		if (i < size - 1)
			j += ft_strcpy(res + j, sep);
		i++;
	}
	res[j] = '\0';
	return (res);
}

/*
#include <stdio.h>
int main(void) {
	char *s1[5] = { "hello", "world", "and", "enjoy", "42" };
	char *sep = ", ";
	char *str = ft_strjoin(5, s1, sep);
	printf("%s\n", str);
}
*/
