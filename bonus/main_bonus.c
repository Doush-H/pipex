/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:08:48 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/06/15 00:53:31 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	checks(char **argv, int argc)
{
	int		i;
	char	**tmp;

	i = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (tmp[0] == NULL)
		{
			printf("Empty strings was found.\n");
			exit(1);
		}
		free_split(tmp);
		i++;
	}
}

//fd[0] - read end
//fd[1] = write end
void	p_f_run(char *cmd, char **args, char **env, t_pipex *pipex)
{
	if (pipex->cmd_number < pipex->cmd_count - 1)
	{
		if (pipe(pipex->pipe[pipex->cmd_number]) < 0)
			perror("PIPE Error");
	}
	pipex->pids[pipex->cmd_number] = fork();
	if (pipex->pids[pipex->cmd_number] < 0)
		perror("FORK Error");
	else if (pipex->pids[pipex->cmd_number] == 0)
	{
		conf_pipes(pipex);
		free(pipex->pids);
		if (execve(cmd, args, env) < 0)
			perror_exit("CMD ERROR", 4);
	}
	free_split(args);
	free(cmd);
	pipex->cmd_number++;
}

char	*read_to_file(char *limiter)
{
	int		fd;
	char	*t;

	fd = open("/tmp/.tmp", O_WTC, RIGHTS | S_IWGRP | S_IWOTH);
	if (fd < 0)
	{
		ft_printf("Error: Could not create a tmp file\n");
		exit(1);
	}
	t = ft_strdup("");
	limiter = ft_strjoin_new(ft_strdup(limiter), ft_strdup("\n"));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	while (t != NULL && ft_strncmp(limiter, t, ft_strlen(limiter) + 1) != 0)
	{
		free(t);
		t = get_next_line(STDIN_FILENO);
		if (t != NULL && ft_strncmp(limiter, t, ft_strlen(limiter) + 1) != 0)
			ft_printf("%s", t);
	}
	free(limiter);
	return ("/tmp/.tmp");
}

//fd[0] - read end
//fd[1] = write end
int	main(int argc, char **argv, char **env)
{
	int		i;
	int		of;
	t_pipex	pipex;

	if (argc < 5)
		perror_exit("Too few arguments", 5);
	i = -1;
	of = 2;
	set_default(&pipex, argv, argc);
	if (ft_strncmp(argv[1], "here_doc", (ft_strlen("here_doc") + 1)) == 0)
	{
		of = 3;
		pipex.i_path = read_to_file(argv[2]);
	}
	pipex.cmd_count = argc - (of + 1);
	init_pipes_pids(&pipex);
	while (++i < pipex.cmd_count)
		p_f_run(get_cmd_path(get_cmd(argv[i + of]), get_paths(env)),
			ft_split(argv[i + of], ' '), env, &pipex);
	pipex.cmd_number--;
	close_free_pipes(&pipex);
	wait_for_pids(&pipex);
	if (ft_strncmp("/tmp/.tmp", pipex.i_path, 7) == 0)
		unlink("/tmp/.tmp");
	return (0);
}
