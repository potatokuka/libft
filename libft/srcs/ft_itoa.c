/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 16:43:13 by greed          #+#    #+#                */
/*   Updated: 2019/11/04 13:57:42 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_numlen(int n)
{
	int		res;

	res = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		res++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static char		*ft_memorysize(int len)
{
	char	*res;

	res = (char*)malloc(len);
	if (res == NULL)
		return (NULL);
	res[len - 1] = '\0';
	return (res);
}

static char		*ft_exceptions(int n)
{
	char	*res;

	res = (char*)malloc((n == 0) ? 2 : 13);
	if (n == 0)
		ft_strlcpy(res, "0", 2);
	else
		ft_strlcpy(res, "-2147483648", 12);
	return (res);
}

char			*ft_itoa(int n)
{
	int		nbr_len;
	int		sign;
	char	*res;
	int		i;

	sign = n < 0;
	nbr_len = ft_numlen(n);
	res = ft_memorysize(nbr_len + 1);
	if (res == NULL)
		return (NULL);
	if (n == -2147483648 || n == 0)
		return (ft_exceptions(n));
	if (sign)
	{
		*res = '-';
		n *= -1;
	}
	i = -1;
	while (++i < nbr_len - sign)
	{
		res[nbr_len - 1 - i] = (char)(n % 10 + '0');
		n /= 10;
	}
	return (res);
}
