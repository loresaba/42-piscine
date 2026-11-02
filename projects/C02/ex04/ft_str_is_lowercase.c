/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:45:45 by losabati          #+#    #+#             */
/*   Updated: 2026/10/08 16:48:52 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_islower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_str_is_lowercase(char *str)
{
	while (*str != '\0' && my_islower(*str))
	{
		str++;
	}
	if (*str != '\0')
	{
		return (0);
	}
	return (1);
}
