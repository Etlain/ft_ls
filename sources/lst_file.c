/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:18:38 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/14 19:58:04 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lst_add(t_file **lst, struct dirent *file)
{
	t_file *tmp;

	if (*lst == NULL)
	{
		*lst = (t_file *)malloc(sizeof(t_file));
		(*lst)->file = file;
		(*lst)->index = 1;
		(*lst)->next = *lst;
		(*lst)->pre = *lst;
	}
	else
	{
		tmp = (t_file *)malloc(sizeof(t_file));
		tmp->file = file;
		tmp->pre = (*lst)->pre;
		tmp->index = tmp->pre->index + 1;
		if (tmp->index == 2)
			(*lst)->next = tmp;
		else
			tmp->pre->next = tmp;
		(*lst)->pre = tmp;
		tmp->next = *lst;
	}
}

t_file *fill_lst(char *directory)
{
	struct dirent *file;
	t_file  *lst;
	void    *dir;
	int nbr_file;

	lst = NULL;
	nbr_file = 0;
	dir = opendir(directory);
	if (dir != NULL)
	{
		while ((file = readdir(dir)) != NULL)
			lst_add(&lst, file);
		closedir(dir);
	}
	return (lst);
}
