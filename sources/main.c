/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:37:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/08/05 11:40:53 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft/includes/libft.h"

#include "../includes/ft_ls.h"

/*#ifndef MAIN_C
#define MAIN_C

#include "ft_ls.h"

//#include <errno.h>

//#include <sys/ioctl.h>

//#include <fcntl.h>
#include "ft_param.c"
#include "lst_file.c"

#endif*/

int	is_param(char c)
{
	if (c == 'a' || c == 'r' || c == 'R' || c == 't' || c == 'l')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	//char *path;
	char *param;
	int i;
	t_max max;
	//char *buf;
	char **tab;

	// Parametre
	char *test;
	//buf = (char *)malloc(BUF_MAX);
	//ft_bzero(buf, BUF_MAX);
	test = ft_ctoa('.');
	tab = fill_tab(test, &max);
	//sort_tab(tab, 0);
	//sort_time("./", tab, 0);
	ft_putdir(tab);
	ft_free_tab(tab);
	ft_memdel((void **)&test);
	/*ft_putdirr(test);
	//ft_putdirl(test);
	free(test);*/
	/*while (1//)
	{
	}*/
	/*param = ft_param(argv, argc, is_param);
	//ft_printf("param : %s\n", param);
	if (param)
		i = 2;
	else
		i = 1;
	if (param != NULL && param[0] == '-')
	{
		ft_putendl("error param");
		exit(0); // verifie leaks
	}

	if (argc == 1 || (argc == 2 && param != NULL))
		ft_putls("./", param, 0);
	else if (argc > 1)
	{
		int b;
		if (argc - i > 1)
			b = 1;
		else
			b = 0;
		while (i < argc)
		{
			ft_putls(argv[i], param, b);
			i++;
		}
	}
	free(param);
	return (0);*/
}
