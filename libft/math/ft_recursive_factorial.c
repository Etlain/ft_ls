/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 10:57:14 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/03 02:53:52 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb > 1)
	{
		nb = nb * ft_recursive_factorial(nb - 1);
		return (nb);
	}
	else if ((nb == 1) || (nb == 0))
		return (1);
	else
		return (0);
}
