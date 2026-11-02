/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:23:30 by losabati          #+#    #+#             */
/*   Updated: 2026/10/12 10:54:15 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return ((c == ' ') || (c == '\f') || (c == '\n') || (c == '\r')
		|| (c == '\t') || (c == '\v'));
}

int	ft_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	unsigned int	n;
	int				sign;

	n = 0;
	sign = 1;
	while (*str != '\0' && ft_isspace(*str))
		str++;
	while (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (*str != '\0' && ft_isnum(*str))
	{
		n = *str - '0';
		str++;
	}
	while (*str != '\0' && ft_isnum(*str))
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	return (n * sign);
}

/*
#include <stdio.h>
int main(void) {
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi("-42"));
	printf("%d\n", ft_atoi("3408323"));
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", ft_atoi("21474836473487230487"));
	printf("%d\n", ft_atoi("     ---+--+1234ab567"));
}
*/
