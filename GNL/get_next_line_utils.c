/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:15:10 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/04/08 11:08:20 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_slen(char *str, unsigned char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

int	find_char(char *str, unsigned char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*stradd(char *storage, char *buf)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (storage == NULL)
	{
		storage = malloc(1);
		if (storage == NULL)
			return (NULL);
		storage[0] = '\0';
	}
	ret = malloc(ft_slen(storage, '\0') + ft_slen(buf, '\0') + 1);
	if (ret != NULL)
	{
		while (storage[i] != '\0')
			ret[j++] = storage[i++];
		i = 0;
		while (buf[i] != '\0')
			ret[j++] = buf[i++];
		ret[j] = '\0';
	}
	free(storage);
	return (ret);
}
