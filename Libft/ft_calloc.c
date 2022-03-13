/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:24:11 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/17 15:16:27 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t	count, size_t	size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		size = 1;
		count = size;
	}
	ptr = malloc(count * size);
	if (ptr)
	{
		ft_bzero(ptr, count * size);
	}
	return (ptr);
}
