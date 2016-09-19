/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:37:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/19 13:39:47 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_putbuf(void *buf, char *str, int *i)
{
	char	*b;
	int		j;

	j = 0;
	b = (char *)buf;
	while (str[j] != '\0')
	{
		if (*i > (BUF_MAX - 2))
		{
			ft_putstr(b);
			ft_bzero(b, BUF_MAX);
			*i = 0;
		}
		if (*i < (BUF_MAX - 1))
		{
			b[*i] = str[j];
			j++;
			(*i)++;
		}
	}
}

void		ft_putdir(char **tab)
{
	char	buf[BUF_MAX];
	int		i;
	int		index;

	index = 0;
	i = 0;
	ft_bzero(buf, BUF_MAX);
	while (tab[index] != NULL)
	{
		ft_putbuf(buf, tab[index], &i);
		ft_putbuf(buf, "\n", &i);
		index++;
	}
	if (buf[0] != '\0')
	{
		ft_putstr(buf);
		ft_bzero(buf, BUF_MAX);
	}
}

static void	ft_dirr(char *path, char **dir, int i, char *param)
{
	struct stat st;
	char		*path2;

	path2 = NULL;
	if (!path || !dir)
		return ;
	path2 = ft_strjoin_path(path, dir[i]);
	if (lstat(path2, &st) == -1)
	{
		ft_printf("error stat path : %s, %s\n", path2, path);
		ft_memdel((void **)&param);
		ft_memdel((void **)&path2);
		ft_free_tab(dir);
		exit(0);
	}
	else
	{
		if (S_ISDIR(st.st_mode))
			ft_putdirr(path2, param);
	}
	ft_memdel((void **)&path2);
}

void		ft_putdirr(char *path, char *param)
{
	t_max	max;
	char	**dir;
	int		i;

	if (!path)
		return ;
	if ((dir = ft_tab(path, &max, param)) == NULL)
		return ;
	ft_strchr(path, '/') != NULL ? ft_printf("\n\n%s:\n", path) : 0;
	if (ft_strchr(param, 'l') != NULL)
		ft_putdirl(path, param);
	else if (ft_strchr(param, '2') != NULL)
		ft_putformat(path, param);
	else if (ft_strchr(param, 'G') != NULL)
		ft_color_g(dir, path, param);
	else
		ft_putdir(dir);
	i = 0;
	while (dir[i] != 0)
	{
		if (ft_strcmp(dir[i], ".") != 0 && ft_strcmp(dir[i], "..") != 0)
			ft_dirr(path, dir, i, param);
		i++;
	}
	ft_free_tab(dir);
}

void		ft_putls(char *path, char *param, int b)
{
	char	**tab;
	t_max	max;

	init_max(&max);
	if (param != NULL && (ft_strchr(param, 'R') != NULL))
	{
		ft_putdirr(path, param);
		return ;
	}
	else if (param != NULL && (ft_strchr(param, 'l') != NULL))
	{
		ft_putdirl(path, param);
		return ;
	}
	if ((tab = ft_tab(path, &max, param)) == NULL)
		return ;
	if (b == 1)
		ft_printf("\n%s:\n", path);
	if (param != NULL && ft_strchr(param, '2') != NULL)
		ft_putformat(path, param);
	else if (param != NULL && ft_strchr(param, 'G') != NULL)
		ft_color_g(tab, path, param);
	else
		ft_putdir(tab);
	ft_free_tab(tab);
}
