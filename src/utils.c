/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:28:12 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/12 14:10:33 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_files(char *file2)
{
	int	fd;

	if (access(file2, F_OK) == -1)
	{
		fd = open(file2, O_CREAT, 0644);
		if (fd == -1)
			return (-1);
		close (fd);
	}
	else if (access(file2, W_OK) == -1)
		return (-1);
	else
	{
		fd = open(file2, O_WRONLY | O_TRUNC);
		if (fd == -1)
			return (-1);
		close (fd);
	}
	return (1);
}

int	nb_str(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	liberator_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->paths)
	{
		while (data->paths[i])
		{
			free(data->paths[i]);
			i++;
		}
		free(data->paths);
	}
	if (data->here_doc == 1)
	{
		unlink(data->file1);
		free(data->file1);
	}
	free(data->cmds);
	free(data->pids);
	free(data);
}

void	join2(char *s1, char *s2, char *conc)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (s1[i])
	{
		conc[i] = s1[i];
		i++;
	}
	while (s2[t])
	{
		conc[i + t] = s2[t];
		t++;
	}
	free(s1);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*conc;
	int		t;
	int		i;

	i = 0;
	t = 0;
	while (s1[i])
		i++;
	while (s2[t])
		t++;
	conc = (char *)malloc((t + i + 1) * sizeof(char));
	if (!conc)
	{
		free(s1);
		return (NULL);
	}
	conc[t + i] = '\0';
	join2(s1, s2, conc);
	return (conc);
}
