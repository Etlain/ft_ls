/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:37:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/16 22:09:41 by mmouhssi         ###   ########.fr       */
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

static void fill_struct_m(t_l l, t_max *m, int *nbr)
{
	(*nbr = ft_strlen(l.link)) > m->link ? m->link = *nbr : 0;
	(*nbr = ft_strlen(l.pw_name)) > m->pw_name ? m->pw_name = *nbr : 0;
	(*nbr = ft_strlen(l.gr_name)) > m->gr_name ? m->gr_name = *nbr : 0;
	if (l.rwx[0] == 'b' || l.rwx[0] == 'c')
	{
		(*nbr = ft_strlen(l.minor)) > m->minor ? m->minor = *nbr : 0;
		(*nbr = ft_strlen(l.major)) > m->major ? m->major = *nbr : 0;
	}
	else
		(*nbr = ft_strlen(l.size)) > m->size ? m->size = *nbr : 0;
}

void fill_struct_max(char *file, t_max *m, char *param)
{
	struct stat buf;
	t_l l;
	int nbr;

	lstat(file, &buf);
	m->blocks = m->blocks + buf.st_blocks;
	fill_struct_l(buf, file, &l, param);
	(nbr = ft_strlen(l.file)) > m->file ? m->file = nbr : 0;
	free(file);
	fill_struct_m(l, m, &nbr);
	if (param != NULL && ft_strchr(param, 'T') != NULL)
	{
		(nbr = ft_strlen(l.time[0])) > m->time1 ? m->time1 = nbr : 0;
		return ;
	}
	(nbr = ft_strlen(l.time[1])) > m->time1 ? m->time1 = nbr : 0;
	if (ft_strchr(l.time[2], ':') != NULL)
		(nbr = ft_strlen(l.time[2]) - 3) > m->time2 ? m->time2 = nbr : 0;
	else
		(nbr = ft_strlen(l.time[2])) > m->time2 ? m->time2 = nbr : 0;
	free_struct_l(&l);
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
