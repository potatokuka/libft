/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 17:10:12 by greed          #+#    #+#                */
/*   Updated: 2019/10/31 12:07:56 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*srcs;

	dest = dst;
	srcs = src;
	if (dest < srcs)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = srcs[i];
			i++;
		}
	}
	else if (dest > srcs)
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = srcs[i - 1];
			i--;
		}
	}
	return (dst);
}
