/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: greed <greed@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:46:17 by greed          #+#    #+#                */
/*   Updated: 2019/11/05 16:05:30 by greed         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*link;
	t_list		*next_link;

	link = *lst;
	while (link)
	{
		next_link = link->next;
		del(link->content);
		free(link);
		link = next_link;
	}
	*lst = NULL;
}
