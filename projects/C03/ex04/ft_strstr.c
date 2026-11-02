/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:56:10 by losabati          #+#    #+#             */
/*   Updated: 2026/10/11 15:21:45 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = i;
		k = 0;
		while (str[j] != '\0' && to_find[k] != '\0' && str[j] == to_find[k])
		{
			j++;
			k++;
		}
		if (to_find[k] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}
