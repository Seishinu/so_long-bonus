/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:14:21 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/18 23:06:57 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;
	char	*new;

	if (!f || !s)
		return (0);
	str = (char *)s;
	i = 0;
	new = (char *)malloc(ft_strlen(str) + 1);
	if (!new)
		return (0);
	while (str[i])
	{
		new[i] = f(i, str[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
