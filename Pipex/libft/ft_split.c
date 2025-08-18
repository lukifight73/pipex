/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:04:34 by lbenatar          #+#    #+#             */
/*   Updated: 2024/10/08 14:26:19 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	if (!s[0])
		return (0);
	i = 1;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static char	*create_tab(const char *s, char c, int i)
{
	char	*chaine;
	int		j;
	int		k;

	j = i;
	k = 0;
	while (s[j] && s[j] != c)
		j++;
	chaine = (char *)malloc((j - i + 1) * sizeof(char));
	if (!chaine)
		return (NULL);
	chaine[j - i] = '\0';
	while (i + k < j)
	{
		chaine[k] = s[i + k];
		k++;
	}
	return (&chaine[0]);
}

static void	liberator(char **s, int k)
{
	int	i;

	i = 0;
	while (i <= k)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static int	fill_tab(char **tab, char *chaine, int k)
{
	tab[k] = chaine;
	if (!tab[k])
	{
		liberator(tab, k);
		return (-1);
	}
	k++;
	return (k);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		k;

	tab = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[count_words(s, c)] = 0;
	i = 0;
	k = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			k = fill_tab(tab, create_tab(s, c, i), k);
		else if (s[i - 1] == c && s[i] != c)
			k = fill_tab(tab, create_tab(s, c, i), k);
		if (k == -1)
			return (NULL);
		i++;
	}
	return (tab);
}

/*
int	main(int argc, char **argv)
{
	int	i;
	char	**tab;

	i = 0;
	argc = argc + 1;
	tab = ft_split(argv[1], argv[2][0]);
	while (i < count_words(argv[1], argv[2][0]))
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}*/
