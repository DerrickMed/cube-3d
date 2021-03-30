/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 22:48:38 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:38:15 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				res;

	while ((*s1 || *s2) && n--)
	{
		if ((res = (*(unsigned char*)s1 - *(unsigned char*)s2)))
			return (res);
		s1++;
		s2++;
	}
	return (0);
}
