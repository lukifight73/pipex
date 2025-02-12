/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:52:14 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/05 09:52:15 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (i < n && (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]))
		i++;
	if (i == n)
		return (0);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

/*
int	main(int argc, char **argv)
{
	argc = argc + 0;
	printf("vrai : %d\nmien : %d\n", memcmp(argv[1], argv[2], 2), 
	ft_memcmp(argv[1], argv[2], 2));
	return (0);
}*/
