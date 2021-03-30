/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:11:53 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:38:08 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	const char	*s;
	size_t		newsize;

	if (src == NULL)
		return (0);
	if (size == 0)
		newsize = 1;
	else
		newsize = size;
	s = src;
	while (newsize-- > 1 && (*dest++ = *s++) != '\0')
		;
	if (newsize == 0)
	{
		if (size != 0)
			*dest = '\0';
	}
	return (ft_strlen(src));
}
