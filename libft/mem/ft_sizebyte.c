/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizebyte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 21:49:14 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/21 18:55:10 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_sizebyte(uint64_t nbr)
{
	int size;

	size = 0;
	while (nbr != 0)
	{
		nbr = nbr >> 1;
		size++;
	}
	return (size);
}
