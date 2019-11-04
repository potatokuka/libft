/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 15:51:34 by greed          #+#    #+#                */
/*   Updated: 2019/11/04 10:48:27 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	unsigned char	*block;
	int				len;
	int				i;
	char			*str;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	if (!(block = (unsigned char*)ft_calloc(sizeof(char), len)))
		ENOMEM;
	else
	{
		str = (char*)malloc(len + 1);
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}
