/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:43:26 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/03 02:51:50 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *list;
	t_list *t;

	res = NULL;
	if (lst)
	{
		list = lst;
		res = f(list);
		t = res;
		list = list->next;
		while (list != NULL)
		{
			t->next = f(list);
			list = list->next;
			t = t->next;
		}
		t->next = NULL;
	}
	return (res);
}
