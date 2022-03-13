/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_so_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:39:22 by ynuiga            #+#    #+#             */
/*   Updated: 2022/03/12 20:25:39 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_images	render_images(t_so_long so_long)
{
	t_images	images;

	images.grass.img = mlx_xpm_file_to_image(so_long.mlx,
			"./T/grass.xpm", &images.grass.w, &images.grass.h);
	images.walls.img = mlx_xpm_file_to_image(so_long.mlx,
			"./T/walls.xpm", &images.walls.w, &images.walls.h);
	images.closed_door.img = mlx_xpm_file_to_image(so_long.mlx,
			"./T/closed_door.xpm", &images.closed_door.w,
			&images.closed_door.h);
	images.hero.img = mlx_xpm_file_to_image(so_long.mlx,
			"./C/hero_face.xpm", &images.hero.w, &images.hero.h);
	images.collect.img = mlx_xpm_file_to_image(so_long.mlx,
			"./T/collectibles.xpm", &images.collect.w, &images.collect.h);
	images.obstacles.img = mlx_xpm_file_to_image(so_long.mlx,
			"./T/obstacles.xpm", &images.obstacles.w, &images.obstacles.h);
	return (images);
}

void	run_so_long(t_so_long	*so_long)
{
	so_long->mlx = mlx_init();
	so_long->images = render_images(*so_long);
	so_long->mlx_win = mlx_new_window(so_long->mlx,
			so_long->map.columns * so_long->images.walls.w,
			so_long->map.rows * so_long->images.walls.h, "AVERAGE GAME");
	fill_map(so_long);
	fill_characters(so_long);
	fill_tilesets(so_long);
	fill_ground(so_long);
	fill_exit(so_long);
	ft_putnbr_fd(so_long->count, 1);
	write(1, "\n", 1);
	mlx_hook(so_long->mlx_win, 2, 0, key_input, so_long);
	mlx_hook(so_long->mlx_win, 17, 0, exit_hook, so_long);
	mlx_loop(so_long->mlx);
}
