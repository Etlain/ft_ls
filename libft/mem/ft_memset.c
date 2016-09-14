/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:09:04 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/03 03:02:31 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int n, size_t len)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	tab = b;
	while (i < len)
	{
		tab[i] = (unsigned char)n;
		i++;
	}
	return (b);
}
