/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:20:01 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/14 14:25:53 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	i = 0;
	if (ft_strlen(s2) == 0)
		return (s1);
	while (s1[i] && len > i)
	{
		if (s1[i] == s2[0] && len >= i + ft_strlen(s2))
		{
			if (!ft_strncmp(&s1[i], s2, ft_strlen(s2)))
				return (&s1[i]);
		}
		i++;
	}
	return (NULL);
}
