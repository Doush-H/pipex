/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:31:49 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/04/27 13:22:31 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

static int	dec_hex_print(char *str)
{
	int	ret;

	ret = 0;
	ft_putstr_fd(str, 1);
	ret = ft_strlen(str);
	free(str);
	return (ret);
}

int	dec_to_hex(unsigned int nbr, char c)
{
	unsigned int	copy;
	char			*str;
	int				i;
	char			*base;
	int				ret;

	i = 0;
	copy = nbr;
	base = ft_get_base_hex(c);
	if (copy == 0)
		i++;
	while (copy != 0)
	{
		copy = copy / 16;
		i++;
	}
	str = malloc(i + 1);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = base[nbr % 16];
		nbr /= 16;
	}
	ret = dec_hex_print(str);
	return (ret);
}
