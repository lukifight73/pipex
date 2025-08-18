/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:52:27 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/05 09:52:30 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	h;

	h = 0;
	while (little[h])
		h++;
	j = 0;
	i = 0;
	if (h == 0)
		return ((char *)big);
	while (big[j] && j < n)
	{
		while (big[j + i] == little[i] && little[i] && (j + i) < n)
			i++;
		if (i == h)
			return ((char *)&big[j]);
		i = 0;
		j++;
	}
	return (NULL);
}
