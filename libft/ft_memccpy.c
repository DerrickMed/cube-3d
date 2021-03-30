/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 03:13:23 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:37:27 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;

	i = 0;
	if (n == 0)
		return (0);
	ch = (unsigned char)c;
	while (i < n && *(unsigned char*)src != ch)
	{
		*(unsigned char*)dest = *(unsigned char*)src;
		dest++;
		src++;
		i++;
	}
	if (i != n && *(unsigned char*)src == ch)
		*(unsigned char*)dest = ch;
	return (*(unsigned char*)dest == ch ? dest + 1 : 0);
}
