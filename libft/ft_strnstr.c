/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:25:22 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:38:18 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char	*a;
	char	*b;
	size_t	i;
	size_t	j;

	i = 0;
	b = (char*)to_find;
	if (*b == 0)
		return ((char*)str);
	while (*str != '\0' && i++ < len)
	{
		str++;
		if (*(str - 1) != *b)
			continue;
		a = (char*)str - 1;
		j = i - 1;
		while (i++ - 1 < len + 1)
			if (*b == 0)
				return ((char*)str - 1);
			else if (*a++ != *b++)
				break ;
		i = j;
		b = (char*)to_find;
	}
	return (0);
}
