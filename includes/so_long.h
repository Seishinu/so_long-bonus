/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:11:57 by ynuiga            #+#    #+#             */
/*   Updated: 2022/03/14 13:46:28 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "mlx.h"
# include "../Libft/libft.h"
# define BUFFER_SIZE 100
# define E_IMS -1
# define E_MAC -2
# define E_OPM -3
# define E_WAN -4
# define E_AWC -5
# define E_WFE -6

typedef struct s_image
{
	void	*img;
	int		w;
	int		h;
}			t_image;

typedef struct s_images
{
	t_image	grass;
	t_image	stairs;
	t_image	walls;
	t_image	closed_door;
	t_image	hero;
	t_image	collect;
	t_image	obstacles;
}			t_images;

typedef struct s_map
{
	char	**map;
	size_t	columns;
	size_t	rows;
}			t_map;

typedef struct s_so_long
{
	void		*mlx;
	void		*mlx_win;
	size_t		height;
	size_t		width;
	t_map		map;
	t_images	images;
	int			count;
}				t_so_long;

char		*get_next_line(int fd);
void		check(t_so_long	*so_long);
t_so_long	read_map(char *file_name);
void		throwerror(int f);
void		fill_map(t_so_long *so_long);
void		fill_characters(t_so_long *so_long);
void		fill_tilesets(t_so_long *so_long);
void		fill_ground(t_so_long *so_long);
void		fill_exit(t_so_long *so_long);
void		move_player(int key, t_so_long	*so_long);
void		run_so_long(t_so_long *so_long);
void		check_win(t_so_long *so_long, int i, int j);
void		move_player2(int key, t_so_long	*so_long);
void		turn_left(t_so_long	*so_long, size_t	i, size_t	j);
void		turn_right(t_so_long	*so_long, size_t	i, size_t	j);
void		go_up(t_so_long	*so_long, size_t	i, size_t	j);
void		go_down(t_so_long	*so_long, size_t	i, size_t	j);
void		can_exit(t_so_long *so_long, int key);
void		move_player3(int key, t_so_long	*so_long);
void		move_player4(int key, t_so_long	*so_long);
void		open_door(t_so_long	*so_long);
void		fill_open_exit(t_so_long *so_long);
void		count(t_so_long *so_long);

#endif