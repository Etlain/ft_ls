/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ahtoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 23:47:44 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/03 02:39:09 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_ahtoi(char *str)
{
	int nbr;
	int i;
	int max;

	if (!str)
		return (-1);
	max = ft_strlen(str);
	if (max < 3 || str[0] != '0' || str[1] != 'x')
		return (-1);
	nbr = 0;
	i = 2;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = nbr + (str[i] - '0') * ft_power(16, max - 3);
		if (str[i] >= 'A' && str[i] <= 'F')
			nbr = nbr + (str[i] - 55) * ft_power(16, max - 3);
		if (str[i] >= 'a' && str[i] <= 'f')
			nbr = nbr + (str[i] - 87) * ft_power(16, max - 3);
		max--;
		i++;
	}
	return (nbr);
}
