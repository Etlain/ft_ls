/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:15:31 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/03 03:20:35 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char static		*ft_compare(const char *s1, const char *s2, size_t n, size_t i)
{
	int j;

	j = 0;
	while (i < n && s1[i] != '\0')
	{
		if (s1[i] == s2[j])
			j++;
		else if (s2[j] == '\0')
			return (char *)(&s1[i - j]);
		else
			j = 0;
		i++;
	}
	if (s2[j] == '\0')
		return (char *)(&s1[i - j]);
	return (NULL);
}

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	while (i < n && s1[i] != '\0')
	{
		if (s1[i] == s2[0])
			str = ft_compare(s1, s2, n, i);
		if (str != NULL)
			return (str);
		i++;
	}
	if (s2[0] == '\0')
		return (char *)(s1);
	return (str);
}
