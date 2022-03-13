/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lose_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:47:01 by ynuiga            #+#    #+#             */
/*   Updated: 2022/03/13 15:27:38 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	lost_2(t_so_long *so_long, int key)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (key == 2 && ((so_long->map.map[i][j] == 'P'
					&& so_long->map.map[i][j + 1] == 'X')
					|| (so_long->map.map[i][j] == 'X'
					&& so_long->map.map[i][j + 1] == 'P')))
				exit (1);
			else if (key == 0 && ((so_long->map.map[i][j] == 'P'
					&& so_long->map.map[i][j - 1] == 'X')
					|| (so_long->map.map[i][j] == 'X'
					&& so_long->map.map[i][j - 1] == 'P')))
				exit (1);
			j++;
		}
		i++;
	}
}

void	lost(t_so_long *so_long, int key)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < so_long->map.rows)
	{
		j = 0;
		while (j < so_long->map.columns)
		{
			if (key == 1 && ((so_long->map.map[i][j] == 'P'
					&& so_long->map.map[i + 1][j] == 'X') ||
					(so_long->map.map[i][j] == 'X' &&
					so_long->map.map[i + 1][j] == 'P')))
				exit (1);
			else if (key == 13 && ((so_long->map.map[i][j] == 'P'
					&& so_long->map.map[i - 1][j] == 'X')
					|| (so_long->map.map[i][j] == 'X'
					&& so_long->map.map[i - 1][j] == 'P')))
				exit (1);
			j++;
		}
		i++;
	}
	lost_2(so_long, key);
}
