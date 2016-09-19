/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:37:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/19 13:41:09 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	is_param(char c)
{
	if (c == 'a' || c == 'r' || c == 'R' || c == 't' || c == 'l')
		return (1);
	if (c == '1' || c == 'G' || c == '2' || c == 'T' || c == 'u')
		return (1);
	return (0);
}

static void	ft_display(int argc, char **argv, char *param, int i)
{
	int b;

	if (argc - i == 0)
		ft_putls(".", param, 0);
	else if (argc - i > 0)
	{
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
}

int			main(int argc, char **argv)
{
	char	*param;
	int		i;
	int		b;

	param = ft_param(argv, argc, is_param);
	i = 1;
	while (argc - i > 0 && argv[i][0] == '-')
		i++;
	if (param != NULL && param[0] == '-')
	{
		i = 1;
		while (is_param(param[i]) != 1 && param[i] != '\0')
			i++;
		if (i - 1 >= 0)
			ft_putchar_fd(param[i - 1], 2);
		ft_putendl_fd(" : error param", 2);
		ft_memdel((void **)&param);
		exit(0);
	}
	ft_display(argc, argv, param, i);
	return (0);
}
