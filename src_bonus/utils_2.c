/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:59:29 by lbenatar          #+#    #+#             */
/*   Updated: 2025/01/06 14:59:31 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//dup2(fd, 0); on choppe les infos dans file1;

void	open_infile(t_data *data, int *pipefd)
{
	int	fd;

	fd = open(data->file1, O_RDONLY);
	if (fd == -1)
	{
		perror(strerror(errno));
		close(pipefd[1]);
		liberator_data(data);
		exit(EXIT_FAILURE);
	}
	else
	{
		dup2(fd, 0);
		close (fd);
	}
}

void	exit_failed_daughter(t_data *data, char **cmd)
{
	ft_printf("command not found: %s\n", data->cmds[data->nb_exec]);
	execve_cmd_freedom(data, cmd, -1);
	exit(EXIT_FAILURE);
}
