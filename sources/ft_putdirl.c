/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdirl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 20:17:56 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/15 00:41:23 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_space(int a, char *str)
{
	int b;

	b = ft_strlen(str);
	return (b + (a - b));
}

void    put_permission(struct stat buf, char *path, t_max max, char *param)
{
	t_l l;
	int n;
	int second;

	fill_struct_l(buf, path, &l, param);
	ft_printf("%s ", l.rwx);
	ft_printf("%*s ", ft_space(max.link, l.link), l.link);
	ft_printf("%*s ", ft_space(max.pw_name, l.pw_name), l.pw_name);
	ft_printf("%*s ", ft_space(max.gr_name, l.gr_name), l.gr_name);
	if (l.rwx[0] == 'b' || l.rwx[0] == 'c')
	{
		ft_printf("%*s, ", ft_space(max.minor, l.minor), l.minor);
		ft_printf("%*s ", ft_space(max.major, l.major), l.major);
	}
	else
		ft_printf("%*s ", ft_space(max.size, l.size), l.size);
	
	if (param != NULL && ft_strchr(param, 'T') != NULL)
		ft_printf("%*s ", ft_space(max.time1, l.time[0]), l.time[0]);
	else
	{
		n = 0;
		while (l.time[2][n] != '\n' && l.time[2][n] != '\0')
			n++;
		if (l.time[2][n] == '\0')
			n = 5;
		ft_printf("%s ", l.time[0]);
		ft_printf("%*s ", ft_space(max.time1, l.time[1]), l.time[1]);
		ft_printf("%*.*s ", ft_space(max.time2, l.time[2]), n, l.time[2]); // prob espace seconde et : a enlever
	}
	if (ft_strchr(param, 'G') == NULL)
		ft_printf("%s\n", l.file);
	else
	{
		ft_putcolor(l.rwx[0], l.file);
	}
	free_struct_l(&l);
}
/*
void	ft_put_max(t_max max)// a effacer
{
	ft_printf("%d %d %d ", max.link, max.pw_name, max.gr_name);
	ft_printf("%d %d %d\n", max.size, max.time1, max.time2);
}*/

void    ft_putdirl(char *path, char *param)
{
	t_max max;
	char *pth2;
	char **tab;
	int i;
	struct stat st;

	init_max(&max);
	if ((tab = ft_tab(path, &max, param)) == NULL)
		return ;
	i = 0;
	while (param[i] != 'l')
		i++;
	while (param[i] != '1' && param[i] != '\0')
		i++;
	if (param[i] == '1')
	{
		if (ft_strchr(param, 'G') != NULL)
			ft_color_g(tab, path, param);
		else
			ft_putdir(tab);
		ft_free_tab(tab);
		return ;
	}
	//path = ft_strjoin(path, "/");
	ft_printf("total %ld\n", max.blocks);
	i = 0;
	while (tab[i] != 0)
	{
		pth2 = ft_strjoin_path(path, tab[i]);
		lstat(pth2, &st);
		put_permission(st, pth2, max, param);
		i++;
		ft_memdel((void **)&pth2);
	}
	ft_free_tab(tab);
}
