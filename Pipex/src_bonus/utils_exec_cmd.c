/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:11:28 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/19 17:11:29 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	still_backslash(char *cmd, int i)
{
	i++;
	if (!cmd[i])
		return (-1);
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (-1);
		i++;
	}
	return (1);
}

int	get_rang_cmd(char *path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (path[i] == '/')
		{
			if (still_backslash(path, i) == 1)
				return (i + 1);
		}
		i++;
	}
	return (i);
}

void	get_data_pids(t_data *data)
{
	data->pids = (int *)malloc(sizeof(pid_t) * data->nb_cmds);
	if (!data->pids)
	{
		free(data->paths);
		free(data->cmds);
		free(data);
		perror("Error Malloc\n");
	}
}

char	*get_classique_path(char *cmd)
{
	char	*path;
	int		j;

	path = (char *)malloc(sizeof(char) * (11 + ft_strlen(cmd)));
	if (!path)
		return (NULL);
	path[0] = '/';
	path[1] = 'u';
	path[2] = 's';
	path[3] = 'r';
	path[4] = '/';
	path[5] = 'b';
	path[6] = 'i';
	path[7] = 'n';
	path[8] = '/';
	j = 0;
	while (cmd[j])
	{
		path[j + 9] = cmd[j];
		j++;
	}
	path[9 + j] = '\0';
	return (path);
}
