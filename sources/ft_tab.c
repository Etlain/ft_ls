/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:37:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/08/05 11:32:54 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// penser a ajouter erno
// gestion -a
// tableau trois dimenssion pour le formatage de l'affichage (ligne colonne
// pointeur)

// faire un tableau de char*

char **fill_tab_a(char *directory, t_max *max)
{
	char **tab;
	int nbr_file;
	char *s;
	struct dirent *file;
	void	*dir;
	int i;

	nbr_file = 0;
	dir = opendir(directory);
	//ft_printf("{cyan}cyan{cyan}\n");
	while ((file = readdir(dir)) != NULL)
		nbr_file++;
	closedir(dir);
	tab = (char **)ft_memalloc(sizeof(char *) * (nbr_file + 1));
	if (tab == NULL)
	{
		ft_putendl("error malloc");
	}
	tab[nbr_file + 1] = NULL;
	dir = opendir(directory);
	i = 0;
	while ((file = readdir(dir)) != NULL)
	{
		s = (char *)ft_memalloc(ft_strlen(file->d_name) + 1);
		if (s == NULL)
		{
			ft_putendl("error malloc");
		}
		ft_strcpy(s, file->d_name);
		tab[i] = s;
		i++;
	}
	closedir(dir);
	return (tab);
}

char **fill_tab(char *directory, t_max *max)
{
	char **tab;
	int nbr_file;
	char *s;
	struct dirent *file;
	void	*dir;
	int i;
	int error;

	nbr_file = 0;
	dir = opendir(directory);
	if (dir == NULL)
	{
		error = errno;
		strerror(error);
		perror("opendir : fill_tab");
		exit(-1);
	}
	if (dir == NULL)
		ft_putendl("error dir fill tab");
	while ((file = readdir(dir)) != NULL)
		nbr_file++;
	closedir(dir);
	dir = NULL;
	tab = (char **)ft_memalloc(sizeof(char *) * (nbr_file + 1));
	if (tab == NULL)
		ft_putendl("error memalloc fill tab");
	tab[nbr_file + 1] = NULL;
	dir = opendir(directory);
	if (dir == NULL)
		{
			error = errno;
			strerror(error);
			perror("opendir");
			exit(-1);
		}
	i = 0;
	while ((file = readdir(dir)) != NULL)
	{
		if (file == NULL)
		{
			error = errno;
			strerror(error);
			perror("readdir");
			exit(-1);
		}
		if (file->d_name[0] != '.')
		{
			s = (char *)ft_memalloc(ft_strlen(file->d_name) + 1);
			if (s == NULL)
				ft_putendl("error memalloc 2 fill tab");
			ft_strcpy(s, file->d_name);
			tab[i] = s;
			i++;
		}
	}
	closedir(dir);
	dir = NULL;
	return (tab);
}
