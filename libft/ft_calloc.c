/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:47:24 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:32:05 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;

	res = malloc(nmemb * size);
	if (res)
		ft_bzero(res, nmemb * size);
	return (res);
}
