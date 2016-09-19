/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 12:38:00 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/19 12:37:45 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_space(int space)
{
	int i;

	i = 0;
	while (i < space)
	{
		ft_putchar(' ');
		i++;
	}
}

void		ft_putformat(char *path, char *param)
{
	struct winsize	ws;
	t_max			max;
	char			**tab;
	int				i;
	int				nbr_file;

	ioctl(0, TIOCGWINSZ, &ws);
	init_max(&max);
	tab = ft_tab(path, &max, param);
	i = 0;
	nbr_file = ws.ws_col / max.file;
	while (tab[i] != '\0')
	{
		if (param != NULL && ft_strchr(param, 'G') != NULL)
			ft_color_dir(path, tab[i], param);
		else
			ft_putstr(tab[i]);
		if ((i + 1) % nbr_file == 0 || tab[i + 1] == '\0')
			ft_putchar('\n');
		else
			ft_space((max.file + 1) - ft_strlen(tab[i]));
		i++;
	}
}
