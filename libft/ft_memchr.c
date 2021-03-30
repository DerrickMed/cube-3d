/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 03:13:23 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:37:30 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *str, int ch, size_t n)
{
	unsigned char	c;
	size_t			i;

	c = (unsigned char)ch;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)str == c)
		{
			return ((void*)str);
		}
		i++;
		str++;
	}
	if (n > 0 && *(char*)(str - 1) == 0 && c == 0)
		return ((void*)(str - 1));
	return (0);
}
