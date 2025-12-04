/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:18:45 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/04 21:54:44 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static	void	close_pipe(t_pipex *data, int fd)
{
	close(data->fd[0]);
	close(data->fd[1]);
	close(fd);
}

void	free_process(t_pipex *data)
{
	free(data->path2);
	free_split(data->cmd1);
	free_split(data->cmd2);
	close(data->fd[0]);
	close(data->fd[1]);
}

void	child_process(t_pipex *data, char **arg)
{
	int		in_fd;

	in_fd = open(arg[1], O_RDONLY, 0644);
	if (in_fd == -1)
	{
		free(data->path1);
		free_process(data);
		error_message();
	}
	if (!data->path1)
	{
		free_process(data);
		close(in_fd);
		exit(1);
	}
	dup2(in_fd, STDIN_FILENO);
	dup2(data->fd[1], STDOUT_FILENO);
	close_pipe(data, in_fd);
	free(data->path2);
	free_split(data->cmd2);
	if (execve(data->path1, data->cmd1, NULL) == -1)
	{
		free(data->path1);
		free_split(data->cmd1);
	}
}

void	parent_process(t_pipex *data, int o_fd)
{
	if (o_fd == -1)
	{
		free_helper(data);
		error_message();
	}
	if (!data->path2)
	{
		free_helper(data);
		close(o_fd);
		exit(1);
	}
	dup2(data->fd[0], STDIN_FILENO);
	dup2(o_fd, STDOUT_FILENO);
	close_pipe(data, o_fd);
	free(data->path1);
	free_split(data->cmd1);
	if (execve(data->path2, data->cmd2, NULL) == -1)
	{
		free(data->path2);
		free_split(data->cmd2);
	}
}
