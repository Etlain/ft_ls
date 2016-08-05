/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permission.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:37:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/08/05 10:16:00 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft/includes/libft.h"
#include "../includes/ft_ls.h"

void	type_file(mode_t *st_mode, char *tab)
{
	if (*st_mode & 8)
	{
		if (*st_mode & 2)
			tab[0] = 'l';
		else if (*st_mode & 4)
			tab[0] = 's';
	}
	else
	{
		if (*st_mode & 2 && *st_mode & 4)
			tab[0] = 'b';
		else if (*st_mode & 1)
			tab[0] = 'p';
		else if (*st_mode & 2)
			tab[0] = 'c';
		else if (*st_mode & 4)
			tab[0] = 'd';
	}
}

int	ft_rwx(mode_t *st_mode, char *tab, int size)
{
	if (*st_mode & 1)
		tab[size] = 'x';
	size--;
	if (*st_mode & 2)
		tab[size] = 'w';
	size--;
	if (*st_mode & 4)
		tab[size] = 'r';
	size--;
	*st_mode = *st_mode >> 3;
	return (size);
}

char	*ft_permission(struct stat buf, char *path) // droit // pense a free derriere
{
	struct passwd *pwd;
	struct group *gr;
	char *tab;
	int size;

	// faire une fonction pour le formatage de l'affichage
	size = 9;
	tab = (char *)malloc(10);
	ft_init_str(tab, '-', 10);
	tab[10] = '\0';
	size = ft_rwx(&buf.st_mode, tab, size);
	size = ft_rwx(&buf.st_mode, tab, size);
	size = ft_rwx(&buf.st_mode, tab, size);
	buf.st_mode = buf.st_mode >> 3;
	type_file(&buf.st_mode, tab);
	ft_printf("%s ", tab);
	ft_printf("%d ", buf.st_nlink);
	pwd = getpwuid(buf.st_uid);
	ft_printf("%s ", pwd->pw_name);
	gr = getgrgid(pwd->pw_gid);
	ft_printf("%s ", gr->gr_name);
	ft_printf("%d ", buf.st_size);
	ft_putnstr(ctime(&buf.st_mtime), 16); // faire une fonction pour la date
	ft_printf(" %s\n", path);
	return (tab);
}
