/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:25:29 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/03/29 18:11:33 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	letter;

	letter = (char)c;
	while (*s != letter)
	{
		s++;
		if (*s == '\0' && c != '\0')
			return (0);
	}
	return ((char *)s);
}
