/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 09:07:10 by greed          #+#    #+#                */
/*   Updated: 2019/11/04 13:00:07 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	void				*stored;
	size_t				i;
	char				*dst;

	i = 0;
	if (s == 0)
		return (NULL);
	if (!(stored = (void*)ft_calloc(sizeof(char), len + 1)))
		return (NULL);
	dst = (char*)malloc(len + 1);
	while (i < len)
	{
		dst[i] = s[start];
		start++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
