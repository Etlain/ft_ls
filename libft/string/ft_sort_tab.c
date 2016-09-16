/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 22:37:39 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/09/16 22:44:09 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int sort(char *s1, char *s2, int b)
{
	if (b == 1)
		return (ft_strcmp(s2, s1));
	else
		return (ft_strcmp(s1, s2));
}

void	ft_sort_tab(char **tab, int b)
{
	char	*tmp;
	int	i;
	int	move;

	move = 1;
	while (move == 1)
	{
		i = 0;
		move = 0;
		while(tab[i + 1] != NULL)
		{
			if (sort(tab[i + 1], tab[i], b) < 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				move = 1;
			}
			i++;
		}
	}
}
