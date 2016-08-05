/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:52:34 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/03 03:07:42 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	if (*str == (unsigned char)c)
		return (str);
	return (NULL);
}
