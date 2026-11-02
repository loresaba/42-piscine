/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:00:39 by losabati          #+#    #+#             */
/*   Updated: 2026/10/27 11:32:37 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_islower(char c)
{
	return (c >= 'a' && c <= 'z');
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (my_islower(str[i]))
		{
			str[i] = str[i] - 'a' + 'A';
		}
		i++;
	}
	return (str);
}

int main(void)
{
	char str[] = "Hello world";
	ft_strupcase(str);
}
