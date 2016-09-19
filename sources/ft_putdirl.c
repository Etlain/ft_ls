/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdirl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 20:17:56 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/19 12:37:51 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	ft_space(int a, char *str)
{
	int b;

	b = ft_strlen(str);
	return (b + (a - b));
}

static void	put(t_l l, t_max m, char *param)
{
	ft_printf("%s ", l.rwx);
	ft_printf("%*s ", ft_space(m.link, l.link), l.link);
	ft_printf("%*s ", ft_space(m.pw_name, l.pw_name), l.pw_name);
	ft_printf("%*s ", ft_space(m.gr_name, l.gr_name), l.gr_name);
	if (l.rwx[0] == 'b' || l.rwx[0] == 'c')
	{
		ft_printf("%*s, ", ft_space(m.minor, l.minor), l.minor);
		ft_printf("%*s ", ft_space(m.major, l.major), l.major);
	}
	else
		ft_printf("%*s ", ft_space(m.size, l.size), l.size);
}

static void	put_permission(struct stat buf, char *path, t_max m, char *param)
{
	t_l l;
	int n;

	fill_struct_l(buf, path, &l, param);
	put(l, m, param);
	if (param != NULL && ft_strchr(param, 'T') != NULL)
		ft_printf("%*s ", ft_space(m.time1, l.time[0]), l.time[0]);
	else
	{
		n = 0;
		while (l.time[2][n] != '\n' && l.time[2][n] != '\0')
			n++;
		l.time[2][n] == '\0' ? n = 5 : 0;
		ft_printf("%s ", l.time[0]);
		ft_printf("%*s ", ft_space(m.time1, l.time[1]), l.time[1]);
		ft_printf("%*.*s ", ft_space(m.time2, l.time[2]), n, l.time[2]);
	}
	if (ft_strchr(param, 'G') == NULL)
		ft_printf("%s\n", l.file);
	else
	{
		ft_putcolor(l.rwx[0], l.file);
		ft_putchar('\n');
	}
	free_struct_l(&l);
}

static int	display(char **tab, char *path, char *param, int *i)
{
	*i = 0;
	while (param[*i] != 'l')
		(*i)++;
	while (param[*i] != '1' && param[*i] != '\0')
		(*i)++;
	if (param[*i] == '1')
	{
		if (ft_strchr(param, '2') != NULL)
			ft_putformat(path, param);
		else if (ft_strchr(param, 'G') != NULL)
			ft_color_g(tab, path, param);
		else
			ft_putdir(tab);
		ft_free_tab(tab);
		return (-1);
	}
	return (0);
}

void		ft_putdirl(char *path, char *param)
{
	struct stat st;
	t_max		max;
	char		**tab;
	char		*pth2;
	int			i;

	init_max(&max);
	if ((tab = ft_tab(path, &max, param)) == NULL)
		return ;
	if (display(tab, path, param, &i) < 0)
		return ;
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
