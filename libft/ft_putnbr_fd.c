/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 03:13:23 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:37:48 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int sign;
	int tmp[10];
	int i;

	sign = (n >= 0 ? 1 : -1);
	i = (n == 0 ? 1 : 0);
	tmp[0] = 0;
	while (n != 0)
	{
		tmp[i] = n % 10 * sign;
		n /= 10;
		i++;
	}
	if (sign == -1)
		ft_putchar_fd('-', fd);
	while (i > 0)
		ft_putchar_fd(tmp[--i] + '0', fd);
}
