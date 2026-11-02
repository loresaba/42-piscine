/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:25:57 by losabati          #+#    #+#             */
/*   Updated: 2026/10/08 17:49:57 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int	my_islower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	my_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	my_isalnum(char c)
{
	return (my_islower(c) || my_isupper(c) || my_isnum(c));
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	wstart;

	i = 0;
	wstart = 1;
	while (str[i] != '\0')
	{
		if (wstart)
		{
			if (my_islower(str[i]))
				str[i] = str[i] - 'a' + 'A';
			wstart = 0;
		}
		else if (my_isupper(str[i]))
			str[i] = str[i] - 'A' + 'a';
		if (!(my_isalnum(str[i])))
			wstart = 1;
		i++;
	}
	return (str);
}
