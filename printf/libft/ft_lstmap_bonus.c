/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:50:43 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:50:52 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*previous;
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	first = ft_lstnew((*f)(lst->content));
	if (first == NULL)
		return (first);
	previous = first;
	lst = lst->next;
	while (lst)
	{
		current = ft_lstnew((*f)(lst->content));
		if (current == NULL)
		{
			ft_lstclear(&first, del);
			return (first);
		}
		previous->next = current;
		previous = current;
		lst = lst->next;
	}
	return (first);
}
