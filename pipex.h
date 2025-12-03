/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:25:35 by zeyildir          #+#    #+#             */
/*   Updated: 2025/11/09 19:11:59 by zeyildir         ###   ########.fr       */
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
void	child_process(char *path, char **arg, char **cmd, int *fd);
void	parent_process(char *path, char **arg, char **cmd, int *fd);
void	null_check(char **arg);
void	free_split(char **arr);

#endif
