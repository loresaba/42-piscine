/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:02:26 by losabati          #+#    #+#             */
/*   Updated: 2026/10/15 15:53:58 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ch_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_word_count(char *str, char *charset)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if (ft_ch_in_str(str[i], charset))
			in_word = 0;
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	ft_copy_words(char **res, char *str, char *charset)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_ch_in_str(str[i], charset))
			i++;
		if (str[i] == '\0')
			break ;
		len = 0;
		while (str[i] != '\0' && !ft_ch_in_str(str[i], charset))
		{
			len++;
			i++;
		}
		res[j] = malloc(sizeof(char) * (len + 1));
		res[j] = ft_strncpy(res[j], str + i - len, len);
		res[j][len] = '\0';
		j++;
	}
	res[j] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		count;

	count = ft_get_word_count(str, charset);
	res = malloc(sizeof(char *) * (count + 1));
	if (res == NULL)
		return (NULL);
	ft_copy_words(res, str, charset);
	return (res);
}

/*
#include <stdio.h>
void	print_split(char *str, char *charset)
{
	char	**result;
	int		i;

	printf("Input:   \"%s\"\n", str);
	printf("Charset: \"%s\"\n", charset);
	result = ft_split(str, charset);
	if (!result)
	{
		printf("Result: NULL\n\n");
		return ;
	}
	i = 0;
	while (result[i])
	{
		printf("result[%d] = \"%s\"\n", i, result[i]);
		i++;
	}
	printf("result[%d] = NULL\n\n", i);
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

int	main(void)
{
	// Test 1: Basic split 
	print_split("hello,world,42", ",");

	// Test 2: Multiple separators 
	print_split("hello,world;42:42", ",;:");

	// Test 3: Consecutive separators 
	print_split("hello,,,world;;42", ",;");

	// Test 4: Separators at the beginning and end 
	print_split(",hello,world,", ",");

	// Test 5: Empty input string 
	print_split("", ",");

	// Test 6: Input contains only separators 
	print_split(",,,;;;", ",;");

	// Test 7: No separators found 
	print_split("hello world", ",");

	// Test 8: Every character is a separator 
	print_split("abc", "abc");

	// Test 9: Space as a separator 
	print_split("hello world from 42", " ");

	// Test 10: Mixed spaces and punctuation 
	print_split("  hello,,world;42  ", " ,;");

	// Test 11: Empty charset 
	print_split("hello world", "");

	// Test 12: Single-character input 
	print_split("a", ",");

	return (0);
}
*/
