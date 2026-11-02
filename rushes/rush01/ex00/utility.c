/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 16:41:44 by losabati          #+#    #+#             */
/*   Updated: 2026/10/17 18:11:00 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_nbrs(char *str, int *seq)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		n = str[i] - '0';
		if (n < 1 || n > 4)
			return (0);
		i++;
		if (i == 31)
		{
			if (str[i] != '\0')
				return (0);
			seq[j++] = n;
			break ;
		}
		if (str[i] != ' ')
			return (0);
		i++;
		seq[j++] = n;
	}
	return (j);
}

int	is_rept(int *arr, int n)
{
	int	i;
	int	j;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	inv_nums(int *nums)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < 2)
	{
		tmp = nums[i];
		nums[i] = nums[4 - i - 1];
		nums[4 - i - 1] = tmp;
		i++;
	}
}
