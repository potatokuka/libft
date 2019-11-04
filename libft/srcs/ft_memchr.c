/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 16:26:58 by greed          #+#    #+#                */
/*   Updated: 2019/11/04 13:58:47 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*ptr;
	const char	*xs;

	i = 0;
	ptr = 0;
	xs = s;
	while (i < n)
	{
		if (xs[i] == c)
		{
			ptr = &xs[i];
			break ;
		}
		i++;
	}
	return ((char*)ptr);
}
