/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:10:41 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/03 03:22:54 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_words(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			words++;
		i++;
	}
	if (s[0] != c)
		words++;
	return (words);
}

static int	ft_buf(char *buf, char const *s, char c, int *i)
{
	int j;

	j = 0;
	while (s[*i] != '\0' && s[*i] != c)
	{
		buf[j] = s[*i];
		j++;
		(*i)++;
	}
	buf[j] = '\0';
	return (j);
}

static void	ft_tab(char **tab, char const *buf, int length, int *j)
{
	int		i;

	i = 0;
	if (length > 0)
	{
		tab[*j] = (char*)malloc(sizeof(char) * length + 1);
		while (buf[i] != '\0' && length != 0)
		{
			tab[*j][i] = buf[i];
			i++;
		}
		tab[*j][i] = '\0';
		(*j)++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*buf;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	length = 0;
	if (!s)
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * ft_words(s, c) + 1);
	buf = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (tab == NULL || buf == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		length = ft_buf(buf, s, c, &i);
		length == 0 ? i++ : 0;
		ft_tab(tab, buf, length, &j);
	}
	tab[j] = NULL;
	free(buf);
	return (tab);
}
