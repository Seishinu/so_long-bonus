/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:01:24 by ynuiga            #+#    #+#             */
/*   Updated: 2022/03/13 16:14:51 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fix_map(t_so_long *so_long, int fd)
{
	size_t	len;
	size_t	i;
	char	*line;

	i = 0;
	while (i < so_long->map.rows)
	{
		line = get_next_line(fd);
		len = ft_strlen(line);
		if (line[len - 1] == '\n' && i < so_long->map.rows - 1)
			line[len - 1] = '\0';
		so_long->map.map[i++] = line;
	}
	so_long->map.map[so_long->map.rows] = NULL;
}

t_so_long	read_map(char *file_name)
{
	int			fd;
	char		*line;
	t_so_long	so_long;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		throwerror(errno);
	so_long.map.rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		so_long.map.rows++;
	}
	if (so_long.map.rows < 3)
		throwerror(E_IMS);
	so_long.map.map = malloc (sizeof(char *) * (so_long.map.rows + 1));
	close(fd);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		throwerror(0);
	fix_map(&so_long, fd);
	check(&so_long);
	return (so_long);
}

void	count(t_so_long *so_long)
{
	so_long->count++;
	ft_putnbr_fd(so_long->count, 1);
	write(1, "\n", 1);
}
