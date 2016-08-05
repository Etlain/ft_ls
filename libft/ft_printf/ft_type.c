/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/01 19:02:08 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	add_umodifier(t_format format, va_list lst)
{
	int length;

	length = 0;
	if (format.modifier == NULL)
		return (0);
	if (ft_strcmp(format.modifier, "hh") == 0)
		length = write_nbr(format, (long long)(unsigned char)va_arg(lst, int));
	else if (format.modifier[0] == 'h')
		length = write_nbr(format, (long long)(unsigned short)va_arg(lst, int));
	else if (format.modifier[0] == 'l')
		length = write_nbr(format, (long long)va_arg(lst, unsigned long));
	else if (ft_strcmp(format.modifier, "ll") == 0)
		length = write_nbr(format, va_arg(lst, unsigned long long));
	else if (format.modifier[0] == 'j')
		length = write_nbr(format, (long long)va_arg(lst, uintmax_t));
	else if (format.modifier[0] == 'z')
		length = write_nbr(format, (long long)va_arg(lst, size_t));
	return (length);
}

static int	add_modifier(t_format format, va_list lst)
{
	int length;

	length = 0;
	if (format.modifier == NULL)
		return (0);
	if (format.type == 'u' || format.type == 'o' ||
			format.type == 'x' || format.type == 'X')
		length = add_umodifier(format, lst);
	else if (ft_strcmp(format.modifier, "hh") == 0)
		length = write_nbr(format, (long long)(char)va_arg(lst, int));
	else if (format.modifier[0] == 'h')
		length = write_nbr(format, (long long)(short)va_arg(lst, int));
	else if (format.modifier[0] == 'l')
		length = write_nbr(format, (long long)va_arg(lst, long));
	else if (ft_strcmp(format.modifier, "ll") == 0)
		length = write_nbr(format, va_arg(lst, long long));
	else if (format.modifier[0] == 'j')
		length = write_nbr(format, (long long)va_arg(lst, intmax_t));
	else if (format.modifier[0] == 'z')
		length = write_nbr(format, (long long)va_arg(lst, size_t));
	return (length);
}

static int	ft_dioux(t_format format, va_list lst, char str)
{
	int length;

	length = 0;
	if (str == 'd' || str == 'i')
		length = write_nbr(format, (long long)va_arg(lst, int));
	else if (str == 'D')
		length = write_nbr(format, (long long)va_arg(lst, long int));
	else if (str == 'u' || str == 'x' || str == 'X' || str == 'o' || str == 'b')
		length = write_nbr(format, (long long)va_arg(lst, unsigned int));
	else if (str == 'U' || str == 'O' || str == 'p')
		length = write_nbr(format, (long long)va_arg(lst, unsigned long));
	else
		return (-1);
	return (length);
}

static int	write_type(t_format format, char str, int length)
{
	format.type = 's';
	format.flags != '-' ? add_width(format, L"%", &length) : 0;
	ft_putchar(str);
	format.flags == '-' ? add_width(format, L"%", &length) : 0;
	length++;
	return (length);
}

int			ft_type(t_format *format, va_list lst, char str)
{
	int length;

	length = 0;
	if (is_dioux(str) > 0 || str == 'p' || str == 'b')
	{
		format->type = str;
		if (format->modifier != NULL && is_dioux(str) == 1)
			length = add_modifier(*format, lst);
		else
			length = ft_dioux(*format, lst, str);
	}
	else if (str == '%')
		return (write_type(*format, str, length));
	else if (is_str(str) > 0)
	{
		format->type = str;
		length = ft_sc(*format, lst, str);
	}
	else if (is_dioux(str) == 0 && is_str(str) == 0 && str != 'p' && str != 'b'
			&& is_flags(str) == 0 && ft_isprint(str) == 1 && str != '.')
		length = write_type(*format, str, length);
	return (length);
}
