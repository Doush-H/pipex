/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:21:45 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/03/31 11:33:26 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int				mem_size;
	char			*mem;
	char			*copy;

	mem_size = 0;
	copy = NULL;
	while (s1[mem_size] != '\0')
	{
		mem_size++;
	}
	mem_size++;
	mem = malloc(mem_size);
	if (mem != NULL)
	{
		copy = mem;
		while (*s1 != '\0')
		{
			*copy = *s1;
			copy++;
			s1++;
		}
		*copy = '\0';
	}
	return (mem);
}
