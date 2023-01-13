/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:31:09 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/03/29 18:17:04 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putnbr_fd(int n, int fd)
{
	int		copy_n;
	int		size;
	char	c;

	copy_n = n;
	size = get_size(n);
	if (n < 0)
	{
		write(fd, "-", 1);
		size--;
	}
	while (size > 0)
	{
		copy_n = checks(copy_n, size);
		c = copy_n + '0';
		write(fd, &c, 1);
		copy_n = n;
		size--;
	}
}
