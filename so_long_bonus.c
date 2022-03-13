/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:12:28 by ynuiga            #+#    #+#             */
/*   Updated: 2022/03/13 17:24:54 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_so_long	so_long;

	if (argc != 2)
		throwerror(E_WAN);
	if (!strnstr(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		throwerror (E_WFE);
	so_long = read_map(argv[1]);
	run_so_long(&so_long);
}
