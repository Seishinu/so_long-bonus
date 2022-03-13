/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:20:37 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/17 15:16:49 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void	*dest, const void	*src, size_t	len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!s && !d)
		return (0);
	if (d < s)
		ft_memcpy(dest, src, len);
	else
	{
		s += len - 1;
		d += len - 1;
		while (len--)
			*d-- = *s--;
	}
	return (dest);
}
