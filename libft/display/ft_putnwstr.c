/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:03:28 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/21 18:48:24 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_nbroctet(wchar_t c)
{
	int nb;

	nb = ft_sizebyte(c);
	if (nb < 8)
		return (1);
	else if (nb < 12)
		return (2);
	else if (nb < 17)
		return (3);
	else if (nb < 22)
		return (4);
	return (-1);
}

void		ft_putnwstr(wchar_t *str, int lgt)
{
	int i;

	i = 0;
	while (1)
	{
		lgt = lgt - ft_nbroctet(str[i]);
		if (lgt < 0 || str[i] == '\0')
			break ;
		ft_putwchar(str[i]);
		i++;
	}
}
