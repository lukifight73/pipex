/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:52:20 by lbenatar          #+#    #+#             */
/*   Updated: 2024/09/25 16:55:20 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	r;
	unsigned char	*s11;
	unsigned char	*s12;

	i = 0;
	r = 0;
	s11 = (unsigned char *)s1;
	s12 = (unsigned char *)s2;
	while (i < n && (s11[i] != '\0' && s12[i] != '\0'))
	{
		if (s11[i] != s12[i])
		{
			r = s11[i] - s12[i];
			return (r);
		}
		i++;
	}	
	if (s11[i] != '\0' && i < n)
		r = s11[i] - s12[i];
	else if (s12[i] != '\0' && i < n)
		r = s11[i] - s12[i];
	return (r);
}

/*
int	main(void)
{
	char	s11[] = "";
	char	s12[] = "yoyoyoyo";
	int	r;
	int	g;

	r = ft_strncmp(s11, s12, 6);
	printf("%d", r);
	g = strncmp(s11, s12, 6);
	printf("%d", g);
	printf("\n%d", r == g);
	return (0);
}*/
