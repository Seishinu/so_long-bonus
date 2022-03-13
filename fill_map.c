/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:22:17 by ynuiga            #+#    #+#             */
/*   Updated: 2022/03/12 15:45:15 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_tilesets(t_so_long *so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < ft_strlen(so_long->map.map[i]))
		{
			if (so_long->map.map[i][j] == 'C')
			{
				mlx_put_image_to_window(so_long->mlx,
					so_long->mlx_win, so_long->images.grass.img,
					so_long->images.grass.w * j, so_long->images.grass.h * i);
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					so_long->images.collect.img, so_long->images.collect.w * j,
					so_long->images.collect.h * i);
			}
			j++;
		}
		i++;
	}
}

void	fill_ground(t_so_long *so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (so_long->map.map[i][j] == '0')
				mlx_put_image_to_window(so_long->mlx,
					so_long->mlx_win, so_long->images.grass.img,
					so_long->images.grass.w * j, so_long->images.grass.h * i);
			j++;
		}
		i++;
	}
}

void	fill_characters(t_so_long *so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (so_long->map.map[i][j] == 'P')
			{
				mlx_put_image_to_window(so_long->mlx,
					so_long->mlx_win, so_long->images.grass.img,
					so_long->images.grass.w * j, so_long->images.grass.h * i);
				mlx_put_image_to_window(so_long->mlx,
					so_long->mlx_win, so_long->images.hero.img,
					so_long->images.hero.w * j, so_long->images.hero.h * i);
			}	
			j++;
		}
		i++;
	}
}

void	fill_map(t_so_long *so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (so_long->map.map[i][j] == '1')
			{
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					so_long->images.grass.img,
					so_long->images.grass.w * j, so_long->images.grass.h * i);
				mlx_put_image_to_window(so_long->mlx,
					so_long->mlx_win, so_long->images.walls.img,
					so_long->images.walls.w * j, so_long->images.walls.h * i);
			}
			j++;
		}
		i++;
	}
}
