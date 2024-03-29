/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 09:15:07 by greed          #+#    #+#                */
/*   Updated: 2019/11/12 10:31:40 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void			*fremashin(int j, char **words)
{
	while (j != 0)
	{
		j--;
		if (words[j])
			free(words[j]);
	}
	free(words);
	return (NULL);
}

static int			ft_count_words(char const *str, char c)
{
	int i;
	int in_words;
	int count;

	i = 0;
	in_words = 0;
	count = 0;
	if (!(str))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			in_words = 0;
		else if (in_words == 0)
		{
			in_words = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static int			ft_wordlen(char const *str, int i, char c)
{
	int len;

	len = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char			**ft_gridfill(char const *s, char c, char **words)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < ft_count_words(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		words[j] = (char*)malloc(sizeof(char) * ft_wordlen(s, i, c) + 1);
		if (!(words[j]))
			return (fremashin(j, words));
		while (s[i] != c && s[i] != '\0')
		{
			words[j][k] = s[i];
			k++;
			i++;
		}
		words[j][k] = '\0';
		j++;
	}
	words[j] = NULL;
	return (words);
}

char				**ft_split(char const *s, char c)
{
	char **words;

	if (!(s))
		return (NULL);
	words = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1));
	if (!(words))
		return (NULL);
	ft_gridfill(s, c, words);
	return (words);
}
