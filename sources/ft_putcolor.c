/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 21:31:51 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/14 22:56:15 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_putcolor(char rwx, char *s)
{
	if (rwx == 'd')
		ft_printf("{cyan}%s{cyan}\n", s);
	else if (rwx == 'l')
		ft_printf("{magenta}%s{magenta}\n", s);
	else if (rwx == 'b')
		ft_printf("{yellow}%s{yellow}\n", s);
	else if (rwx == 'c')
		ft_printf("{green}%s{green}\n", s);
	else
		ft_printf("%s\n", s);
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
		pth = ft_strjoin_path(path, tab[i]);
		lstat(pth, &buf);
		fill_struct_l(buf, pth, &l, param);
		ft_putcolor(l.rwx[0], tab[i]);
		free_struct_l(&l);
		free(pth);
		i++;
	}
}
