/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/01 19:08:15 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_val_wp(char *str, int *i)
{
	char	*tmp;
	int		j;
	int		lgt;

	j = *i;
	lgt = 0;
	while (str[j] >= '0' && str[j] <= '9')
	{
		lgt++;
		j++;
	}
	tmp = (char *)ft_memalloc(lgt + 1);
	ft_strncat(tmp, &str[*i], j - *i);
	*i = j;
	return (tmp);
}

static char		*ft_star(t_format *format, va_list lst, int *i, int b)
{
	char	*tmp;
	int		j;

	(*i)++;
	j = va_arg(lst, int);
	if (j < 0)
	{
		if (b == 1)
			return (NULL);
		j = j * (-1);
		format->flags = '-';
	}
	tmp = ft_itoa(j);
	return (tmp);
}

void			ft_wp(t_format *format, va_list lst, char *str, int *i)
{
	char	*tmp;
	int		b;

	if (str[*i] == '.')
		b = 1;
	else
		b = 0;
	while (str[*i] == '.')
		(*i)++;
	if (str[*i] >= '0' && str[*i] <= '9')
		tmp = ft_val_wp(str, i);
	else if (str[*i] == '*')
		tmp = ft_star(format, lst, i, b);
	else
	{
		b == 1 ? (format->precision = ".") : 0;
		return ;
	}
	if (b == 1)
		format->precision = tmp;
	else
		format->width = tmp;
}
