/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:36:35 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:35:22 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*n;

	n = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	while (n->next)
		n = n->next;
	n->next = new;
}
