/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoah.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 23:05:39 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/03 02:42:35 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static long	ft_less(const unsigned int nbr, int *i, int *h)
{
	long s;

	s = 0;
	*h = 15;
	while (s < nbr)
	{
		s = ft_power(16, *i) * *h;
		(*i)++;
	}
	s >= nbr ? (*i)-- : 0;
	while (s > nbr)
	{
		*h < 1 ? (*i)-- : 0;
		*h < 1 ? *h = 15 : 0;
		s = ft_power(16, *i) * *h;
		s > nbr ? (*h)-- : 0;
	}
	return (s);
}

static char	nbr_to_hex(int h, int size)
{
	if (h >= 10 && h <= 15 && size == 1)
		return (h + 87);
	else if (h >= 10 && h <= 15 && size == 2)
		return (h + 55);
	else
		return (h + '0');
}

char		*ft_itoah(unsigned int nbr, int size)
{
	char	*str;
	long	l;
	int	i;
	int	h;
	int	max;

	if (nbr == 0)
		return ("0");
	i = 0;
	l = ft_less(nbr, &i, &h);
	max = i;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i + 1] = '\0';
	ft_init_str(str, '0', i + 1);
	i = max;
	while (i >= 0  && nbr != 0)
	{
		nbr = nbr - l;
		str[max - i] = nbr_to_hex(h, size);
		l = ft_less(nbr, &i, &h);
	}
	return (str);
}
