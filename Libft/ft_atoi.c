/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:39:23 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/17 14:20:49 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	quickmaphs(const char *str, int sign, size_t i)
{
	size_t	rslt;

	rslt = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		if ((unsigned long)rslt * 10 + (str[i] - 48)
			> (unsigned long)9223372036854775807 && sign == 1)
			return (-1);
		else if ((unsigned long)rslt * 10 + (str[i] - 48)
			> (unsigned long)9223372036854775807 + 1 && sign == -1)
			return (0);
		rslt = (rslt * 10) + (str[i] - 48);
		i++;
	}
	return (rslt * sign);
}

int	ft_atoi(const char	*str)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (quickmaphs(str, sign, i));
}
