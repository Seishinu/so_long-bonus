/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:35:13 by ynuiga            #+#    #+#             */
/*   Updated: 2022/03/13 21:54:39 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

void	move_enemy_left(t_so_long	*so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (so_long->map.map[i][j] == 'X' && \
				so_long->map.map[i][j - 1] != '1' &&
				so_long->map.map[i][j - 1] != 'E' &&
				so_long->map.map[i][j - 1] != 'C')
			{
				lost(so_long, 0);
				turn_enemy_left(so_long, i, j);
			}
			j++;
		}
		i++;
	}
}

void	move_enemy_down(t_so_long	*so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (so_long->map.map[i][j] == 'X' && \
				so_long->map.map[i + 1][j] != '1' &&
				so_long->map.map[i + 1][j] != 'E' &&
				so_long->map.map[i + 1][j] != 'C')
			{
				lost(so_long, 1);
				turn_enemy_down(so_long, i, j);
				i = so_long->map.rows;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	move_enemy_right(t_so_long	*so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{	
			if (so_long->map.map[i][j] == 'X' && \
				so_long->map.map[i][j + 1] != '1' &&
				so_long->map.map[i][j + 1] != 'E' &&
				so_long->map.map[i][j + 1] != 'C')
			{
				lost(so_long, 2);
				turn_enemy_right(so_long, i, j);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	move_enemy_up(t_so_long	*so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (so_long->map.map[i][j] == 'X' && \
				so_long->map.map[i - 1][j] != '1' &&
				so_long->map.map[i - 1][j] != 'E' &&
				so_long->map.map[i - 1][j] != 'C')
			{
				lost(so_long, 13);
				turn_enemy_up(so_long, i, j);
			}
			j++;
		}
		i++;
	}
}

int	move_enemy_bonus(t_so_long	*so_long)
{
	static short	time;
	int				i;
	char			c;

	time++;
	if (time < 5000)
		return (0);
	else
		time = 0;
	i = open("/dev/random", O_RDONLY);
	if (i == -1)
		exit(1);
	if (read(i, &c, 1) == -1)
		exit(1);
	if (c >= -128 && c <= -64)
		move_enemy_left(so_long);
	else if (c >= -63 && c <= 0)
		move_enemy_right(so_long);
	else if (c >= 1 && c <= 64)
		move_enemy_up(so_long);
	else if (c >= 65 && c <= 127)
		move_enemy_down(so_long);
	close(i);
	return (0);
}
