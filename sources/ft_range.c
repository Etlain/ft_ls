/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:37:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/15 22:03:34 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// penser a ajouter erno
// gestion -a
// tableau trois dimenssion pour le formatage de l'affichage (ligne colonne
// pointeur)

// faire un tableau de char*

static int sort(char *s1, char *s2, int b)
{
	if (b == 1)
		return (ft_strcmp(s2, s1));
	else
		return (ft_strcmp(s1, s2));
}

static void	sort_tab(char **tab, int b) // 1 = reverse // ajouter a la biblio
{
	char *tmp;
	int i;
	int move;

	move = 1;
	while (move == 1)
	{
		i = 0;
		move = 0;
		while (tab[i + 1] != NULL)
		{
			if (sort(tab[i + 1], tab[i], b) < 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				move = 1;
			}
			i++;
		}
	}
}

int	compare_time(struct stat buf1, struct stat buf2, int b)
{
	if (b == 0 || b == 1)
	{
		if (buf2.st_mtimespec.tv_sec > buf1.st_mtimespec.tv_sec) 
				return (-1);
		else if (buf2.st_mtimespec.tv_sec == buf1.st_mtimespec.tv_sec)
		{
			/*if (buf2.st_mtimespec.tv_nsec > buf1.st_mtimespec.tv_nsec)
				return (-1);*/
			if (buf2.st_mtimespec.tv_nsec == buf1.st_mtimespec.tv_nsec)
				return (1);
		}
	}
	else if (b == 2 || b == 3)
	{
		if (buf2.st_atimespec.tv_sec > buf1.st_atimespec.tv_sec) 
				return (-1);
		else if (buf2.st_atimespec.tv_sec == buf1.st_atimespec.tv_sec)
		{
			/*if (buf2.st_mtimespec.tv_nsec > buf1.st_mtimespec.tv_nsec)
				return (-1);*/
			if (buf2.st_atimespec.tv_nsec == buf1.st_atimespec.tv_nsec)
				return (1);
		}
	}
	return (0);
}

static int sort_tu(char *path, char *s1, char *s2, int b)
{
	char *pth1;
	char *pth2;
	struct stat buf1;
	struct stat buf2;
	int nbr;

	nbr = 0;
	pth1 = ft_strjoin_path(path, s1);
	pth2 = ft_strjoin_path(path, s2);
	lstat(pth1, &buf1);
	lstat(pth2, &buf2);
	//ft_printf("%s, %s\n", pth1, ctime(&buf1.st_atimespec.tv_sec));
	ft_memdel((void **)&pth1);
	ft_memdel((void **)&pth2);
	if (b == 0 || b == 2)
	{
		//nbr = compare_mtime(buf2, buf1, b);
		if ((nbr = compare_time(buf2, buf1, b)) == 1)
			return (ft_strcmp(s2, s1));
		else if (nbr == -1)
			return (nbr);
	}
	else if (b == 1 || b == 3)
	{
		//nbr = compare_mtime(buf1, buf2);
		if ((nbr = compare_time(buf1, buf2, b)) == 1)
			return (ft_strcmp(s1, s2));
		else if (nbr == -1)
			return (nbr);
	}
	return (0);
}

static void	sort_time(char *path, char **tab, int b) // 1 = reverse
{
	char *tmp;
	//char *pth;
	int i;
	int move;

	move = 1;
	while (move == 1)
	{
		i = 0;
		move = 0;
		while (tab[i + 1] != NULL)
		{
			if (sort_tu(path, tab[i + 1], tab[i], b) < 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				move = 1;
			}
			i++;
		}
	}
}

void	ft_sort(char *path, char **tab, char *param)
{
	int r;

	r = 0;
	if (param != NULL)
	{
		if (ft_strchr(param, 'r') != NULL)
			r = 1;
		if (path != NULL && (ft_strchr(param, 't') != NULL))
		{
			if (ft_strchr(param, 'u') != NULL)
			{
				//ft_putendl("test");
				r == 1 ? (r = 3) : (r = 2);
				sort_time(path, tab, r);
				return ;
			}
			sort_time(path, tab, r);
			return ;
		}
	}
	sort_tab(tab, r);
}
