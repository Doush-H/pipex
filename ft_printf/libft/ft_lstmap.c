/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:41:35 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/03/31 11:55:23 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*newlist;

	current = NULL;
	newlist = NULL;
	while (lst != NULL)
	{
		current = ft_lstnew(f(lst->content));
		if (current == NULL)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&newlist, current);
	}
	return (newlist);
}
