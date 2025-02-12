/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:25:59 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/11 18:23:48 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new;
	size_t		i;
	size_t		j;

	i = 0;
	j = ft_strlen(s);
	if (len > 2147483647 && ((size_t)start <= j))
		len = j - (size_t)start;
	else if ((size_t)start > j)
		len = 0;
	else if (j - (size_t)start <= len)
		len = j - (size_t)start;
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < len && ((size_t)start + i < j))
	{
		new[i] = s[(size_t)start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
int	main(int ac, char **av)
{
	char	*s;
	long int	d;

	d = atoi(av[2]);
	ac = ac + 0;
	s = ft_substr(av[1], 0, d);
	printf("%s\n", s);
	free(s);
	return (0);
}*/
