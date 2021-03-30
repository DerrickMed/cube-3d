/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:36:36 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:31:48 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int				sign;
	long long int	res;
	long long int	res_tmp;

	res = 0;
	while (*str && ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && ft_isdigit(*str))
	{
		res_tmp = res;
		res = res * 10 + (*str++ - '0') * sign;
		if ((res < res_tmp && sign == 1) || (res > res_tmp && sign == -1))
			return (sign == 1 ? -1 : 0);
	}
	return ((int)res);
}
