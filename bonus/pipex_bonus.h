/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:46:27 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/06/15 00:53:03 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../ft_printf/ft_printf.h"
# include "../GNL/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# ifndef RIGHTS
#  define RIGHTS 420
# endif
# ifndef O_WTC
#  define O_WTC 1537
# endif
# ifndef O_WAC
#  define O_WAC 521
# endif

typedef struct s_pipex
{
	int		**pipe;
	int		*pids;
	int		cmd_number;
	int		cmd_count;
	char	*i_path;
	int		infile;
	char	*o_path;
	int		outfile;
}				t_pipex;

void	free_split(char **split);
char	*ft_strjoin_new(char *s1, char *s2);
void	perror_exit(char *str, int exitcode);
void	wait_for_pids(t_pipex *pipex);
void	close_free_pipes(t_pipex *pipex);
void	init_pipes_pids(t_pipex *pipex);
char	*get_cmd_path(char *cmd, char **paths);
char	**get_paths(char **env);
char	*get_cmd(char *str);
void	conf_pipes(t_pipex *pipex);
void	set_default(t_pipex *pipex, char **argv, int argc);
void	checks(char **argv, int argc);

#endif