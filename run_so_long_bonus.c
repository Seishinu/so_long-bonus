/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_so_long_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:39:22 by ynuiga            #+#    #+#             */
/*   Updated: 2022/03/13 15:18:39 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_input(int key, t_so_long *so_long)
{
	if (key == 53 || key == 12)
		exit(1);
	if (key == 0)
	{
		can_exit(so_long, key);
		move_player(key, so_long);
	}
	if (key == 1)
	{
		can_exit(so_long, key);
		move_player2(key, so_long);
	}
	if (key == 2)
	{
		can_exit(so_long, key);
		move_player3(key, so_long);
	}
	if (key == 13)
	{
		can_exit(so_long, key);
		move_player4(key, so_long);
	}
	open_door(so_long);
	return (0);
}

int	exit_hook(t_so_long *so_long)
{
	(void)so_long;
	exit(1);
	return (0);
}

void	render_images(t_so_long *so_long)
{
	so_long->images.grass.img = mlx_xpm_file_to_image(so_long->mlx,
			"./T/grass.xpm", &so_long->images.grass.w,
			&so_long->images.grass.h);
	so_long->images.walls.img = mlx_xpm_file_to_image(so_long->mlx,
			"./T/walls.xpm", &so_long->images.walls.w,
			&so_long->images.walls.h);
	so_long->images.closed_door.img = mlx_xpm_file_to_image(so_long->mlx,
			"./T/closed_door.xpm", &so_long->images.closed_door.w,
			&so_long->images.closed_door.h);
	so_long->images.hero.img = mlx_xpm_file_to_image(so_long->mlx,
			"./C/hero_face.xpm", &so_long->images.hero.w,
			&so_long->images.hero.h);
	so_long->images.collect.img = mlx_xpm_file_to_image(so_long->mlx,
			"./T/collectibles.xpm", &so_long->images.collect.w,
			&so_long->images.collect.h);
	so_long->images.obstacles.img = mlx_xpm_file_to_image(so_long->mlx,
			"./T/obstacles.xpm", &so_long->images.obstacles.w,
			&so_long->images.obstacles.h);
	so_long->images.enemy.img = mlx_xpm_file_to_image(so_long->mlx,
			"./C/enemy_face.xpm", &so_long->images.enemy.w,
			&so_long->images.enemy.h);
}

void	count_bonus(t_so_long *so_long)
{
	char	*count;

	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
		so_long->images.grass.img, 0, 0);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.walls.img, 0, 0);
	count = ft_itoa(so_long->count_bonus);
	mlx_string_put(so_long->mlx, so_long->mlx_win, 0, 0, 0xff0000,
		count);
	so_long->count_bonus++;
	free(count);
}

void	run_so_long(t_so_long *so_long)
{
	so_long->mlx = mlx_init();
	render_images(so_long);
	so_long->mlx_win = mlx_new_window(so_long->mlx,
			so_long->map.columns * so_long->images.walls.w,
			so_long->map.rows * so_long->images.walls.h, "AVERAGE GAME");
	fill_map(so_long);
	fill_characters(so_long);
	fill_enemy(so_long);
	fill_tilesets(so_long);
	fill_ground(so_long);
	fill_exit(so_long);
	count_bonus(so_long);
	mlx_hook(so_long->mlx_win, 2, 0, key_input, so_long);
	mlx_loop_hook(so_long->mlx, move_enemy_bonus, so_long);
	mlx_hook(so_long->mlx_win, 17, 0, exit_hook, so_long);
	mlx_loop(so_long->mlx);
}
