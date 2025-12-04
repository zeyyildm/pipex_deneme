/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:18:57 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/04 21:56:17 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	init_pipex(t_pipex *data, char **av, char **env)
{
	data->paths = get_paths(env);
	data->cmd1 = get_commands(av[2]);
	data->cmd2 = get_commands(av[3]);
	if (!data->cmd1 || !data->cmd1[0])
		error_message();
	if (!data->cmd2 || !data->cmd2[0])
		error_message();
	data->path1 = find_real_path(get_split_paths(data->paths), data->cmd1[0]);
	data->path2 = find_real_path(get_split_paths(data->paths), data->cmd2[0]);
	if (!data->path2)
	{
		free(data->path1);
		free_split(data->cmd1);
		free_split(data->cmd2);
		exit(1);
	}
}

static void	run_pipex(t_pipex *data, char **av, int fd)
{
	if (pipe(data->fd) == -1)
		error_message();
	data->pid = fork();
	if (data->pid == -1)
		error_message();
	if (data->pid == 0)
		child_process(data, av);
	data->pid1 = fork();
	if (data->pid1 == -1)
		error_message();
	if (data->pid1 == 0)
		parent_process(data, fd);
	close(data->fd[0]);
	close(data->fd[1]);
	free(data->path1);
	free(data->path2);
	free_split(data->cmd1);
	free_split(data->cmd2);
	waitpid(data->pid, NULL, 0);
	waitpid(data->pid1, NULL, 0);
}

void	init_struct(t_pipex *data)
{
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	data->path1 = NULL;
	data->path2 = NULL;
	data->paths = NULL;
}

int	main(int ac, char **av, char **env)
{
	t_pipex	data;
	int		fd;

	if (ac == 5)
	{
		fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		init_struct(&data);
		null_check(av);
		init_pipex(&data, av, env);
		run_pipex(&data, av, fd);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
