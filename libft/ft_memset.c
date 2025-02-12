/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:49:13 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/05 10:16:35 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (char)c;
		i++;
	}
	return (s);
}
/*
int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	argc = argc + 0;
	ft_memset(argv[2], 'a', 10);
	memset(argv[1], 'a', 10);
	while (i < 10)
	{
		printf("vrai : %s\nMien : %s\n", argv[1], argv[2]);
		i++;
	}
	return (0);;
}*/
