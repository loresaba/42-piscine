/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:11:49 by losabati          #+#    #+#             */
/*   Updated: 2026/10/14 14:15:35 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_is_valid_base(char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_getnbr_base_len(unsigned int nbr, int base)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}

void	ft_setdigit_base_rec(char *buf, int i, unsigned int nbr,
	char *base_chars)
{
	char			c;
	unsigned int	base;

	base = ft_strlen(base_chars);
	if (nbr >= base)
		ft_setdigit_base_rec(buf, i - 1, nbr / base, base_chars);
	c = base_chars[nbr % base];
	buf[i] = c;
}

char	*ft_getnbr_base(int nbr, char *base)
{
	unsigned int	n;
	char			*buf;
	int				nbr_len;

	nbr_len = 0;
	if (nbr < 0)
	{
		nbr_len += 1;
		n = -(unsigned int)nbr;
	}
	else
	{
		n = (unsigned int)nbr;
	}
	nbr_len += ft_getnbr_base_len(n, ft_strlen(base));
	buf = malloc(sizeof(char) * nbr_len + 1);
	if (buf == NULL)
		return (NULL);
	if (nbr < 0)
		buf[0] = '-';
	ft_setdigit_base_rec(buf, nbr_len - 1, n, base);
	buf[nbr_len] = '\0';
	return (buf);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	n;

	if (!ft_is_valid_base(base_from) || !ft_is_valid_base(base_to))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	return (ft_getnbr_base(n, base_to));
}

/*
#include <stdio.h>
int main(void) {
char	*result;

	// Test 1: Decimal to binary
	result = ft_convert_base("42", "0123456789", "01");
	printf("Test 1: %s\n", result);
	free(result);

	// Test 2: Binary to decimal
	result = ft_convert_base("101010", "01", "0123456789");
	printf("Test 2: %s\n", result);
	free(result);

	// Test 3: Decimal to hexadecimal
	result = ft_convert_base("255", "0123456789", "0123456789ABCDEF");
	printf("Test 3: %s\n", result);
	free(result);

	// Test 4: Hexadecimal to decimal
	result = ft_convert_base("FF", "0123456789ABCDEF", "0123456789");
	printf("Test 4: %s\n", result);
	free(result);

	// Test 5: Negative number
	result = ft_convert_base("-42", "0123456789", "01");
	printf("Test 5: %s\n", result);
	free(result);

	// Test 6: Leading whitespace and multiple signs
	result = ft_convert_base("  ---+--42", "0123456789", "0123456789");
	printf("Test 6: %s\n", result);
	free(result);

	// Test 7: Leading zeros
	result = ft_convert_base("00042", "0123456789", "0123456789");
	printf("Test 7: %s\n", result);
	free(result);

	// Test 8: Zero
	result = ft_convert_base("0", "0123456789", "01");
	printf("Test 8: %s\n", result);
	free(result);

	// Test 9: Custom bases
	result = ft_convert_base("21", "0123456789", "poneyvif");
	printf("Test 9: %s\n", result);
	free(result);

	// Test 10: Invalid source base (duplicate characters)
	result = ft_convert_base("42", "01234556789", "01");
	printf("Test 10: %s\n", result);
	free(result);

	// Test 11: Invalid destination base (only one character)
	result = ft_convert_base("42", "0123456789", "0");
	printf("Test 11: %s\n", result);
	free(result);

	// Test 12: Invalid destination base (contains +)
	result = ft_convert_base("42", "0123456789", "01+");
	printf("Test 12: %s\n", result);
	free(result);

	// Test 13: INT_MAX
	result = ft_convert_base("2147483647",
			"0123456789", "0123456789ABCDEF");
	printf("Test 13: %s\n", result);
	free(result);

	// Test 14: INT_MIN
	result = ft_convert_base("-2147483648",
			"0123456789", "0123456789");
	printf("Test 14: %s\n", result);
	free(result);
	return (0);
}
*/
