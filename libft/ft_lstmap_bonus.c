/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:15:32 by lbenatar          #+#    #+#             */
/*   Updated: 2024/11/07 13:15:34 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current;
	void	*content;

	new = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		current = ft_lstnew(content);
		ft_lstadd_back(&new, current);
		lst = lst->next;
		if (!current)
		{
			del(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
	}
	return (new);
}
