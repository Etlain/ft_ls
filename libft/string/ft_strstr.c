/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:31:34 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/03 03:23:20 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char static		*ft_compare(const char *s1, const char *s2, int i)
{
	int j;

	j = 0;
	while (s1[i] != '\0')
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

char			*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
			str = ft_compare(s1, s2, i);
		if (str != NULL)
			return (str);
		i++;
	}
	if (s2[0] == '\0')
		return (char *)(s1);
	return (str);
}
