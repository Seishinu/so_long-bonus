/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_pics_enemy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:06:10 by ynuiga            #+#    #+#             */
/*   Updated: 2022/03/13 15:30:14 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	turn_enemy_left(t_so_long	*so_long, size_t	i, size_t	j)
{
	so_long->images.enemy.img = mlx_xpm_file_to_image(so_long->mlx,
			"./C/enemy_left.xpm", &so_long->images.enemy.w,
			&so_long->images.enemy.h);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * j, so_long->images.grass.h * i);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * (j - 1), so_long->images.grass.h * i);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.enemy.img,
		so_long->images.enemy.w * (j - 1), so_long->images.enemy.h * i);
	so_long->map.map[i][j] = '0';
	so_long->map.map[i][j - 1] = 'X';
}

void	turn_enemy_right(t_so_long	*so_long, size_t	i, size_t	j)
{
	so_long->images.enemy.img = mlx_xpm_file_to_image(so_long->mlx,
			"./C/enemy_right.xpm", &so_long->images.enemy.w,
			&so_long->images.enemy.h);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * j, so_long->images.grass.h * i);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * (j + 1), so_long->images.grass.h * i);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.enemy.img,
		so_long->images.enemy.w * (j + 1), so_long->images.enemy.h * i);
	so_long->map.map[i][j] = '0';
	so_long->map.map[i][j + 1] = 'X';
}

void	turn_enemy_up(t_so_long	*so_long, size_t	i, size_t	j)
{
	so_long->images.enemy.img = mlx_xpm_file_to_image(so_long->mlx,
			"./C/enemy_up.xpm", &so_long->images.enemy.w,
			&so_long->images.enemy.h);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * j, so_long->images.grass.h * i);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * j, so_long->images.grass.h * (i - 1));
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.enemy.img,
		so_long->images.enemy.w * j, so_long->images.enemy.h * (i - 1));
	so_long->map.map[i][j] = '0';
	so_long->map.map[i - 1][j] = 'X';
}

void	turn_enemy_down(t_so_long	*so_long, size_t	i, size_t	j)
{
	so_long->images.enemy.img = mlx_xpm_file_to_image(so_long->mlx,
			"./C/enemy_face.xpm", &so_long->images.enemy.w,
			&so_long->images.enemy.h);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * j, so_long->images.grass.h * i);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * j, so_long->images.grass.h * (i + 1));
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.enemy.img,
		so_long->images.enemy.w * j, so_long->images.enemy.h * (i + 1));
	so_long->map.map[i][j] = '0';
	so_long->map.map[i + 1][j] = 'X';
}
