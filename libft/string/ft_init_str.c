/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 19:35:13 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/07 23:13:22 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_init_str(void *s, unsigned int c, int n)
{
	unsigned char	*str;
	int		i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
}
