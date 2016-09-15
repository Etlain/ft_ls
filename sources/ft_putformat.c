/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 12:38:00 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/15 17:19:53 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_space(int space)
{
	int i;

	i = 0;
	//ft_printf("%d\n", space);
	while (i < space)
	{
		ft_putchar(' ');
		i++;
	}
}

void ft_putformat(char *path, char *param) // ajouter -G
{
	char **tab;
	t_max max;
	struct winsize ws;
	int i;
	int nbr_file;

	ioctl(0, TIOCGWINSZ, &ws);
	init_max(&max);
	tab = ft_tab(path, &max, param);
	i = 0;
	//ft_printf("%d\n", ws.ws_col / max.file);
	nbr_file =  ws.ws_col / max.file;
	while (tab[i] != '\0')
	{
		if (param != NULL && ft_strchr(param, 'G') != NULL)
			ft_color_dir(path, tab[i], param);
		else
			ft_putstr(tab[i]);
		if ((i + 1) % nbr_file == 0)
			ft_putchar('\n');
		else
			ft_space((max.file + 1) - ft_strlen(tab[i]));
		i++;
		//ft_printf("test %d\n", i % nbr_file);
	}
}
