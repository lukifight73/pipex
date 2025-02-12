/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:52:02 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/05 09:52:03 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

/*
int	main(int ac, char **av)
{
	ac = ac + 0;
	av[1] = av[2];
	printf("vrai : %s\nmien : %s\n", (char *)memchr(av[1], 'e', 5), 
	(char *)ft_memchr(av[2], 'e', 5));
	printf("av[1] %s \nav[2] %s\n", av[1], av[2]);
	return (0);
}*/
