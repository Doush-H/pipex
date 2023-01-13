/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:20:31 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/03/29 18:20:25 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*c1;
	const unsigned char	*c2;

	c1 = (const unsigned char *)s1;
	c2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*c1 == '\0' && *c2 == '\0')
			return (0);
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
		n--;
	}
	return (0);
}
