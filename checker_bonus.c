/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:54:46 by ynuiga            #+#    #+#             */
/*   Updated: 2022/03/13 16:13:46 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	throwerror(int f)
{
	if (f == E_IMS)
		write(2, "Error\nInvalide Map Structure !\n", 31);
	else if (f == E_MAC)
		write(2, "Error\nYou Missed A Component !\n", 31);
	else if (f == E_OPM)
		write(2, "Error\nYou need One Player Per Map !\n", 36);
	else if (f == E_WAN)
		write(2, "Error\nWrong Number Of Arguments !\n", 34);
	else if (f == E_AWC)
		write(2, "Error\nYou Added A Wrong Component !\n", 36);
	else if (f == E_WFE)
		write(2, "Error\nWrong File Extention !\n", 29);
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	exit (errno);
}

void	check_walls(t_so_long	so_long)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (so_long.map.map[i])
	{
		j = 0;
		while (so_long.map.map[i][j])
		{
			if (so_long.map.map[0][j] != '1' || \
				so_long.map.map[so_long.map.rows - 1][j] != '1'
				|| so_long.map.map[i][0] != '1' || \
				so_long.map.map[i][so_long.map.columns - 1] != '1')
				throwerror(E_IMS);
			j++;
		}
		i++;
	}
}

void	check_player(t_so_long	so_long)
{
	size_t	i;
	size_t	j;
	int		count;

	count = 0;
	i = 0;
	while (so_long.map.map[i])
	{
		j = 0;
		while (so_long.map.map[i][j])
		{
			if (so_long.map.map[i][j] == 'P')
				count++;
			if (so_long.map.map[i][j] != 'P' && so_long.map.map[i][j] != 'E' &&
				so_long.map.map[i][j] != 'C' && so_long.map.map[i][j] != 'X' &&
				so_long.map.map[i][j] != '1' && so_long.map.map[i][j] != '0')
				throwerror(E_AWC);
			j++;
		}
		i++;
	}
	if (count > 1)
		throwerror(E_OPM);
}

void	check_components(t_so_long	so_long)
{
	if (!ft_strchr2(so_long.map.map, 'P') || !ft_strchr2(so_long.map.map, 'E')
		|| !ft_strchr2(so_long.map.map, 'C'))
		throwerror(E_MAC);
}

void	check(t_so_long	*so_long)
{
	size_t	a;

	a = 1;
	while (a < so_long->map.rows)
	{
		if (ft_strlen(so_long->map.map[a]) != \
			ft_strlen(so_long->map.map[a - 1]))
			throwerror(E_IMS);
		a++;
	}
	so_long->map.columns = ft_strlen(so_long->map.map[0]);
	if (so_long->map.columns < 3)
		throwerror(E_IMS);
	check_walls(*so_long);
	check_components(*so_long);
	check_player(*so_long);
}
