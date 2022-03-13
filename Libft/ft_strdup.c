/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:37:10 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/23 16:25:39 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char	*s1)
{
	size_t	len;
	void	*s2;

	len = ft_strlen(s1) + 1;
	if (len == 0)
		return (0);
	s2 = malloc(len);
	if (s2 == 0)
		return (0);
	ft_memcpy(s2, s1, len);
	return ((char *)s2);
}
