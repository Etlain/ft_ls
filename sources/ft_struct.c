/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:37:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/19 13:39:39 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		free_struct_l(t_l *l)
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

static void	ft_putmax(int l, int *m)
{
	int nbr;

	if ((nbr = l) > *m)
		*m = nbr;
}

static void	fill_struct_m(t_l l, t_max *m)
{
	ft_putmax(ft_strlen(l.link), &(m->link));
	ft_putmax(ft_strlen(l.pw_name), &(m->pw_name));
	ft_putmax(ft_strlen(l.gr_name), &(m->gr_name));
	if (l.rwx[0] == 'b' || l.rwx[0] == 'c')
	{
		ft_putmax(ft_strlen(l.minor), &(m->minor));
		ft_putmax(ft_strlen(l.major), &(m->major));
	}
	else
		ft_putmax(ft_strlen(l.size), &(m->size));
}

void		fill_struct_max(char *file, t_max *m, char *param)
{
	struct stat buf;
	t_l			l;

	lstat(file, &buf);
	m->blocks = m->blocks + buf.st_blocks;
	fill_struct_l(buf, file, &l, param);
	ft_putmax(ft_strlen(l.file), &(m->file));
	free(file);
	fill_struct_m(l, m);
	if (param != NULL && ft_strchr(param, 'T') != NULL)
	{
		ft_putmax(ft_strlen(l.time[0]), &(m->time1));
		return ;
	}
	ft_putmax(ft_strlen(l.time[1]), &(m->time1));
	if (ft_strchr(l.time[2], ':') != NULL)
		ft_putmax(ft_strlen(l.time[2]) - 3, &(m->time2));
	else
		ft_putmax(ft_strlen(l.time[2]), &(m->time2));
	free_struct_l(&l);
}

void		init_max(t_max *max)
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
