/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:25:22 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:37:55 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int ch)
{
	char cc;

	cc = (char)ch;
	while (*str)
	{
		if (*str == cc)
		{
			return ((char*)str);
		}
		str++;
	}
	if (*str == 0 && ch == 0)
		return ((char*)str);
	return (0);
}
