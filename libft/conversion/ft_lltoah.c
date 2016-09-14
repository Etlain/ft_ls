/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoah.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 22:36:14 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/21 17:06:51 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	val_hex(uint64_t *nbr)
{
	int hexa;

	hexa = 0;
	if (*nbr & (long long)1)
		hexa = 1;
	if (*nbr & (long long)2)
		hexa = hexa + 2;
	if (*nbr & (long long)4)
		hexa = hexa + 4;
	if (*nbr & (long long)8)
		hexa = hexa + 8;
	*nbr = *nbr >> 4;
	if (hexa > 9)
		hexa = hexa + 39;
	return (hexa);
}

static int	val_hex2(uint64_t *nbr)
{
	int hexa;

	hexa = 0;
	if (*nbr & (long long)1)
		hexa = 1;
	if (*nbr & (long long)2)
		hexa = hexa + 2;
	if (*nbr & (long long)4)
		hexa = hexa + 4;
	if (*nbr & (long long)8)
		hexa = hexa + 8;
	*nbr = *nbr >> 4;
	if (hexa > 9)
		hexa = hexa + 7;
	return (hexa);
}

char		*ft_lltoah(unsigned long long nbr, int size)
{
	if (size == 1)
		return (ft_base((uint64_t)nbr, val_hex));
	else if (size == 2)
		return (ft_base((uint64_t)nbr, val_hex2));
	return (NULL);
}
