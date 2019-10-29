/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:34:26 by greed          #+#    #+#                */
/*   Updated: 2019/10/29 10:50:00 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (src[i] != '\0')
		i++;
	if (dstsize != 0)
	{
		while(j <= dstsize && j < i)
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (i);
}
