/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/01 18:36:41 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		after_pre(char **str, char *type, int *width, int *i)
{
	int j;

	j = 0;
	if (type[j] == '-' || type[j] == '+' || type[j] == ' ')
	{
		*str[*i] = type[j];
		(*i)++;
		(*width)++;
		j++;
	}
	else if (type[j] == '0' && (type[j + 1] == 'x' || type[j + 1] == 'X'))
	{
		type[j + 1] == 'x' ? ft_strcat(*str, "0x") : 0;
		type[j + 1] == 'X' ? ft_strcat(*str, "0X") : 0;
		j = 2;
		*i = 2;
		*width = *width + 2;
	}
	return (j);
}

char	*fill_zero(t_format format, char *type, int width)
{
	char	*str;
	int		i;
	int		j;

	if (type == NULL || width <= 0)
		return (NULL);
	if (is_dioux(format.type) == 0 && format.type != 'p')
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)ft_memalloc(ft_strlen(type) + width);
	j = after_pre(&str, type, &width, &i);
	while (i < width)
	{
		ft_strcat(str, "0");
		i++;
	}
	ft_strcat(str, &type[j]);
	if (type != NULL && is_dioux(format.type) > 0 && ft_strcmp(type, "0") != 0)
		free(type);
	return (str);
}
