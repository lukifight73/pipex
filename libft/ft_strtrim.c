/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:26:24 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/05 16:26:25 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trim(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	size(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	t;
	size_t	d;

	i = 0;
	t = 0;
	d = 0;
	while (s1[t])
		t++;
	while (s1[d] && is_trim(s1[d], set))
		d++;
	while (s1[d + i])
	{
		if (is_trim(s1[d + i], set))
		{
			j = d + i;
			while (s1[j] && is_trim(s1[j], set))
				j++;
			if (t == j)
				return (i);
		}
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	i;
	size_t	z;
	size_t	b;

	i = 0;
	b = 0;
	z = size(s1, set);
	new = (char *)malloc((z + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s1[i] && is_trim(s1[i], set))
		i++;
	while (b < z)
	{
		new[b] = s1[b + i];
		b++;
	}
	new[b] = '\0';
	return (new);
}
/*
int	main(int ac, char **av)
{
	ac = ac + 0;
	printf("%s\n", ft_strtrim(av[1], av[2]));
	return (0);
}*/	
