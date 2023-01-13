/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:40:00 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/04/07 16:53:52 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*mem;
	unsigned char	*copy;
	size_t			mem_size;
	size_t			i;

	i = 0;
	mem_size = count * size;
	mem = malloc(mem_size);
	copy = (unsigned char *)mem;
	if (mem != NULL)
	{
		while (mem_size > i)
		{
			copy[i] = 0;
			i++;
		}
		return (mem);
	}
	return (NULL);
}
