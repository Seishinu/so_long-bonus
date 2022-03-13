/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynuiga <ynuiga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:49:03 by ynuiga            #+#    #+#             */
/*   Updated: 2021/11/18 19:59:23 by ynuiga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static char	*substr_2(char const *s, unsigned int start, size_t len)
{
	char	*smain;
	size_t	i;
	char	*sub;

	i = 0;
	smain = (char *)s;
	sub = (char *) malloc(len + 1);
	if (!sub)
		return (0);
	while (i < len)
	{
		sub[i] = smain[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static char	*substr_3(char const *s, unsigned int start, size_t len)
{
	char	*smain;
	size_t	i;
	char	*sub;

	i = 0;
	smain = (char *)s;
	sub = (char *) malloc(ft_strlen(smain) - start + 1);
	if (!sub)
		return (0);
	while (smain[start + i])
	{
		sub[i] = smain[start + i + len - len];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*smain;
	size_t	i;
	char	*sub;

	i = 0;
	smain = (char *)s;
	if (!smain)
		return (0);
	if (start >= ft_strlen(smain))
	{
		sub = (char *) malloc(1);
		if (!sub)
			return (0);
		sub[0] = '\0';
		return (sub);
	}
	if (ft_strlen(smain) > start + len)
		return (substr_2(s, start, len));
	else
	{
		return (substr_3(s, start, len));
	}
	return (0);
}
