/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:36:03 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/14 15:58:21 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	write_c(va_list apc, size_t k)
{
	char	c;

	c = va_arg(apc, int);
	k = ft_putchar_k(c, k);
	return (k);
}

size_t	write_s(va_list apc, size_t k)
{
	char	*str;

	str = va_arg(apc, char *);
	if (str == NULL)
	{
		k = ft_putstr_k("(null)", k);
		return (k);
	}
	k = ft_putstr_k(str, k);
	return (k);
}

size_t	write_d(va_list apc, size_t k)
{
	char	*num;

	num = ft_itoa(va_arg(apc, int));
	k = ft_putstr_k(num, k);
	free(num);
	return (k);
}

size_t	write_u(va_list apc, size_t k)
{
	char	*num;

	num = ft_itoa_u(va_arg(apc, unsigned int));
	k = ft_putstr_k(num, k);
	free(num);
	return (k);
}

size_t	write_x(va_list apc, size_t k)
{
	char	*num;

	num = ft_int_hex(va_arg(apc, unsigned int));
	k = ft_putstr_k(num, k);
	free(num);
	return (k);
}
