/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 16:20:14 by greed          #+#    #+#                */
/*   Updated: 2019/11/06 10:41:05 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new;
	void	*content;

	if (lst == 0)
		return (0);
	res = 0;
	while (lst)
	{
		content = f(lst);
		if (!(content))
			del(lst);
		new = ft_lstnew(content);
		ft_lstadd_back(&res, new);
		lst = lst->next;
	}
	return (res);
}
