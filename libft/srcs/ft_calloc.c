/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 15:09:14 by greed          #+#    #+#                */
/*   Updated: 2019/10/31 15:52:55 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_calloc(size_t count, size_t size)
{
	void		*stored;

	if (!(stored = (void*)malloc(count * size)))
		return (NULL);
	ft_bzero(stored, count * size);
	return (stored);
}
