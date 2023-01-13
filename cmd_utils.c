/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:35:49 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/06/15 00:46:16 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd_path(char *cmd, char **paths)
{
	char	*cmd_path;
	int		i;

	i = 0;
	cmd_path = NULL;
	if (ft_strchr(cmd, '/') != 0)
		cmd_path = ft_strdup(cmd);
	else
	{
		while (paths[i] != NULL)
		{
			paths[i] = ft_strjoin_new(paths[i], ft_strdup("/"));
			paths[i] = ft_strjoin_new(paths[i], ft_strdup(cmd));
			if (access(paths[i], F_OK) == 0)
				cmd_path = ft_strdup(paths[i]);
			i++;
		}
	}
	free(cmd);
	free_split(paths);
	return (cmd_path);
}

char	**get_paths(char **env)
{
	int		i;
	char	*path;

	path = NULL;
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = &(env[i][5]);
		i++;
	}
	if (path == NULL)
		path = "./";
	return (ft_split(path, ':'));
}

char	*get_cmd(char *str)
{
	char	*ret;
	char	**tmp;

	tmp = ft_split(str, ' ');
	ret = ft_strdup(tmp[0]);
	free_split(tmp);
	return (ret);
}
