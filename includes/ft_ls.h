/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:49:57 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/19 13:45:45 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <stdio.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# define BUF_MAX 100

typedef struct		s_l
{
	char			*rwx;
	char			*link;
	char			*pw_name;
	char			*gr_name;
	char			*minor;
	char			*major;
	char			*size;
	char			**time;
	char			*file;
}					t_l;

typedef struct		s_max
{
	int				blocks;
	int				file;
	int				link;
	int				pw_name;
	int				gr_name;
	int				minor;
	int				major;
	int				size;
	int				time1;
	int				time2;
	char			*space;
}					t_max;

void				ft_sort(char *path, char **tab, char *param);
void				ft_putls(char *path, char *param, int b);
char				**ft_tab(char *directory, t_max *max, char *param);
char				*last_namep(char *path);
void				ft_putcolor(char rwx, char *s);
void				ft_color_dir(char *path, char *dir, char *param);
void				ft_color_g(char **tab, char *path, char *param);
void				ft_putformat(char *path, char *param);
char				*ft_param(char **argv, int argc, int (*f)(char c));
void				ft_putdir(char **tab);
void				ft_putdirl(char *path, char *param);
void				ft_putdirr(char *path, char *param);
void				fill_struct_l(struct stat buf, char *path, t_l *l, char *p);
void				free_struct_l(t_l *l);
void				init_max(t_max *max);
void				fill_struct_max(char *file, t_max *max, char *param);

#endif
