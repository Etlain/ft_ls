/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/21 18:54:27 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_c(t_format format, va_list lst, char str)
{
	wchar_t c;
	int		width;

	width = 0;
	c = 0;
	if (format.modifier != NULL && format.modifier[0] == 'l')
		str == 'c' ? str = 'C' : 0;
	format.flags != '-' ? add_width(format, L"1", &width) : 0;
	if (str == 'c')
		ft_putchar((char)va_arg(lst, int));
	else
		ft_putwchar((c = va_arg(lst, wchar_t)));
	format.flags == '-' ? add_width(format, L"1", &width) : 0;
	if (str == 'C')
		width = ft_sizewchar((long)c);
	else
		width++;
	return (width);
}

static void	s_empty(t_format format, wchar_t **word)
{
	if (format.precision != NULL && (format.precision[0] == '.'))
	{
		if (format.type == 's')
			*word = (wchar_t *)"";
		else
			*word = L"";
	}
	else if (*word == NULL)
	{
		format.type == 's' ? (*word = (wchar_t *)"(null)") : 0;
		format.type == 'S' ? (*word = L"(null)") : 0;
	}
}

static char	ft_s(t_format format, va_list lst, wchar_t **word, int *width)
{
	if (format.modifier != NULL && format.modifier[0] == 'l')
		format.type == 's' ? format.type = 'S' : 0;
	if (format.type == 'S')
		*word = va_arg(lst, wchar_t *);
	else if (format.type == 's')
		*word = (wchar_t *)va_arg(lst, char *);
	s_empty(format, word);
	if (word != NULL)
	{
		format.flags != '-' ? add_width(format, *word, width) : 0;
		if (format.precision != NULL)
		{
			if (format.type == 's' && format.precision[0] != '.')
				ft_putnstr((char *)*word, ft_atoi(format.precision));
			else if (format.type == 'S' && format.precision[0] != '.')
				ft_putnwstr(*word, ft_atoi(format.precision));
		}
		else if (format.type == 's')
			ft_putstr((char *)*word);
		else
			ft_putwstr(*word);
		format.flags == '-' ? add_width(format, *word, width) : 0;
	}
	return (format.type);
}

int			ft_sc(t_format format, va_list lst, char str)
{
	wchar_t *word;
	int		width;

	width = 0;
	word = NULL;
	if (str == 'c' || str == 'C')
		return (ft_c(format, lst, str));
	else if (str == 'S' || str == 's')
		str = ft_s(format, lst, &word, &width);
	if (format.precision != NULL && format.precision[0] != '.' &&
			(str == 's' || str == 'S') && ft_atoi(format.precision)
			< (int)ft_strlen((char *)word))
		width = ft_atoi(format.precision) + width;
	else if (word != NULL && str == 's')
		width = ft_strlen((char *)word) + width;
	else if (str == 'S' && word != NULL && format.precision != NULL)
		width = ft_wnstrlen(word, ft_atoi(format.precision)) + width;
	else if (word != NULL && str == 'S')
		width = ft_wstrlen(word) + width;
	if ((str == 's' || str == 'S') && width == 0)
		width = -1;
	return (width);
}
