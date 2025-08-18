/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:28:12 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/20 12:00:52 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	if (ac != 5)
		return (1);
	data = init_data(av, env, ac);
	if (!data)
		return (1);
	exec_programme(data);
	liberator_data(data);
	return (0);
}
