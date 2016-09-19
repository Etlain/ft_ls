/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:37:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/19 13:46:43 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	type_file(mode_t *st_mode, char *tab)
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

static int	ft_rwx(mode_t *st_mode, char *tab, int size)
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

static void	ft_date(struct stat buf, t_l *l)
{
	time_t t;
	time_t month_6;

	month_6 = 15770000;
	l->time = ft_strsplit(ctime(&buf.st_mtimespec.tv_sec), ' ');
	free(l->time[0]);
	l->time[0] = l->time[1];
	l->time[1] = l->time[2];
	if (time(&t) - buf.st_mtimespec.tv_sec > month_6 ||
			time(&t) < buf.st_mtimespec.tv_sec)
	{
		l->time[2] = l->time[4];
		free(l->time[3]);
		l->time[3] = NULL;
	}
	else
	{
		l->time[2] = l->time[3];
		l->time[3] = NULL;
		free(l->time[4]);
	}
}

static void	ft_fill(struct stat buf, t_l *l)
{
	struct passwd	*pwd;
	struct group	*gr;
	int				size;

	size = 9;
	l->rwx = (char *)ft_memalloc(10 + 1);
	ft_init_str(l->rwx, '-', 10);
	size = ft_rwx(&buf.st_mode, l->rwx, size);
	size = ft_rwx(&buf.st_mode, l->rwx, size);
	size = ft_rwx(&buf.st_mode, l->rwx, size);
	buf.st_mode = buf.st_mode >> 3;
	type_file(&buf.st_mode, l->rwx);
	l->link = ft_itoa(buf.st_nlink);
	pwd = getpwuid(buf.st_uid);
	l->pw_name = ft_strdup(pwd->pw_name);
	gr = getgrgid(pwd->pw_gid);
	l->gr_name = ft_strdup(gr->gr_name);
	if (l->rwx[0] == 'c' || l->rwx[0] == 'b')
	{
		l->minor = ft_itoa(buf.st_rdev >> 24 & 0xff);
		l->major = ft_itoa(buf.st_rdev & 0xffffff);
	}
	else
		l->size = ft_itoa(buf.st_size);
}

void		fill_struct_l(struct stat buf, char *path, t_l *l, char *p)
{
	char *s;
	char buffer[100];

	ft_fill(buf, l);
	if (p != NULL && ft_strchr(p, 'T') != NULL)
	{
		l->time = (char **)ft_memalloc(2 * sizeof(char *));
		s = ctime(&buf.st_mtimespec.tv_sec);
		l->time[0] = ft_strndup(s, ft_strlen(s) - 1);
	}
	else
		ft_date(buf, l);
	if (l->rwx[0] == 'l')
	{
		ft_bzero(buffer, 100);
		ft_strcpy(buffer, " -> ");
		readlink(path, &buffer[4], 96);
		l->file = ft_strjoin(last_namep(path), last_namep(buffer));
	}
	else
		l->file = last_namep(path);
}
