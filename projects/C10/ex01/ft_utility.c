/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 17:55:40 by losabati          #+#    #+#             */
/*   Updated: 2026/10/21 13:44:53 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

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

void	ft_puterr(char *prgname, char *fname, int errnum)
{
	char	*errstr;

	while (*prgname != '\0')
	{
		write(2, prgname, 1);
		prgname++;
	}
	write(2, ": ", 2);
	while (*fname != '\0')
	{
		write(2, fname, 1);
		fname++;
	}
	write(2, ": ", 2);
	errstr = strerror(errnum);
	while (*errstr != '\0')
	{
		write(2, errstr, 1);
		errstr++;
	}
	write(2, "\n", 1);
}
