/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:25:35 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/04 21:55:05 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid1;
	char	*paths;
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
}			t_pipex;

char	*get_paths(char **env);
char	**get_split_paths(char *path);
char	**get_commands(char *cmd);
char	*find_real_path(char **paths, char *cmd);
void	child_process(t_pipex *data, char **arg);
void	parent_process(t_pipex *data, int o_fd);
void	null_check(char **arg);
void	free_split(char **arr);
void	error_message(void);
void	free_helper(t_pipex *data);
void	free_process(t_pipex *data);

#endif
