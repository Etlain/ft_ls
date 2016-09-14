/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 22:36:14 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/21 00:54:52 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	val_bin(unsigned long long *nbr)
{
	int bin;

	bin = 0;
	if (*nbr & (long long)1)
		bin++;
	*nbr = *nbr >> 1;
	return (bin);
}

char		*ft_lltoab(unsigned long long nbr)
{
	return (ft_base((long long)nbr, val_bin));
}
