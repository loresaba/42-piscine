/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:24:05 by losabati          #+#    #+#             */
/*   Updated: 2026/10/12 14:49:07 by losabati         ###   ########.fr       */
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
	j = 0;
	while (i < base_len)
	{
		if (base[i] == '+' || base[i] == '-')
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

void	ft_putnbr_base_rec(unsigned int nbr, char *base_chars,
	unsigned int base)
{
	char	c;

	if (nbr >= base)
		ft_putnbr_base_rec(nbr / base, base_chars, base);
	c = base_chars[nbr % base];
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;

	if (!ft_is_valid_base(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = -(unsigned int)nbr;
	}
	else
	{
		n = (unsigned int)nbr;
	}
	ft_putnbr_base_rec(n, base, (unsigned int)ft_strlen(base));
}

/*
int main(void) {
	ft_putnbr_base(0, "01");
	write(1, "\n", 1);
	ft_putnbr_base(42, "01");
	write(1, "\n", 1);
	ft_putnbr_base(42, "poneyvif");
	write(1, "\n", 1);
	ft_putnbr_base(42, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n", 1);
	ft_putnbr_base(-2147483648, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(-2147483648, "0123456789abcdef");
	write(1, "\n", 1);
}
*/
