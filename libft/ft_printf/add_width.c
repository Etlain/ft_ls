/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/21 18:48:46 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_width(t_format format, wchar_t *type, int *width)
{
	int lgt;
	int prcsn;

	if (format.type == 'S')
		lgt = ft_wstrlen(type);
	else
		lgt = ft_strlen((char *)type);
	if (format.precision != NULL && format.precision[0] != '.')
	{
		prcsn = ft_atoi(format.precision);
		if (format.type == 's' && prcsn < lgt)
			lgt = prcsn;
		else if (format.type == 'S' && prcsn < lgt)
			lgt = ft_wnstrlen(type, prcsn);
	}
	if (format.width == NULL)
		return ((char *)type);
	else if (format.width[0] >= '0' && format.width[0] <= '9')
		*width = ft_atoi(format.width) - lgt;
	else
		return ((char *)type);
	return (NULL);
}

static char	*flags_str_zero(t_format format, wchar_t *type, int *width)
{
	char *str;

	str = NULL;
	if (format.flags == '0')
	{
		if (format.precision == NULL || (format.precision[0] == '.'
					&& is_dioux(format.type) != 1))
			str = fill_zero(format, (char *)type, *width);
		if (format.precision == NULL && is_str(format.type) == 0)
			*width = 0;
	}
	return (str);
}

char		*add_width(t_format format, wchar_t *type, int *width)
{
	int		i;
	char	*str;
	char	c;

	if (ft_width(format, type, width) != NULL)
		return ((char *)type);
	if (no_print(format, (char *)type) == 1)
		(*width)++;
	str = flags_str_zero(format, type, width);
	*width < 0 ? *width = 0 : 0;
	if (str != NULL && is_str(format.type) == 0)
		return (str);
	i = 0;
	if (is_str(format.type) > 0 && format.flags == '0')
		c = '0';
	else
		c = ' ';
	while (i < *width && *width > 0)
	{
		ft_putchar(c);
		i++;
	}
	return ((char *)type);
}
