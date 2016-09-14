/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:37:52 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/09 11:47:53 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char *ft_strjoin_path(char const *path, char const *file)
{
	char *str;

	if (!path || !file)
		return (NULL);
	str = (char *)malloc(ft_strlen(path) + ft_strlen(file) + 2);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	ft_strcat(str, (char *)path);
	ft_strcat(str, "/");
	ft_strcat(str, (char *)file);
	return (str);
}
