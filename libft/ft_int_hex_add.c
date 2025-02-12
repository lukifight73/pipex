/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_hex_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:42:48 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/14 15:57:37 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_hex_add(unsigned long long n)
{
	int	i;

	i = 0;
	if (n < 16)
		i++;
	if (n >= 16)
	{
		i++;
		i += ft_size_hex_add(n / 16);
	}
	return (i);
}

static void	fill_hex_add(unsigned long long n, int i, char *num, char *hex)
{
	while (n > 15)
	{
		num[i] = hex[n % 16];
		n = n / 16;
		i--;
	}
	num[i] = hex[n % 16];
}

char	*ft_int_hex_add(unsigned long long n)
{
	char	*num;
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	num = (char *)malloc((ft_size_hex_add(n) + 1) * sizeof(char));
	if (!num)
		return (NULL);
	i = ft_size_hex_add(n);
	num[i] = '\0';
	i--;
	fill_hex_add(n, i, num, hex);
	return (num);
}
