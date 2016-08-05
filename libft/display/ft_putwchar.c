/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 21:49:14 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/21 18:52:16 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_write(wchar_t c, int mask, int left, int right)
{
	unsigned int nbr;

	nbr = ((unsigned int)c << left >> right) | mask;
	write(1, &nbr, 1);
}

void		ft_putwchar(wchar_t c)
{
	int size;

	size = ft_sizebyte(c);
	if (size < 8)
		ft_putchar(c);
	else if (size < 12)
	{
		ft_write(c, 192, 0, 6);
		ft_write(c, 128, 26, 26);
	}
	else if (size < 17)
	{
		ft_write(c, 224, 0, 12);
		ft_write(c, 128, 20, 26);
		ft_write(c, 128, 26, 26);
	}
	else if (size < 22)
	{
		ft_write(c, 240, 0, 18);
		ft_write(c, 128, 14, 26);
		ft_write(c, 128, 20, 26);
		ft_write(c, 128, 26, 26);
	}
}
