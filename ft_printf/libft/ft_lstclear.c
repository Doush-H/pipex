/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:02:18 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/03/31 11:50:14 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	tmp = NULL;
	while ((*lst) != NULL && lst != NULL && del != NULL)
	{
		(*del)((*lst)->content);
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
