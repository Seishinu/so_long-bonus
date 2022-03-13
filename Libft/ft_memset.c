/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:10:28 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/17 15:16:52 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memset(void	*b, int c, size_t	len)
{
	unsigned char	*dest;

	dest = b;
	while (len > 0)
	{
		*dest++ = c;
		len--;
	}
	return (b);
}
