/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/01 18:53:11 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_getcolor(char *s, int b)
{
	int color;

	color = 0;
	if (ft_strcmp("cyan", s) == 0)
		color = 36;
	else if (ft_strcmp("magenta", s) == 0)
		color = 35;
	else if (ft_strcmp("blue", s) == 0)
		color = 34;
	else if (ft_strcmp("yellow", s) == 0)
		color = 33;
	else if (ft_strcmp("green", s) == 0)
		color = 32;
	else if (ft_strcmp("red", s) == 0)
		color = 31;
	else if (ft_strcmp("black", s) == 0)
		color = 30;
	else
		return (0);
	if (b == 0)
		color = 0;
	ft_putstr("\033[");
	ft_putnbr(color);
	ft_putchar('m');
	return (1);
}

static int	ft_color(char *str, int i)
{
	static int	b;
	int			j;
	char		*s;

	if (b == 0 || !b)
		b = 1;
	else if (b == 1)
		b = 0;
	j = i;
	while (str[j] != '}')
		j++;
	s = (char *)malloc(j + 1);
	s[j + 1] = '\0';
	ft_strncat(s, &str[i], j - i);
	if (ft_getcolor(s, b) == 0)
	{
		free(s);
		i--;
		return (i);
	}
	free(s);
	j++;
	return (j);
}

int			change_color(char *str, int i)
{
	if (str[i] == '{')
	{
		i++;
		if (str[i] != '\0')
			i = ft_color((char *)str, i);
		if (str[i] == '\0')
			return (-1);
	}
	return (i);
}
