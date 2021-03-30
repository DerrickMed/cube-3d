/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:54:14 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 19:37:21 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *l;

	if ((l = (t_list *)malloc(sizeof(t_list))) != NULL)
	{
		l->content = content;
		l->next = NULL;
	}
	return (l);
}
