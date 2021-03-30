/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 03:13:23 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:37:37 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if ((size_t)dest + n < (size_t)src || (size_t)src >= (size_t)dest)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		((unsigned char*)dest)[n - 1] = ((unsigned char*)src)[n - 1];
		n--;
	}
	return (dest);
}
