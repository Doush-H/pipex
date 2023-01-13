/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:30:54 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/04/27 13:10:29 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

static int	get_size(int num)
{
	int	res;

	res = 0;
	if (num < 0)
		res++;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		res++;
	}
	return (res);
}

static int	to_pow(int num, int pow)
{
	if (pow == 0)
		return (1);
	return (num * to_pow(num, pow - 1));
}

static int	checks(int num, int size)
{
	if (size > 1)
		num /= to_pow(10, size - 1);
	num %= 10;
	if (num < 0)
		num *= -1;
	return (num);
}

int	putnbr_int(int n)
{
	int		copy_n;
	int		size;
	int		ret;
	char	c;

	copy_n = n;
	size = get_size(n);
	ret = size;
	if (n < 0)
	{
		write(1, "-", 1);
		size--;
	}
	while (size > 0)
	{
		copy_n = checks(copy_n, size);
		c = copy_n + '0';
		write(1, &c, 1);
		copy_n = n;
		size--;
	}
	return (ret);
}
