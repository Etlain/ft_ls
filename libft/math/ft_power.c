/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:35:40 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/03 02:53:20 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_power(int nb, int power)
{
	long result;

	if (power > 0)
	{
		result = nb * ft_power(nb, power - 1);
		return (result);
	}
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	else
		return (0);
}
