/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:28:12 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/12 14:10:33 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmds_here(char **av, int ac, t_data *data)
{
	int		i;
	int		j;
	char	**cmds;

	cmds = (char **)malloc(sizeof(char *) * (ac - 3) + 1);
	if (!cmds)
	{
		perror("Malloc\n");
		free(data);
		return (NULL);
	}
	j = 0;
	i = 3;
	while (i + j < ac - 1)
	{
		cmds[j] = av[i + j];
		j++;
	}
	cmds[j] = NULL;
	data->cmds = cmds;
	return (cmds);
}

int	init_int_data_here(char **av, int ac, t_data *data)
{
	data->file1 = (char *)malloc(sizeof(char) * 9);
	if (!data->file1)
	{
		free(data->paths);
		free(data->cmds);
		free(data);
		return (-1);
	}
	data->file2 = av[ac - 1];
	data->nb_cmds = ac - 4;
	data->here_doc = 1;
	data->nb_exec = 0;
	data->file1[0] = 'h';
	data->file1[1] = 'e';
	data->file1[2] = 'r';
	data->file1[3] = 'e';
	data->file1[4] = '_';
	data->file1[5] = 'd';
	data->file1[6] = 'o';
	data->file1[7] = 'c';
	data->file1[8] = '\0';
	return (1);
}

void	get_data_pids_here(t_data *data)
{
	data->pids = (pid_t *)malloc(sizeof(pid_t) * data->nb_cmds);
	if (!data->pids)
	{
		free(data->paths);
		free(data->cmds);
		free(data->file1);
		free(data);
	}
}

t_data	*init_data_here(char **av, char **env, int ac)
{
	t_data	*data;

	if (check_files_here(av[ac - 1]) == -1)
	{
		perror("Error Permissions Files\n");
		return (NULL);
	}
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	if (!get_cmds_here(av, ac, data))
		return (NULL);
	data->paths = get_paths(env, data);
	if (!data->paths)
	{
		free(data->cmds);
		free(data);
		return (NULL);
	}
	if (init_int_data_here(av, ac, data) == -1)
		return (NULL);
	get_data_pids_here(data);
	if (!data->pids)
		return (NULL);
	return (data);
}
