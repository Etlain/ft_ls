/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/21 17:09:10 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*add_precision(t_format format, char *type, int *prcsn)
{
	char *str;

	str = NULL;
	if (format.precision == NULL)
		return (type);
	else if (format.precision[0] >= '0' && format.precision[0] <= '9')
		*prcsn = ft_atoi(format.precision) - ft_strlen(type);
	else
		return (type);
	if (type != NULL && (type[0] == '-' || type[0] == '+'))
		(*prcsn)++;
	str = fill_zero(format, type, *prcsn);
	if (str != NULL)
		return (str);
	return (type);
}

static char	*add_prenbr(t_format format, char *nbr)
{
	char *pre;
	char *str;

	pre = NULL;
	if (format.pre == '#' && ft_strcmp(nbr, "0") != 0)
	{
		format.type == 'x' ? (pre = "0x") : 0;
		format.type == 'X' ? (pre = "0X") : 0;
	}
	if (format.pre == '#' && (format.type == 'o' || format.type == 'O'))
		nbr[0] != '0' ? (pre = "0") : 0;
	if (format.sign == ' ' && nbr[0] != '-' && is_unsigned(format.type) == 0)
		pre = " ";
	else if (format.type == 'd' || format.type == 'D' || format.type == 'i')
	{
		if (format.sign == '+' && nbr[0] != '-')
			pre = "+";
	}
	if (pre != NULL)
	{
		str = nbr;
		nbr = ft_strjoin(pre, str);
		free(str);
	}
	return (nbr);
}

static char	*fill_word(char type, long long nbr)
{
	char *word;

	word = NULL;
	if (type == 'd' || type == 'D' || type == 'i')
		word = ft_lltoa(nbr);
	else if (type == 'u' || type == 'U')
		word = ft_ulltoa((unsigned long long)nbr);
	else if (type == 'x' || type == 'p')
		word = ft_lltoah(nbr, 1);
	else if (type == 'X')
		word = ft_lltoah(nbr, 2);
	else if (type == 'o' || type == 'O')
		word = ft_lltoao(nbr);
	else if (type == 'b')
		word = ft_lltoab(nbr);
	return (word);
}

static char	*p_precision(t_format format, char *word, int *width, int *b)
{
	char *tmp;

	if (format.type == 'p' && ft_strcmp(word, "0") == 0 && *b == 1)
	{
		tmp = word;
		word = ft_strjoin(tmp, "x");
		tmp != NULL ? free(tmp) : 0;
		*b = 0;
	}
	word = add_precision(format, word, width);
	if (format.type == 'p' && ft_strcmp(word, "0x") != 0)
	{
		tmp = word;
		word = ft_strjoin("0x", tmp);
		tmp != NULL ? free(tmp) : 0;
	}
	return (word);
}

int			write_nbr(t_format format, long long nbr)
{
	char	*word;
	int		width;
	int		b;

	width = 0;
	b = 0;
	word = fill_word(format.type, nbr);
	b = no_print(format, word);
	if (format.type == 'p')
		word = p_precision(format, word, &width, &b);
	else
		word = add_precision(format, word, &width);
	width = 0;
	word = add_prenbr(format, word);
	if (format.flags != '-')
		word = add_width(format, (wchar_t *)word, &width);
	b == 0 ? ft_putstr(word) : 0;
	format.flags == '-' ? add_width(format, (wchar_t *)word, &width) : 0;
	b == 0 ? (width = width + ft_strlen(word)) : 0;
	if (b == 1 && width == 0)
		width = -1;
	word == NULL ? width = 0 : 0;
	word != NULL ? free(word) : 0;
	return (width);
}
