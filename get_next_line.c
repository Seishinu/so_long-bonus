/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:42:34 by ynuiga            #+#    #+#             */
/*   Updated: 2022/02/15 12:08:10 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char	*s, int c)
{
	s = (char *)s;
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*get_line(char **saved)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 0;
	while ((*saved)[i] != '\n' && (*saved)[i])
		i++;
	if ((*saved)[i] == '\n')
	{
		line = ft_substr(*saved, 0, i + 1);
		tmp = *saved;
		*saved = ft_strjoin(*saved + i + 1, "");
		free(tmp);
	}
	else
	{
		line = *saved;
		*saved = 0;
	}
	if (*line == '\0')
	{
		free(line);
		line = 0;
	}
	return (line);
}

char	*get_read(int fd, char **saved)
{
	int			eof;
	char		*tmp;
	char		*reed;

	reed = (char *)malloc(BUFFER_SIZE + 1);
	if (!reed)
		return (0);
	eof = 1;
	while (eof && !ft_strchr(*saved, '\n'))
	{
		eof = read(fd, reed, BUFFER_SIZE);
		reed[eof] = '\0';
		tmp = *saved;
		*saved = ft_strjoin(*saved, reed);
		free(tmp);
	}
	free (reed);
	return (get_line(saved));
}

char	*get_next_line(int fd)
{
	static char	*saved;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, saved, 0) < 0)
		return (0);
	if (!saved)
		saved = ft_strjoin("", "");
	return (get_read(fd, &saved));
}
