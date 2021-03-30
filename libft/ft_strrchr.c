/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:25:22 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:38:20 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	unsigned char	cc;
	char			*ret;

	ret = 0;
	cc = (unsigned char)ch;
	while (*str)
	{
		if (*str == cc)
		{
			ret = (char*)str;
		}
		str++;
	}
	if (*str == 0 && ch == 0)
		ret = (char*)str;
	return (ret);
}
