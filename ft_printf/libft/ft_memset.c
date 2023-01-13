/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:52:45 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/03/31 12:11:02 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*beg;

	beg = (unsigned char *)b;
	while (len > 0)
	{
		*beg = (unsigned char)c;
		beg++;
		len--;
	}
	return (b);
}
