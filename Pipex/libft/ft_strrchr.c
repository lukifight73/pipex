/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:51:30 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/11 18:08:04 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s1;
	int			i;

	s1 = s;
	i = ft_strlen(s);
	s1 = s1 + i;
	while (*s1 != *s || i > 0)
	{
		if (*s1 == (unsigned char)c)
			return ((char *)s1);
		s1--;
		i--;
	}
	if (*s1 == (unsigned char)c)
		return ((char *)s1);
	return (NULL);
}
/*
int	main(void)
{
	printf("la mienne : %p\nla vraie  : %p\n", ft_strchr("teste", 'e')
	, strchr("teste", 'e'));
	printf("la mienne : %p\nla vraie  : %p\n", ft_strchr("teste", '\0')
	, strchr("teste", '\0'));
	printf("la mienne : %p\nla vraie  : %p\n", ft_strrchr("teste", 'e')
	, strrchr("teste", 'e'));
	printf("la mienne : %p\nla vraie  : %p\n", ft_strrchr("teste", '\0')
	, strrchr("teste", '\0'));
	printf("la mienne : %p\nla vraie  : %p\n", ft_strrchr("pepe y cparlos", 'c')
	, strrchr("pepe y cparlos", 'c'));
	printf("la mienne : %p\nla vraie  : %p\n", ft_strrchr("pepe y cparlos", 'd')
	, strrchr("pepe y cparlos", 'd'));
	return (0);
}*/
