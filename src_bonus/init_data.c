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

char	**get_cmds(char **av, int ac, t_data *data)
{
	int		i;
	int		j;
	char	**cmds;

	cmds = (char **)malloc(sizeof(char *) * (ac - 2) + 1);
	if (!cmds)
	{
		perror("Malloc\n");
		free(data);
		return (NULL);
	}
	j = 0;
	i = 2;
	while (i + j < ac - 1)
	{
		cmds[j] = av[i + j];
		j++;
	}
	cmds[j] = NULL;
	data->cmds = cmds;
	return (cmds);
}

int	get_correct_paths(char **paths)
{
	int	j;
	int	verif;

	j = 0;
	verif = 0;
	while (paths[j])
	{
		paths[j] = ft_strjoin2(paths[j], "/");
		if (!paths[j])
			verif = -1;
		j++;
	}
	if (verif == -1)
	{
		verif = 0;
		while (verif != j)
		{
			if (paths[verif])
				free(paths[verif]);
			verif++;
		}
		free(paths);
		return (-1);
	}
	return (1);
}

char	**get_paths(char **env, t_data *data)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
	{
		data->path = 0;
		return (NULL);
	}
	data->path = 1;
	while (*env[i] != '=')
		env[i]++;
	env[i]++;
	paths = ft_split(env[i], ':');
	if (!paths || get_correct_paths(paths) == -1)
	{
		perror("Error Malloc\n");
		return (NULL);
	}
	return (paths);
}

void	init_int_data(char **av, int ac, t_data *data)
{
	data->file1 = av[1];
	data->file2 = av[ac - 1];
	data->nb_cmds = ac - 3;
	data->nb_exec = 0;
	data->here_doc = 0;
}

t_data	*init_data(char **av, char **env, int ac)
{
	t_data	*data;

	if (check_files(av[ac - 1]) == -1)
	{
		perror("Error Permissions Files\n");
		return (NULL);
	}
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		perror("Error Malloc\n");
		return (NULL);
	}
	if (!get_cmds(av, ac, data))
		return (NULL);
	data->paths = get_paths(env, data);
	if (!data->paths && data->path == 1)
		return (free(data->cmds), free(data), NULL);
	init_int_data(av, ac, data);
	get_data_pids(data);
	if (!data->pids)
		return (NULL);
	return (data);
}
