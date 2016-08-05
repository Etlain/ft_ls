/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 14:09:28 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/03 02:54:14 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int result;

	if (power > 0)
	{
		result = nb * ft_recursive_power(nb, power - 1);
		return (result);
	}
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	else
		return (0);
}
