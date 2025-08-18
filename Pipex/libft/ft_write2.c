/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:37:46 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/14 15:58:58 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putchar_k(int c, size_t k)
{
	write(1, &c, 1);
	k++;
	return (k);
}

size_t	ft_putstr_k(char *str, size_t k)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		k++;
	}
	return (k);
}

size_t	write_xx(va_list apc, size_t k)
{
	char	*num;

	num = ft_int_hex(va_arg(apc, int));
	ft_strtoupper(num);
	k = ft_putstr_k(num, k);
	free(num);
	return (k);
}

size_t	write_p(va_list apc, size_t k)
{
	void	*p;
	char	*num;

	p = va_arg(apc, void *);
	if (p == NULL)
	{
		k = ft_putstr_k("(nil)", k);
		return (k);
	}
	write(1, "0x", 2);
	k += 2;
	num = ft_int_hex_add((unsigned long long)p);
	k = ft_putstr_k(num, k);
	free(num);
	return (k);
}

size_t	ft_write_special(char c, va_list apc, size_t k)
{
	if (c == 'c')
		k = write_c(apc, k);
	if (c == 's')
		k = write_s(apc, k);
	if (c == 'u')
		k = write_u(apc, k);
	if (c == 'd' || c == 'i')
		k = write_d(apc, k);
	if (c == 'x')
		k = write_x(apc, k);
	if (c == 'X')
		k = write_xx(apc, k);
	if (c == 'p')
		k = write_p(apc, k);
	return (k);
}
