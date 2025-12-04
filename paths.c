/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:18:32 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/04 21:55:52 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_paths(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	error_message();
	return (NULL);
}

char	**get_split_paths(char *path)
{
	char	**tmp;

	tmp = ft_split(path, ':');
	return (tmp);
}

char	**get_commands(char *cmd)
{
	char	**tmp;

	tmp = NULL;
	if (cmd[0] != '\0')
		tmp = ft_split(cmd, ' ');
	return (tmp);
}

static char	*join_with_cmd(char *dir, char *cmd, char **paths)
{
	char	*joined_path;
	char	*path_with_cmd;

	if (ft_strchr(cmd, '/') != 0)
		return (ft_strdup(cmd));
	joined_path = ft_strjoin(dir, "/");
	if (!joined_path)
	{
		free_split(paths);
		return (NULL);
	}
	path_with_cmd = ft_strjoin(joined_path, cmd);
	free(joined_path);
	if (!path_with_cmd)
	{
		free_split(paths);
		return (NULL);
	}
	return (path_with_cmd);
}

char	*find_real_path(char **paths, char *cmd)
{
	int		i;
	char	*path_with_cmd;

	if (!paths || !cmd || cmd[0] == '\0')
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path_with_cmd = join_with_cmd(paths[i], cmd, paths);
		if (!path_with_cmd)
			return (NULL);
		if (access(path_with_cmd, F_OK | X_OK) == 0)
		{
			free_split(paths);
			return (path_with_cmd);
		}
		free(path_with_cmd);
		i++;
	}
	write(2, "Error\n", 6);
	free_split(paths);
	return (NULL);
}
