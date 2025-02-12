/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_fille.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:10:05 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/19 17:10:06 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execve_cmd_freedom(t_data *data, char **cmd, int j)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	liberator_data(data);
	if (j == -1)
	{	
		perror(strerror(errno));
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	execve_cmd(char **cmd, t_data *data)
{
	char	*path;
	int		i;
	int		verif;

	if (still_backslash(cmd[0], -1) == 1)
		path = get_classique_path(cmd[0]);
	else
	{
		i = 0;
		while (cmd[0][i])
			i++;
		path = (char *)malloc(sizeof(char) * (i + 1));
		if (!path)
			execve_cmd_freedom(data, cmd, -1);
		ft_strlcpy(path, cmd[0], (size_t)(i + 1));
	}
	if (!path)
		execve_cmd_freedom(data, cmd, -1);
	verif = execve(path, cmd, NULL);
	free(path);
	execve_cmd_freedom(data, cmd, -1);
}

void	exec_cmd_fille2(char **cmd, t_data *data, int j)
{
	char	*path;

	if (cmd[0] == NULL)
		return ;
	if (cmd[0][0] == '/' || data->path == 0)
		execve_cmd(cmd, data);
	else
	{
		path = ft_strjoin(data->paths[0], cmd[0]);
		if (!path)
			execve_cmd_freedom(data, cmd, -1);
		while (j < nb_str(data->paths) && access(path, F_OK | X_OK) != 0)
		{
			free(path);
			path = ft_strjoin(data->paths[j], cmd[0]);
			if (!path)
				execve_cmd_freedom(data, cmd, -1);
			j++;
		}
		execve(path, cmd, NULL);
		free(path);
		execve_cmd_freedom(data, cmd, -1);
	}
}

void	exec_cmd_fille_exec(t_data *data)
{
	char	**cmd;
	char	*cmd1;

	cmd = ft_split(data->cmds[data->nb_exec], '\0');
	if (!cmd)
	{
		perror(strerror(errno));
		liberator_data(data);
		exit(EXIT_FAILURE);
	}
	if (cmd[0][0] && cmd[0][1] && cmd[0][0] == '.' && cmd[0][1] == '/')
		execve(cmd[0], cmd, NULL);
	else
	{
		cmd1 = ft_strjoin("./", cmd[0]);
		if (!cmd1)
			exit_failed_daughter(data, cmd);
		execve(cmd1, cmd, NULL);
		free(cmd1);
	}
	exit_failed_daughter(data, cmd);
}

void	exec_cmd_fille(t_data *data)
{
	char	**cmd;
	int		j;

	j = 1;
	if (access(data->cmds[data->nb_exec], X_OK) != -1)
		exec_cmd_fille_exec(data);
	cmd = ft_split(data->cmds[data->nb_exec], ' ');
	if (!cmd)
	{
		perror(strerror(errno));
		liberator_data(data);
		exit(EXIT_FAILURE);
	}
	exec_cmd_fille2(cmd, data, j);
	j = 0;
	while (cmd[j])
	{
		free(cmd[j]);
		j++;
	}
	free(cmd);
	liberator_data(data);
	exit(EXIT_SUCCESS);
}
