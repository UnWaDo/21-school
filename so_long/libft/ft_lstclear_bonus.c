/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex <lalex@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:45:35 by lalex             #+#    #+#             */
/*   Updated: 2021/10/13 20:50:59 by lalex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*el;
	t_list	*next;

	el = *lst;
	while (el)
	{
		next = el->next;
		ft_lstdelone(el, del);
		el = next;
	}
	*lst = NULL;
}
