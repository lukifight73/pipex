/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:12:55 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/14 15:58:09 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	verif_type(const char *entry, size_t i)
{
	if (entry[i + 1] == 'c')
		return ('c');
	else if (entry[i + 1] == 's')
		return ('s');
	else if (entry[i + 1] == 'p')
		return ('p');
	else if (entry[i + 1] == 'd')
		return ('d');
	else if (entry[i + 1] == 'i')
		return ('i');
	else if (entry[i + 1] == 'u')
		return ('u');
	else if (entry[i + 1] == 'x')
		return ('x');
	else if (entry[i + 1] == 'X')
		return ('X');
	else if (entry[i + 1] == 'p')
		return ('p');
	else if (entry[i + 1] == '%')
		return ('%');
	return ('1');
}

size_t	write_entry(const char *entry, va_list apc)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (entry[i])
	{
		if (entry[i] != '%' || (entry[i] == '%'
				&& (verif_type(entry, i) == '1')))
			k = ft_putchar_k(entry[i], k);
		else if (entry[i] == '%' && verif_type(entry, i) == '%')
		{
			k = ft_putchar_k(entry[i], k);
			i++;
		}
		else
		{
			k = ft_write_special(verif_type(entry, i), apc, k);
			i++;
		}
		i++;
	}
	return (k);
}

size_t	ft_printf(const char *entry, ...)
{
	va_list	ap;
	va_list	apc;
	size_t	k;

	if (!entry[0])
		return (0);
	va_start(ap, entry);
	va_copy(apc, ap);
	va_end(ap);
	k = write_entry(entry, apc);
	return (k);
}
