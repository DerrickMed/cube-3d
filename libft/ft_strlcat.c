/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:27:39 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:38:06 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t dest_len;
	size_t src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (*dest && i < size)
	{
		i++;
		dest++;
	}
	dest_len = i;
	if (size != 0)
		while (*src && i < size - 1)
		{
			i++;
			*dest = *src;
			src++;
			dest++;
		}
	if (i < size)
		*dest = '\0';
	return (dest_len + src_len);
}
