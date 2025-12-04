/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:59:46 by zeyildir          #+#    #+#             */
/*   Updated: 2025/12/04 21:05:50 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	null_check(char **arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if ((arg[i][0] == '\0' || arg[i][0] == ' ') && i != 2)
			write(2, "Error\n", 6);
		i++;
	}
}

void	free_helper(t_pipex *data)
{
	free(data->path1);
	free_process(data);
}
