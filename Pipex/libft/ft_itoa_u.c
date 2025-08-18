/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:40:43 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/14 15:58:02 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_u(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n < 10)
		i++;
	if (n >= 10)
	{
		i++;
		i += ft_size_u(n / 10);
	}
	return (i);
}

static void	fill_itoa_u(unsigned int n, unsigned int i, char *num)
{
	while (n > 9)
	{
		num[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	num[i] = (n % 10) + '0';
}

char	*ft_itoa_u(unsigned int n)
{
	unsigned int	i;
	char			*num;

	num = (char *)malloc((ft_size_u(n) + 1) * sizeof(char));
	if (!num)
		return (NULL);
	i = ft_size_u(n);
	num[i] = '\0';
	i--;
	fill_itoa_u(n, i, num);
	return (num);
}

char	*ft_strtoupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
