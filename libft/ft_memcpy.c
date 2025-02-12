/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:50:18 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/05 09:50:21 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
int	main(int argc, char **argv)
{
	char	*s;
	char	*s1;
	
	s = (char *)malloc(10 * sizeof(char));
	s1 = (char *)malloc(10 * sizeof(char));
	argc = argc + 0;
	printf("vrai : %s\nmien : %s\n", (char *)memcpy(s, argv[1], 15), 
	(char *)ft_memcpy(s1, argv[1], 15));
	return (0);
}*/
