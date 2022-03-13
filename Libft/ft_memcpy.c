/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:21:39 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/17 15:16:46 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (0);
	d = (char *)dst;
	s = (char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
