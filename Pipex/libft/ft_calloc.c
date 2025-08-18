/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:02:05 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/05 16:25:05 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	n;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		res = (void *)malloc(0);
		if (!res)
			return (NULL);
		return (res);
	}
	n = nmemb * size;
	if (n > 2147483647)
		return (NULL);
	res = (void *)malloc(n);
	if (!res)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)res)[i] = '\0';
		i++;
	}
	return (res);
}
/*
int	main(void)
{
	printf("%s\n%s\n", (char *)calloc(5, 50), (char *)ft_calloc(5, 50));
	return (0);
}*/
