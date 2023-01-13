/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:52:26 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/03/31 12:23:27 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

//Checking the beginng of the string for chars to trim and returning an index 
//which indicates the position from which we should start copying
static size_t	get_beg(char const *str, char const *set)
{
	size_t	beg_index;
	size_t	i;
	size_t	j;

	beg_index = 0;
	i = 0;
	j = 0;
	while (i < ft_strlen(str))
	{
		while (j < ft_strlen(set))
		{
			if (set[j] == str[i])
			{
				i++;
				beg_index++;
				break ;
			}
			j++;
		}
		if (j == ft_strlen(set))
			break ;
		j = 0;
	}
	return (beg_index);
}

//Checking the end of the string for chars to trim and returning an index 
//which indicates until when we should copy the string
static size_t	get_end(char const *str, char const *set, size_t beg_index)
{
	size_t	end_index;
	size_t	i;
	size_t	j;

	end_index = 0;
	if (ft_strlen(str) > 0)
		end_index = ft_strlen(str) - 1;
	i = end_index;
	j = -1;
	while (i > beg_index)
	{
		while (++j < ft_strlen(set))
		{
			if (set[j] == str[i])
			{
				i--;
				end_index--;
				break ;
			}
		}
		if (j == ft_strlen(set))
			break ;
		j = -1;
	}
	return (end_index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*mem;
	size_t	b_index;
	size_t	e_index;
	size_t	i;

	i = 0;
	b_index = 0;
	if (s1 == NULL)
		return (NULL);
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	b_index = get_beg(s1, set);
	e_index = get_end(s1, set, b_index);
	mem = malloc(ft_strlen(s1) - (b_index) - (ft_strlen(s1) - e_index) + 2);
	if (mem == NULL)
		return (NULL);
	while (b_index <= e_index)
	{
		mem[i++] = s1[b_index];
		b_index++;
	}
	mem[i] = '\0';
	return (mem);
}
