/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:06:42 by lbenatar          #+#    #+#             */
/*   Updated: 2024/10/10 15:55:09 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join(const char *s1, const char *s2, char *conc)
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
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	join(s1, s2, conc);
	return (conc);
}
/*
int	main(int argc, char **argv)
{
	char	*new;

	argc = argc + 0;
	new = ft_strjoin(argv[1], argv[2]);
	printf("%s\n", new);
	return (0);
}*/
