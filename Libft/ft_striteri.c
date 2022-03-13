/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:55:32 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/18 22:56:51 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char	*str;
	int		i;

	if (!f || !s)
		return ;
	i = 0;
	str = (char *)s;
	while (str[i])
	{
		f(i, &str[i]);
		i++;
	}
}
