/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:35:07 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/05 13:22:46 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[k])
		k++;
	while (src[j])
		j++;
	if (k >= size)
		return (size + j);
	while (src[i] && (i + k < size - 1))
	{
		dest[i + k] = src[i];
		i++;
	}
	dest[i + k] = '\0';
	return (k + j);
}
