/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:04:12 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/04/07 14:06:40 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*mem;
	size_t		i;
	size_t		s_len;

	i = 0;
	if (s == NULL)
		return (NULL);
	mem = malloc(len + 1);
	if (mem == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
	{
		mem[i] = '\0';
		return (mem);
	}
	while (start < s_len && i < len)
		mem[i++] = s[start++];
	mem[i] = '\0';
	return (mem);
}
