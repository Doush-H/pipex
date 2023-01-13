/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:45:53 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/04/27 13:31:51 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

static int	print_and_free(char *str)
{
	int	ret;

	write(1, "0x", 2);
	ft_putstr_fd(str, 1);
	ret = ft_strlen(str) + 2;
	free(str);
	return (ret);
}

char	*ft_get_base_hex(char c)
{
	char	*ret;

	ret = "";
	if (c == 'l')
	{
		ret = "0123456789abcdef";
	}
	else if (c == 'L')
	{
		ret = "0123456789ABCDEF";
	}
	return (ret);
}

int	ptr_to_hex(uintptr_t ptr, char c)
{
	uintptr_t	copy;
	char		*str;
	int			i;
	char		*base;
	int			ret;

	i = 0;
	copy = ptr;
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
		str[i] = base[ptr % 16];
		ptr /= 16;
	}
	ret = print_and_free(str);
	return (ret);
}
