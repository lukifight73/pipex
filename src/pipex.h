/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:13:20 by lbenatar          #+#    #+#             */
/*   Updated: 2024/12/16 11:13:24 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <strings.h>
# include <ctype.h>
# include <bsd/string.h>

typedef struct s_data
{
	char	**cmds;
	char	**paths;
	char	*file1;
	char	*file2;
	pid_t	*pids;
	int		nb_cmds;
	int		nb_exec;
	int		here_doc;
	int		path;
	int		res;
}		t_data;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		get_rang_cmd(char *path);
int		exec_programme(t_data *data);
int		check_files(char *file2);
int		check_files_here(char *file2);
int		still_backslash(char *cmd, int i);
int		get_ligne(char *buf, int fd);
int		ft_strlen(char *str);
int		ft_strlen4(char *str);
int		nb_str(char **tab);
int		get_standard_input_console(char **av);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	liberator_data(t_data *data);
void	open_infile(t_data *data, int *pipefd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	exec_cmd_fille(t_data *data);
void	get_data_pids(t_data *data);
char	**ft_split(char const *s, char c);
size_t	ft_printf(const char *entry, ...);
t_data	*init_data(char **av, char **env, int ac);
t_data	*init_data_here(char **av, char **env, int ac);
char	*ft_strjoin2(char *s1, char *s2);
char	**get_paths(char **env, t_data *data);
char	*ft_strjoin7(char *line, char *buf);
char	*ft_strchr8(const char *s, int c);
char	*get_current_line(char *next_line);
char	*get_classique_path(char *cmd);
char	*get_new_next_line(char *next_line);
char	*get_next_line(int fd);

#endif
