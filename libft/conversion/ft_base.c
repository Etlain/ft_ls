/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 22:36:14 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/21 17:07:54 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_zero(void)
{
	char *bin;

	bin = (char *)ft_memalloc(2);
	bin[0] = '0';
	return (bin);
}

char		*ft_base(uint64_t nbr, int (*val)(uint64_t *nbr))
{
	char	tab[sizeof(nbr) * 8];
	char	*bin;
	int		i;
	int		j;

	if (nbr == 0)
		return (ft_zero());
	i = 0;
	while (nbr != 0)
	{
		tab[i] = '0' + val(&nbr);
		i++;
	}
	tab[i] = '\0';
	bin = (char *)ft_memalloc(i + 1);
	j = 0;
	i--;
	while (i >= 0)
	{
		bin[j] = tab[i];
		j++;
		i--;
	}
	return (bin);
}
