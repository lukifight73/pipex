/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:26:44 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/06 15:02:24 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i++;
		n = n / 10;
	}
	if (n < 0)
	{
		i++;
		n = -n;
	}	
	if (n < 10)
		i++;
	if (n >= 10)
	{
		i++;
		i += ft_size(n / 10);
	}
	return (i);
}

static void	fill_itoa(int n, int i, char *num)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			num[i] = '8';
			i--;
			n = -214748364;
		}
		num[0] = '-';
		n = -n;
	}
	while (n > 9)
	{
		num[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	num[i] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;

	num = (char *)malloc((ft_size(n) + 1) * sizeof(char));
	if (!num)
		return (NULL);
	i = ft_size(n);
	num[i] = '\0';
	i--;
	fill_itoa(n, i, num);
	return (num);
}
