/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:49:49 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/05 09:49:50 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	size_t			i;

	i = 0;
	d = dest;
	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		while (i < n)
		{
			d[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			d[n - 1 - i] = ((unsigned char *)src)[n - 1 - i];
			i++;
		}
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
	printf("vrai : %s\nmien : %s\n", (char *)memmove(s, argv[1], 15)
	, (char *)ft_memmove(s1, argv[1], 15));
	free(s);
	free(s1);
	return (0);
}*/
