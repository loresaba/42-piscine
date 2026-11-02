/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:49:53 by losabati          #+#    #+#             */
/*   Updated: 2026/10/08 16:54:03 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0' && my_isupper(*str))
	{
		str++;
	}
	if (*str != '\0')
	{
		return (0);
	}
	return (1);
}
