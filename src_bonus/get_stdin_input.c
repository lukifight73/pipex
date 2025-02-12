/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stdin_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:06:38 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/19 17:09:35 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	join5(char *s1, char *s2, char *conc)
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

char	*ft_strjoin5(char *s1, char *s2)
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
		return (NULL);
	conc[t + i] = '\0';
	join5(s1, s2, conc);
	return (conc);
}

int	verif_limiter(char *instructions, char **av)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	ft_printf("instructions : %s\n", instructions);
	ft_printf("av[2] : %s\n", av[2]);
	while (instructions[i])
	{
		if (instructions[i] == '\n' || i == 0)
		{
			j = i;
			t = 0;
			while (instructions[j] && instructions[j] != '\n')
			{
				if (instructions[j] == av[2][t])
					t++;
				if (ft_strlen(av[2]) == t)
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

char	*get_standard_input(char **av)
{
	char	*instructions;
	char	*current;

	instructions = (char *)malloc(1 * sizeof(char));
	if (!instructions)
		return (NULL);
	instructions[0] = '\0';
	current = get_next_line(0);
	if (!current)
		return (NULL);
	while (ft_strncmp(av[2], current, ft_strlen(current) - 1) != 0
		|| strlen(av[2]) != strlen(current) - 1)
	{
		instructions = ft_strjoin5(instructions, current);
		if (!instructions)
			return (NULL);
		free(current);
		current = get_next_line(1);
	}
	free(current);
	return (instructions);
}

int	get_standard_input_console(char **av)
{
	char	*instructions;
	int		fd;

	instructions = get_standard_input(av);
	if (!instructions)
		return (-1);
	fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd == -1)
		return (-1);
	if (dup2(fd, 1) == -1)
	{
		close(fd);
		return (-1);
	}
	close (fd);
	ft_printf("%s", instructions);
	free(instructions);
	return (1);
}
