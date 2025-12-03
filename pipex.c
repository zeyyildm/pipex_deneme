/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:18:57 by zeyildir          #+#    #+#             */
/*   Updated: 2025/11/09 20:05:22 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_pipex(t_pipex *data, char **av, char **env)
{
	data->paths = get_paths(env);
	data->cmd1 = get_commands(av[2]);
	data->cmd2 = get_commands(av[3]);
	if (!data->cmd1 || !data->cmd1[0])
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (!data->cmd2 || !data->cmd2[0])
	{
		write(2, "Error: Command not found\n", 25);
		exit(1);
	}
	data->path1 = find_real_path(get_split_paths(data->paths), data->cmd1[0]);
	data->path2 = find_real_path(get_split_paths(data->paths), data->cmd2[0]);
	if (!data->path1 || !data->path2)
	{
		free_split(data->cmd1);
		free_split(data->cmd2);
		write(2, "Error\n", 6);
		exit(1);
	}
}

static void	run_pipex(t_pipex *data, char **av)
{
	if (pipe(data->fd) == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	data->pid = fork();
	if (data->pid == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (data->pid == 0)
		child_process(data->path1, av, data->cmd1, data->fd);
	else
	{
		waitpid(data->pid, NULL, 0);
		parent_process(data->path2, av, data->cmd2, data->fd);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	data;

	if (ac == 5)
	{
		null_check(av);
		init_pipex(&data, av, env);
		run_pipex(&data, av);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
