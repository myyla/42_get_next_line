/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtouham <amtouham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:16:00 by amtouham          #+#    #+#             */
/*   Updated: 2023/02/26 22:43:09 by amtouham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*p;

	i = -1;
	p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s[++i])
		p[i] = s[i];
	p[i] = '\0';
	return (p);
}

int	check_newline(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	char	*sx;
	int		i;
	int		j;

	if (!s1)
		sx = ft_strdup("");
	else
		sx = ft_strdup(s1);
	s = malloc((ft_strlen(sx) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (0);
	i = -1;
	j = -1;
	while (sx[++i])
		s[i] = sx[i];
	while (s2[++j])
		s[i++] = s2[j];
	s[i] = '\0';
	free(sx);
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;
	unsigned int	slen;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	slen = ft_strlen(s + start);
	if (len > slen)
		len = slen;
	i = 0;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	slen = ft_strlen(s);
	i = -1;
	while (++i < len && s[i + start] && start < slen)
		sub[i] = s[i + start];
	sub[i] = '\0';
	return (sub);
}
