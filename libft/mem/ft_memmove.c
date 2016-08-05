/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:02:15 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/03 03:01:53 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *buf;

	buf = (unsigned char*)malloc(len + 1);
	ft_memcpy(buf, src, len);
	ft_memcpy(dst, buf, len);
	free(buf);
	return (dst);
}
