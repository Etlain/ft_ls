/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:37:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/14 23:42:44 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// penser a ajouter erno
// gestion -a
// tableau trois dimenssion pour le formatage de l'affichage (ligne colonne
// pointeur)

// faire un tableau de char*

static int	ft_nbr_file(char *directory)
{
	void *dir;
	int nbr_file;
	int error;
	struct dirent *file;

	nbr_file = 0;
	if ((dir = opendir(directory)) == NULL)
	{
		error = errno;
		strerror(error);
		//perror("fill_tab : opendir");
		perror(directory);
		return (-1);
		//exit(-1);
	}
	while ((file = readdir(dir)) != NULL)
		nbr_file++;
	closedir(dir);
	dir = NULL;
	return (nbr_file);
}

char **fill_tab_a(char *directory, t_max *max, char *param)
{
	char **tab;
	int nbr_file;
	struct dirent *file;
	void	*dir;
	int i;

	if ((nbr_file = ft_nbr_file(directory)) == -1)
		return (NULL);
	tab = (char **)ft_memalloc(sizeof(char *) * (nbr_file + 1));
	dir = opendir(directory);
	i = 0;
	while ((file = readdir(dir)) != NULL)
	{
		tab[i] = (char *)ft_memalloc(ft_strlen(file->d_name) + 1);
		ft_strcpy(tab[i], file->d_name);
		fill_struct_max(ft_strjoin_path(directory, file->d_name), max, param);
		i++;
	}
	closedir(dir);
	dir = NULL;
	return (tab);
}

char **fill_tab(char *directory, t_max *max, char *param)
{
	char **tab;
	int nbr_file;
	struct dirent *file;
	void	*dir;
	int i;

	if ((nbr_file = ft_nbr_file(directory)) == -1)
		return (NULL);
	tab = (char **)ft_memalloc(sizeof(char *) * (nbr_file + 1));
	dir = opendir(directory);
	i = 0;
	while ((file = readdir(dir)) != NULL)
	{
		if (file->d_name[0] != '.')
		{
			tab[i] = (char *)malloc(ft_strlen(file->d_name) + 1);
			ft_bzero(tab[i], ft_strlen(file->d_name) + 1);
			ft_strcpy(tab[i], file->d_name);
			fill_struct_max(ft_strjoin_path(directory, file->d_name), max, param); // -l condition
			i++;
		}
	}
	closedir(dir);
	dir = NULL;
	return (tab);
}

char **ft_tab(char *directory, t_max *max, char *param)
{
	char **tab;

	tab = NULL;
	if (param != NULL && ft_strchr(param, 'a') != NULL)
		tab = fill_tab_a(directory, max, param);
	else
		tab = fill_tab(directory, max, param);
	if (tab != NULL)
		ft_sort(directory, tab, param);
	return (tab);
}
