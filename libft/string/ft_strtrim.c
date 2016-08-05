/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 11:37:35 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/03 03:24:04 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	start;
	size_t			length;

	if (!s)
		return (NULL);
	start = 0;
	length = ft_strlen(s) - 1;
	if (length > 0)
	{
		while (s[length] == '\t' || s[length] == '\n' || s[length] == ' ')
			length--;
		while (s[start] == '\t' || s[start] == '\n' || s[start] == ' ')
			start++;
	}
	length++;
	if (length < start)
		length = start;
	str = ft_strsub(s, start, length - start);
	return (str);
}
