/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:29:56 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/03/29 18:04:44 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*mysrc;
	unsigned char	*mydst;

	mysrc = (unsigned char *)src;
	mydst = (unsigned char *)dst;
	if ((mysrc < mydst) && (mydst < mysrc + len))
	{
		mydst += len;
		mysrc += len;
		while (len != 0 && (dst != NULL || src != NULL))
		{
			*--mydst = *--mysrc;
			len--;
		}
	}
	else
	{
		while (len != 0 && (dst != NULL || src != NULL))
		{
			*mydst++ = *mysrc++;
			len--;
		}
	}
	return (dst);
}
