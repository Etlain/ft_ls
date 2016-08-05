/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:37:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/08/05 11:21:38 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

//void	ft_putdirr(char *path); // a effacer
/*
int	is_param(char c)
{
	if (c == 'a' || c == 'r' || c == 'R' || c == 't' || c == 'l')
		return (1);
	return (0);
}*/

void	ft_putbuf(void *buf, char *str, int *i)
{
	char *b;
	int j;

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

void	ft_putdir(char **tab)
{
	//char *buf;
	int i;
	int index;
	//int error;

	index = 0;
	i = 0;
	//buf = (char *)malloc(BUF_MAX);
	//ft_bzero(buf, BUF_MAX);
	while (tab[index] != NULL)
	{
		ft_putendl(tab[index]);
		//ft_putbuf(buf, tab[index], &i);
		//ft_putbuf(buf, "\n", &i);
		index++;
	}
	/*if (ft_strcmp(buf, "") != 0)
	{
		ft_putstr(buf); // ptet a mettre a la fin du programme 
		ft_bzero(buf, BUF_MAX);
	}
	free(buf)*/
	//if (buf[0] != '\0')
	//{
		//ft_putstr(buf); // ptet a mettre a la fin du programme 
		//ft_bzero(buf, BUF_MAX);
	//}
	/*
	else
	{
		//error = errno;
		//strerror(error); // gestion d erreur
		//perror("opendir ");
	}*/
}

void	ft_dirr(char *path, char **dir, int i)
{
	struct stat st;
	char *path2;

	path2 = NULL;
	if (!path || !dir/* || path[0] == '\0'*/)
		return ;
	path2 = ft_strjoin(path, dir[i]);
	//stat(path2, &st);
	if (stat(path2, &st) == -1)
	{
		ft_printf("error stat path : %s, %s\n", path2, path);
		free(path);
		path = NULL;
		free(path2);
		path2 = NULL;
		ft_free_tab(dir);
		exit(0);
	}
	else
	{
		if (S_ISDIR(st.st_mode))
			ft_putdirr(path2);
	}
	free(path2);
	path2 = NULL;
}

void	ft_putdirr(char *path)
{
	t_max max;
	char **dir;
	//char *s;
 	int i;
	static int b;

	dir = NULL;
	if (!path)
		return ;
	dir = fill_tab(path, &max); //"."
	//sort_tab(dir, 0); // nouvelle fonction sort en connaissant le parametre
	path[1] == '/' ? ft_printf("\n\n%s:\n", path) : 0;
	//ft_sort();
	ft_putdir(dir);
	//s = path;
	path = ft_strjoin(path, "/"); // probleme free
	//free(s);
	i = 0;
	while (dir[i] != 0)
	{
		ft_strcmp(dir[i], ".") == 0 ? i++ : 0;
		ft_strcmp(dir[i], "..") == 0 ? i++ : 0;
		if (dir[i] != 0)
			ft_dirr(path, dir, i);
		/*else
			break ;*/
		i++;
	}
	/*ft_putstr(buf); // ptet a mettre a la fin du programme 
	ft_bzero(buf, BUF_MAX);*/
	ft_free_tab(dir);
	//dir = NULL;
	if (b == 1)
	{
		free(path);
		path = NULL;
	}
	if (!b)
		b = 1;
}

void	ft_putdirl(char *path/*, char *param*/)
{
	t_max max;
	char *pth2;
	char **tab;
	int i;
	struct stat st;

	/*if (param != NULL && (ft_strchr(param, 'a') != NULL))
		tab = fill_tab_a(path, &max);
	else
		tab = fill_tab(path, &max);*/
	i = 0;
	tab = fill_tab(path, &max);
	path = ft_strjoin(path, "/");
	while (tab[i] != 0)
	{
		pth2 = ft_strjoin(path, tab[i]);
		stat(pth2, &st);
		ft_permission(st, pth2);
		i++;
		//free
	}
}

void	ft_putls(char *path, char *param, int b)
{
	//char *buf;
	char **tab;
	t_max max;

	/*buf = (char *)malloc(BUF_MAX);
	ft_bzero(buf, BUF_MAX);*/
	if (param != NULL && (ft_strchr(param, 'R') != NULL))
	{
		ft_putdirr(path);
		return ;
	}
	else if (param != NULL && (ft_strchr(param, 'l') != NULL))
	{
		ft_putdirl(path/*, param*/);
		return ;
	}
	if (param != NULL && (ft_strchr(param, 'a') != NULL))
		tab = fill_tab_a(path, &max);
	else
		tab = fill_tab(path, &max);
	ft_sort(path, tab, param);
	if (b == 1)
		ft_printf("\n%s:\n", path);
	else
		ft_putdir(tab);
}
