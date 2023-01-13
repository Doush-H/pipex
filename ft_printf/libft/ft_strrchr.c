/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:32:16 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/03/29 18:21:29 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char			letter;
	const char		*begg;

	letter = (char)c;
	begg = s;
	while (*s != '\0')
		s++;
	while (*s != letter)
	{
		if (s == begg && *begg != letter)
			return (0);
		s--;
	}
	return ((char *)s);
}
