/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:28:51 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/06/12 16:46:04 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// void	ft_putstr_fd(char *s, int fd)
// {
// 	if (s != NULL)
// 	{
// 		while (*s != '\0')
// 		{
// 			write(fd, s, 1);
// 			s++;
// 		}
// 	}
// }

int	check_args(va_list args, char c)
{
	int	len;

	len = 1;
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		len = print_str(va_arg(args, char *));
	else if (c == 'p')
		len = ptr_to_hex(va_arg(args, uintptr_t), 'l');
	else if (c == 'd' || c == 'i')
		len = putnbr_int(va_arg(args, int));
	else if (c == 'u')
		len = putnbr_uint(va_arg(args, unsigned int));
	else if (c == 'x')
		len = dec_to_hex(va_arg(args, unsigned int), 'l');
	else if (c == 'X')
		len = dec_to_hex(va_arg(args, unsigned int), 'L');
	else if (c == '%')
		ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *format_str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format_str);
	i = 0;
	len = 0;
	while (format_str[i] != '\0')
	{
		if (format_str[i] == '%' && format_str[i + 1] != '\0')
		{
			len += check_args(args, format_str[i + 1]);
			i++;
		}
		else
		{
			write(1, &format_str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
