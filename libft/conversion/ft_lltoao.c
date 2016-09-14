/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoao.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 22:36:14 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/21 00:55:16 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	val_oct(unsigned long long *nbr)
{
	int octal;

	octal = 0;
	if (*nbr & (long long)1)
		octal = 1;
	if (*nbr & (long long)2)
		octal = octal + 2;
	if (*nbr & (long long)4)
		octal = octal + 4;
	*nbr = *nbr >> 3;
	return (octal);
}

char		*ft_lltoao(unsigned long long nbr)
{
	return (ft_base(nbr, val_oct));
}
