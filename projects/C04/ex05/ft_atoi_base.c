/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:51:21 by losabati          #+#    #+#             */
/*   Updated: 2026/10/12 16:25:43 by losabati         ###   ########.fr       */
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

int	ft_is_valid_base(char *base)
{
	int	base_len;
	int	i;
	int	j;

	base_len = ft_strlen(base);
	if (base_len == 0 || base_len == 1)
		return (0);
	i = 0;
	while (i < base_len)
	{
		if (base[i] == '+' || base[i] == '-' || ((*base == ' ')
				|| (*base == '\f') || (*base == '\n') || (*base == '\r')
				|| (*base == '\t') || (*base == '\v')))
			return (0);
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_getch(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

unsigned int	ft_getnbr(char *str, char *base)
{
	unsigned int	n;
	int				i;
	int				base_len;

	n = 0;
	base_len = ft_strlen(base);
	if (*str != '\0')
	{
		i = ft_getch(*str, base);
		if (i != -1)
		{
			n = i;
			str++;
		}
	}
	while (*str != '\0')
	{
		i = ft_getch(*str, base);
		if (i == -1)
			break ;
		n = (n * base_len) + i;
		str++;
	}
	return (n);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	n;
	int				sign;

	if (!ft_is_valid_base(base))
		return (0);
	sign = 1;
	while (*str != '\0' && ((*str == ' ') || (*str == '\f') || (*str == '\n')
			|| (*str == '\r') || (*str == '\t') || (*str == '\v')))
		str++;
	while (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	n = ft_getnbr(str, base);
	return (n * sign);
}

/*
#include <stdio.h>
int main(void) {
	printf("%d\n", ft_atoi_base("0", "01"));
	printf("%d\n", ft_atoi_base("1", "01"));
	printf("%d\n", ft_atoi_base("101010", "01"));
	printf("%d\n", ft_atoi_base("poney", "poneyvif"));
	printf("%d\n", ft_atoi_base("42", "0123456789"));
	printf("%d\n", ft_atoi_base("2a", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("-2147483648", "0123456789"));
	printf("%d\n", ft_atoi_base("-80000000", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("+42", "0123456789"));
	printf("%d\n", ft_atoi_base("   ---+--+123", "0123456789"));
	printf("%d\n", ft_atoi_base("   -42", "0123456789"));
	printf("%d\n", ft_atoi_base("42abc", "0123456789"));
	printf("%d\n", ft_atoi_base("101xyz", "01"));
	printf("%d\n", ft_atoi_base("", "0123456789"));
}
*/
