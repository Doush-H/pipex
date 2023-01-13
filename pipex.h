/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhamdiev <dhamdiev@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:46:27 by dhamdiev          #+#    #+#             */
/*   Updated: 2022/06/15 00:54:31 by dhamdiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./ft_printf/ft_printf.h"
# include "./GNL/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# ifndef RIGHTS
#  define RIGHTS 420
# endif
# ifndef O_WTC
#  define O_WTC 1537
# endif

typedef struct s_pipex
{
	int		pipe[2];
	int		pids[2];
	char	*infile;
	char	*outfile;
}				t_pipex;

char	*get_cmd(char *str);
char	**get_paths(char **env);
char	*get_cmd_path(char *cmd, char **paths);
void	free_split(char **split);
char	*ft_strjoin_new(char *s1, char *s2);
void	perror_exit(char *str, int exitcode);
void	checks(char **argv, int argc);

#endif