/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:51:55 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/03/31 16:16:19 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_itoa(int n)
{
	int		copy_n;
	int		index_i;
	char	*str;
	int		size;

	copy_n = n;
	size = get_size(n);
	index_i = 0;
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[index_i++] = '-';
		size--;
	}
	while (size > 0)
	{
		copy_n = checks(copy_n, size);
		str[index_i++] = copy_n + '0';
		copy_n = n;
		size--;
	}
	str[index_i] = '\0';
	return (str);
}
