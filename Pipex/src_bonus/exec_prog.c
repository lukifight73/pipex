/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:34:18 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/16 14:34:19 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// dup2(pipefd[0], 0); on choppe les infos dans le pipefd[1];

int	exec_cmd_pere(int *pipefd, int last, t_data *data)
{
	int	status;
	int	i;

	i = 0;
	close(pipefd[1]);
	if (last != 1 && dup2(pipefd[0], 0) == -1)
	{
		close(pipefd[0]);
		return (-1);
	}
	close(pipefd[0]);
	if (last == 1)
	{
		while (i < data->nb_cmds)
		{
			if (waitpid(data->pids[i], &status, 0) == -1)
				return (-1);
			i++;
		}
	}
	return (1);
}

//fork / dub / pid
//dup2(pipefd[1], 1); on ecrit dans pipefd[1];
//dup2(fd, 1); on ecrit dans file2;

int	open_output_file(t_data *data, int *pipefd)
{
	int	fd;

	close(pipefd[1]);
	if (data->here_doc == 1)
		fd = open(data->file2, O_WRONLY | O_APPEND);
	else
		fd = open(data->file2, O_WRONLY | O_TRUNC);
	if (fd == -1)
		return (-1);
	if (dup2(fd, 1) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}

int	exec_cmd_bis(t_data *data, pid_t pid, int *pipefd, int last)
{
	int	verif;

	verif = 1;
	if (pid == 0)
	{
		close(pipefd[0]);
		if (data->nb_exec == 0)
			open_infile(data, pipefd);
		data->pids[data->nb_exec] = pid;
		if (last != 1)
		{
			if (dup2(pipefd[1], 1) == -1)
			{
				close(pipefd[1]);
				return (-1);
			}
			close(pipefd[1]);
		}
		else if (open_output_file(data, pipefd) == -1)
			return (-1);
		exec_cmd_fille(data);
	}
	else
		verif = exec_cmd_pere(pipefd, last, data);
	return (verif);
}

int	exec_cmd(t_data *data)
{
	int		pipefd[2];
	int		verif;
	int		last;

	verif = 0;
	last = 0;
	if (pipe(pipefd) == -1)
		return (-1);
	if (data->nb_exec == data->nb_cmds - 1)
		last = 1;
	data->pids[data->nb_exec] = fork();
	if (data->pids[data->nb_exec] < 0)
		return (-1);
	verif = exec_cmd_bis(data, data->pids[data->nb_exec], pipefd, last);
	return (verif);
}

int	exec_programme(t_data *data)
{
	int	verif;

	verif = 1;
	while (data->nb_exec <= data->nb_cmds - 1 && verif != -1)
	{
		verif = exec_cmd(data);
		if (verif == -1)
		{
			perror(strerror(errno));
			return (-1);
		}
		data->nb_exec++;
	}
	return (1);
}
