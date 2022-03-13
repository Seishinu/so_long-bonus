/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_pics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:49:12 by ynuiga            #+#    #+#             */
/*   Updated: 2022/03/11 21:37:23 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	turn_left(t_so_long	*so_long, size_t	i, size_t	j)
{
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * j, so_long->images.grass.h * i);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * (j - 1), so_long->images.grass.h * i);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.hero.img,
		so_long->images.hero.w * (j - 1), so_long->images.hero.h * i);
	so_long->map.map[i][j] = '0';
	so_long->map.map[i][j - 1] = 'P';
}

void	turn_right(t_so_long	*so_long, size_t	i, size_t	j)
{
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * j, so_long->images.grass.h * i);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * (j + 1), so_long->images.grass.h * i);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.hero.img,
		so_long->images.hero.w * (j + 1), so_long->images.hero.h * i);
	so_long->map.map[i][j] = '0';
	so_long->map.map[i][j + 1] = 'P';
}

void	go_up(t_so_long	*so_long, size_t	i, size_t	j)
{
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * j, so_long->images.grass.h * i);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * j, so_long->images.grass.h * (i - 1));
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.hero.img,
		so_long->images.hero.w * j, so_long->images.hero.h * (i - 1));
	so_long->map.map[i][j] = '0';
	so_long->map.map[i - 1][j] = 'P';
}

void	go_down(t_so_long	*so_long, size_t	i, size_t	j)
{
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * j, so_long->images.grass.h * i);
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.grass.img,
		so_long->images.grass.w * j, so_long->images.grass.h * (i + 1));
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, so_long->images.hero.img,
		so_long->images.hero.w * j, so_long->images.hero.h * (i + 1));
	so_long->map.map[i][j] = '0';
	so_long->map.map[i + 1][j] = 'P';
}
