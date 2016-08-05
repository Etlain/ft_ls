/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:57:57 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/01 18:38:15 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_flags(char str)
{
	if (str == '+' || str == ' ' || str == '-' || str == '0' || str == '#')
		return (1);
	return (0);
}

int		is_str(char type)
{
	if (type == 's' || type == 'S')
		return (1);
	else if (type == 'c' || type == 'C')
		return (2);
	return (0);
}

int		is_dioux(char type)
{
	if (type == 'd' || type == 'i' || type == 'o')
		return (1);
	if (type == 'u' || type == 'x' || type == 'X')
		return (1);
	if (type == 'D' || type == 'O' || type == 'U')
		return (2);
	return (0);
}

int		is_unsigned(char str)
{
	if (str == 'u' || str == 'U' || str == 'x' || str == 'X')
		return (1);
	else if (str == 'o' || str == 'O' || str == 'p')
		return (2);
	return (0);
}

int		is_modifier(char *str)
{
	if (str == NULL)
		return (0);
	else if (ft_strncmp(str, "ll", 2) == 0 || str[0] == 'z')
		return (5);
	else if (str[0] == 'l')
		return (4);
	else if (str[0] == 'j')
		return (3);
	else if (ft_strncmp(str, "hh", 2) == 0)
		return (1);
	else if (str[0] == 'h')
		return (2);
	return (0);
}
