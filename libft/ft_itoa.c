/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 03:13:23 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:35:15 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		nb;
	int		len;
	char	*ret;

	len = 2;
	if (n < 0)
		len++;
	nb = n;
	while (!(nb < 10 && nb > -10))
	{
		len++;
		nb /= 10;
	}
	if (!(ret = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ret[--len] = '\0';
	nb = (n < 0) ? -1 : 1;
	while (n || len)
	{
		ret[--len] = n % 10 * nb + '0';
		n /= 10;
	}
	if (nb < 0)
		ret[0] = '-';
	return (ret);
}
