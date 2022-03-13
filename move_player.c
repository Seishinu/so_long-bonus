/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:01:26 by ynuiga            #+#    #+#             */
/*   Updated: 2022/03/11 14:48:15 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(int key, t_so_long	*so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (key == 0 && so_long->map.map[i][j] == 'P' && \
				so_long->map.map[i][j - 1] != '1' &&
				so_long->map.map[i][j - 1] != 'E')
			{
				count(so_long);
				turn_left(so_long, i, j);
			}
			j++;
		}
		i++;
	}
}

void	move_player2(int key, t_so_long	*so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (key == 1 && so_long->map.map[i][j] == 'P' && \
				so_long->map.map[i + 1][j] != '1' &&
				so_long->map.map[i + 1][j] != 'E')
			{
				count(so_long);
				go_down(so_long, i, j);
				i = so_long->map.rows;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	move_player3(int key, t_so_long	*so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{	
			if (key == 2 && so_long->map.map[i][j] == 'P' && \
				so_long->map.map[i][j + 1] != '1' &&
				so_long->map.map[i][j + 1] != 'E')
			{
				count(so_long);
				turn_right(so_long, i, j);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	move_player4(int key, t_so_long	*so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (key == 13 && so_long->map.map[i][j] == 'P' && \
				so_long->map.map[i - 1][j] != '1' &&
				so_long->map.map[i - 1][j] != 'E')
			{
				count(so_long);
				go_up(so_long, i, j);
			}
			j++;
		}
		i++;
	}
}
