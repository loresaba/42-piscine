/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:19:57 by losabati          #+#    #+#             */
/*   Updated: 2026/10/08 17:23:32 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (my_isupper(str[i]))
		{
			str[i] = str[i] - 'A' + 'a';
		}
		i++;
	}
	return (str);
}
