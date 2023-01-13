/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:08:44 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/03/29 18:18:29 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	index_mem;
	size_t	index_strs;
	size_t	total_len;

	index_mem = 0;
	index_strs = 0;
	total_len = 0;
	if (s1 != NULL && s2 != NULL)
		total_len = ft_strlen(s1) + ft_strlen(s2);
	mem = malloc(total_len + 1);
	if (mem == NULL)
		return (NULL);
	while (index_mem < total_len - ft_strlen(s2) && s1 != NULL)
	{
		mem[index_mem++] = s1[index_strs++];
	}
	index_strs = 0;
	while (index_mem < total_len && s2 != NULL)
	{
		mem[index_mem++] = s2[index_strs++];
	}
	mem[index_mem] = '\0';
	return (mem);
}
