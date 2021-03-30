/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:05:08 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/31 01:17:49 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char				*gnl_strjoin(char *s1, char const *s2)
{
	size_t			total_len;
	size_t			i;
	char			*res;
	char			*to_free;

	i = 0;
	if (!s1 || !s2)
		return (0);
	to_free = s1;
	total_len = protected_strlen(s1) + protected_strlen((char *)s2);
	if (!(res = (char *)malloc(total_len + 1)))
		return (0);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i] = 0;
	if (to_free)
		ft_free(to_free);
	return (res);
}

static int			readit(int fd, char *temp, char **line)
{
	char			buffer;

	buffer = 0;
	while (read(fd, &buffer, 1) && buffer != '\n')
		temp = gnl_strjoin(temp, &buffer);
	if (buffer == '\n')
	{
		temp = gnl_strjoin(temp, "\n\0");
		(*line) = temp;
		return (1);
	}
	temp = gnl_strjoin(temp, "\0");
	(*line) = temp;
	return (0);
}

int					get_next_line(int fd, char **line)
{
	char			*temp;

	temp = 0;
	if (fd < 0 || !(line) || (read(fd, 0, 0) == -1))
		return (-1);
	if (!(temp = malloc(sizeof(char))))
		return (-1);
	*temp = 0;
	return (readit(fd, temp, line));
}
