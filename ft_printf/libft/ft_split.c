/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:31:14 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/04/07 14:09:17 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	str_num(char const *str, char c)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str != NULL && str[i])
	{
		if (i > 0)
		{
			if (str[i] == c && str[i - 1] != c)
				num++;
		}
		i++;
	}
	return (num + 1);
}

static char	*strdup_alt(const char *s1, char c)
{
	int				mem_size;
	char			*mem;
	char			*copy;

	mem_size = 0;
	while (s1[mem_size] != c && s1[mem_size] != '\0')
		mem_size++;
	mem = ft_calloc(mem_size + 1, sizeof(char ));
	if (mem != NULL)
	{
		copy = mem;
		while (*s1 != '\0' && *s1 != c)
		{
			*copy = *s1;
			copy++;
			s1++;
		}
		*copy = '\0';
	}
	return (mem);
}

static void	ft_skip(char c, int *i, const char *s, int *j)
{
	while (*(s + (*i)) != c && *(s + (*i)) != '\0')
		(*i)++;
	while (*(s + (*i)) == c && *(s + (*i)) != '\0')
		(*i)++;
	(*j)++;
}

static int	checks(char **ptrs, int *i, char c, char const *s)
{
	int	i_free;
	int	i_p;

	i_free = 0;
	i_p = 0;
	while (i_p < str_num(s, c) && *(s + *i))
	{
		if (*(s + *i) != c)
		{
			ptrs[i_p] = strdup_alt(s + *i, c);
			if (ptrs[i_p] == NULL)
			{
				while (i_free < i_p)
				{
					free(ptrs[i_free]);
					i_free++;
				}
				free(ptrs);
				free((void *)s);
				return (-1);
			}
		}
		ft_skip(c, i, s, &i_p);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ptrs;
	int		i;
	char	test[2];

	if (s == NULL)
		return (NULL);
	i = 0;
	test[0] = c;
	test[1] = 0;
	s = ft_strtrim(s, test);
	ptrs = ft_calloc(str_num(s, c) + 1, 1 * sizeof(char *));
	if (ptrs == NULL)
	{
		free((void *)s);
		return (NULL);
	}
	if (checks(ptrs, &i, c, s) == -1)
		return (NULL);
	free((void *)s);
	return (ptrs);
}
