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

int	check_files_here(char *file2)
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
	return (1);
}
