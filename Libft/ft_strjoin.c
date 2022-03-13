/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:03:33 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/14 14:25:20 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static char	*allocation(const char	*str1, const char	*str2);

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	new = allocation(s1, s2);
	i = 0;
	j = 0;
	if (!new)
		return (0);
	while (s1[i])
	{
		new[i] = (char)s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = (char)s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

static char	*allocation(const char	*str1, const char	*str2)
{
	size_t	len;
	size_t	lens1;
	size_t	lens2;
	char	*new;

	lens1 = ft_strlen((char *)str1);
	lens2 = ft_strlen((char *)str2);
	len = lens1 + lens2 + 1;
	new = malloc(len);
	return ((char *)new);
}
