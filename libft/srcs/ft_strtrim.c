/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 10:26:02 by greed          #+#    #+#                */
/*   Updated: 2019/11/04 14:02:25 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	in_set(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		set_len;
	char	*bz;
	char	*ez;

	if (s1 == 0)
		return (NULL);
	set_len = ft_strlen(set);
	bz = (char*)s1;
	ez = (char*)s1 + ft_strlen(s1) - 1;
	while (in_set(set, *bz))
		bz++;
	while (in_set(set, *ez))
		ez--;
	ez++;
	res = (char*)malloc((bz >= ez) ? 1 : (ez - bz + 1));
	if (res == NULL)
		return (NULL);
	if (bz >= ez)
		res[0] = '\0';
	else
		ft_strlcpy(res, bz, ez - bz + 1);
	return (res);
}
