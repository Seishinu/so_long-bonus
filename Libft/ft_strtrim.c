/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:36:46 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/18 20:07:07 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strtrim(char const	*s1, char const	*set)
{
	size_t	i;
	size_t	lenmain;
	char	*smain;

	if (!s1 || !set)
		return (0);
	lenmain = ft_strlen(s1) - 1;
	smain = (char *)s1;
	i = 0;
	while (ft_strchr(set, smain[i]) && smain[i])
		i++;
	while (ft_strchr(set, smain[lenmain]) && i < lenmain)
		lenmain--;
	return (ft_substr(s1, i, lenmain - i + 1));
}
