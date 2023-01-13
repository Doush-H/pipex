/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:34:32 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/06/14 17:07:32 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_free_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->cmd_number == pipex->cmd_count - 1)
		pipex->cmd_number--;
	while (i <= pipex->cmd_number)
	{
		close(pipex->pipe[i][0]);
		close(pipex->pipe[i][1]);
		free(pipex->pipe[i]);
		i++;
	}
	free(pipex->pipe);
}

void	init_pipes_pids(t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->pipe = malloc((pipex->cmd_count - 1) * sizeof(int *));
	if (pipex->pipe == NULL)
		perror_exit("MALLOC Error", 1);
	while (i < pipex->cmd_count - 1)
	{
		pipex->pipe[i] = malloc(2 * sizeof(int));
		if (pipex->pipe[i] == NULL)
			perror_exit("MALLOC Error", 2);
		i++;
	}
	pipex->pids = malloc(pipex->cmd_count * sizeof(int));
	if (pipex->pids == NULL)
		perror_exit("MALLOC Error", 3);
}

void	o_outfile_normal(t_pipex *pipex)
{
	pipex->outfile = open(pipex->o_path, O_WTC, RIGHTS);
	if (pipex->outfile < 0)
		perror_exit("OUTPUT FILE Error", 7);
}

void	o_outfile_heredoc(t_pipex *pipex)
{
	pipex->outfile = open(pipex->o_path, O_WAC, RIGHTS);
	if (pipex->outfile < 0)
		perror_exit("OUTPUT FILE Error", 7);
}

void	conf_pipes(t_pipex *pipex)
{
	if (pipex->cmd_number == 0)
	{
		pipex->infile = open(pipex->i_path, O_RDONLY);
		if (pipex->infile < 0)
			perror_exit("INPUT FILE Error", 6);
		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipex->pipe[0][1], STDOUT_FILENO);
		close(pipex->infile);
	}
	else if (pipex->cmd_number == pipex->cmd_count - 1)
	{
		if (ft_strncmp("/tmp/.tmp", pipex->i_path, 7) == 0)
			o_outfile_heredoc(pipex);
		else
			o_outfile_normal(pipex);
		dup2(pipex->pipe[pipex->cmd_number - 1][0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->outfile);
	}
	else
	{
		dup2(pipex->pipe[pipex->cmd_number - 1][0], STDIN_FILENO);
		dup2(pipex->pipe[pipex->cmd_number][1], STDOUT_FILENO);
	}
	close_free_pipes(pipex);
}
