/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:49:29 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/05 09:49:31 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
/*
int	main(int ac, char **av)
{
	int	i;
	
	i = 0;
	ac = ac + 0;
	ft_bzero(av[1], 5);
	bzero(av[2], 5);
	while (i < 10)
	{
		printf("%c %c\n", av[1][i], av[2][i]);
		i++;
	}
	return (0);
}*/
