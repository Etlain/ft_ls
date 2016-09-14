/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:37:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/14 11:10:58 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	free_struct_l(t_l *l)
{
	if (l->rwx[0] == 'l')
		ft_memdel((void **)&(l->file));
	if (l->rwx[0] == 'c' || l->rwx[0] == 'b')
	{
		ft_memdel((void **)&(l->major));
		ft_memdel((void **)&(l->minor));
	}
	else
		ft_memdel((void **)&(l->size));
	ft_memdel((void **)&(l->rwx));
	ft_memdel((void **)&(l->link));
	ft_memdel((void **)&(l->pw_name));
	ft_memdel((void **)&(l->gr_name));
	ft_free_tab(l->time);
}

void fill_struct_max(char *file, t_max *max)
{
	struct stat buf;
	t_l l;
	int nbr;

	lstat(file, &buf);
	max->blocks = max->blocks + buf.st_blocks;
	fill_struct_l(buf, file, &l);
	(nbr = ft_strlen(l.file)) > max->file ? max->file = nbr : 0;
	(nbr = ft_strlen(l.link)) > max->link ? max->link = nbr : 0;
	(nbr = ft_strlen(l.pw_name)) > max->pw_name ? max->pw_name = nbr : 0;
	(nbr = ft_strlen(l.gr_name)) > max->gr_name ? max->gr_name = nbr : 0;
	if (l.rwx[0] == 'b' || l.rwx[0] == 'c')
	{
		(nbr = ft_strlen(l.minor)) > max->minor ? max->minor = nbr : 0;
		(nbr = ft_strlen(l.major)) > max->major ? max->major = nbr : 0;
	}
	else
		(nbr = ft_strlen(l.size)) > max->size ? max->size = nbr : 0;
	(nbr = ft_strlen(l.time[1])) > max->time1 ? max->time1 = nbr : 0;
	if (ft_strchr(l.time[2], ':') != NULL)
		(nbr = ft_strlen(l.time[2]) - 3) > max->time2 ? max->time2 = nbr : 0; // renommer max en m
	else
		(nbr = ft_strlen(l.time[2])) > max->time2 ? max->time2 = nbr : 0;
	free(file);
}

void	init_max(t_max *max)
{
	max->blocks = 0;
	max->file = 0;
	max->link = 0;
	max->pw_name = 0;
	max->gr_name = 0;
	max->minor = 0;
	max->major = 0;
	max->size = 0;
	max->time1 = 0;
	max->time2 = 0;
	max->space = NULL;
}
