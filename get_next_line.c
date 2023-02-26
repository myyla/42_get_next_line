/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtouham <amtouham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:40:12 by amtouham          #+#    #+#             */
/*   Updated: 2023/02/26 23:11:40 by amtouham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read2_newline(char *container, int fd)
{
	ssize_t	cnt;
	char	*ptr;
	char	*buf;

	cnt = 1337;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(container), NULL);
	buf[0] = '\0';
	while (cnt && !check_newline(buf))
	{
		cnt = read(fd, buf, BUFFER_SIZE);
		if (cnt == -1)
			return (free(buf), NULL);
		buf[cnt] = '\0';
		ptr = ft_strjoin(container, buf);
		free(container);
		container = ptr;
	}
	return (free(buf), container);
}

static char	*get_line_from_container(char *container)
{
	char	*line;
	size_t	i;

	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	line = ft_substr(container, 0, i + 1);
	return (line);
}

static char	*update_container(char	*container)
{
	char	*sub;
	size_t	i;

	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (container[i] == '\n')
		i++;
	sub = ft_substr(container, i, ft_strlen(container + i));
	free(container);
	return (sub);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10240)
		return (NULL);
	container = read2_newline(container, fd);
	if (!container)
		return (NULL);
	if (!*container)
	{
		free(container);
		container = 0;
		return (NULL);
	}
	line = get_line_from_container(container);
	container = update_container(container);
	return (line);
}
