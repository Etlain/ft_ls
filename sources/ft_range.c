/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:37:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/08/05 10:16:27 by mmouhssi         ###   ########.fr       */
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

static void	sort_tab(char **tab, int b) // 1 = reverse
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

static int sort_t(char *path, char *s1, char *s2, int b)
{
	char *pth1;
	char *pth2;
	struct stat buf1;
	struct stat buf2;

	pth1 = ft_strjoin(path, s1);
	pth2 = ft_strjoin(path, s2);
	//ft_printf("test : %s\n", pth2);
	stat(pth1, &buf1);
	stat(pth2, &buf2);
	free(pth1);
	free(pth2);
	//ft_printf("test : %llu", time(NULL));
	//ft_printf("test : %s\n", ctime(&buf2.st_mtime));
	if (b == 1 && (buf2.st_mtime > buf1.st_mtime)) 
		return (-1);
	else if (b == 0 && (buf1.st_mtime > buf2.st_mtime))
		return (-1);
	/*else if (buf1.st_mtime == buf2.st_mtime) // ajout ordre alphabetique
	{
		if (b == 1)
			return (ft_strcmp(s2, s1));
		else
			return (ft_strcmp(s1, s2));
	}*/
	/*free(buf1);
	free(buf2);*/
	return (0);
}

static void	sort_time(char *path, char **tab, int b) // 1 = reverse
{
	char *tmp;
	char *pth;
	int i;
	int move;

	move = 1;
	while (move == 1)
	{
		i = 0;
		move = 0;
		while (tab[i + 1] != NULL)
		{
			if (sort_t(path, tab[i + 1], tab[i], b) < 0)
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
	if (param == NULL)
		return ;
	if (ft_strchr(param, 'r') != NULL)
		r = 1;
	if (path != NULL && (ft_strchr(param, 't') != NULL))
		sort_time(path, tab, r);
	else
		sort_tab(tab, r);
}
