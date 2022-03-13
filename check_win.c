/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win_lose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:56:03 by ynuiga            #+#    #+#             */
/*   Updated: 2022/02/27 19:17:30 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	can_exit2(t_so_long	*so_long, int key)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (so_long->map.map[i][j] == 'P' && \
				so_long->map.map[i][j + 1] == 'E' && key == 2 &&
				!ft_strchr2(so_long->map.map, 'C'))
				exit (1);
			else if (so_long->map.map[i][j] == 'P' && \
				so_long->map.map[i][j - 1] == 'E' && key == 0 &&
				!ft_strchr2(so_long->map.map, 'C'))
				exit (1);
			j++;
		}
		i++;
	}
}

void	can_exit(t_so_long *so_long, int key)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (so_long->map.map[i][j] == 'P' && \
				so_long->map.map[i + 1][j] == 'E' && key == 1 &&
				!ft_strchr2(so_long->map.map, 'C'))
				exit (1);
			else if (so_long->map.map[i][j] == 'P' && \
				so_long->map.map[i - 1][j] == 'E' && key == 13 &&
				!ft_strchr2(so_long->map.map, 'C'))
				exit (1);
			j++;
		}
		i++;
	}
	can_exit2(so_long, key);
}

void	check_win(t_so_long *so_long, int i, int j)
{
	if (!ft_strchr2(so_long->map.map, 'C') && so_long->map.map[i][j] == 'E')
		exit (1);
}

void	open_door(t_so_long	*so_long)
{
	if (!ft_strchr2(so_long->map.map, 'C'))
	{
		so_long->images.closed_door.img = mlx_xpm_file_to_image(so_long->mlx,
				"./T/open_door.xpm", &so_long->images.closed_door.w,
				&so_long->images.closed_door.h);
		fill_open_exit(so_long);
	}
}
