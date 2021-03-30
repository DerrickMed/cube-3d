/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:43:17 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:38:02 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	i;
	char	*res;

	i = 0;
	if (!s1 || !s2)
		return (0);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	res = (char*)malloc(total_len + 1);
	if (!res)
		return (0);
	while (*s1)
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = 0;
	return (res);
}
