/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:03:21 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/04/08 11:08:16 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_buf(int fd, char *storage)
{
	char	*tmp_buf;
	int		read_num;

	read_num = 1;
	tmp_buf = malloc(BUFFER_SIZE + 1);
	tmp_buf[0] = '\0';
	while (find_char(tmp_buf, '\n') == 0 && read_num != 0)
	{
		read_num = read(fd, tmp_buf, BUFFER_SIZE);
		if (read_num == -1)
		{
			free(tmp_buf);
			free(storage);
			return (NULL);
		}
		tmp_buf[read_num] = '\0';
		storage = stradd(storage, tmp_buf);
		if (storage == NULL)
		{
			free(tmp_buf);
			return (NULL);
		}
	}
	free(tmp_buf);
	return (storage);
}

char	*rem_line(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = ft_slen(str, '\n') + 1;
	if (str[i] == '\0' || str[i - 1] == '\0')
	{
		free(str);
		return (NULL);
	}
	j = 0;
	ret = malloc(ft_slen(str, '\0') - ft_slen(str, '\n') + 1);
	if (ret == NULL)
	{
		free(str);
		return (NULL);
	}
	while (str[i] != '\0')
		ret[j++] = str[i++];
	ret[j] = '\0';
	free(str);
	return (ret);
}

char	*get_ret(char *storage)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(ft_slen(storage, '\0') + 1);
	if (ret == NULL)
		return (NULL);
	while (storage[i] != '\0')
	{
		ret[i] = storage[i];
		if (storage[i++] == '\n')
			break ;
	}
	ret[i] = '\0';
	if (ret[0] == '\0')
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = get_buf(fd, storage);
	if (storage == NULL)
	{
		return (NULL);
	}	
	ret = get_ret(storage);
	storage = rem_line(storage);
	return (ret);
}
