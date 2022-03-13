/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:45:16 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/17 15:21:08 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int		len;
	char	*str;

	str = (char *)s;
	len = ft_strlen(str);
	while (len)
	{
		if (str[len] == (char)c)
			return (&str[len]);
		len--;
	}
	if ((char)c == str[len])
		return (&str[len]);
	return (0);
}
