/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:46:52 by moudrib           #+#    #+#             */
/*   Updated: 2022/12/03 15:21:07 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_rest(char *buf)
{
	char	*rest;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (buf[++i])
	{
		if (buf[i] == '\n')
		{
			i++;
			break ;
		}
	}
	rest = malloc(((ft_strlen(buf) - i) + 1) * sizeof(char));
	if (!rest)
		return (free(buf), NULL);
	while (buf[i])
		rest[j++] = buf[i++];
	rest[j] = '\0';
	return (free(buf), rest);
}

char	*read_line(int fd, char *buf)
{
	char	*tmp;
	int		read_return;

	read_return = 1;
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (search_newline(buf) && read_return)
	{
		read_return = read(fd, tmp, BUFFER_SIZE);
		if ((read_return == 0 && !buf) || read_return < 0)
			return (free(tmp), free(buf), NULL);
		tmp[read_return] = '\0';
		buf = ft_strjoin(buf, tmp);
	}
	free(tmp);
	if (buf[0] == '\0')
		return (free(buf), NULL);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char		*buf;
	char			*line;
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_line(fd, buf);
	if (!buf)
		return (NULL);
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
		{
			i++;
			break ;
		}
	}
	line = ft_substr(buf, 0, i);
	buf = save_rest(buf);
	return (line);
}
