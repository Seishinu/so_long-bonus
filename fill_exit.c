/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:36:05 by ynuiga            #+#    #+#             */
/*   Updated: 2022/02/26 17:09:29 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_exit(t_so_long *so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (so_long->map.map[i][j] == 'E')
			{
				mlx_put_image_to_window(so_long->mlx,
					so_long->mlx_win, so_long->images.grass.img,
					so_long->images.grass.w * j, so_long->images.grass.h * i);
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					so_long->images.closed_door.img,
					so_long->images.closed_door.w * j,
					so_long->images.grass.h * i);
			}
			j++;
		}
		i++;
	}
}

void	render_put_stairs(t_so_long *so_long, size_t	i, size_t	j)
{
	so_long->images.stairs.img = mlx_xpm_file_to_image(so_long->mlx,
			"./T/stairs.xpm", &so_long->images.stairs.w,
			&so_long->images.stairs.h);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->images.stairs.img,
		so_long->images.stairs.w * j,
		so_long->images.stairs.h * i);
}

void	fill_open_exit(t_so_long *so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (so_long->map.map[i][j] == 'E')
			{
				render_put_stairs(so_long, i, j);
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					so_long->images.closed_door.img,
					so_long->images.closed_door.w * j,
					so_long->images.grass.h * i);
			}
			j++;
		}
		i++;
	}
}
