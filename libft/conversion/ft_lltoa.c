/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:54:54 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/03 02:43:17 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static long	long	ft_dizaine(char **str, long long n)
{
	long long	nbr;
	long long	dizaine;
	int			i;

	nbr = n;
	dizaine = 1;
	i = 1;
	while (nbr > 9 || nbr < -9)
	{
		nbr = nbr / 10;
		i++;
		dizaine = dizaine * 10;
	}
	if (n < 0)
		i++;
	*str = (char*)malloc(sizeof(char) * (i + 1));
	return (dizaine);
}

char static			*ft_fill(char *str, long long nbr, long long d, int *i)
{
	long long s;

	s = 0;
	while (d > 9)
	{
		s = s + (str[*i] - '0') * d;
		d = d / 10;
		(*i)++;
		str[*i] = (nbr - s) / d + '0';
	}
	return (str);
}

char				*ft_lltoa(long long n)
{
	long long	dizaine;
	long long	nbr;
	char		*str;
	int			i;

	i = 0;
	str = NULL;
	nbr = (long long)n;
	dizaine = ft_dizaine(&str, nbr);
	if (str == NULL)
		return (NULL);
	if (nbr < 0)
	{
		str[i] = '-';
		i++;
		nbr = nbr * (-1);
	}
	if (nbr >= 0)
		str[i] = '0' + (nbr / dizaine);
	else
		str[i] = '0' - (nbr / dizaine);
	str = ft_fill(str, nbr, dizaine, &i);
	str[i + 1] = '\0';
	return (str);
}
