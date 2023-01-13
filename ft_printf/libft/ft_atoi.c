/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:02:51 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/05/27 15:49:18 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_spaces(const char **str)
{
	while (**str == ' ' || **str == '\n'
		|| **str == '\t' || **str == '\f' || **str == '\v' || **str == '\r')
	{
		(*str)++;
	}
}

static int	check_minplus(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign *= -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

static void	check_overf(const char *str, int re, int sign)
{
	if (re > 2147483647 / 10 || (re == 2147483647 / 10 && (*str) - 48 > 7))
	{
		if (re > 2147483647 / 10)
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		if (sign == -1 && ((*str) - 48) > 8 && re == 2147483647 / 10)
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		if (sign == 1)
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
	}
}

int	ft_atoi(const char *str)
{
	int	re;
	int	sign;

	re = 0;
	sign = 1;
	check_spaces(&str);
	sign = check_minplus(&str);
	if (ft_strlen(str) > 10)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	while (*str && *str >= 48 && *str <= 57)
	{
		check_overf(str, re, sign);
		re = re * 10 + ((*str) - 48);
		str++;
	}
	return (re * sign);
}
