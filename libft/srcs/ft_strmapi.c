/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 11:44:31 by greed          #+#    #+#                */
/*   Updated: 2019/11/04 13:08:48 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*res;

	i = 0;
	if (s == 0)
		return (NULL);
	len = ft_strlen(s);
	if (!(res = (void*)ft_calloc(sizeof(char), len + 1)))
		return (NULL);
	res = (char*)malloc(len + 1);
	while (s[i] != '\0')
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
