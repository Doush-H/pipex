/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:08:48 by dhamdiev          #+#    #+#             */
/*   Updated: 2023/01/13 16:40:33 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

void	print_exit(char *str, int exitcode)
{
	ft_printf("%s", str);
	exit(exitcode);
}

void	cmd1(char *cmd_path, char **args, char **env, t_pipex *pipex)
{
	int		fd;

	fd = open(pipex->infile, O_RDONLY);
	if (fd < 0)
		perror_exit("INFILE Error", 4);
	dup2(fd, STDIN_FILENO);
	dup2(pipex->pipe[1], STDOUT_FILENO);
	close_pipes(pipex);
	close(fd);
	if (execve(cmd_path, args, env) < 0)
		perror_exit("EXECVE Error", 5);
}

void	cmd2(char *cmd_path, char **args, char **env, t_pipex *pipex)
{
	int		fd;

	fd = open(pipex->outfile, O_WTC, RIGHTS);
	if (fd < 0)
		perror_exit("OUTFIELE Error", 6);
	dup2(fd, STDOUT_FILENO);
	dup2(pipex->pipe[0], STDIN_FILENO);
	close_pipes(pipex);
	close(fd);
	if (execve(cmd_path, args, env) < 0)
		perror_exit("EXECVE Error", 6);
}

//fd[0] - read end
//fd[1] = write end
int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
		print_exit("Number of passed arguments is not correct.\n", 1);
	checks(argv, argc);
	pipex.infile = argv[1];
	pipex.outfile = argv[4];
	if (pipe(pipex.pipe) < 0)
		perror_exit("PIPE Error", 1);
	pipex.pids[0] = fork();
	if (pipex.pids[0] < 0)
		perror_exit("FORK Error", 2);
	else if (pipex.pids[0] == 0)
		cmd1(get_cmd_path(get_cmd(argv[2]), get_paths(env)),
			ft_split(argv[2], ' '), env, &pipex);
	pipex.pids[1] = fork();
	if (pipex.pids[1] < 0)
		perror_exit("FORK Error", 3);
	else if (pipex.pids[1] == 0)
		cmd2(get_cmd_path(get_cmd(argv[3]), get_paths(env)),
			ft_split(argv[3], ' '), env, &pipex);
	close_pipes(&pipex);
	waitpid(pipex.pids[0], NULL, 0);
	waitpid(pipex.pids[1], NULL, 0);
	return (0);
}
