/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/01 18:58:28 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	put_format(va_list lst, char *str, int *i, int length)
{
	int format;

	format = 0;
	(*i)++;
	format = ft_format(lst, str, i);
	format < 0 ? (format = 0) : 0;
	length = length + format;
	return (length);
}

int			ft_printf(const char *str, ...)
{
	va_list lst;
	int		i;
	int		length;

	va_start(lst, str);
	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if ((i = change_color((char *)str, i)) < 0)
			break ;
		if (str[i] == '%')
			length = put_format(lst, (char *)str, &i, length);
		else
		{
			ft_putchar(str[i]);
			length++;
			i++;
		}
	}
	va_end(lst);
	return (length);
}
