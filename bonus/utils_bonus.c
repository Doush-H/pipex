/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:31:05 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/06/15 00:54:02 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*ft_strjoin_new(char *s1, char *s2)
{
	size_t	memsize;
	size_t	i;
	char	*new_str;
	size_t	len_s1;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	memsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(memsize * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (++i < memsize && s1[i] != '\0')
		new_str[i] = s1[i];
	while (i < memsize)
	{
		new_str[i] = s2[i - len_s1];
		i++;
	}
	free(s1);
	free(s2);
	return (new_str);
}

void	perror_exit(char *str, int exitcode)
{
	perror(str);
	exit(exitcode);
}

void	wait_for_pids(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		waitpid(pipex->pids[i], NULL, 0);
		i++;
	}
	free(pipex->pids);
}

void	set_default(t_pipex *pipex, char **argv, int argc)
{
	checks(argv, argc);
	pipex->cmd_number = 0;
	pipex->i_path = argv[1];
	pipex->o_path = argv[argc - 1];
}
