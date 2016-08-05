/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 16:49:57 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/08/05 11:29:58 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
//# include <sys/ioctl.h>
# include <errno.h>
//# include <fcntl.h>
# include <stdio.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# define BUF_MAX 10

typedef struct		s_file // a supprimer si inutile avec le fichier lst_file fait avec amour :(
{
	struct dirent	*file;
	int				index;
	struct s_file	*pre;
	struct s_file	*next;
}					t_file;

typedef struct		s_max // taille max mot chaque categorie pour affichage
{
	//int				nbr_file;
	//int				nbr_line;
	int				file;
	int				link;
	int				pw_name;
	int				gr_name;
	int				size;
	int				time;
	char			*space;
}					t_max;

void    nbr_line(t_max *max); // dans main pour l instant
void	ft_sort(char *path, char **tab, char *param);
char	**fill_tab(char *directory, t_max *max);
char	**fill_tab_a(char *directory, t_max *max);
char	*ft_permission(struct stat buf, char *path);
void	ft_putls(char *path, char *param, int b);
int		is_param(char c); // ptet pas necessaire dans le .h
// a effacer
char	*ft_param(char **argv, int argc, int (*f)(char c));
char	*ft_ctoa(char c);
void	ft_putdir(char **tab);
void	ft_putdirl(char *path);
void	ft_putdirr(char *path);

#endif
