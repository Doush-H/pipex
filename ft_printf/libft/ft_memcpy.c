/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:54:22 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/03/31 11:56:41 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*mysrc;
	unsigned char	*mydst;

	mysrc = (unsigned char *)src;
	mydst = (unsigned char *)dst;
	while (n > 0 && (dst != NULL || src != NULL))
	{
		*mydst = *mysrc;
		mydst++;
		mysrc++;
		n--;
	}
	return (dst);
}
