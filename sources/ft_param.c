/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:37:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/08/05 10:32:30 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"
/* NULL si aucun param trouver 
 * - si mauvais param suivi du param en question
 * renvoie tous les parametre valide derriere un - ou plusieurs consecutifs
*/

char	*ft_ctoa(char c) // a ajouter a la librairie
{
	char *s;

	s = (char *)ft_memalloc(2);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

static int	nbr_param(char *str, char *param, int (*f)(char c))
{
	int nbr;
	int i;

	i = 0;
	nbr = 0;
	while (param[i] != '\0')
	{
		if (f(param[i]) == 1)
			nbr++;
		i++;
	}
	return (nbr);
}

static void	add_param(char *str, char *s, char param, int *j)
{
	if (str == NULL ||(str != NULL && ft_strchr(str, param) == NULL))
	{
		if (ft_strchr(s, param) == NULL)
		{
			s[*j] = param;
			(*j)++;
		}
	}
}

static void	fill_str(char **str, char *s)
{
	char *tmp;

	if (*str != NULL)
	{
		tmp = *str;
		*str = ft_strjoin(*str, s);
		//free(tmp);
		//free(s);
	}
	else
		*str = s;
}

static void	param(char **str, char *param, int (*f)(char c))
{
	char *tmp;
	char *s;
	int i;
	int j;

	s = (char *)ft_memalloc((size_t)nbr_param(*str, param, f) + 1);
	i = 0;
	j = 0;
	while (param[i] != '\0')
	{
		if (f(param[i]) == 1)
			add_param(*str, s, param[i], &j);
		else
		{
			//free(s);
			*str != NULL ? free(*str) : 0;
			tmp = ft_ctoa(param[i]);
			*str = ft_strjoin("-", tmp);
			//free(tmp);
			return ;
		}
		i++;
	}
	fill_str(str, s);
}

char	*ft_param(char **argv, int argc, int (*f)(char c))
{
	char *str;
	int i;

	i = 1;
	str = NULL;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] != '\0')
				param(&str, &argv[i][1], f);
			else
				return ("-");
			if (str != NULL && str[0] == '-')
				return (str);
		}
		else
			break ;
		i++;
	}
	return (str);
}
