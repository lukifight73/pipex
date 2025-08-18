/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:01:28 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/14 16:01:29 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_current_line(char *next_line)
{
	char	*current_line;
	int		i;

	i = 0;
	if (!next_line[0] || !next_line)
		return (NULL);
	while (next_line[i] != '\n' && next_line[i])
		i++;
	current_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!current_line)
		return (NULL);
	i = 0;
	while (next_line[i] != '\n' && next_line[i])
	{
		current_line[i] = next_line[i];
		i++;
	}
	if (next_line[i] && next_line[i] == '\n')
	{
		current_line[i] = '\n';
		i++;
	}
	current_line[i] = '\0';
	return (current_line);
}

char	*get_new_next_line(char *next_line)
{
	char	*new_next_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (next_line[i] != '\n' && next_line[i])
		i++;
	if (!next_line[i])
	{
		free(next_line);
		return (NULL);
	}
	new_next_line = malloc(sizeof(char) * (ft_strlen4(next_line) + 1 - i));
	if (!new_next_line)
		return (NULL);
	while (next_line[i + j + 1])
	{
		new_next_line[j] = next_line[i + j + 1];
		j++;
	}
	new_next_line[j] = '\0';
	free(next_line);
	return (new_next_line);
}

void	mini_liberator(char *next_line, char *buf)
{
	free(next_line);
	free(buf);
}

char	*get_new_line(int fd, char *next_line)
{
	char	*buf;
	int		r;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	r = 1;
	while (ft_strchr8(next_line, '\n') == NULL && r != 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			mini_liberator(next_line, buf);
			return (NULL);
		}
		buf[r] = '\0';
		next_line = ft_strjoin7(next_line, buf);
		if (!next_line)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*next_line;

	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = get_new_line(fd, next_line);
	if (next_line == NULL)
		return (NULL);
	return (next_line);
}

/*
int	main(void)
{
	char	*line;
	int		fd;

	line = "";
	fd = open("text1.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	line = "";
	printf("\n\nsuivant :\n\n");
	close(fd);
	fd = open("text2.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	line = "";
	printf("\n\nsuivant :\n\n");
	close(fd);
	fd = open("text3.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	line = "";
	printf("\n\nsuivant :\n\n");
	close(fd);
	fd = open("text4.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	line = "";
	printf("\n\nsuivant :\n\n");
	close(fd);
	fd = open("text5.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	line = "";
	printf("\n\nsuivant :\n\n");
	close(fd);
	fd = open("text6.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	line = "";
	printf("\n\nsuivant :\n\n");
	close(fd);
	fd = open("text7.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	line = "";
	printf("\n\nsuivant :\n\n");
	close(fd);
	fd = open("text8.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
