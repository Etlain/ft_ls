/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 21:31:51 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/15 17:15:12 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_putcolor(char rwx, char *s)
{
	if (rwx == 'd')
		ft_printf("{cyan}%s{cyan}", s);
	else if (rwx == 'l')
		ft_printf("{magenta}%s{magenta}", s);
	else if (rwx == 'b')
		ft_printf("{yellow}%s{yellow}", s);
	else if (rwx == 'c')
		ft_printf("{green}%s{green}", s);
	else
		ft_printf("%s", s);
}

void	ft_color_dir(char *path, char *dir, char *param)
{
	struct stat buf;
	char *pth;
	t_l l;

	pth = ft_strjoin_path(path, dir);
	lstat(pth, &buf);
	fill_struct_l(buf, pth, &l, param);
	ft_putcolor(l.rwx[0], dir);
	free_struct_l(&l);
	free(pth);
}

void	ft_color_g(char **tab, char *path, char *param)
{
	struct stat buf;
	char *pth;
	t_l l;
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_color_dir(path, tab[i], param);
		ft_putchar('\n');
		i++;
	}
}
