/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:02:16 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/05 16:11:33 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	i = 0;
	while (s[i])
		i++;
	new = (char *)malloc((i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new[i] = '\0';
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}
/*
int	main(int argc, char **argv)
{
	char	*s;
	char	*u;

	argc = argc + 0;
	s = ft_strdup(argv[1]);
	u = strdup(argv[1]);
	printf("v%s\nm%s\n", u, s);
	free(u);
	free(s);
	return (0);
}*/
